#include <iostream>
#include <string>

using namespace std;

class Movie
{
private:
    string title;
    string director;
    int duration; // in minutes

public:
    Movie()
    {
        title = " ";
        director = " ";
        duration = 0;
    }

    Movie(string t, string d, int du)
    {
        title = t;
        director = d;
        duration = du;
    }

    void display() const
    {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " mins" << endl;
    }
};

class CinemaHall
{
private:
    Movie *movies;
    string hallName;
    int count;
    int total;

public:
    CinemaHall()
    {
        movies = NULL;
        hallName = " ";
        count = 0;
        total = 0;
    }

    CinemaHall(string n, int t)
    {
        hallName = n;
        total = t;
        count = 0;
        movies = new Movie[total];
    }

    void addMovie(const Movie &m)
    {
        if (count < total)
        {
            movies[count] = m;
            count++;
        }
        else
        {
            cout << "Cannot add more movies. Cinema Hall is full!" << endl;
        }
    }

    void display() const
    {
        cout << "Cinema Hall: " << hallName << endl;
        cout << "Total Movies: " << count << endl;
        cout << "Movies Showing: " << endl;
        for (int i = 0; i < count; i++)
        {
            movies[i].display();
        }
    }

    ~CinemaHall()
    {
        delete[] movies;
    }
};

int main()
{
    CinemaHall hall("Nueplex", 4);

    Movie barbie("Barbie (2024)", "Greta Gerwig", 114);
    Movie johnWick1("John Wick", "Chad Stahelski", 101);
    Movie johnWick2("John Wick: Chapter 2", "Chad Stahelski", 122);
    Movie johnWick3("John Wick: Chapter 3 - Parabellum", "Chad Stahelski", 131);

    hall.addMovie(barbie);
    hall.addMovie(johnWick1);
    hall.addMovie(johnWick2);
    hall.addMovie(johnWick3);

    hall.display();

    return 0;
}
