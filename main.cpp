#include "Game.h"
#include "GameMenu.h"
#include <iostream>
#include <memory>

using namespace std;

int Game::count = 0; // Vain alun pelien alustusta varten. Muuten tätä ei enää käytetä tulevaisuudessa.

void hello()
{
  cout << "Hei tää toimii!" << endl;
}

void kakka()
{
  cout << 1 + 2 << endl;
}

GameMenu initGames()
{

  // TÄMÄ ALAPUOLELLE KAIKKI PELIT
  Game board("Miinaharava", false, &hello, "Tämä on hankalaa!");
  Game helloBoard("Hello World!", false, &kakka);
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

void startMenu(GameMenu game)
{
  string choice;
  int gameOption;

  if (game.gameAmount == 0)
  {
    cout << "An error has occured: the amount of games initialized is " << game.gameAmount << ". Please fix the error and try again." << endl;
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
    cout << game.welcome() << "\n"
         << endl;

    for (int i = 0; i < game.gameAmount; i++)
    {
      cout << "Peli #" << (i + 1) << ": " << game.getGame(i).getName();

      // Lisää uuden rivin iteraation perään mikäli kyseinen iteraatio on rivin kolmas ja se ei ole viimeinen iteraatio
      if ((i + 1) % 3 == 0 && (i + 1) != game.gameAmount)
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
      cerr << "Ole hyvä ja anna luku 1 ja" << game.gameAmount << " väliltä!" << endl;
      cin.get();
      cin.get();
    }

    game.getGame((gameOption - 1)).func();

    cout << "\n\n\n\n\n\n"
         << endl;
  } while (true);
}

int main(void)
{
  GameMenu game = initGames();
  startMenu(game);
  return 0;
}