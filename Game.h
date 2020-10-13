// Game-luokan header
#pragma once
#include <string>

using namespace std;

class Game
{
private:
  string name;
  string description;

public:
  static int count;
  bool twoPlayers;

public:
  Game();
  Game(string pName, string pDesc, bool isTwo);
  string getName();
  string getDesc();
  int getGameAmount();
  void setGameAmount(int amount);
};
