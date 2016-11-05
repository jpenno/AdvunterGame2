#pragma once		
#include "GameStates.h"
#include "string.h"
#include "Button.h"
class GameOver {
private:
	enum eButton {
		RESET_BUTTON,
		EXIT_BUTTON,
		MAX_BUTTONS
	};

	Button m_buttons[MAX_BUTTONS];

	int m_level;

	bool m_clearScreen;
	String gameOverText;
	eGameStates m_gameState;
	void UpDate();
	void Draw();

public:
	GameOver();
	~GameOver();

	eGameStates Run();
	void SetLevel(int a_level) { m_level = a_level; }
};

