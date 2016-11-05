#pragma once
#include "RoomManager.h"
#include "Player.h"
#include "UI.h"
#include "GameStates.h"
#include "Controlls.h"
class Game {
private:
	eGameStates m_gameState;
	UI m_ui;
	RoomManager m_roomManager;
	Player *m_player = nullptr;
	String m_input;
	Controlls *m_controllsRef;
	String m_outPut;

	int m_screenHeight;
	int m_screenWidth;

	void init();
	void Draw();
	void MovePlayer();
	void UnLockRoom();
	void UpDate();
	void InPut();

public:
	Game();
	Game(int, int, int, int, Controlls* );

	~Game();

	eGameStates Run();

	int GetLevel();
	void ReSet();
};

