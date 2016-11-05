#include "Game.h"
#include "window.h"	   

Game::Game() {
	m_ui.Set(120, 60, 5, 5);
	init();
	m_controllsRef = nullptr;
	//m_roomManager.Set(5, 5, m_player, m_controllsRef);
}

Game::Game(int a_width, int a_height, int a_screenWidth, int a_screenHeight, Controlls *a_cReff) {
	m_controllsRef = a_cReff;
	m_screenHeight = a_screenHeight;
	m_screenWidth = a_screenWidth;
	m_ui.Set(m_screenWidth, m_screenHeight, a_width, a_height );
	m_roomManager.SetWidth(a_width);
	m_roomManager.SeHeight(a_height);
	init();
}

Game::~Game() {
}

void Game::init() {
	m_gameState = GAME;
	if (m_player)
		delete m_player;
	m_player = new Player();
	m_roomManager.Set(m_roomManager.GetHeight(), m_roomManager.GetWidth(), 
						m_player, m_controllsRef);
	m_player->SetPos(1, 1);
}

void Game::MovePlayer() {
	//set the out put setting to empty ready to be sets
	m_outPut.setString("");
	//move the player up
	if (m_input.equalTo(m_controllsRef->up)) {
		//checks if the player is trying to move out of bounds
		if (m_player->GetPos().GetY() - 1 >= 0) {
			if (m_roomManager.GetRoomType(m_player->GetPos().GetX(), m_player->GetPos().GetY() - 1) != LOCKED) {
				m_player->SetPos(m_player->GetPos().GetX(), m_player->GetPos().GetY() - 1);
			}
			else {			
				//tells the room next to them is locked and if they can unlock it
				if (m_player->GetHasKey()) {
					m_outPut.setString(m_controllsRef->use.cStr());
					m_outPut.append(m_controllsRef->up.cStr());
					m_outPut.append(": to unlock the door");
				}
				else {
					m_outPut.setString("The Room UP is locked");
				}
			}
		}
	}
	//move the player down
	else if (m_input.equalTo(m_controllsRef->down)) {
		//checks if the player is trying to move out of bounds
		if (m_player->GetPos().GetY() + 1 < m_roomManager.GetHeight()) {
			if (m_roomManager.GetRoomType(m_player->GetPos().GetX(), m_player->GetPos().GetY() + 1) != LOCKED) {
				m_player->SetPos(m_player->GetPos().GetX(), m_player->GetPos().GetY() + 1);
			}
			else {
				//tells the room next to them is locked and if they can unlock it
				if (m_player->GetHasKey()) {
					m_outPut.setString(m_controllsRef->use.cStr());
					m_outPut.append(m_controllsRef->down.cStr());
					m_outPut.append(": to unlock the door");
				}
				else {
					m_outPut.setString("The Room DOWN is locked");
				}
			}
		}
	}
	//move the player left
	else if (m_input.equalTo(m_controllsRef->left)) {
		//checks if the player is trying to move out of bounds
		if (m_player->GetPos().GetX() - 1 >= 0) {
			if (m_roomManager.GetRoomType(m_player->GetPos().GetX() -1, m_player->GetPos().GetY()) != LOCKED) {
				m_player->SetPos(m_player->GetPos().GetX() - 1, m_player->GetPos().GetY());
			}
			else {
				//tells the room next to them is locked and if they can unlock it
				if (m_player->GetHasKey()) {
					m_outPut.setString(m_controllsRef->use.cStr());
					m_outPut.append(m_controllsRef->left.cStr());
					m_outPut.append(": to unlock the door");
				}
				else {
					m_outPut.setString("The Room LEFT is locked");
				}
			}
		}
	}
	//move the player Right
	else if (m_input.equalTo(m_controllsRef->right)) {
		//checks if the player is trying to move out of bounds
		if (m_player->GetPos().GetX() + 1 < m_roomManager.GetWidth()) {
			if (m_roomManager.GetRoomType(m_player->GetPos().GetX() + 1, m_player->GetPos().GetY()) != LOCKED) {
				m_player->SetPos(m_player->GetPos().GetX() + 1, m_player->GetPos().GetY());
			}
			else {
				//tells the room next to them is locked and if they can unlock it
				if (m_player->GetHasKey()) {
					m_outPut.setString(m_controllsRef->use.cStr());
					m_outPut.append(m_controllsRef->right.cStr());
					m_outPut.append(": to unlock the door");
				}
				else {
					m_outPut.setString("The Room RIGHT is locked");
				}
			}
		}
	}

	m_roomManager.UpDate();
}

