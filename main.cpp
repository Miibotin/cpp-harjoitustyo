#include "GameMenu.h"
#include "Startup.h"

using namespace std;

int main(void)
{
  GameMenu game = initGames();
  startMenu(game);
  return 0;
}