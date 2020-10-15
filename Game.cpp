#include <string>
#include <iostream>
#include <functional>
#include "Game.h"

using namespace std;

void noGame()
{
  cout << "Error: No game available!" << endl;
}

Game::Game()
{
  name = "";
  description = "This is just a placeholder text, which means this game is either non-existent or developer forgot to include any description for this.";
  start = &noGame;
  count++;
}

Game::Game(string pName, function<void()> pFunc, string pDesc)
{
  name = pName;
  description = pDesc;
  start = pFunc;
  count++;
}

Game::~Game()
{
  count--;
}

string Game::getName()
{
  return name;
}

string Game::getDesc()
{
  return description;
}

int Game::getGameAmount()
{
  return count;
}
