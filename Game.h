// Game-luokan header
#pragma once
#include <string>
#include <functional>

using namespace std;

class Game
{
private:
  string name;
  string description;

public:
  static int count;
  function<void()> start;

public:
  Game();
  Game(string pName, function<void()> pFunc, string pDesc = "");
  ~Game();
  string getName();
  string getDesc();
  int getGameAmount();
};
