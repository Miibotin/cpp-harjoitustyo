// CLI-Minesweeper

#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <chrono>
#include <vector>

#include "Minesweeper.h"

using namespace std;

// Prints the board of the game.
// @param vector<vector<char>> matrix - 2d vector of symbols, which represents the current state of the tiles.
// @param vector<vector<int>> bombs - 2d vector which holds the coordinates of the bombs.
void buildBoard(vector<vector<char>> matrix, vector<vector<int>> bombs = vector<vector<int>>())
{
  char letter = 'A';

  for (int i = 0; i < matrix.size(); i++)
  {
    // If first loop, prints the numbers representing the x-axis.
    if (i == 0)
    {
      cout << "# | ";
      for (int j = 0; j < matrix[0].size(); j++)
      {
        if (j > 8)
        {
          string s = to_string(j + 1);
          s = s.substr(1, 1);
          cout << s << " ";
        }
        else
        {
          cout << j + 1 << " ";
        }
      }
      cout << endl;

      for (int j = 0; j < (matrix[0].size() + 2); j++)
      {
        cout << "- ";
      }
      cout << endl;
    }

    cout << letter++ << " | ";

    // Prints the rows of letters representing the y-axis and the board itself.
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (bombs != vector<vector<int>>() && bombs[i][j] == 1 && matrix[i][j] == '#')
      {
        // If the game's over the bombs are also printed.
        cout << "* ";
      }
      else
      {
        // If the game coninues normally the current state of each tile is printed.
        cout << matrix[i][j] << " ";
      }
    }
    cout << endl;
  }
}

// Used by analyzeNeighbours-functions to see if the neighbouring tile is yet to be analyzed.
// @param int xCoord - position of the neighbour tile in x-axis.
// @param int yCoord - position of the neighbour tile in y-axis.
// @param vector<vector<char>> matrix - reference to the 2d vector, which represents the current state of the tiles.
void checkNeighbourTile(int xCoord, int yCoord, vector<vector<char>> &matrix)
{
  if (matrix[yCoord][xCoord] != ' ')
  {
    matrix[yCoord][xCoord] = ',';
  }
  return;
}

// Runs the tile check once again to determine if neighbour tiles needs to be checked. This is ran only if the tile in xCoord and yCoord is an empty tile with no bombs around. Declares the current tile from ','-tile to an empty ' '-tile at the end to indicate that the tile is empty and it's not needed to be checked again.
// @param int xCoord - position of the tile in x-axis.
// @param int yCoord - position of the tile in y-axis.
// @param vector<vector<char>> matrix - reference to the 2d vector, which represents the current state of the tile.
void analyzeNeighbours(int xCoord, int yCoord, vector<vector<char>> &matrix)
{
  // Upper x-axis, if there's any.
  if (yCoord != 0)
  {
    int yUp = yCoord - 1;

    // Upper left
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      checkNeighbourTile(xLeft, yUp, matrix);
    }

    // Upper mid.
    checkNeighbourTile(xCoord, yUp, matrix);

    // Upper right.
    if (xCoord != (matrix[0].size() - 1))
    {
      int xRight = xCoord + 1;
      checkNeighbourTile(xRight, yUp, matrix);
    }
  }

  // X-axis of the same y-axis.
  // Left.
  if (xCoord != 0)
  {
    int xLeft = xCoord - 1;
    checkNeighbourTile(xLeft, yCoord, matrix);
  }

  // Right.
  if (xCoord != (matrix[0].size() - 1))
  {
    int xRight = xCoord + 1;
    checkNeighbourTile(xRight, yCoord, matrix);
  }

  // Bottom x-axis, if there's any.
  if (yCoord != (matrix.size() - 1))
  {
    int yDown = yCoord + 1;

    // Bottom left.
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      checkNeighbourTile(xLeft, yDown, matrix);
    }

    // Bottom middle.
    checkNeighbourTile(xCoord, yDown, matrix);

    // Bottom right
    if (xCoord != (matrix[0].size() - 1))
    {
      int xRight = xCoord + 1;
      checkNeighbourTile(xRight, yDown, matrix);
    }
  }

  // Finally marks the current tile to be empty, so it won't be analyzed anymore.
  matrix[yCoord][xCoord] = ' ';
}

// Checks if there's a bomb in the neighbouring tile.
// @param int xCoord - position of the tile in x-axis.
// @param int yCoord - position of the tile in y-axis.
// @param vector<vector<int>> bombs - 2d vector which holds the coordinates of the bombs.
// @return int - value that is added to the bombsAround-variable.
int checkBombs(int xCoord, int yCoord, vector<vector<int>> bombs) { return bombs[yCoord][xCoord] == 1 ? 1 : 0; }

