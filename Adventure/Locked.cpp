#include "Locked.h"

Locked::Locked(Postion a_postion, int a_w, int a_h, eRoomType a_type, int a_level, Controlls *a_cReff) :
				Room(a_postion, a_w, a_h, a_type, a_cReff) {
	m_locked = true;
	m_looted = false;
	//randomley select a pickup
	switch ((ePickUpType)rand() % END_PICKUP) {
		case HEALTH_POTION:
			m_itean = new HealthPotion(HEALTH_POTION, a_level);
			break;
		case DAMAGE_POTION:
			m_itean = new AttackPotion(DAMAGE_POTION, a_level);
			break;
	}
}

Locked::~Locked() {
	if (m_itean != nullptr)
		delete m_itean;
}

void Locked::InPut(Player &a_playerReff, String a_inPut) {
	if (m_locked)
		a_playerReff.SetKey(false);
	
	UnLock();
	

	if (a_inPut.equalTo(m_controllsRef->pickup)) {
		if (!a_playerReff.GetFullInv()) {			   //break
			a_playerReff.SetIteam(m_itean);
			m_itean = nullptr;

			m_looted = true;
		}
	}
}

void Locked::UnLock() {
	m_locked = false;
	m_type = UNLOCKED;
}

void Locked::Draw() {
	Rect pLocation = { m_drawPos.GetX(), m_drawPos.GetY(), m_width, m_height };
	Window::DrawBorder(pLocation, MAGENTA);
	Window::SetTextColor(m_playerHere ? CYAN : YELLOW);
	Window::DrawChar(m_drawPos.GetX() + 3, m_drawPos.GetY() + 2, m_playerHere ? '!' : m_locked ? 'L' : m_looted ? ' ': 'u');
}

void Locked::DrawOptions(){
	Room::DrawOptions();
	if (!m_looted) {
		String optionText;
		optionText.setString(m_controllsRef->pickup.cStr());
		optionText.append(": to pick up the potion");
		DrawOptionText(optionText.cStr());
	}
}

void Locked::DrawRoonInfo(){
	Room::DrawRoonInfo();

	if (m_itean != nullptr)
		m_itean->Draw(45, m_infoY);
}
