#include "SnakeGame.h"

char board = 219;

Food::Food(int boardWidth, int boardHeight) {
	boardWidth = 20 * 2;
	boardHeight = 20;

	srand(time(NULL));
	posX = rand() % boardWidth;
	posY = rand() % boardHeight;
}

void Food::generateNewPosition(int boardWidth, int boardHeight) {
	srand(time(NULL));
	posX = rand() % boardWidth;
	posY = rand() % boardHeight;
}

int Food::getPosX() { return posX; }
int Food::getPosY() { return posY; }


void SnakeGame::setup() {
	gameOver = false;
	points = 0;

	width = 20 * 2;
	height = 20;

	directions = STOP;
	snakePosX = width / 2;
	snakePosY = height / 2;

	snakeBodyX.resize(100);
	snakeBodyY.resize(100);
}

void SnakeGame::print(Food& food) {
	system("cls");

	//char upperBoard = 205;

	for (int i = 0; i < width + 2; i++) {
		cout << board;
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0) {
				cout << board;
			}

			if (i == snakePosY && j == snakePosX) {
				cout << "O";
			}
			else if (i == food.getPosY() && j == food.getPosX()) {
				cout << food.getSymbol();
			}
			else {
				bool isSnakeTailCoord = false;
				for (int k = 0; k < snakeLength; k++) {
					if (j == snakeBodyX[k] && i == snakeBodyY[k]) {
						cout << "o";
						isSnakeTailCoord = true;
					}
				}
				if (!isSnakeTailCoord)
					cout << " ";
			}
			if (j == width - 1)
				cout << board;
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++) {
		cout << board;
	}
	cout << endl;
	cout << "\nPOINTS: " << points << endl;
}

void SnakeGame::input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			directions = UP;
			break;
		case 'a':
			directions = LEFT;
			break;
		case 's':
			directions = DOWN;
			break;
		case 'd':
			directions = RIGHT;
			break;
		case 27:	// ESC button
			gameOver = true;
			break;
		}
	}
}

void SnakeGame::logic(Food& food) {
	int previousX = snakeBodyX[0];
	int previousY = snakeBodyY[0];
	int prev2X, prev2Y;

	snakeBodyX[0] = snakePosX;
	snakeBodyY[0] = snakePosY;

	for (int i = 1; i < snakeLength; i++) {
		prev2X = snakeBodyX[i];
		prev2Y = snakeBodyY[i];

		snakeBodyX[i] = previousX;
		snakeBodyY[i] = previousY;

		previousX = prev2X;
		previousY = prev2Y;
	}

	switch (directions) {
	case LEFT:
		snakePosX--;
		break;
	case RIGHT:
		snakePosX++;
		break;
	case UP:
		snakePosY--;
		break;
	case DOWN:
		snakePosY++;
		break;
	default:
		break;
	}

	if (snakePosX >= width)
		snakePosX = 0;
	else if (snakePosX < 0)
		snakePosX = width - 1;

	if (snakePosY >= height)
		snakePosY = 0;
	else if (snakePosY < 0)
		snakePosY = height - 1;

	for (int i = 0; i < snakeLength; i++) {
		if (snakeBodyX[i] == snakePosX && snakeBodyY[i] == snakePosY)
			gameOver = true;
	}

	if (snakePosX == food.getPosX() && snakePosY == food.getPosY()) {
		snakeLength++;
		points++;
		food.generateNewPosition(width, height);
	}
}

void howToPlay();

int main() {
	int action;

	cout << "1. PLAY" << endl;
	cout << "2. HOW TO PLAY" << endl;
	cout << "3. EXIT" << endl;

	cout << "\nChoose what you want to do: ";
	cin >> action;

	if (action == 1) {
		SnakeGame snake;
		int foodType = rand() % 3;
		Food* food = nullptr; // Initialize food pointer as nullptr

		switch (foodType) {
		case 0:
			food = new FoodDollar(snake.getWidth(), snake.getHeight());
			break;
		case 1:
			food = new FoodAt(snake.getWidth(), snake.getHeight());
			break;
		case 2:
			food = new FoodAmpersand(snake.getWidth(), snake.getHeight());
			break;
		}

		if (food != nullptr) {
			snake.setup();
			while (!snake.isGameOver()) {
				snake.print(*food);
				snake.input();
				snake.logic(*food);
				Sleep(50);
			}
		}

		delete food;
	}
	else if (action == 2) {
		howToPlay();
	}
	else if (action == 3) {
		system("cls");
		cout << "\nEXIT\n";
		return 1;
	}
	else {
		system("cls");
		cout << "\nYou crashed the game :D\n";
	}

	return 0;
}

void howToPlay() {
	system("cls");
	cout << "\nIt's realyy easy\n";
	cout << "All you have to do is move your snake and eat food\n\n";
	cout << "How to move:\n";
	cout << "w - up\na - left\ns - down\nd - right\n";
	cout << "ESC - ends the game\n";
}