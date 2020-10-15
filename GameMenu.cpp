#include "GameMenu.h"
#include "Game.h"
#include <iostream>

GameMenu::GameMenu()
{
  int size = 0;
  games = new Game[size];
  gameAmount = size;
  welcomeLetter = "This is just a placeholder, which means the gamemenu was not initialized properly. Please correct the mistake and try again.";
}

GameMenu::GameMenu(int size, string pLetter)
{
  games = new Game[size];
  gameAmount = size;
  welcomeLetter = pLetter;
}

GameMenu::~GameMenu()
{
  // cout << "Releasing memory... ";
  delete[] games;
  // cout << "Done!" << endl;
}

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

Game GameMenu::getGame(int index)
{
  if (index > gameAmount)
  {
    cout << "Error: index out of range!" << endl;
    Game empty;
    return empty;
  }

  if (games[index].getName() != "")
  {
    return games[index];
  }
  else
  {
    cout << "Error: no game found!";
    Game empty;
    return empty;
  }
}

string GameMenu::welcome()
{
  return welcomeLetter;
}
