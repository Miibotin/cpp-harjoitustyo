#include "GameMenu.h"
#include "Game.h"
#include <iostream>

GameMenu::GameMenu(int size)
{
  games = new Game[size];
  gameAmount = size;
}

GameMenu::~GameMenu()
{
  cout << "Releasing memory... ";
  delete[] games;
  cout << "Done!" << endl;
}

bool GameMenu::addGames(Game *g)
{
  bool val;

  for (int i = 0; i < gameAmount; i++)
  {
    if (games[i].getName() == "Placeholder")
    {
      games[i] = *g;
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
    cout << "Error: no game found on index " << index << endl;
    Game empty;
    return empty;
  }
}
