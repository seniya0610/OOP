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

    Movie(string title, string director, int duration)
        : title(title), director(director), duration(duration) {}

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
    Movie *movies;
    int numMovies;
    int maxMovies = 100;

public:
    Playlist() : name("unknown"), numMovies(0) 
    {
        movies = new Movie[maxMovies];
    }

    Playlist(string name) : name(name), numMovies(0)
    {
        movies = new Movie[maxMovies];
    }

    // Deep Copy Constructor
    Playlist(const Playlist& other)
        : name(other.name), numMovies(other.numMovies)
    {
        movies = new Movie[maxMovies];
        for (int i = 0; i < numMovies; i++)
        {
            movies[i] = other.movies[i]; // Deep copy
        }
    }

    ~Playlist()
    {
        delete[] movies;
    }

    void addMovie(Movie &movie)
    {
        if (numMovies < maxMovies)
        {
            movies[numMovies++] = movie;
        }
        else
        {
            cout << "Playlist is full!" << endl;
        }
    }

    void removeMovie(const Movie &movie)
    {
        bool found = false;
        for (int i = 0; i < numMovies; i++)
        {
            if (movies[i].getTitle() == movie.getTitle())
            {
                // Shift all movies after the found movie one position to the left
                for (int j = i; j < numMovies - 1; j++)
                {
                    movies[j] = movies[j + 1];
                }
                numMovies--;
                found = true;
                cout << "Movie '" << movie.getTitle() << "' removed from the playlist." << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Movie '" << movie.getTitle() << "' not found in the playlist." << endl;
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
    Playlist *playlists;
    int numPlaylists;
    const int maxPlaylists = 10; // Maximum playlists per user

public:
    User(string name) : name(name), numPlaylists(0)
    {
        playlists = new Playlist[maxPlaylists];
    }

    // Deep Copy Constructor
    User(const User& other)
        : name(other.name), numPlaylists(other.numPlaylists)
    {
        playlists = new Playlist[maxPlaylists];
        for (int i = 0; i < numPlaylists; i++)
        {
            playlists[i] = other.playlists[i]; // Deep copy
        }
    }

    ~User()
    {
        delete[] playlists;
    }

    void createPlaylist(Playlist &P)
    {
        if (numPlaylists < maxPlaylists)
        {
            playlists[numPlaylists++] = P;
        }
        else
        {
            cout << "Limit Reached" << endl;
        }
    }

    void addMovieToPlaylist(Playlist &playlist, Movie &movie)
    {
        playlist.addMovie(movie);
    }

    void removeMovieFromPlaylist(Playlist &playlist, Movie &movie)
    {
        playlist.removeMovie(movie);
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
    Movie movie1("The Dark Knight", "Christopher Nolan", 152);
    Movie movie2("Inception", "Christopher Nolan", 148);
    Movie movie3("The Hangover", "Todd Phillips", 100);
    Movie movie4("Superbad", "Greg Mottola", 113);

    Playlist playlist("Action Movies");

    playlist.addMovie(movie1);
    playlist.addMovie(movie2);
    playlist.addMovie(movie3);
    playlist.addMovie(movie4);

    cout << "Initial Playlist:" << endl;
    playlist.displayInfo();

    playlist.removeMovie(movie2);

    cout << "\nUpdated Playlist:" << endl;
    playlist.displayInfo();

    User user("Mujeeb Rehman");

    Playlist playlist1("Action Movies");
    playlist1.addMovie(movie1);
    playlist1.addMovie(movie2);

    Playlist playlist2("Comedy Movies");
    playlist2.addMovie(movie3);
    playlist2.addMovie(movie4);

    user.createPlaylist(playlist1);
    user.createPlaylist(playlist2);

    cout << "\nUser Playlists:" << endl;
    user.displayUserPlaylists();

    return 0;
}
