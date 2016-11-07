#include "UI.h"
#include "Render.h"


UI::UI() {
}

UI::~UI() {
}

void UI::Set(int a_screenWidth, int a_screenHeight, int a_mWidth, int a_mHeight) {
	m_screenHeight = a_screenHeight;
	m_screenWidth = a_screenWidth;
	m_mWidht = a_mWidth;
	m_mHeight = a_mHeight;
	m_inPutTitle.setString("In Put:");
	m_inventoryTitle.setString("Inventory");
	m_roomInfoTitle.setString("Room Info");
	m_roomOptionsTitle.setString("Room Options");
}

void UI::UpDate(){
}

void UI::Draw(){
	//the border around the screen
	Rect screenBorder = { 0, 0, m_screenWidth, m_screenHeight };
	Render::DrawBorder(screenBorder, RED);

	//the border around the game map
	Rect mapBorder = { 0, 0, m_mWidht * 9-2, m_mHeight * 6- 2 };
	Render::DrawBorder(mapBorder, RED);

	//the border for game info
	Rect gameInfoBorder = { m_mWidht * 9 - 2 , 1, 80 - (m_mWidht * 9 - 2), 5 };
	Render::DrawBorder(gameInfoBorder, RED);

	//input box
	Rect inPutBorder = { 0, m_mHeight * 6 - 3, m_mWidht * 9 - 2, 6 };
	Render::DrawBorder(inPutBorder, RED);
	Render::DrawLine(2, m_mHeight * 6 - 1, WHITE, m_inPutTitle.cStr(), 50);

	//inventory border
	Rect inventoryBorder = { 0, m_mHeight * 6 +2, m_mWidht * 9 - 2, 20 };
	Render::DrawBorder(inventoryBorder, RED);
	Render::DrawLine(15, m_mHeight * 6 + 3, WHITE, m_inventoryTitle.cStr(), 50);

	//room info border
	Rect roomInfoBorder = { m_mWidht * 9 - 2, 5, 80 - (m_mWidht * 9 - 2), 23 };
	Render::DrawBorder(roomInfoBorder, RED);
	Render::DrawLine(55, 6, WHITE, m_roomInfoTitle.cStr(), 50);

	//room options
	Rect roomOprionsBorder = { m_mWidht * 9 - 2, 27, 80 - (m_mWidht * 9 - 2), 25 };
	Render::DrawBorder(roomOprionsBorder, RED);
	Render::DrawLine(55, 28, WHITE, m_roomOptionsTitle.cStr(), 50);
}
