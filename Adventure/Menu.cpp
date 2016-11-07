#include "Menu.h"
#include <string>
#include "Render.h"
Menu::Menu(){
	m_gameState = MENU;

	m_buttons[GAME_BUTTON].Set(33 , 13, 15, 6);
	String tmp("Play Game");
	m_buttons[GAME_BUTTON].SetText(tmp);

	m_buttons[EXIT_BUTTON].Set(33, 20, 15, 6);
	tmp.setString("Exit Game");
	m_buttons[EXIT_BUTTON].SetText(tmp);
}

Menu::~Menu() {}

void Menu::UpDate() {
	m_gameState = MENU;

	if (m_buttons[GAME_BUTTON].UpDate()) 
		m_gameState = GAME;

	if (m_buttons[EXIT_BUTTON].UpDate())
		m_gameState = EXIT;
}

void Menu::Draw() {
	Render::Clear();
	int x = 28;
	int y = 3;
	Rect screenBorder = { x, y, 25, 8 };
	Render::DrawBorder(screenBorder, YELLOW);
	Render::DrawLine(x + 5, y +3, WHITE, "Advunter Game", 50);

	for (int i = 0; i < MAX_BUTTONS; i++) {
		m_buttons[i].Draw();
	}

	Render::DrawLine(2, 50, WHITE, "By: Jason Penno", 50);

	Render::Draw();
}

eGameStates Menu::Run() {
	UpDate();
	Draw();
	return m_gameState;
}