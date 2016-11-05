#include "End.h"


End::End(Postion a_postion, int a_w, int a_h, eRoomType a_type, Controlls *a_cReff) :
				Room(a_postion, a_w, a_h, a_type,  a_cReff) {
}

End::~End() {
}

void End::Draw() {
	Rect pLocation = { m_drawPos.GetX(), m_drawPos.GetY(), m_width, m_height };
	Window::DrawBorder(pLocation, RED);
	Window::SetTextColor(m_playerHere ? CYAN : YELLOW);
	Window::DrawChar(m_drawPos.GetX() + 3, m_drawPos.GetY() + 2, m_playerHere ? '!' : 'F');

	Window::DrawLine(4, 37, WHITE, m_info.cStr(), 50);
}

void End::InPut(Player &a_playerReff, String a_inPut) {
	if (a_inPut.equalTo(m_controllsRef->go)) {
		a_playerReff.SetFloorDone(true);
	}
}

void End::DrawOptions() {
	Room::DrawOptions();
	String optionText;
	optionText.setString(m_controllsRef->go.cStr());
	optionText.append(": to go to the next floor");
	DrawOptionText(optionText.cStr());
}