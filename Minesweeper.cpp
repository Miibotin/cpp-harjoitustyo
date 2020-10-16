// WIP työ

#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "Minesweeper.h"

using namespace std;

// Rakennetaan lauta
void build(vector<vector<char>> matrix, vector<vector<int>> bombs = vector<vector<int>>())
{
  char letter = 'A';

  for (int i = 0; i < matrix.size(); i++)
  {
    // Jos eka loop, kirjoitetaan konsoliin x-koordinaatistoa indikoivat luvut
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

    // Kirjoitetaan y-koordinaatistoa indikoivat kirjaimet ja itse pelilaudan rivit
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (bombs != vector<vector<int>>() && bombs[i][j] == 1 && matrix[i][j] == '#')
      {
        cout << "* ";
      }
      else
      {
        cout << matrix[i][j] << " ";
      }
    }
    cout << endl;
  }
}

int checkBombs(int xCoord, int yCoord, vector<vector<int>> bombs) { return bombs[yCoord][xCoord] == 1 ? 1 : 0; }

bool analyzeSelf(int xCoord, int yCoord, vector<vector<char>> &matrix, vector<vector<int>> bombs)
{
  // MUUTA SITEN, ETTÄ NAAPURI-PAIKKOJEN ALUEET TUTKITAAN JA CLEANUP-FUNKTIO LAUAKAISTAAN JOS YMPÄRILLÄ EI OLE YHTÄÄN POMMIA
  int bombsAround = 0;

  // Yläpuolinen x-akseli, jos on
  if (yCoord != 0)
  {
    int yUp = yCoord - 1;

    // Ylävasen
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      bombsAround += checkBombs(xLeft, yUp, bombs);
    }

    // Yläkeski
    bombsAround += checkBombs(xCoord, yUp, bombs);

    // Yläoikea
    if (xCoord != (matrix[0].size() - 1))
    {
      int xRight = xCoord + 1;
      bombsAround += checkBombs(xRight, yUp, bombs);
    }
  }

  // Saman y-akselin x-akseli
  if (xCoord != 0)
  {
    int xLeft = xCoord - 1;
    bombsAround += checkBombs(xLeft, yCoord, bombs);
  }
  if (xCoord != (matrix[0].size() - 1))
  {
    int xRight = xCoord + 1;
    bombsAround += checkBombs(xRight, yCoord, bombs);
  }

  // Alapuolinen x-akseli, jos on
  if (yCoord != (matrix.size() - 1))
  {
    int yDown = yCoord + 1;

    // Alavasen
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      if (bombs[yDown][xLeft] == 1)
        bombsAround += checkBombs(xLeft, yDown, bombs);
    }

    // Alakeski
    bombsAround += checkBombs(xCoord, yDown, bombs);

    // Alaoikea
    if (xCoord != (matrix[0].size() - 1))
    {
      int xRight = xCoord + 1;
      bombsAround += checkBombs(xRight, yDown, bombs);
    }
  }

  // Jos löytyy pommeja lähettyviltä, tulostetaan niiden määrä koordinaattiin ja palautetaan false
  if (bombsAround > 0)
  {
    char c = '0';
    c += bombsAround;
    matrix[yCoord][xCoord] = c;
    return false;
  }
  else
  {
    matrix[yCoord][xCoord] = ',';
    return true;
  }
}

void checkNeighbourBombs(int xCoord, int yCoord, vector<vector<char>> &matrix, vector<vector<int>> bombs)
{
  if (bombs[yCoord][xCoord] == 0 && matrix[yCoord][xCoord] != ' ')
  {
    matrix[yCoord][xCoord] = ',';
  }

  return;
}

void analyzeNeighbours(int xCoord, int yCoord, vector<vector<char>> &matrix, vector<vector<int>> bombs)
{
  // Yläpuolinen x-akseli, jos on
  if (yCoord != 0)
  {
    int yUp = yCoord - 1;

    // Ylävasen
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      checkNeighbourBombs(yUp, xLeft, matrix, bombs);
    }

    // Yläkeski
    checkNeighbourBombs(xCoord, yUp, matrix, bombs);

    // Yläoikea
    if (xCoord != (matrix[0].size() - 1))
    {
      int xRight = xCoord + 1;
      checkNeighbourBombs(xRight, yUp, matrix, bombs);
    }
  }

  // Saman y-akselin x-akseli
  if (xCoord != 0)
  {
    int xLeft = xCoord - 1;
    checkNeighbourBombs(xLeft, yCoord, matrix, bombs);
  }
  if (xCoord != (matrix[0].size() - 1))
  {
    int xRight = xCoord + 1;
    checkNeighbourBombs(xRight, yCoord, matrix, bombs);
  }

  // Alapuolinen x-akseli, jos on
  if (yCoord != (matrix.size() - 1))
  {
    int yDown = yCoord + 1;

    // Alavasen
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      checkNeighbourBombs(xLeft, yDown, matrix, bombs);
    }

    // Alakeski
    checkNeighbourBombs(xCoord, yDown, matrix, bombs);

    // Alaoikea
    if (xCoord != (matrix[0].size() - 1))
    {
      int xRight = xCoord + 1;
      checkNeighbourBombs(xRight, yDown, matrix, bombs);
    }
  }

  matrix[yCoord][xCoord] = ' ';
}

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
          bool checkAround = analyzeSelf(xCoord, yCoord, matrix, bombs);

          if (checkAround)
            analyzeNeighbours(xCoord, yCoord, matrix, bombs);
        }
      }
    }
    loopEnd = noChecks;
  } while (!loopEnd);
}