void Game::UnLockRoom(){
	//set tmpStr to = m_use to append a direction on to it
	String tmpStr(m_controllsRef->use);

	//check if the room the player is trying to move to is locked
	//check if going out of bounds in the array
	if (m_player->GetPos().GetX() + 1 < m_roomManager.GetWidth()) {
		//check if the player has a key to unlock the door
		if (m_player->GetHasKey()) {
			//check the room to the right
			if (m_roomManager.GetRoomType(m_player->GetPos().GetX() + 1, m_player->GetPos().GetY()) == LOCKED) {
				//append right to the input string
				tmpStr.append(m_controllsRef->right.cStr());
				//check if input == useright
				if (m_input.equalTo(tmpStr)) {
					//unlock the locked room
					m_roomManager.GetRoom(m_player->GetPos().GetX() + 1, m_player->GetPos().GetY())->InPut(*m_player, m_input);
				}
				else {
					tmpStr.setString(m_controllsRef->use.cStr());
				}
			}
		}
	}

	//check if the player has a key to unlock the door
	if (m_player->GetPos().GetX() - 1 >= 0) {
		if (m_player->GetHasKey()) {
			//check the room to the right
			if (m_roomManager.GetRoomType(m_player->GetPos().GetX() - 1, m_player->GetPos().GetY()) == LOCKED) {
				//append right to the input string
				tmpStr.append(m_controllsRef->left.cStr());
				//check if input == useright
				if (m_input.equalTo(tmpStr)) {
					//unlock the locked room
					m_roomManager.GetRoom(m_player->GetPos().GetX() - 1, m_player->GetPos().GetY())->InPut(*m_player, m_input);
				}
				else {
					tmpStr.setString(m_controllsRef->use.cStr());
				}
			}
		}
	}
	//check if going out of bounds in the array
	if (m_player->GetPos().GetY() + 1 < m_roomManager.GetHeight()) {
		//check if the player has a key to unlock the door
		if (m_player->GetHasKey()) {
			//check the room to the right
			if (m_roomManager.GetRoomType(m_player->GetPos().GetX(), m_player->GetPos().GetY() + 1) == LOCKED) {
				//append right to the input string
				tmpStr.append(m_controllsRef->down.cStr());
				//check if input == usedown
				if (m_input.equalTo(tmpStr)) {
					//unlock the locked room
					m_roomManager.GetRoom(m_player->GetPos().GetX(), m_player->GetPos().GetY() + 1)->InPut(*m_player, m_input);
				}
				else {
					tmpStr.setString(m_controllsRef->use.cStr());
				}
			}
		}
	}

	//check if going out of bounds in the array
	if (m_player->GetPos().GetY() - 1 >= 0) {
		//check if the player has a key to unlock the door
		if (m_player->GetHasKey()) {
			//check the room to the right
			if (m_roomManager.GetRoomType(m_player->GetPos().GetX(), m_player->GetPos().GetY() - 1) == LOCKED) {
				//append right to the input string
				tmpStr.append(m_controllsRef->up.cStr());
				//check if input == useright
				if (m_input.equalTo(tmpStr)) {
					//unlock the locked room
					m_roomManager.GetRoom(m_player->GetPos().GetX(), m_player->GetPos().GetY() - 1)->InPut(*m_player, m_input);
				}
				else {
					tmpStr.setString(m_controllsRef->use.cStr());
				}
			}
		}
	}
}

void Game::InPut() {
	//get the string from the console
	m_input.ReadFromConsole();

	//get rid of the spaces in the user input
	String space(" ");
	m_input.replace(space, "");

	if (m_input.equalTo(m_controllsRef->iteam1)) {
		m_player->UseItean(0);
	}
	if (m_input.equalTo(m_controllsRef->iteam2)) {
		m_player->UseItean(1);
	}
	if (m_input.equalTo(m_controllsRef->iteam3)) {
		m_player->UseItean(2);
	}

	m_roomManager.InPut(m_input);

	UnLockRoom();
	MovePlayer();
}

void Game::UpDate() {
	if (m_player->GetDead()) {
		m_gameState = GAME_OVER;
		return;
	}

	if (m_input.equalTo(m_controllsRef->quit)) {
		m_gameState = GAME_OVER;
		return;
	}

	if (m_player->GetFloorDone()) {
		m_roomManager.SetRooms();
		m_player->SetFloorDone(false);
	}
}

void Game::Draw() {
	system("CLS");
	m_roomManager.Draw();
	m_player->Draw();

	//tells the player if the room they tried to move to is locked
	Window::DrawLine(45, 24, WHITE, m_outPut.cStr(), 50);

	m_ui.Draw();
}


eGameStates Game::Run() {
	Draw();
	InPut();
	UpDate();
	return 	m_gameState;
}

int Game::GetLevel() {
	return m_roomManager.GetLevel();
}

void Game::ReSet() {
	init();
	m_roomManager.ReSet();
}
