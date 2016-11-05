#include "GameOver.h"
#include "window.h"
GameOver::GameOver() {
	m_gameState = GAME_OVER;
	m_clearScreen = true;
	m_level = -1;

	m_buttons[RESET_BUTTON].Set(20, 15, 15, 6);
	m_buttons[RESET_BUTTON].SetText("Reset");

	m_buttons[EXIT_BUTTON].Set(20, 25, 15, 6);
	m_buttons[EXIT_BUTTON].SetText("Exit");
}

GameOver::~GameOver() {
}

void GameOver::UpDate() {	
	if (m_buttons[EXIT_BUTTON].UpDate()) {
		m_gameState = EXIT;
	}
	if (m_buttons[RESET_BUTTON].UpDate()) {
		m_gameState = RESET;
	}
}

void GameOver::Draw() {
	if (m_clearScreen) {
		m_clearScreen = false;
		system("CLS");
		Window::SetCursorVisibility(false);
	}

	Window::DrawLine(34,  3, WHITE, "Game Over", 50);


	gameOverText.setString("You mde it to level: ");
	char levelChar[10];
	//convert from int to char array to append 
	_itoa_s(m_level, levelChar, 10);
	gameOverText.append(levelChar);

	Window::DrawLine(20, 10, WHITE, gameOverText.cStr(), 50);

	for (int i = 0; i < MAX_BUTTONS; i++) {
		m_buttons[i].Draw();
	}
}

eGameStates GameOver::Run() {
	m_gameState = GAME_OVER;
	UpDate();
	Draw();
	//check if the the game state is changing to clear the screen if it comes back to game over
	if (m_gameState != GAME_OVER) {
		 m_clearScreen = true;
	}

	return m_gameState;
}
