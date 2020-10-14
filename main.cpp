#include "Game.h"
#include "GameMenu.h"
#include <iostream>

using namespace std;

int Game::count = 0;

GameMenu *initGames()
{
  // ALAS PELIT
  Game *board = new Game{"Miinaharava", "Tämä on hankalaa!", false};
  Game *helloBoard = new Game("Hello world!", "Tämä on testi, mikä osoittaa että näitä voidaan lisäillä!", false);
  Game *emptyBoard = new Game();
  // TÄMÄN YLÄPUOLELLE KAIKKI PELIT

  int amount = Game::count;

  cout << "Pelejä on " << amount << endl;

  // PELI-VALIKON ALUSTUS
  GameMenu *game = new GameMenu(amount);
  game->addGames(board);
  game->addGames(helloBoard);
  game->addGames(emptyBoard);

  // LISÄÄ PELISI TÄHÄN, JOTTA EI MUISTIA KARKAA
  delete board, helloBoard, emptyBoard;

  return game;
}

int main(void)
{
  GameMenu *game = initGames();

  if (game->gameAmount > 0)
  {
    for (int i = 0; i < game->gameAmount; i++)
    {
      cout << "Peli #" << i << ": " << game->getGame(i).getName() << "\t";
    }
  }
  cout << endl;
  // cin.get();
  return 0;
}