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
  bool twoPlayers;
  function<void()> func;

public:
  Game();
  Game(string pName, bool isTwo, function<void()> pFunc, string pDesc = "");
  ~Game();
  string getName();
  string getDesc();
  int getGameAmount();
};
