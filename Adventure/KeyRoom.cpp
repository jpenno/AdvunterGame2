#include "KeyRoom.h"

KeyRoom::KeyRoom(Postion a_postion, int a_w, int a_h, eRoomType a_type, Controlls *a_cReff):
						Room(a_postion, a_w, a_h, a_type, a_cReff) {
	m_hasKey = true;
}

KeyRoom::~KeyRoom() {
}

void KeyRoom::InPut(Player &a_playerReff, String a_inPut) {
	if (m_hasKey) {
		if (a_inPut.equalTo(m_controllsRef->pickup)) {
			if (!a_playerReff.GetHasKey()) {
				a_playerReff.SetKey(true);
				m_hasKey = false;
			}
		}
	}
}

void KeyRoom::Draw() {		  
	Rect pLocation = { m_drawPos.GetX(), m_drawPos.GetY(), m_width, m_height };
	Window::DrawBorder(pLocation, BLUE);
	Window::SetTextColor(m_playerHere ? CYAN : YELLOW);
	Window::DrawChar(m_drawPos.GetX() + 3, m_drawPos.GetY() + 2, m_playerHere ? '!' : m_hasKey ? 'K': ' ');
}

void KeyRoom::DrawOptions() {
	Room::DrawOptions();
	if (m_hasKey) {
		String optionText;
		optionText.setString(m_controllsRef->pickup.cStr());
		optionText.append(": to pick up the key");
		DrawOptionText(optionText.cStr());
	}
}
