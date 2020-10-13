#include "Game.h"

class GameMenu
{
public:
  Game *games;

public:
  GameMenu();
  GameMenu(int amount);
  ~GameMenu();
  void addGames();
};
