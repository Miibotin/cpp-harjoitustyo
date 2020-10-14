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

  cout << "Pelejä on " << amount << endl;

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

int main(void)
{
  string choice;
  int gameOption;
  GameMenu *game = initGame();

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
    if (game->gameAmount > 0)
    {
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
      std::cerr << e.what() << '\n';
    }

    cout << "\n\n\n\n\n\n"
         << endl;
  } while (true);

  // cin.get();
  return 0;
}