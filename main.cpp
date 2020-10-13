#include "Game.h"
#include <iostream>

using namespace std;

int Game::count = 0;

void initGames()
{
  // ALAS PELIT
  Game board{"Miinaharava", "Tämä on hankalaa!", false};
  Game helloBoard("Hello world!", "Tämä on testi, mikä osoittaa että näitä voidaan lisäillä!", false);
  Game emptyBoard;
  // TÄMÄN YLÄPUOLELLE KAIKKI PELIT

  int amount = Game::count;

  cout << "Pelejä on " << amount << endl;
}

int main(void)
{
  initGames();
  return 0;
}