#pragma once
#include "string.h"
class UI {
private:
	String m_inPutTitle;
	String m_inventoryTitle;
	String m_roomInfoTitle;
	String m_roomOptionsTitle;

	int m_screenHeight;
	int m_screenWidth;
	int m_mWidht;
	int m_mHeight;
	int m_tWidth;
	int m_tHeight;

public:
	UI();
	~UI();

	void Set(int, int, int, int);

	void UpDate();
	void Draw();
};

