// Game-class wherefrom all the games are initialized.

#include <string>
#include <iostream>
#include <functional>

#include "Game.h"

using namespace std;

// Default function for an empty object.
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

// Returns the name of the game.
string Game::getName()
{
  return name;
}

// Return the description of the game.
string Game::getDesc()
{
  if (this->description.length() > 0)
    return description;
  else
    return "This is just a placeholder text, which means this game is either non-existent or developer forgot to include any description for this.";
}

// Returns the amount of instances created from this class.
int Game::getGameAmount()
{
  return count;
}
