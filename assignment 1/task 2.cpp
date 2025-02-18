#include <iostream>
#include <string>

using namespace std;

// Function to convert string to lowercase
string lowercase(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	return s;
}

// Ball class
class Ball {
private:
	int x_coordinate;
	int y_coordinate;

public:
	Ball() {
		x_coordinate = 0;
		y_coordinate = 0;
	}

	int GetX() { return x_coordinate; }
	int GetY() { return y_coordinate; }

	void SetX(int x) { x_coordinate = x; }
	void SetY(int y) { y_coordinate = y; }

	void displayPosition() {
		cout << "Ball Position: (" << x_coordinate << ", " << y_coordinate << ")\n";
	}
};

class Robot {
private:
	string name;
	int hits;

public:
	Robot() {
		name = "RobotX";
		hits = 0;
	}

	void hitBall(Ball& ball, string direction) {
		string d = lowercase(direction);
		cout << "Robot " << name << " is hitting the ball " << d << "!\n";

		int ballX = ball.GetX();
		int ballY = ball.GetY();

		if (d == "up") {
			if (ballY == 3) {
				cout << "Cannot move up. Reached end of field.\n";
			} else {
				cout << "Moving Up!\n";
				ball.SetY(ballY + 1);
			}
		} 
		else if (d == "down") {
			if (ballY == 0) {
				cout << "Cannot move down. Reached end of field.\n";
			} else {
				cout << "Moving Down!\n";
				ball.SetY(ballY - 1);
			}
		} 
		else if (d == "left") {
			if (ballX == 0) {
				cout << "Cannot move left. Reached end of field.\n";
			} else {
				cout << "Moving Left!\n";
				ball.SetX(ballX - 1);
			}
		} 
		else if (d == "right") {
			if (ballX == 3) {
				cout << "Cannot move right. Reached end of field.\n";
			} else {
				cout << "Moving Right!\n";
				ball.SetX(ballX + 1);
			}
		} 
		else {
			cout << "Invalid direction!\n";
		}
	}
};

class Team
{
    string teamName;
    Robot *myRobot;
};

class Game{

};

// Main function with hardcoded moves
int main() {
	Ball ball;
	Robot robot;

	cout << "Initial ";
	ball.displayPosition();

	// Hardcoded moves
	robot.hitBall(ball, "UP");
	ball.displayPosition();

	robot.hitBall(ball, "Right");
	ball.displayPosition();

	robot.hitBall(ball, "DOWN");
	ball.displayPosition();

	robot.hitBall(ball, "LEFT");
	ball.displayPosition();

	return 0;
}
