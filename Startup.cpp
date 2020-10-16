#include <iostream>

#include "Game.h"
#include "GameMenu.h"

void showDescription(Game g)
{
  cout << "\n\n\n\n\n\n\n\n\n"
       << endl;
  string choice;
  int gameOption;
  bool loop = true;

  do
  {
    cout << "Game: " << g.getName() << "\n\n\n"
         << "Description: " << g.getDesc() << "\n\n"
         << "Options: Play (1), Back (2)" << endl;

    cin >> choice;
    cin.ignore();

    try
    {
      gameOption = stoi(choice);

      switch (gameOption)
      {
      case 1:
        cout << "\n\n\n\n\n\n\n\n\n"
             << endl;
        g.start();
        break;
      case 2:
        loop = false;
        break;
      default:
        cout << "Please give a number representing one of the options above!" << endl;
        cin.get();
        break;
      }
    }
    catch (const std::exception &e)
    {
      cerr << "Please give a number representing one of the options above!" << endl;
      cin.get();
    }

    cout << "\n\n\n\n\n\n\n\n\n"
         << endl;
  } while (loop);
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
      string name = game.getGame(i).getName();
      if (name == "")
        name = "Error: no game found!";

      cout << "Game #" << (i + 1) << ": " << name;

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

    cout << "\nOther actions: Quit (exit)" << endl;
    cin >> choice;
    cin.ignore();

    if (choice == "exit" || choice == "EXIT")
      break;

    try
    {
      gameOption = stoi(choice);
      showDescription(game.getGame((gameOption - 1)));
    }
    catch (const std::exception &e)
    {
      cerr << "Please give a proper number between 1 and " << game.gameAmount << "!" << endl;
      cin.get();
      gameOption = 0;
    }

    cout << "\n\n\n\n\n\n\n\n\n"
         << endl;

  } while (true);
}