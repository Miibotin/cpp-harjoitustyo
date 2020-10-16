#include <iostream>

#include "GameMenu.h"
#include "Game.h"

// Include possible headers that your games uses
#include "Minesweeper.h"

int Game::count = 0; // Vain alun pelien alustusta varten. Muuten tätä ei enää käytetä tulevaisuudessa.

void test()
{
  cout << 1 + 2 << endl;
  cin.get();
}

GameMenu initGames()
{

  // TÄMÄ ALAPUOLELLE KAIKKI PELIT
  Game board("Miinaharava", &initMinesweeper, "Tämä on hankalaa!");
  Game helloBoard("Hello World!", &test);
  Game emptyBoard;
  // TÄMÄN YLÄPUOLELLE KAIKKI PELIT

  int amount = Game::count;

  // PELI-VALIKON ALUSTUS
  GameMenu game(amount, "TERVETULOA PELAAMAAN! OLE HYVÄ JA VALITSE PELI KIRJOITTAMALLA SITÄ VASTAAVA NUMERO!");

  // LISÄÄ ALUSTETTAVAT PELIT SILMUKAN SISÄLLE
  if (game.gameAmount > 0)
  {
    game.addGames(board);
    game.addGames(helloBoard);
    game.addGames(emptyBoard);
  }

  return game;
}