#include "Button.h"

Button::Button(){
}

Button::Button(int a_x, int a_y, int a_w, int a_h){
	m_y = a_y;
	m_x = a_x;
	m_w = a_w;
	m_h = a_h;
	m_color = YELLOW;
	m_upDateDraw = true;
}


Button::~Button(){
}

void Button::Set(int a_x, int a_y, int a_w, int a_h){
	m_y = a_y;
	m_x = a_x;
	m_w = a_w;
	m_h = a_h;
	m_color = YELLOW;
	m_upDateDraw = true;
}

void Button::SetText(String a_buttonText){
	m_Text.setString(a_buttonText.cStr());
}

bool Button::UpDate()
{
	COORD mPos = Window::getMousePos();
	//check if the mouse is coliding with the button
	if (mPos.X > m_x && mPos.X < m_x + m_w) {
		if (mPos.Y > m_y && mPos.Y < m_y + m_h) {
			//set the buton border to green
			m_color = GREEN;
			//check if the mouse is pressed
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				return true;
		}
	}
	return false;
}

void Button::Draw(){
	Rect screenBorder = { m_x, m_y, m_w, m_h };
	Window::DrawBorder(screenBorder, m_color);
	Window::DrawLine(m_x +2, m_y +2, WHITE, m_Text.cStr(), 50);
	m_color = YELLOW;
}
