#pragma once
#include "window.h"
#include "GameStates.h"
#include "Button.h"
class Menu {
private:
	enum eButton{
		GAME_BUTTON,
		EXIT_BUTTON,
		MAX_BUTTONS
	};
	eGameStates m_gameState;
	Button m_buttons[MAX_BUTTONS];

	Button m_gameButton;
	Button m_exitBUtton;

	void UpDate();
	void Draw();
public:
	Menu();
	~Menu();

	eGameStates Run();
};

