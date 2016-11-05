#include "MonsterRoom.h"

MonsterRoom::MonsterRoom(Postion a_postion, int a_w, int a_h, eRoomType a_type, int a_level, Controlls *a_cReff) :
	Room(a_postion, a_w, a_h, a_type, a_cReff) {
	m_monster.Set(a_level);
}

MonsterRoom::~MonsterRoom() {
}

void MonsterRoom::InPut(Player &a_playerReff, String a_inPut) {
	m_info.setString("");
	if (!m_monster.GetDead()) {
		if (a_inPut.equalTo(m_controllsRef->attack)) {
			//store the damage the player dose to the enemy
			int pDamage = a_playerReff.GetDamage();
			m_monster.TakeDamage(pDamage, a_playerReff);
			m_info.setString("Delt: ");
			char damageChar[10];
			//convert from int to char array to append 
			_itoa_s(pDamage, damageChar, 10);
			m_info.append(damageChar);
			m_info.append(" damage to the monster");

			if (m_monster.GetDead()) {
				a_playerReff.AddXp(1);
			}
		}
		else {
			if (!m_monster.GetDead()) {
				a_playerReff.TakeDamage(m_monster.GetDamage() * 2);
				m_info.setString("you take duble damage from runing: ");
				char damageChar[10];
				//convert from int to char array to append 
				_itoa_s(m_monster.GetDamage() * 2, damageChar, 10);
				m_info.append(damageChar);
			}
		}
	}
}

void MonsterRoom::Draw() {
	Rect pLocation = { m_drawPos.GetX(), m_drawPos.GetY(), m_width, m_height };
	Window::DrawBorder(pLocation, DARKCYAN);
	eColor color = m_playerHere ? CYAN : YELLOW;
	Window::SetTextColor(color);
	Window::DrawChar(m_drawPos.GetX() + 3, m_drawPos.GetY() + 2, m_playerHere ? '!' : m_monster.GetDead() ? ' ': 'M');

	Window::DrawLine(45, 24, WHITE, m_info.cStr(), 30);
	m_info.setString("");
}

void MonsterRoom::DrawOptions() {
	Room::DrawOptions();
	String optionText;
	optionText.setString(m_controllsRef->attack.cStr());
	optionText.append(": to attack the enemy");
	DrawOptionText(optionText.cStr());
}

void MonsterRoom::DrawRoonInfo() {
	Room::DrawRoonInfo();
	if (!m_monster.GetDead()) {
		Window::DrawLine(45, m_infoY, WHITE, "Monster", 50);
		m_infoY++;
		m_monster.DrawInfo(47, m_infoY);
	}
}
