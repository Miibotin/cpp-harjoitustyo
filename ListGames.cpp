#include <iostream>

#include "GameMenu.h"
#include "Game.h"

// Include possible headers that your games uses.
#include "Minesweeper.h"

int Game::count = 0; // Only for initializing the amount of games the menu handles for this run.

// Just a minor test.
void test()
{
  cout << "Hello, world!" << endl;
  cin.get();
}

// Function responsible on initializing the game menu and allocating the games to it.
// @return GameMenu menu - Menu of initialized games, which is used throughout the app's lifecycle.
GameMenu initGames()
{
  // INSERT THE GAMES BELOW THIS COMMENT

  Game board("Miinaharava", &initMinesweeper, "Are you smart enough to beat Minesweeper? In this game you're tasked to find the mines by clearing the areas around them, while avoiding the spots that hold the mine inside.\n\nYou can choose between three different difficulties and you have all the time at your disposal.");
  Game helloBoard("Hello World!", &test);
  Game emptyBoard;

  // INSERT THE GAMES ABOVE THIS COMMENT

  int amount = Game::count;

  // Initializing the menu itself, taking the amount of initialized games to determine the size of the game array.
  GameMenu menu(amount, "Are you ready to play a game? Please choose the game by writing it's number.");

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