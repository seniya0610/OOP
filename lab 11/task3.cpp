#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;

class FileException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "File Error";
    }
};

class FileNotFoundException : public FileException
{
public:
    const char *what() const noexcept override
    {
        return "FileNotFoundException - File not found!";
    }
};

class PermissionDeniedException : public FileException
{
public:
    const char *what() const noexcept override
    {
        return "PermissionDeniedException - Access denied!";
    }
};

void Readfile(string filename)
{
    if (filename == "data.txt")
    {
        throw FileException();
    }
    else if (filename == "missing.txt")
    {
        throw FileNotFoundException();
    }
    else if (filename == "secret.txt")
    {
        throw PermissionDeniedException();
    }
    else
    {
        fstream file(filename);
        if (!file)
        {
            throw FileException();
        }
        cout << "Reading '" << filename << "' successfully." << endl;
    }
}

int main()
{
    string filenames[] = {"data.txt", "missing.txt", "secret.txt"};

    for (int i = 0; i < 3; i++)
    {
        try
        {
            Readfile(filenames[i]);
        }
        catch (const FileNotFoundException &e)
        {
            cerr << "Reading '" << filenames[i] << "': " << e.what() << endl;
        }
        catch (const PermissionDeniedException &e)
        {
            cerr << "Reading '" << filenames[i] << "': " << e.what() << endl;
        }
        catch (const FileException &e)
        {
            cerr << "Reading '" << filenames[i] << "': " << e.what() << endl;
        }
    }

    return 0;
}
