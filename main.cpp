// FINAL ASSIGNMENT - GAME MENU AND MINESWEEPER
// BY MIKKO HANNUKAINEN

#include "GameMenu.h"
#include "Startup.h"

// Initializes the game menu and sends it to startup.
int main(void)
{
  GameMenu menu = initGames();
  startMenu(menu);
  return 0;
}