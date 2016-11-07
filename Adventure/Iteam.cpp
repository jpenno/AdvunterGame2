#include "Iteam.h"
#include "Render.h"

Iteam::Iteam(ePickUpType a_type) {
	m_type = a_type;
	m_info.setString("pick iteam info not set");
	m_active = false;
	m_textColor = WHITE;
}

Iteam::~Iteam() {
}

void Iteam::Use(){
	m_active = true;
}

void Iteam::Draw(int m_x, int m_y){
	if (m_info.cStr() == "") {
		int x = 10;
	}
	Render::DrawLine(m_x, m_y, m_textColor, m_info.cStr(), 50);
}