#include <string>
#include <iostream>
#include <functional>
#include "Game.h"

using namespace std;

void noGame()
{
  cout << "Error: No game available!" << endl;
  cin.get();
}

Game::Game()
{
  name = "";
  description = "";
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
  if (this->description.length() > 0)
    return description;
  else
    return "This is just a placeholder text, which means this game is either non-existent or developer forgot to include any description for this.";
}

int Game::getGameAmount()
{
  return count;
}
