#include "Postion.h"

Postion::Postion() {
	m_x = 0;
	m_y = 0;
}

Postion::Postion(int a_y, int a_x) {
	m_x = a_x;
	m_y = a_y;
}
Postion::Postion(Postion &a_postion) {
	m_y = a_postion.m_y;
	m_x = a_postion.m_x;
}
Postion::~Postion() {
}

void Postion::Set(Postion & a_postion) {
	m_y = a_postion.m_y;
	m_x = a_postion.m_x;
}
