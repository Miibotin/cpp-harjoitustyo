// GameMenu-class wherefrom the menu itself is generated.

#include "GameMenu.h"
#include "Game.h"

GameMenu::GameMenu()
{
  int size = 0;
  games = new Game[size];
  gameAmount = size;
  welcomeLetter = "This is just a placeholder, which means the menu was not initialized properly. Please correct the mistake and try again.";
}

// @param int size - determines the size of the games-array.
// @param string pLetter - the message that is printed at the beginning.
GameMenu::GameMenu(int size, string pLetter)
{
  games = new Game[size];
  gameAmount = size;
  welcomeLetter = pLetter;
}

GameMenu::~GameMenu()
{
  // cout << "Releasing memory... ";
  delete[] games; // Memory address holding the games is released at the end of application's lifecycle.
  // cout << "Done!" << endl;
}

// Inserts a new game into the menu.
bool GameMenu::addGames(Game g)
{
  bool val;

  if (g.getName() == "")
  {
    val = false;
  }

  for (int i = 0; i < gameAmount; i++)
  {
    if (games[i].getName() == "")
    {
      games[i] = g;
      val = true;
      break;
    }
    else
    {
      val = false;
    }
  }

  return val;
}

// Returns the game based on the index-value.
// @param int index - array index, where the wanted game is held.
Game GameMenu::getGame(int index)
{
  if (index > gameAmount)
  {
    Game empty;
    return empty;
  }

  if (games[index].getName() != "")
  {
    return games[index];
  }
  else
  {
    Game empty;
    return empty;
  }
}

// Retunrs the welcome-text, which is printed at the beginning of application's lifecycle.
string GameMenu::welcome()
{
  return welcomeLetter;
}
