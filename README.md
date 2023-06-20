# Gra Snake

--------

## Opis:
Snake – gra komputerowa, w której gracz za pomocą klawiszy strzałek steruje wężem. Wąż porusza się w zamkniętym prostokącie/kwadracie i nie może „uderzyć” w samego siebie. Zadaniem gracza jest zdobycie jak największej liczby punktów, poprzez karmienie węża pojawiającym się na ekranie pokarmem.

## Założenia gry:
* Nie ma limitu czasowego
* Plansza jest ograniczona do prostokąta lub kwadratu ograniczonego ścianami
* Wąż nie może uderzyć w samego siebie
* Wąż porusza się ze stałą prędkością
* Po najechaniu na pokarm gracz otrzymuje 1 punkt, a jego waż staje się większy
* Wężem steruje się za pomocą przycisków ‘w’ ‘a’ ‘s’ ‘d’
* Gra kończy się w momencie gdy wąż uderzy w samego siebie

--------

Projekt składa się z dwóch plików:
1. SnakeGame.h: Plik nagłówkowy zawierający deklaracje klas i funkcji.
2. SnakeGame.cpp: Plik implementacyjny zawierający definicje funkcji.

--------

![image](https://github.com/kakarotto2004/snake_Cpp_OOP/assets/126653764/b1caad31-c735-4be4-b1a5-30c5843ffb70)

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

--------

# Założenia funkcjonalne:
* Gracz może poruszać wężem w górę, w dół, w lewo i w prawo na planszy.
* Wąż powinien rosnąć o jeden segment po zjedzeniu jedzenia.
* Jeśli głowa węża zderzy się z jakimkolwiek segmentem swojego ciała, gra kończy się.
* Wyświetlanie planszy gry, węża, jedzenia i punktacji.
* Wygenerowanie nowego jedzenia po zjedzeniu poprzedniego.

# Założenia niefunkcjonalne:
* Interfejs użytkownika: Interfejs gry powinien być intuicyjny i łatwy w obsłudze, umożliwiając płynną i przyjemną rozgrywkę.
* Przenośność: Gra powinna być przenośna i kompatybilna z różnymi platformami, takimi jak Windows, macOS i Linux, aby użytkownicy mogli cieszyć się grą na swoich preferowanych systemach operacyjnych.
* Bezpieczeństwo: Implementacja gry powinna być wolna od podatności na ataki i błędy, aby zapewnić bezpieczne środowisko rozgrywki dla graczy.
* Dokumentacja: Implementacja gry powinna być udokumentowana, zawierając komentarze w kodzie, instrukcje użytkowania i ewentualnie instrukcje instalacji, aby ułatwić zrozumienie i użytkowanie gry przez inne osoby.
