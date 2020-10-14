#include "Game.h"
#include "GameMenu.h"
#include <iostream>

using namespace std;

int Game::count = 0; // Vain alun pelien alustusta varten. Muuten tätä ei enää käytetä tulevaisuudessa.

GameMenu *initGame()
{

  // ALAS PELIT
  Game *board = new Game{"Miinaharava", "Tämä on hankalaa!", false};
  Game *helloBoard = new Game("Hello world!", "Tämä on testi, mikä osoittaa että näitä voidaan lisäillä!", false);
  Game *emptyBoard = new Game();
  Game *emptyBoard2 = new Game();
  // TÄMÄN YLÄPUOLELLE KAIKKI PELIT

  int amount = Game::count;

  // PELI-VALIKON ALUSTUS
  GameMenu *game = new GameMenu(amount, "TERVETULOA PELAAMAAN! OLE HYVÄ JA VALITSE PELI KIRJOITTAMALLA SITÄ VASTAAVA NUMERO!");

  // LISÄÄ ALUSTETTAVAT PELIT SILMUKAN SISÄLLE
  if (game->gameAmount > 0)
  {
    game->addGames(board);
    game->addGames(helloBoard);
    game->addGames(emptyBoard);
    game->addGames(emptyBoard2);
  }

  // LISÄÄ PELISI TÄHÄN, JOTTA EI MUISTIA KARKAA
  delete board, helloBoard, emptyBoard, emptyBoard2;

  return game;
}

void startMenu(GameMenu *game)
{
  string choice;
  int gameOption;

  if (game->gameAmount == 0)
  {
    cout << "An error has occured: the amount of games initialized is " << game->gameAmount << ". Please fix the error and try again." << endl;
    cin.get();
    return;
  }

  cout << "********************************************************************" << endl
       << "*  *    *    *   ****   *       ****     ****     *     *    ****  *" << endl
       << "*  *    *    *   *      *      *        *    *   * *   * *   *     *" << endl
       << "*   *  * *  *    ****   *      *        *    *   *  * *  *   ***   *" << endl
       << "*   *  * *  *    *      *      *        *    *   *   *   *   *     *" << endl
       << "*    **   **     ****   ****    ****     ****    *       *   ****  *" << endl
       << "********************************************************************" << endl;

  // LOOPATAAN KUNNES KÄYTTÄJÄ KIRJOITTAA exit/EXIT
  do
  {
    cout << game->welcome() << "\n"
         << endl;

    for (int i = 0; i < game->gameAmount; i++)
    {
      cout << "Peli #" << (i + 1) << ": " << game->getGame(i).getName();
      if ((i + 1) % 3 == 0)
      {
        cout << endl;
      }
      else
      {
        cout << "\t";
      }
    }

    cout << endl;

    cout << "\nMuita komentoja: Lopeta (exit)" << endl;
    cin >> choice;

    if (choice == "exit" || choice == "EXIT")
      break;

    try
    {
      gameOption = stoi(choice);
    }
    catch (const std::exception &e)
    {
      cerr << "Ole hyvä ja anna luku 1 ja" << game->gameAmount << " väliltä!" << endl;
      cin.get();
      cin.get();
    }

    cout << "\n\n\n\n\n\n"
         << endl;
  } while (true);
}

int main(void)
{
  GameMenu *game = initGame();
  startMenu(game);

  // cin.get();
  return 0;
}