#include "Room.h"
#include "Controlls.h"

BaseRoom::BaseRoom(){}
BaseRoom::~BaseRoom(){}

void Room::DrawOptionText(char a_option[]) {
	m_optinos.append(a_option);
	Window::DrawLine(45, m_optionsY, WHITE, m_optinos.cStr(), 30);
	m_optionsY += 2;
	m_optinos.setString("Options: ");
}

Room::Room() {
	m_postion = Postion(0,0);
}

Room::Room(Postion a_postion, int a_w, int a_h , eRoomType a_type, Controlls *a_controllsRef) {
	//sets the room type
	m_type = a_type;
	//set the postion of the room
	m_postion.Set(a_postion);
	//set the width and height of the room
	m_width  = a_w;
	m_height = a_h;
	m_offSetX = 2;
	m_offSetY = 1;
	//set the drawing postiion of the room
	m_drawPos.Set((m_postion.GetX() *(m_width + 1) + m_offSetX),
					(m_postion.GetY() * (m_height - 1) + m_offSetY));
	m_playerHere = false;
	m_controllsRef = a_controllsRef;
}

Room::~Room() {}

void Room::DrawRoonInfo(){
	m_infoY = 8;
	String roomType("Room Type: ");

	switch (m_type) {
		case EMPTY:
			roomType.append("Empty");
			break;
		case LOCKED:
			roomType.append("Locked");
			break;
		case KEYROOM:
			roomType.append("Key");
			break;
		case LOOT:
			roomType.append("Loot");
			break;
		case MONSTER:
			roomType.append("Monster");
			break;
		case END:
			roomType.append("End");
			break;
		case START:
			roomType.append("Start");
			break;
		case UNLOCKED:
			roomType.append("Unlocked");
			break;
	}

	Window::DrawLine(45, m_infoY, WHITE, roomType.cStr(), 50);
	m_infoY += 2;
}

void Room::DrawOptions() {
	m_optionsY = 30;
	String optionText;

	m_optinos.setString("Options: ");

	if (m_postion.GetX() > 0) {
		optionText.setString(m_controllsRef->left.cStr());
		optionText.append(": to go left");
		DrawOptionText(optionText.cStr());
	}	
	if (m_postion.GetY() > 0) {
		optionText.setString(m_controllsRef->up.cStr());
		optionText.append(": to go up");
		DrawOptionText(optionText.cStr());
	}
	if (m_postion.GetX() < 4) {
		optionText.setString(m_controllsRef->right.cStr());
		optionText.append(": to go right");
		DrawOptionText(optionText.cStr());
	}
	if (m_postion.GetY() < 4) {
		optionText.setString(m_controllsRef->down.cStr());
		optionText.append(": to go down");
		DrawOptionText(optionText.cStr());
	}
}
