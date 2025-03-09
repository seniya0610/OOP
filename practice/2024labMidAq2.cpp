#include <iostream>
#include <string>
using namespace std;

class Movie
{
private:
    string title;
    string director;
    int duration;

public:
    Movie() : title(""), director(""), duration(0) {}

    Movie(const string& _title, const string& _director, int _duration)
        : title(_title), director(_director), duration(_duration) {}

    string getTitle() const { return title; }
    string getDirector() const { return director; }
    int getDuration() const { return duration; }

    void display() const
    {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " mins" << endl;
    }
};

class Playlist
{
private:
    string name;
    Movie* movies;
    int numMovies;
    const int maxMovies = 100; // Maximum movies per playlist

public:
    Playlist(const string& _name) : name(_name), numMovies(0)
    {
        movies = new Movie[maxMovies];
    }

    ~Playlist()
    {
        delete[] movies;
    }

    void addMovie(Movie* movie)
    {
        if (numMovies < maxMovies)
        {
            movies[numMovies++] = *movie;
        }
        else
        {
            cout << "Playlist is full!" << endl;
        }
    }

    void removeMovie(Movie* movie)
    {
        bool found = false;
        for (int i = 0; i < numMovies; i++)
        {
            if (movies[i].getTitle() == movie->getTitle())
            {
                // Shift all movies after the found movie one position to the left
                for (int j = i; j < numMovies - 1; j++)
                {
                    movies[j] = movies[j + 1];
                }
                numMovies--;
                found = true;
                cout << "Movie '" << movie->getTitle() << "' removed from the playlist." << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Movie '" << movie->getTitle() << "' not found in the playlist." << endl;
        }
    }

    void displayInfo() const
    {
        cout << "Playlist: " << name << endl;
        for (int i = 0; i < numMovies; ++i)
        {
            movies[i].display();
            cout << "-----------------" << endl;
        }
    }
};

class User
{
private:
    string name;
    Playlist* playlists;
    int numPlaylists;
    const int maxPlaylists = 10; // Maximum playlists per user

public:
    User(const string& _name) : name(_name), numPlaylists(0)
    {
        playlists = new Playlist[maxPlaylists];
    }

    ~User()
    {
        delete[] playlists;
    }

    void createPlaylist(const string& playlistName)
    {
        if (numPlaylists < maxPlaylists)
        {
            playlists[numPlaylists++] = Playlist(playlistName);
        }
        else
        {
            cout << "Cannot create more playlists!" << endl;
        }
    }

    void addMovieToPlaylist(Playlist* playlist, Movie* movie)
    {
        playlist->addMovie(movie);
    }

    void removeMovieFromPlaylist(Playlist* playlist, Movie* movie)
    {
        playlist->removeMovie(movie);
    }

    void displayUserPlaylists() const
    {
        cout << "User: " << name << endl;
        for (int i = 0; i < numPlaylists; ++i)
        {
            playlists[i].displayInfo();
            cout << "=================" << endl;
        }
    }
};

int main()
{
    // Create movies
    Movie movie1("The Dark Knight", "Christopher Nolan", 152);
    Movie movie2("Inception", "Christopher Nolan", 148);
    Movie movie3("The Hangover", "Todd Phillips", 100);
    Movie movie4("Superbad", "Greg Mottola", 113);

    // Create user
    User user("Mujeeb Rehman");

    // Create playlists
    user.createPlaylist("Action Movies");
    user.createPlaylist("Comedy Movies");

    // Add movies to playlists
    user.addMovieToPlaylist(&user.getPlaylist(0), &movie1);
    user.addMovieToPlaylist(&user.getPlaylist(0), &movie2);
    user.addMovieToPlaylist(&user.getPlaylist(1), &movie3);
    user.addMovieToPlaylist(&user.getPlaylist(1), &movie4);

    // Display playlists
    cout << "Initial Playlists:" << endl;
    user.displayUserPlaylists();

    // Remove "Inception" from "Action Movies"
    user.removeMovieFromPlaylist(&user.getPlaylist(0), &movie2);

    // Display updated playlists
    cout << "\nUpdated Playlists:" << endl;
    user.displayUserPlaylists();

    return 0;
}
