#include <iostream>
#include <string>
using namespace std;

class Players
{
private:
    int ballScores[12];
    string PlayerName;
    int TotalScore;

public:
    Players(string n)
    {
        PlayerName = n;
        TotalScore = 0;
        for (int i = 0; i < 12; i++)
        {
            ballScores[i] = 0;
        }
    }

    float average()
    {
        float avg;
        avg = TotalScore / 12;
        return avg;
    }

    int getTotalScore()
    {
        return TotalScore;
    }

    string getName()
    {
        return PlayerName;
    }

    int *getBallscores()
    {
        return ballScores;
    }

    // Function to update the total score
    void updateTotalScore(int score)
    {
        TotalScore += score;
    }
};

class Game
{
private:
    string name;

public:
    Game(string n)
    {
        name = n;
    }

    void playGame(Players &player)
    {
        cout << "Playing game for " << player.getName() << ":\n";
        for (int i = 0; i < 12; i++)
        {
            int score;
            cout << "Enter score for ball " << i + 1 << " (0-6): ";
            cin >> score;
            if (validateScore(score))
            {
                player.getBallscores()[i] = score;
                player.updateTotalScore(score);
            }
            else
            {
                player.getBallscores()[i] = 0;
            }
        }
    }

    bool validateScore(int score)
    {
        return (score >= 0 && score <= 6);
    }

    void findWinner(Players &player1, Players &player2)
    {
        if (player1.getTotalScore() > player2.getTotalScore())
        {
            cout << "Winner: " << player1.getName() << "!\n";
        }
        else if (player1.getTotalScore() < player2.getTotalScore())
        {
            cout << "Winner: " << player2.getName() << "!\n";
        }
        else
        {
            cout << "It's a tie!\n";
        }
    }

    void displayMatchScoreBoard(Players &player1, Players &player2)
    {
        cout << "Match Results:\n";

        // Sort and display player1's scores
        int *scores1 = player1.getBallscores();
        bubbleSort(scores1, 12);
        cout << player1.getName() << "'s scores: ";
        for (int i = 0; i < 12; i++)
        {
            cout << scores1[i] << " ";
        }
        cout << "\nTotal: " << player1.getTotalScore() << ", Average: " << player1.average() << endl;

        // Sort and display player2's scores
        int *scores2 = player2.getBallscores();
        bubbleSort(scores2, 12);
        cout << player2.getName() << "'s scores: ";
        for (int i = 0; i < 12; i++)
        {
            cout << scores2[i] << " ";
        }
        cout << "\nTotal: " << player2.getTotalScore() << ", Average: " << player2.average() << endl;
    }

private:
    // Helper function to sort the scores using bubble sort
    void bubbleSort(int *arr, int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

int main()
{
    Players player1("Alice");
    Players player2("Bob");

    Game game("Cricket");

    game.playGame(player1);
    game.playGame(player2);

    game.displayMatchScoreBoard(player1, player2);

    game.findWinner(player1, player2);

    return 0;
}
