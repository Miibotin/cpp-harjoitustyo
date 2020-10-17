#include <iostream>

#include "Game.h"
#include "GameMenu.h"

using namespace std;

// Shows the information of the chosen game. Also includes the option to play the game itself.
// @param Game g - the chosen game.
void showDescription(Game g)
{
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
       << endl;
  string choice;
  int gameOption;
  bool loop = true;
  string name = g.getName();
  if (name == "")
    name = "NO_GAME";

  do
  {
    cout << "Game: " << name << "\n\n"
         << "Description: " << g.getDesc() << "\n\n"
         << "Options: Play (1), Back (2)" << endl;

    cin >> choice;
    cin.ignore();

    // Quick check to see if user gives an integer.
    try
    {
      gameOption = stoi(choice);

      switch (gameOption)
      {
      case 1:
        // Starts the game.
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << endl;
        g.start();
        break;
      case 2:
        // Goes back to the game menu.
        loop = false;
        break;
      default:
        // Works as a error handler, if the user tries to give the wrong number.
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

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
         << endl;
  } while (loop);
}

// Main function of the startup. Handles the printing of the banner, the menu and the games.
// @param GameMenu menu - Menu itself that is essential for the application's runtime.
void startMenu(GameMenu menu)
{
  string choice;
  int gameOption;

  if (menu.gameAmount == 0)
  {
    cout << "An error has occured: the amount of games initialized is " << menu.gameAmount << ". Please fix the error and try again." << endl;
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

  // Loops infinitely until user gives either 'exit' or 'EXIT'
  do
  {
    cout << menu.welcome() << "\n"
         << endl;

    // Loop that prints the games.
    for (int i = 0; i < menu.gameAmount; i++)
    {
      string name = menu.getGame(i).getName();
      if (name == "")
        name = "NO_GAME";

      cout << "Game #" << (i + 1) << ": " << name;

      // Adds a new line after every iteration, if the current iteration is the third of the line and it's not the last iteration of the loop.
      if ((i + 1) % 3 == 0 && (i + 1) != menu.gameAmount)
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

    // Terminates the application.
    if (choice == "exit" || choice == "EXIT")
      break;

    // Quick check to see if user gives an integer.
    try
    {
      gameOption = stoi(choice);
      showDescription(menu.getGame((gameOption - 1)));
    }
    catch (const std::exception &e)
    {
      cerr << "Please give a proper number between 1 and " << menu.gameAmount << "!" << endl;
      cin.get();
      gameOption = 0;
    }

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
         << endl;

  } while (true);
}