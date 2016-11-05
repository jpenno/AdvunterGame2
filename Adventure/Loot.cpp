#include "Loot.h"

Loot::Loot(Postion a_postion, int a_w, int a_h, eRoomType a_type, int a_level, Controlls *a_controllsRef):
					Room(a_postion, a_w, a_h, a_type, a_controllsRef){
	m_looted = false;

	m_weapon = new Sword;	
	m_weapon->Set(a_level);
}

 Loot::~Loot() {
	if (m_weapon != nullptr)
		delete m_weapon;
}

void Loot::InPut(Player &a_playerReff, String a_inPut) {
	if (!m_looted) {
		if (a_inPut.equalTo(m_controllsRef->pickup)) {
			a_playerReff.SetWeapon(m_weapon);
			m_weapon = nullptr;
			m_looted = true;
		}
	}
}

void Loot::DrawOptions(){
	Room::DrawOptions();
	if (m_weapon != nullptr) {
		String optionText;
		optionText.setString(m_controllsRef->pickup.cStr());
		optionText.append(": to pick up the weapon");
		DrawOptionText(optionText.cStr());
	}
}

void Loot::Draw() {
	Rect pLocation = { m_drawPos.GetX(), m_drawPos.GetY(), m_width, m_height };
	Window::DrawBorder(pLocation, YELLOW);
	Window::SetTextColor(m_playerHere ? CYAN : YELLOW);
	Window::DrawChar(m_drawPos.GetX() + 3, m_drawPos.GetY() + 2, m_playerHere ? '!' : m_looted? ' ' : '=');
}

void Loot::DrawRoonInfo() {
	Room::DrawRoonInfo();

	if (m_weapon != nullptr)
		m_weapon->Draw(45, m_infoY);
}
