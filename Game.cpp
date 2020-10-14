#include <string>
#include <iostream>
#include "Game.h"

using namespace std;

Game::Game()
{
  name = "Placeholder";
  description = "lorem ipsum";
  twoPlayers = false;
  count++;
}

Game::Game(string pName, string pDesc, bool twoPl)
{
  name = pName;
  description = pDesc;
  twoPlayers = twoPl;
  count++;
}

Game::~Game()
{
  count--;
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

