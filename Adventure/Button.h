#pragma once
#include "window.h"
#include "string.h"
class Button
{
private:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	eColor m_color;
	String m_Text;
	bool m_upDateDraw;

public:
	Button();

	Button(int, int, int, int);
	~Button();

	void Set(int, int, int, int);
	void SetText(String);

	bool UpDate();
	void Draw();
};