// Function that checks around the current tile to see if there's any bombs around.
// @param int xCoord - position of the tile in x-axis.
// @param int yCoord - position of the tile in y-axis.
// @param vector<vector<char>> matrix - reference to the 2d vector, which represents the current state of the tile.
// @param vector<vector<int>> bombs - 2d vector which holds the coordinates of the bombs.
void analyzeSelf(int xCoord, int yCoord, vector<vector<char>> &matrix, vector<vector<int>> bombs)
{
  int bombsAround = 0;

  // Upper x-axis, if there's any.
  if (yCoord != 0)
  {
    int yUp = yCoord - 1;

    // Upper left.
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      bombsAround += checkBombs(xLeft, yUp, bombs);
    }

    // Upper mid.
    bombsAround += checkBombs(xCoord, yUp, bombs);

    // Upper right.
    if (xCoord != (matrix[0].size() - 1))
    {
      int xRight = xCoord + 1;
      bombsAround += checkBombs(xRight, yUp, bombs);
    }
  }

  // X-axis of the same y-axis.
  // Left.
  if (xCoord != 0)
  {
    int xLeft = xCoord - 1;
    bombsAround += checkBombs(xLeft, yCoord, bombs);
  }

  // Right.
  if (xCoord != (matrix[0].size() - 1))
  {
    int xRight = xCoord + 1;
    bombsAround += checkBombs(xRight, yCoord, bombs);
  }

  // Bottom x-axis, if there's any
  if (yCoord != (matrix.size() - 1))
  {
    int yDown = yCoord + 1;

    // Bottom left
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      if (bombs[yDown][xLeft] == 1)
        bombsAround += checkBombs(xLeft, yDown, bombs);
    }

    // Bottom middle
    bombsAround += checkBombs(xCoord, yDown, bombs);

    // Bottom right
    if (xCoord != (matrix[0].size() - 1))
    {
      int xRight = xCoord + 1;
      bombsAround += checkBombs(xRight, yDown, bombs);
    }
  }

  if (bombsAround > 0)
  {
    // If there's any bombs around the tile, the amount is given to the current tile.
    char c = '0';
    c += bombsAround;
    matrix[yCoord][xCoord] = c;
  }
  else
  {
    // If there's no bombs around, ','-symbol is given to the current tile and another check runs.
    matrix[yCoord][xCoord] = ',';
    analyzeNeighbours(xCoord, yCoord, matrix);
  }
}

// Loops and checks if there's any ','-symbols left on the board and runs the analyze-function to check them.
// @param vector<vector<char>> matrix - reference to the 2d vector, which represents the current state of the tile.
// @param vector<vector<int>> bombs - 2d vector which holds the coordinates of the bombs.
void cleanUp(vector<vector<char>> &matrix, vector<vector<int>> bombs)
{
  bool loopEnd = false;
  do
  {
    bool noChecks = true;
    for (int i = 0; i < matrix.size(); i++)
    {

      for (int j = 0; j < matrix[0].size(); j++)
      {
        if (matrix[i][j] == ',')
        {
          noChecks = false;
          int xCoord = j;
          int yCoord = i;
          analyzeSelf(xCoord, yCoord, matrix, bombs);
        }
      }
    }
    loopEnd = noChecks; // If the board is free of ','-symbols, the loop will stop.
  } while (!loopEnd);
}

// Checks the coordinate given by the user to determine the state of the tile.
// @param vector<vector<string>> inputs - 2d vector that represents the available inputs for every coordinate.
// @param vector<vector<char>> matrix - reference to the 2d vector, which represents the current state of the tile.
// @param vector<vector<int>> bombs - 2d vector which holds the coordinates of the bombs.
// @param string choice - Holds the value of a coordinate to be checked given by the user.
// @return bool - if returned value is false, then the user accidentally chose the bomb coordinate and the game's over.
bool checkCoordinate(vector<vector<string>> inputs, vector<vector<char>> &matrix, vector<vector<int>> bombs, string choice = "NULL")
{
  transform(choice.begin(), choice.end(), choice.begin(), ::toupper); // Transforms the choice-variable's letter to uppercase.
  bool skipped = false;
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (inputs[i][j] == choice && matrix[i][j] == '#') // Checks the tile if the user input matches the coordinate and its state is still untouched.
      {
        if (bombs[i][j] == 1)
        {
          // If the coordinate holds a bomb the game's over and the checked tile is marked for the failure.
          matrix[i][j] = 'X';
          return false;
        }
        else
        {
          // If there's no bombs on the tile the analyze-function will be ran.
          int xCoord = j;
          int yCoord = i;
          analyzeSelf(xCoord, yCoord, matrix, bombs);
          skipped = true;
        }
        break;
      }
    }
    if (skipped) // Ends the loop, when the right coordinate is checked.
      break;
  }
  return true;
}

// Checks if the victory is gained by comparing the amount of bombs to the current amount of unchecked tiles.
// @param vector<vector<char>> matrix - 2d vector of symbols, which represents the current state of the tiles.
// @param int bombs - The amount of bombs on the current game.
// @return bool - if this is true then the game is won.
bool checkVictory(vector<vector<char>> matrix, int bombs)
{
  int check = 0;

  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (matrix[i][j] == '#')
      {
        check++;
      }
    }
  }

  // If there's more unchecked tiles than there's bombs, the game continues.
  if (check > bombs)
    return false;
  else
    return true;
}

