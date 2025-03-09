#include <iostream>
#include <string>
using namespace std;

class User;
class Post;
class Comment;
class SocialMediaPlatform;

class Comment
{
private:
    int commentID;
    string content;
    User *Author;

public:
    Comment()
    {
        commentID = -1;
        content = "";
        Author = nullptr;
    }

    Comment(int id, string c, User *auth)
    {
        commentID = id;
        content = c;
        Author = auth;
    }

    void displayComment()
    {
        cout << "\tComment ID: " << commentID << ", Content: " << content << endl;
    }
};

class Post
{
private:
    int postID;
    string content;
    int MaxComments = 20;
    Comment *listC;
    int count;

public:
    Post()
    {
        postID = -1;
        content = "";
        listC = new Comment[MaxComments];
        count = 0; // Fixed: Initialize count to 0
    }
    Post(int id, string c)
    {
        postID = id;
        content = c;
        listC = new Comment[MaxComments];
        count = 0;
    }
    ~Post()
    {
        delete[] listC;
    }

    void addcomment(Comment& c)
    {
        if (count < MaxComments) // Fixed: Add comment if there's space
        {
            listC[count++] = c;
        }
        else
        {
            cout << "Comment limit reached for this post." << endl;
        }
    }

    void displayPosts() const
    {
        cout << "Post ID: " << postID << ", Content: " << content << endl;
        for (int i = 0; i < count; i++)
        {
            listC[i].displayComment();
        }
    }
};

class User
{
private:
    int UserID;
    string name;
    int maxPosts;
    Post *listP;
    int count;

public:
    User()
    {
        UserID = -1;
        name = "";
        maxPosts = 20;
        listP = new Post[maxPosts];
        count = 0;
    }

    User(int id, string n)
    {
        UserID = id;
        name = n;
        maxPosts = 20;
        listP = new Post[maxPosts];
        count = 0;
    }
    ~User()
    {
        delete[] listP;
    }

    void displayUserFeed() const
    {
        cout << "User ID: " << UserID << ", Name: " << name << endl;
        for (int i = 0; i < count; i++)
        {
            listP[i].displayPosts();
        }
    }

    void addpost(Post& P)
    {
        if (count < maxPosts) // Fixed: Add post if there's space
        {
            listP[count++] = P;
        }
        else
        {
            cout << "Post limit reached for this user." << endl;
        }
    }
};

class SocialMediaPlatform
{
private:
    User *listU;
    int count;
    int maxUsers;

public:
    SocialMediaPlatform()
    {
        maxUsers = 100; // Fixed: Initialize maxUsers
        listU = new User[maxUsers];
        count = 0;
    }

    ~SocialMediaPlatform()
    {
        delete[] listU;
    }

    void display() const
    {
        for (int i = 0; i < count; ++i)
        {
            listU[i].displayUserFeed();
        }
    }

    void addUser(User& u)
    {
        if (count < maxUsers) // Fixed: Add user if there's space
        {
            listU[count++] = u;
        }
        else
        {
            cout << "User limit reached on the platform." << endl;
        }
    }
};

int main()
{
    SocialMediaPlatform platform;

    User user1(1, "Alice");
    User user2(2, "Bob");

    Post post1(101, "Hello, world!");
    Post post2(102, "Another post.");

    Comment comment1(1, "Nice post!", &user1);
    Comment comment2(2, "Great!", &user2);

    post1.addcomment(comment1);
    post2.addcomment(comment2);

    user1.addpost(post1);
    user2.addpost(post2);

    platform.addUser(user1);
    platform.addUser(user2);

    platform.display();

    return 0;
}
