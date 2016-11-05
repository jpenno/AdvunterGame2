#include "RoomManager.h"
#include <iostream>
#include <stdlib.h>   
#include <time.h>     
using namespace std;

void RoomManager::SetRooms() {
	//incress the dungion level
	m_levelString.setString("Dungon Level: ");
	m_level++;
	
	
	

	//check if there is empty rooms left for more monster rooms
	if (m_maxMonsterRooms >= m_maxPossMonsterRooms) {
		m_maxMonsterRooms = m_maxPossMonsterRooms;
	}
	else {
		//incress how many monster rooms can spawn
		m_maxMonsterRooms++;
	}

	char levelChar[10];
	//convert from int to char array to append
	_itoa_s(m_level, levelChar, 10);
	m_levelString.append(levelChar);

	//set all the rooms to null	
	for (int i = 0; i < m_width * m_height; i++) {
		if (m_rooms[i] != nullptr) {
			delete m_rooms[i];
			m_rooms[i] = nullptr;
		}
	}
	//reset the room count for every room
	m_lockedRooms = 0;
	m_KeyRooms = 0;
	m_lootRooms = 0;
	m_monsterRooms = 0;
	
	//set the player starting room
	m_rooms[m_playerReff->GetPos().GetY() * m_width + m_playerReff->GetPos().GetX()]
					= new Start(m_playerReff->GetPos(), m_roomWidth, m_roomHeight, START, m_controllsRef);
	//set the player to being in this room
	m_rooms[m_playerReff->GetPos().GetY() * m_width + m_playerReff->GetPos().GetX()]->SetPlayerHere();
	
	//the the postion the romm will be set to
	Postion tmpPos;
	// x and y postion for the end room
	int x, y;
	 //sets the end room
	do {
		// gets a random x and y for where to place the end room
		x = rand() % m_width;
		y = rand() % m_height;
		//checks if the postion of the end room is != to the start room  
		if (x != m_playerReff->GetPosReff()->GetX() &&
			y != m_playerReff->GetPosReff()->GetY()) {
			tmpPos.Set(x, y);
			//sets the end room 
			m_rooms[y * m_width + x] = new End(tmpPos, m_roomWidth, m_roomHeight, END, m_controllsRef);
			break;
		}
	} while (true);

	do {
		//sets all the other rooms up 
		for (int i = 0; i < m_height; i++) {
			for (int j = 0; j < m_width;) {
				//set the room x and y for where the room will be
				tmpPos.Set(j, i);
				//check if the room has not all ready been set
				if (m_rooms[i *m_width + j] == nullptr || m_rooms[i *m_width + j]->GetType() == EMPTY) {
					switch ((eRoomType)rand() % END) {
					case EMPTY:
						//set room to be an empty room
						m_rooms[i * m_width + j] = new Empty(tmpPos, m_roomWidth, m_roomHeight, EMPTY, m_controllsRef);
						j++;
						break;
					case LOCKED:
						//sets locked room
						MakeLockedRooms(tmpPos, j, i);
						break;
					case KEYROOM:
						//check if made too many key rooms
						if (m_KeyRooms < m_maxKeyRooms) {
							//set room to KeyRoom
							m_rooms[i * m_width + j] = new KeyRoom(tmpPos, m_roomWidth, m_roomHeight, KEYROOM, m_controllsRef);
							m_KeyRooms++;
							j++;
						}
						break;
					case MONSTER:
						//check if too many monster rooms
						if (m_monsterRooms < m_maxMonsterRooms) {
							//set room to MonsterRoom
							m_rooms[i * m_width + j] = new MonsterRoom(tmpPos, m_roomWidth, m_roomHeight, MONSTER, m_level, m_controllsRef);
							m_monsterRooms++;
							j++;
						}
						break;
					case LOOT:
						//check if too many loot rooms 
						if (m_lootRooms < m_maxLoodRooms) {
							//set room to loot room
							m_rooms[i * m_width + j] = new Loot(tmpPos, m_roomWidth, m_roomHeight, LOOT, m_level, m_controllsRef);
							m_lootRooms++;
							j++;
						}
						break;
					}
				}
				else {
					j++;
				}
			}
		}
	} while (m_monsterRooms < m_maxMonsterRooms);
}

