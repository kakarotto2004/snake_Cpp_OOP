#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

class Food
{
private:
	int posX, posY;	// food position on board

public:
	Food(int boardWidth, int boardHeight);

	void generateNewPosition(int boardWidth, int boardHeight);
	int getPosX();
	int getPosY();
	virtual char getSymbol() = 0; // pure virtual function to make Food an abstract class
};

class FoodDollar : public Food {
public:
	FoodDollar(int boardWidth, int boardHeight) : Food(boardWidth, boardHeight) {}
	char getSymbol() override { return '$'; }
};

class FoodAt : public Food {
public:
	FoodAt(int boardWidth, int boardHeight) : Food(boardWidth, boardHeight) {}
	char getSymbol() override { return '@'; }
};

class FoodAmpersand : public Food {
public:
	FoodAmpersand(int boardWidth, int boardHeight) : Food(boardWidth, boardHeight) {}
	char getSymbol() override { return '&'; }
};


class SnakeGame
{
private:
	bool gameOver;
	int width, height;	// board size
	int snakePosX, snakePosY;	// snake's head position on board
	int points;

	vector<int> snakeBodyX, snakeBodyY;
	int snakeLength;

	enum Directions {
		STOP = 0,
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	Directions directions;

public:
	bool isGameOver() { return gameOver; }

	int getWidth() { return width; }
	int getHeight() { return height; }

	void setup();
	void print(Food& food);	// print board, snake and food
	void input();	// check the button pressing by player
	void logic(Food& food);
};