#include <iostream>
#include <string>
using namespace std;

class Media
{
public:
    string title, publication, uniqueID, publisher;
    bool isCheckedOut;

    Media(string t, string p, string id, string pub)
        : title(t), publication(p), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo()
    {
        cout << "Title: " << title << "\nPublication Date: " << publication
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
             << "\nStatus: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut()
    {
        if (!isCheckedOut)
        {
            isCheckedOut = true;
            cout << title << " has been checked out.\n";
        }
        else
        {
            cout << title << " not available\n";
        }
    }

    void returnItem()
    {
        if (isCheckedOut)
        {
            isCheckedOut = false;
            cout << title << " has been returned.\n";
        }
        else
        {
            cout << title << " was not checked out.\n";
        }
    }

    string getTitle()
    {
        return title;
    }

    string getPublication()
    {
        return publication;
    }

    virtual string getAuthorOrDirector()
    {
        return "";
    }

    virtual ~Media() {}
};

class Book : public Media
{
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string p, string id, string pub, string auth, string isbn, int pages)
        : Media(t, p, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }

    string getAuthorOrDirector() override
    {
        return author;
    }
};

class DVD : public Media
{
    string director;
    int duration;
    float rating;

public:
    DVD(string t, string p, string id, string pub, string dir, int dur, float rate)
        : Media(t, p, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " min\nRating: " << rating << endl;
    }

    string getAuthorOrDirector() override
    {
        return director;
    }
};

class CD : public Media
{
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string p, string id, string pub, string art, int tracks, string gen)
        : Media(t, p, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

class Library
{
private:
    Media *items[100];
    int itemCount;

public:
    Library() : itemCount(0) {}

    void addItem(Media *newItem)
    {
        if (itemCount < 100)
        {
            items[itemCount] = newItem;
            itemCount++;
        }
        else
        {
            cout << "Library is full!" << endl;
        }
    }

    void search(string title)
    {
        bool found = false;
        for (int i = 0; i < itemCount; i++)
        {
            if (items[i]->getTitle() == title)
            {
                items[i]->displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "Not found" << endl;
    }

    void search(string creator, int type)
    {
        bool found = false;
        for (int i = 0; i < itemCount; i++)
        {
            if (items[i]->getAuthorOrDirector() == creator)
            {
                items[i]->displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "not found" << endl;
    }

    void search(int year)
    {
        bool found = false;
        for (int i = 0; i < itemCount; i++)
        {
            if (items[i]->getPublication() == to_string(year))
            {
                items[i]->displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "Not found" << endl;
    }

    ~Library()
    {
        for (int i = 0; i < itemCount; i++)
        {
            delete items[i];
        }
    }
};

int main()
{
    Library library;
    Book *b1 = new Book("The Great Gatsby", "1925", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    library.addItem(b1);

    DVD *d1 = new DVD("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, 8.8);
    library.addItem(d1);

    CD *c1 = new CD("Thriller", "1982", "C001", "Epic", "Michael Jackson", 9, "Pop");
    library.addItem(c1);

    library.search("Inception");
    library.search("Christopher Nolan");
    library.search(1982);

    return 0;
}
