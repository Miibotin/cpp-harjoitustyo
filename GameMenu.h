#include "Game.h"

using namespace std;

class GameMenu
{
private:
  Game *games;

public:
  int gameAmount;

public:
  GameMenu();
  GameMenu(int amount);
  ~GameMenu();
  Game getGame(int index);
  bool addGames(Game *game);
};
