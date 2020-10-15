#pragma once
#include "Game.h"
#include <string>
#include <memory>

using namespace std;

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
