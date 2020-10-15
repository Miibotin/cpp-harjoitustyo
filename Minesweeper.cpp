// WIP työ

#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#include "Minesweeper.h"

using namespace std;

const int y = 1;
const int x = 1;
const int bombs = 1;
// Rakennetaan lauta
void build(char(matrix)[y][x], int(bombs)[y][x] = NULL)
{
  char letter = 'A';

  for (int i = 0; i < y; i++)
  {
    // Jos eka loop, kirjoitetaan konsoliin x-koordinaatistoa indikoivat luvut
    if (i == 0)
    {
      cout << "# | ";
      for (int j = 0; j < x; j++)
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

      for (int j = 0; j < (x + 2); j++)
      {
        cout << "- ";
      }
      cout << endl;
    }

    cout << letter++ << " | ";

    // Kirjoitetaan y-koordinaatistoa indikoivat kirjaimet ja itse pelilaudan rivit
    for (int j = 0; j < x; j++)
    {
      if (bombs != NULL && bombs[i][j] == 1)
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

bool analyzeCoordinate(int xCoord, int yCoord, char (&matrix)[y][x], int (&bombs)[y][x])
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
      if (bombs[yUp][xLeft] == 1)
      {
        bombsAround++;
      }
    }

    // Yläkeski
    if (bombs[yUp][xCoord] == 1)
    {
      bombsAround++;
    }

    // Yläoikea
    if (xCoord != (x - 1))
    {
      int xRight = xCoord + 1;
      if (bombs[yUp][xRight] == 1)
      {
        bombsAround++;
      }
    }
  }

  // Saman y-akselin x-akseli
  if (xCoord != 0)
  {
    int xLeft = xCoord - 1;
    if (bombs[yCoord][xLeft] == 1)
    {
      bombsAround++;
    }
  }
  if (xCoord != (x - 1))
  {
    int xRight = xCoord + 1;
    if (bombs[yCoord][xRight] == 1)
    {
      bombsAround++;
    }
  }

  // Alapuolinen x-akseli, jos on
  if (yCoord != (y - 1))
  {
    int yDown = yCoord + 1;

    // Alavasen
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      if (bombs[yDown][xLeft] == 1)
      {
        bombsAround++;
      }
    }

    // Alakeski
    if (bombs[yDown][xCoord] == 1)
    {
      bombsAround++;
    }

    // Alaoikea
    if (xCoord != (x - 1))
    {
      int xRight = xCoord + 1;
      if (bombs[yDown][xRight] == 1)
      {
        bombsAround++;
      }
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

  // return bombsAround != 0 ? c : ' ';
}

void analyzeNeighbours(int xCoord, int yCoord, char (&matrix)[y][x], int(bombs)[y][x])
{
  // Yläpuolinen x-akseli, jos on
  if (yCoord != 0)
  {
    int yUp = yCoord - 1;

    // Ylävasen
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      if (bombs[yUp][xLeft] == 0 && matrix[yUp][xLeft] != ' ')
      {
        matrix[yUp][xLeft] = ',';
      }
    }

    // Yläkeski
    if (bombs[yUp][xCoord] == 0 && matrix[yUp][xCoord] != ' ')
    {
      matrix[yUp][xCoord] = ',';
    }

    // Yläoikea
    if (xCoord != (x - 1))
    {
      int xRight = xCoord + 1;
      if (bombs[yUp][xRight] == 0 && matrix[yUp][xRight] != ' ')
      {
        matrix[yUp][xRight] = ',';
      }
    }
  }

  // Saman y-akselin x-akseli
  if (xCoord != 0)
  {
    int xLeft = xCoord - 1;
    if (bombs[yCoord][xLeft] == 0 && matrix[yCoord][xLeft] != ' ')
    {
      matrix[yCoord][xLeft] = ',';
    }
  }
  if (xCoord != (x - 1))
  {
    int xRight = xCoord + 1;
    if (bombs[yCoord][xRight] == 0 && matrix[yCoord][xRight] != ' ')
    {
      matrix[yCoord][xRight] = ',';
    }
  }

  // Alapuolinen x-akseli, jos on
  if (yCoord != (y - 1))
  {
    int yDown = yCoord + 1;

    // Alavasen
    if (xCoord != 0)
    {
      int xLeft = xCoord - 1;
      if (bombs[yDown][xLeft] == 0 && matrix[yDown][xLeft] != ' ')
      {
        matrix[yDown][xLeft] = ',';
      }
    }

    // Alakeski
    if (bombs[yDown][xCoord] == 0 && matrix[yDown][xCoord] != ' ')
    {
      matrix[yDown][xCoord] = ',';
    }

    // Alaoikea
    if (xCoord != (x - 1))
    {
      int xRight = xCoord + 1;
      if (bombs[yDown][xRight] == 0 && matrix[yDown][xRight] != ' ')
      {
        matrix[yDown][xRight] = ',';
      }
    }
  }

  matrix[yCoord][xCoord] = ' ';
}