// Tsekataan kyseinen koordinaatti
bool check(vector<vector<string>> inputs, vector<vector<char>> &matrix, vector<vector<int>> bombs, string choice = "NULL")
{
  transform(choice.begin(), choice.end(), choice.begin(), ::toupper); // Muutetaan merkit isoiksi (ei mitään hajua miksi vaaditaan noin, mut se toimii :D)
  bool skipped = false;
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      if (inputs[i][j] == choice && matrix[i][j] == '#')
      {
        if (bombs[i][j] == 1)
        {
          matrix[i][j] = 'X';

          return false;
        }
        else
        {
          int xCoord = j;
          int yCoord = i;
          bool checkAround = analyzeSelf(xCoord, yCoord, matrix, bombs);

          if (checkAround)
            analyzeNeighbours(xCoord, yCoord, matrix, bombs);

          skipped = true;
        }
        break;
      }
    }
    if (skipped)
      break;
  }
  return true;
}

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

  // Jos tutkimattomia koordinaatteja on enemmän kuin mitä miinoja on kentällä, peli jatkuu
  if (check > bombs)
  {

    return false;
  }
  else
  {
    return true;
  }
}

void minesweeperLoop(int pX, int pY, int pBombs)
{
  vector<vector<char>> symbolCoord(pY);
  vector<vector<string>> inputCoord(pY);
  vector<vector<int>> bombCoord(pY);

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
      symbolCoord[i][j] = '#';
      inputCoord[i][j] = str + to_string(j + 1);
    }
    initLetter++;
  }
  cout << "Done!\n\n\n"
       << endl;

  build(symbolCoord);

  // Pelin loop joka jatkuu niin kauan, kunnes pelaaja kirjoittaa konsoliin X-kirjaimen
  while (true)
  {

    cin >> choice;

    // Lopettaa pelin saatana
    if (choice == "exit" || choice == "EXIT")
      break;

    // Poistuu pelistä jos on false
    if (!check(inputCoord, symbolCoord, bombCoord, choice))
    {
      cout << "\n\n\n\n\n\n\n"
           << endl;
      build(symbolCoord, bombCoord);
      cout << "You lose! :(" << endl;
      cin.get();
      break;
    }

    cout << "\n\n\n\n\n\n\n"
         << endl;

    cleanUp(symbolCoord, bombCoord);

    bool victory = checkVictory(symbolCoord, pBombs);

    // Rakennetaan taulukko uusiksi
    build(symbolCoord, victory ? bombCoord : vector<vector<int>>());

    if (victory)
    {
      cout << "You win! :)" << endl;
      cin.get();
      break;
    }
  }
  cin.get();
}

void initMinesweeper()
{
  string choice;
  int diffOption;
  bool loop = false;

  do
  {
    loop = false;
    cout << "\n\n\n\n\n\n\n\n\n"
         << endl;
    cout << "Select your difficulty: Easy (1), Medium (2), Hard (3)" << endl;

    cin >> choice;
    try
    {
      diffOption = stoi(choice);

      if (diffOption < 1 && diffOption > 3)
      {
        loop = true;
        cout << "Please give a number representing one of the options above!" << endl;
        cin.get();
        cin.get();
      }
    }
    catch (const std::exception &e)
    {
      cerr << "Please give a number representing one of the options above!" << endl;
      loop = true;
      cin.get();
      cin.get();
    }
  } while (loop);

  switch (diffOption)
  {
  case 1:
    cout << "\n\n\n\n\n\n\n\n\n"
         << endl;
    minesweeperLoop(9, 9, 10);
    break;
  case 2:
    cout << "\n\n\n\n\n\n\n\n\n"
         << endl;
    minesweeperLoop(16, 16, 40);
    break;
  case 3:
    cout << "\n\n\n\n\n\n\n\n\n"
         << endl;
    minesweeperLoop(30, 16, 99);
    break;
  default:
    cout << "\n\n\n\n\n\n\n\n\n"
         << endl;
    minesweeperLoop(9, 9, 10);
    break;
  }
}
