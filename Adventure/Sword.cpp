#include "Sword.h"
#include <time.h>
Sword::Sword() {
	m_name.setString("Sword of damage");
	m_damage = rand() % 20;
}

Sword::~Sword() {
}

void Sword::Set(int a_level) {
	m_level = (rand() % 2) + a_level;
	m_name.setString("Sword of damage");
	m_damage = rand() % 5 + m_level;
}

int Sword::GetDamage() {
	return m_damage;
}

void Sword::Draw(int a_x, int a_y) {
	String name("Name: ");
	name.append(m_name.cStr());
	String damage("Damage: ");
	char damageChar[10];
	//convert from int to char array to append
	itoa(m_damage, damageChar, 10);
	damage.append(damageChar);

	String level("Level: ");
	char levelChar[10];
	//convert from int to char array to append
	itoa(m_level, levelChar, 10);
	level.append(levelChar);

	Window::DrawLine(a_x, a_y, WHITE, "Sword", 50);
	Window::DrawLine(a_x + 2, a_y, WHITE, name.cStr(), 50);
	Window::DrawLine(a_x + 2, a_y + 1, WHITE, damage.cStr(), 50);
	Window::DrawLine(a_x + 2, a_y + 2, WHITE, level.cStr(), 50);
}