void cleanUp(char (&matrix)[y][x], int (&bombs)[y][x])
{
  bool loopEnd = false;
  do
  {
    bool noChecks = true;
    for (int i = 0; i < y; i++)
    {

      for (int j = 0; j < x; j++)
      {
        if (matrix[i][j] == ',')
        {
          noChecks = false;
          int xCoord = j;
          int yCoord = i;
          bool checkAround = analyzeCoordinate(xCoord, yCoord, matrix, bombs);

          if (checkAround)
            analyzeNeighbours(xCoord, yCoord, matrix, bombs);
        }
      }
    }
    loopEnd = noChecks;
  } while (!loopEnd);
}

// Tsekataan kyseinen koordinaatti
bool check(string(inputCoords)[y][x], char (&matrix)[y][x], int (&bombs)[y][x], string choice = "NULL")
{
  transform(choice.begin(), choice.end(), choice.begin(), ::toupper); // Muutetaan merkit isoiksi (ei mitään hajua miksi vaaditaan noin, mut se toimii :D)
  bool skipped = false;
  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      if (inputCoords[i][j] == choice && matrix[i][j] == '#')
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
          bool checkAround = analyzeCoordinate(xCoord, yCoord, matrix, bombs);

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

bool checkVictory(char(matrix)[y][x])
{
  int check = 0;

  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
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
  char coordSymbols[y][x];  // 2d-taulukko joka sisältää koordinaattien nykyisen tilan
  string inputCoords[y][x]; // 2d-taulukko joka sisältää pelilaudan koordinaatit
  int bombCoords[y][x]{};   // 2d-taulukko, joka sisältää pommien sijainnin pelilaudalla
  string choice = "a";
  char initLetter = 'A';
  srand(time(0)); // EPÄKOMMENTOI TÄMÄ!

  cout << "Initializing bombs...";
  do
  {
    int yCoord = rand() % y + 1;
    int xCoord = rand() % x + 1;
    if (bombCoords[yCoord][xCoord] != 1)
    {
      bombCoords[yCoord][xCoord] = 1;
      pBombs--;
    }
  } while (pBombs >= 0);
  cout << " Done!" << endl;

  cout << "Initializing the board... ";
  for (int i = 0; i < y; i++)
  {

    for (int j = 0; j < x; j++)
    {
      string str;
      str.push_back(initLetter);
      coordSymbols[i][j] = '#';
      inputCoords[i][j] = str + to_string(j + 1);
    }
    initLetter++;
  }
  cout << "Done!" << endl;

  build(coordSymbols);

  // Pelin loop joka jatkuu niin kauan, kunnes pelaaja kirjoittaa konsoliin X-kirjaimen
  while (true)
  {

    cin >> choice;

    // Lopettaa pelin saatana
    if (choice == "exit" || choice == "EXIT")
      break;

    // Poistuu pelistä jos on false
    if (!check(inputCoords, coordSymbols, bombCoords, choice))
    {
      cout << "\n\n\n\n\n\n\n"
           << endl;
      build(coordSymbols, bombCoords);
      cout << "Hävisit pelin! :(" << endl;
      cin.get();
      break;
    }

    cout << "\n\n\n\n\n\n\n"
         << endl;

    cleanUp(coordSymbols, bombCoords);

    bool victory = checkVictory(coordSymbols);

    // Rakennetaan taulukko uusiksi
    build(coordSymbols, victory ? bombCoords : NULL);

    if (victory)
    {
      cout << "Voitit pelin! :)" << endl;
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
