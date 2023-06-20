# snake_Cpp_OOP

--------

Projekt składa się z dwóch plików:
1. SnakeGame.h: Plik nagłówkowy zawierający deklaracje klas i funkcji.
2. SnakeGame.cpp: Plik implementacyjny zawierający definicje funkcji.

--------

# Klasy:
## Food:
* Jest to abstrakcyjna klasa bazowa dla różnych rodzajów jedzenia w grze.
* Podklasy dziedziczą po niej, reprezentując konkretne rodzaje jedzenia (FoodDollar, FoodAt, FoodAmpersand).
* Klasa Food zarządza pozycją jedzenia na planszy gry.
* Metoda generateNewPosition(boardWidth, boardHeight) generuje nową losową pozycję jedzenia na planszy.
* Metoda getPosX() zwraca wartość X (poziomą) pozycji jedzenia.
* Metoda getPosY() zwraca wartość Y (pionową) pozycji jedzenia.
* Metoda getSymbol() jest czysto wirtualną funkcją, która jest przesłaniana przez podklasy, aby zwracać symbol konkretnego rodzaju jedzenia.
## FoodDollar, FoodAt, FoodAmpersand:
* Są to podklasy klasy Food.
* Każda podklasa reprezentuje konkretny rodzaj jedzenia z własnym symbolem.
* Przesłaniają funkcję getSymbol(), aby zwracać swoje odpowiednie symbole.
## SnakeGame:
* Ta klasa reprezentuje samą grę.
* Zarządza stanem gry, takim jak rozmiar planszy, pozycję węża i wynikiem.
* Obsługuje również wejście użytkownika, aktualizuje logikę gry i wyświetla planszę.
* Metoda setup() inicjalizuje początkowy stan gry.
* Metoda print(Food& food) wyświetla planszę, węża i jedzenie na ekranie.
* Metoda input() odczytuje wejście od użytkownika (przyciski) i zmienia kierunek węża zgodnie z nimi.
* Metoda logic(Food** food) kontroluje logikę gry, taką jak poruszanie wężem, sprawdzanie kolizji i obsługa zjedzenia jedzenia.
* Metoda isGameOver() sprawdza, czy gra została zakończona.
* Metody getWidth() i getHeight() zwracają szerokość i wysokość planszy.

--------

# Zmienne globalne:
## board:
* Ta zmienna reprezentuje znak używany do wyświetlania planszy gry.
## food:
* Ta zmienna przechowuje wskaźnik do aktualnego obiektu jedzenia w grze.

--------

# Funkcje:
## generateRandomFood():
* Ta funkcja generuje losowe położenie jedzenia na planszy gry.
## howToPlay():
* wyświetla instrukcje dla gracza, jak grać w grę Snake.
## defecaultyLevel():
* pobiera od gracza wybór poziomu trudności gry.

## main():
* jest główną funkcją programu. Wyświetla menu, obsługuje wybór gracza i uruchamia grę.
