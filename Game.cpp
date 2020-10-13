#include <string>
#include <iostream>
#include "Game.h"

using namespace std;

Game::Game()
{
  name = "Placeholder";
  description = "lorem ipsum";
  twoPlayers = false;
  setGameAmount(1);
}

Game::Game(string pName, string pDesc, bool twoPl)
{
  name = pName;
  description = pDesc;
  twoPlayers = twoPl;
  setGameAmount(1);
}

Game::~Game()
{
}

string Game::getName()
{
  if (name != "")
  {
    return name;
  }
  else
  {
    return "";
  }
}

string Game::getDesc()
{
  return description;
}

int Game::getGameAmount()
{
  return count;
}

void Game::setGameAmount(int amount)
{
  count += amount;
}
