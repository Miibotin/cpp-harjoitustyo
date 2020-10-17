// Game-luokan header
#pragma once
#include <string>
#include <functional>

using namespace std;

// Class which handles the data of a game and it's startup logic.
class Game
{
private:
  string name;
  string description;

public:
  static int count;
  function<void()> start; // Function where the start of the game's logic is included.

public:
  Game();
  Game(string pName, function<void()> pFunc, string pDesc = "");
  ~Game();
  string getName();
  string getDesc();
  int getGameAmount();
};
