#include "GameMenu.h"
#include "Game.h"

GameMenu::GameMenu(int size)
{
  Game *games = new Game[size];
}

GameMenu::~GameMenu()
{
  delete[] games;
}
