#include "Start.h"

Start::Start() {
}

Start::Start(Postion a_postion, int a_w, int a_h, eRoomType a_type, Controlls *a_controllsRef) :
	Room(a_postion, a_w, a_h, a_type, a_controllsRef) {
}


Start::~Start() {
}

void Start::Draw() {
	Rect pLocation = { m_drawPos.GetX(), m_drawPos.GetY(), m_width, m_height };
	Window::DrawBorder(pLocation, GREEN);
	eColor color = m_playerHere ? CYAN : YELLOW;
	Window::SetTextColor(color);
	Window::DrawChar(m_drawPos.GetX() + 3, m_drawPos.GetY() + 2, m_playerHere ? '!' : 's');
}

void Start::InPut(Player &a_playerReff, String a_inPut) {
}
