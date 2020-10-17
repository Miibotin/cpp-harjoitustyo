// GameMenu-header file, which includes the declaration of the GameMenu-class.

#pragma once

#include <string>
#include <memory>

#include "Game.h"

using namespace std;

// Class which handles the menu of the application and all of it's games.
class GameMenu
{
private:
  Game *games;
  string welcomeLetter;

public:
  int gameAmount;

public:
  GameMenu();
  GameMenu(int amount, string pLetter);
  ~GameMenu();
  Game getGame(int index);
  bool addGames(Game g);
  string welcome();
};
