#include <string>
#include <iostream>
#include <functional>
#include "Game.h"

using namespace std;

Game::Game()
{
  name = "";
  description = "This is just a placeholder text, which means this game is either non-existent or developer forgot to include any description for this.";
  twoPlayers = false;
  count++;
}

Game::Game(string pName, bool twoPl, function<void()> pFunc, string pDesc)
{
  name = pName;
  description = pDesc;
  twoPlayers = twoPl;
  count++;
  func = pFunc;
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
