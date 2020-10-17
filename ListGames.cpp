#include <iostream>

#include "GameMenu.h"
#include "Game.h"

// Include possible headers that your games uses.
#include "Minesweeper.h"

int Game::count = 0; // Only for initializing the amount of games the menu handles for this run.

// Just a minor test.
void test()
{
  cout << 1 + 2 << endl;
  cin.get();
}

// Function responsible on initializing the game menu and allocating the games to it.
// @return GameMenu menu - Menu of initialized games, which is used throughout the app's lifecycle.
GameMenu initGames()
{
  // INSERT THE GAMES BELOW THIS COMMENT

  Game board("Miinaharava", &initMinesweeper, "Tämä on hankalaa!");
  Game helloBoard("Hello World!", &test);
  Game emptyBoard;

  // INSERT THE GAMES ABOVE THIS COMMENT

  int amount = Game::count;

  // Initializing the menu itself, taking the amount of initialized games to determine the size of the game array.
  GameMenu menu(amount, "TERVETULOA PELAAMAAN! OLE HYVÄ JA VALITSE PELI KIRJOITTAMALLA SITÄ VASTAAVA NUMERO!");

  // REMEMBER TO INCLUDE YOUR GAMES BELOW THIS COMMENT
  if (menu.gameAmount > 0)
  {
    menu.addGames(board);
    menu.addGames(helloBoard);
    menu.addGames(emptyBoard);
  }
  // REMEMBER TO INCLUDE YOUR GAMES ABOVE THIS COMMENT

  return menu;
}