void RoomManager::MakeLockedRooms( Postion &a_tmpPos, int &a_j, int &a_i) {
	//checks how many locked rooms have been set
	if (m_lockedRooms < m_maxLockedRooms) {
		//check if goning out of the array bounds
		if (!(a_j == 0)) {
			if(!(a_i == 0)) {
				//checks if the room above and to the left are a locked type room
				if ((m_rooms[a_i *m_width + (a_j - 1)]->GetType() != LOCKED)  && 
						(m_rooms[(a_i - 1) *m_width + a_j]->GetType() != LOCKED) ) {
					//checks if the room above and to the left are the start room
					if ((m_rooms[a_i *m_width + (a_j - 1)]->GetType() != START) && 
							(m_rooms[(a_i - 1) *m_width + a_j]->GetType() != START)) {
						//sets the romm to a locked room
						m_rooms[a_i *m_width + a_j] = new Locked(a_tmpPos, m_roomWidth, m_roomHeight, LOCKED, m_level, m_controllsRef);
						m_lockedRooms++;
						a_j++;
					}
				}
			}
		}
	}
}

RoomManager::RoomManager() {
	m_level = 0;
	m_maxLockedRooms = 3;
	m_maxKeyRooms = 4;
	m_maxLoodRooms = 2;
	m_maxMonsterRooms = 3;

	//set m_rooms to null pointer
	m_rooms = nullptr;
	m_playerReff = nullptr;
	srand((unsigned)time(NULL));
	m_level = 0;
}

RoomManager::~RoomManager() {
	//delete m_rooms if not set to null poniter
	if (m_rooms != nullptr)
		delete[] m_rooms;
}

//sets the rooms up
void RoomManager::Set(int a_height, int a_width, Player *a_playerReff, Controlls *a_controllsRef) {
	m_controllsRef = a_controllsRef;
	//set player postion reff
	m_playerReff = a_playerReff;
	//set up the array of rooms
	m_height = a_height;
	m_width = a_width;
	m_rooms = new Room*[m_height * m_width];
	//the width and height of the room
	m_roomWidth = 7;
	m_roomHeight = 6;

	m_maxPossMonsterRooms = (m_height * m_width) - (m_maxKeyRooms + m_maxLockedRooms + m_maxLoodRooms + 2);

	//set the rooms to null pointer
	for (int i = 0; i < m_width * m_height; i++) 
		m_rooms[i] = nullptr;

	SetRooms();
}

void RoomManager::ReSet() {
	m_level = 0;
	m_maxLockedRooms = 3;
	m_maxKeyRooms = 4;
	m_maxLoodRooms = 2;
	m_maxMonsterRooms = 3;
	SetRooms();
}

void RoomManager::InPut(String a_inPut) {
	//call the room the player is in to handle input for that room
	m_rooms[m_playerReff->GetPos().GetY() * m_width + m_playerReff->GetPos().GetX()]->InPut(*m_playerReff, a_inPut);
}

void RoomManager::UpDate() {
	//updates where the player is
	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			if (i == m_playerReff->GetPosReff()->GetY() &&
				j == m_playerReff->GetPosReff()->GetX()) {
				m_rooms[i *m_width + j]->SetPlayerHere();
			}
			else {
				m_rooms[i *m_width + j]->SetPlayerNotHere();
			}
		}
	}
}

void RoomManager::Draw() {
	for (int i = 0; i < m_height * m_width; i++) {
		if (m_rooms[i] != nullptr) {
			m_rooms[i]->Draw();
		}
	}
	Window::DrawLine(60, 2, WHITE, m_levelString.cStr(), 50);

	//draw the room the player is in info
	m_rooms[m_playerReff->GetPos().GetY() * m_width + m_playerReff->GetPos().GetX()]->DrawRoonInfo();

	//draw what the playe can do in the the room there in
	m_rooms[m_playerReff->GetPos().GetY() * m_width + m_playerReff->GetPos().GetX()]->DrawOptions();
}
