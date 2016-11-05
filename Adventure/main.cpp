////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////																																////
////		Name:		Console Template																			////
////																																////
////		Purpose:	Provides necessary routines to set up a console program             ////
////																																////
////		Authors:	Roger Keating with assistance from Mitchell Croft	Jason Penno		jpenno132@hotmail.com				////
////																																////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "window.h"
#include "main.h"

#include "Menu.h"
#include "Game.h"
#include "GameStates.h"
#include "GameOver.h"
#include "Controlls.h"

// need to add duble buffering\

// the main routine
int main() {
	// (140, 80) is a the maximum
	int width = 80;
	int height = 52;
	bool result = Window::Initialise(width, height, L"Adventure");

	eGameStates gameState = MENU;
	bool run = true;

	if (result == EXIT_FAILURE)
		return EXIT_FAILURE;

	Controlls gControlls = {
		"qq",	//quit
		"w",	//up
		"s",	//down
		"a",	//left
		"d",	//right
		"e",	//use
		"e",	//pickup
		"1",	//iteam1
		"2",	//iteam2
		"3",	//iteam3
		"e",	//go to the next floor
		"e",	//attack
	};

	Menu menu;
	Game game(5, 5, width, height, &gControlls);
	GameOver gameOVer;

	//srand(time(NULL));
	while (run) {
		switch (gameState) {
			case MENU:
				gameState = menu.Run();
				break;
			case GAME:
				gameState = game.Run();
				break;
			case GAME_OVER:
				gameOVer.SetLevel(game.GetLevel());
				gameState = gameOVer.Run();
				break;
			case RESET:
				game.ReSet();
				gameState = GAME;
				break;
			case EXIT:
				run = false;
				break;
		}
	}

	system("CLS");
	return EXIT_SUCCESS;
}