// Gameplay loop of the minesweeper. Starts of by initializing all the 2d vectors and their values and starting the timer.
// @param int pX - amount rows on the board.
// @param int pY - amount of columns on the board.
// @param in pBombs - amount of bombs on the board.
void minesweeperLoop(int pX, int pY, int pBombs)
{
  vector<vector<char>> symbolCoord(pY);  // State of the tiles.
  vector<vector<string>> inputCoord(pY); // Inputs of the tiles.
  vector<vector<int>> bombCoord(pY);     // Coordinates for the bombs.

  // INITIALIZING
  for (int i = 0; i < pY; i++)
  {
    for (int j = 0; j < pX; j++)
    {
      symbolCoord[i].push_back(j);
      inputCoord[i].push_back("");
      bombCoord[i].push_back(0);
    }
  }

  int bombs = pBombs;
  string choice = "a";
  char initLetter = 'A';

  cout << "Initializing bombs...";
  srand(time(0));
  while (bombs > 0)
  {
    // Bombs are scattered randomly around the board with this.
    int yCoord = rand() % pY;
    int xCoord = rand() % pX;
    if (bombCoord[yCoord][xCoord] != 1)
    {
      bombCoord[yCoord][xCoord] = 1;
      bombs--;
    }
  }
  cout << " Done!" << endl;

  cout << "Initializing the board... ";
  for (int i = 0; i < pY; i++)
  {
    for (int j = 0; j < pX; j++)
    {
      string str;
      str.push_back(initLetter);
      symbolCoord[i][j] = '#';                   // Adding the default '#'-state for every tile.
      inputCoord[i][j] = str + to_string(j + 1); // Adding the input to represent the tile's coordinate.
    }
    initLetter++;
  }
  cout << "Done!\n\n\n"
       << endl;

  buildBoard(symbolCoord);

  // Starts the timer.
  auto start = chrono::system_clock::now();
  // END OF GAME INIT

  // Game loop which continues as long as the player either writes the 'exit'/'EXIT' to the console or he/she finds on the mine.
  while (true)
  {

    cin >> choice;
    cin.ignore();

    // Ends the game.
    if (choice == "exit" || choice == "EXIT")
    {
      cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           << endl;
      break;
    }

    // Ends the game if this is false, a.i. user found the mine.
    if (!checkCoordinate(inputCoord, symbolCoord, bombCoord, choice))
    {
      cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           << endl;
      buildBoard(symbolCoord, bombCoord); // Rebuilds the board to reveals every bombs location.
      cout << "You lose! :(" << endl;
      cin.get();
      cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           << endl;
      break;
    }

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
         << endl;

    cleanUp(symbolCoord, bombCoord);

    bool victory = checkVictory(symbolCoord, pBombs);

    // Rebuilds the board. If vicotry is gained it also reveals every bombs location.
    buildBoard(symbolCoord, victory ? bombCoord : vector<vector<int>>());

    // Victory-logic
    if (victory)
    {
      auto stop = chrono::system_clock::now();
      chrono::duration<double> seconds = stop - start;
      cout << "You win! Your time is " << chrono::duration_cast<chrono::seconds>(seconds).count() << " seconds. Congrats! :)" << endl;
      cin.get();
      cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
           << endl;
      break;
    }
  }
}

// Function that the game menu invokes. Awaits the user's choice of difficulty before initializing the game itself.
void initMinesweeper()
{
  string choice;
  int diffOption;
  bool loop = false;

  // Loops until the exit/EXIT is given to the console.
  while (true)
  {
    cout << "WELCOME TO MINESWEEPER!\n"
         << endl;

    // Loops until the user gives a proper answer.
    do
    {
      loop = false;
      cout << "Select your difficulty: Easy (1), Medium (2), Hard (3)\nOther options: Quit (exit)" << endl;

      cin >> choice;
      cin.ignore();

      // Escapes from both loops and quits the game.
      if (choice == "exit" || choice == "EXIT")
        return;

      // Quick check to see if user gives an integer.
      try
      {
        diffOption = stoi(choice);

        // Works as a error handler, if the user tries to give the wrong number.
        if (diffOption < 1 && diffOption > 3)
        {
          loop = true;
          cout << "Please give a number representing one of the options above!" << endl;
          cin.get();
          cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               << endl;
        }
      }
      catch (const std::exception &e)
      {
        cerr << "Please give a number representing one of the options above!" << endl;
        loop = true;
        cin.get();
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << endl;
      }
    } while (loop);

    if (choice != "exit" || choice != "EXIT")
    {
      // Chooses the difficulty of the game depending on the user's choice.
      switch (diffOption)
      {
      case 1: // Easy
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << endl;
        minesweeperLoop(9, 9, 10);
        break;
      case 2: // Medium
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << endl;
        minesweeperLoop(16, 16, 40);
        break;
      case 3: // Hard
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << endl;
        minesweeperLoop(30, 16, 99);
        break;
      default: // Default easy
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << endl;
        minesweeperLoop(9, 9, 10);
        break;
      }
    }
  }
}
