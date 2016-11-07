#include "Empty.h"
#include "Render.h"


Empty::Empty(Postion a_postion, int a_w, int a_h, eRoomType a_type, Controlls *a_controllsRef) :
				Room(a_postion, a_w, a_h, a_type, a_controllsRef) {
}

Empty::~Empty() {
}

void Empty::InPut(Player &a_playerReff, String a_inPut) {
}

void Empty::Draw() {
	Rect pLocation = { m_drawPos.GetX(), m_drawPos.GetY(), m_width, m_height };
	Render::DrawBorder(pLocation, LIGHTGRAY);
	Render::DrawChar(m_drawPos.GetX() + 3, m_drawPos.GetY() + 2, m_playerHere ? '!' : ' ',
		m_playerHere ? CYAN : YELLOW);
}
