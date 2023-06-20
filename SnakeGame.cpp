#include "SnakeGame.h"


// =================  GLOBAL variables  =================
char board = 219;
Food* food = nullptr;
// ======================================================


// -------------------------------------------  Food methods  -------------------------------------------

// Function to generate random food
Food* generateRandomFood(int width, int height) {
	int foodType = rand() % 3;
	switch (foodType) {
		case 0:
			return new FoodDollar(width, height);
		case 1:
			return new FoodAt(width, height);
		case 2:
			return new FoodAmpersand(width, height);
		default:
			return nullptr;
	}
}

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
// ---------------------------------------------------------------------------------------------------


// -------------------------------------------  SnakeGame methods  -------------------------------------------

void SnakeGame::setup() {
	gameOver = false;
	points = 0;

	width = 20 * 2;
	height = 20;

	directions = STOP;
	snakePosX = width / 2;
	snakePosY = height / 2;

	// change vactors sizes to 100
	snakeBodyX.resize(100);
	snakeBodyY.resize(100);
}

void SnakeGame::print(Food& food) {
	system("cls");

	// upper board body
	for (int i = 0; i < width + 2; i++) {
		cout << board;
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// left side of board
			if (j == 0) {
				cout << board;
			}

			if (i == snakePosY && j == snakePosX) {	// draw snake head
				cout << "O";
			}
			else if (i == food.getPosY() && j == food.getPosX()) {	// draw food symbol
				cout << food.getSymbol();
			}
			else {
				// draw snake's tail if his coordinates matches 
				bool isSnakeTailCoord = false;
				for (int k = 0; k < snakeLength; k++) {
					if (j == snakeBodyX[k] && i == snakeBodyY[k]) {
						cout << "o";
						isSnakeTailCoord = true;
					}
				}
				if (!isSnakeTailCoord)	// draw " " (space) if snake's tail coordinates does not match
					cout << " ";
			}

			// left side of board
			if (j == width - 1)
				cout << board;
		}
		cout << endl;
	}

	// bottom board body
	for (int i = 0; i < width + 2; i++) {
		cout << board;
	}
	cout << endl;
	cout << "\nPOINTS: " << points << endl;
}

void SnakeGame::input() {
	if (_kbhit()) {	// check if a key has been pressed on the keyboard
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

void SnakeGame::logic(Food** food) {
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

	// snake can go through the walls
	if (snakePosX >= width)
		snakePosX = 0;
	else if (snakePosX < 0)
		snakePosX = width - 1;

	if (snakePosY >= height)
		snakePosY = 0;
	else if (snakePosY < 0)
		snakePosY = height - 1;

	// chceck does snake eats himself
	for (int i = 0; i < snakeLength; i++) {
		if (snakeBodyX[i] == snakePosX && snakeBodyY[i] == snakePosY)
			gameOver = true;
	}

	// check does the snake eats the food
	if (snakePosX == (*food)->getPosX() && snakePosY == (*food)->getPosY()) {
		snakeLength++;
		points++;
		delete* food; // Delete old food

		// Generate new food of random type
		*food = generateRandomFood(width, height);
	}
}
// ---------------------------------------------------------------------------------------------------


// --------------------------------------------  functions  ------------------------------------------
void howToPlay() {
	system("cls");
	cout << "\nIt's realy easy\n";
	cout << "All you have to do is move your snake and eat food\n\n";
	cout << "How to move:\n";
	cout << "w - up\na - left\ns - down\nd - right\n";
	cout << "ESC - ends the game\n";
}

int difficultyLevel() {
	int level, defecaulty;
	system("cls");
	cout << "Choose defecaulty level:\n";
	cout << "1. SLOW\n";
	cout << "2. NORMAL\n";
	cout << "3. FAST\n";
	cin >> level;

	if (level == 1) {
		defecaulty = 120;
	}
	else if (level == 2) {
		defecaulty = 30;
	}
	else if (level == 3) {
		defecaulty = 10;
	}
	else {
		defecaulty = 30;
	}

	return defecaulty;
}
// ---------------------------------------------------------------------------------------------------


// ================================================ MAIN  ================================================
int main() {
	int action;

	cout << "1. PLAY" << endl;
	cout << "2. HOW TO PLAY" << endl;
	cout << "3. EXIT" << endl;

	cout << "\nChoose what you want to do: ";
	cin >> action;

	if (action == 1) {
		int difficulty = difficultyLevel();

		SnakeGame snake;
		food = generateRandomFood(snake.getWidth(), snake.getHeight()); // Initial food type

		snake.setup();
		while (!snake.isGameOver()) {
			snake.print(*food);
			snake.input();
			snake.logic(&food); // Pass pointer to logic function
			Sleep(difficulty);
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