#include "Monster.h"
#include "Render.h"

Monster::Monster() {
	m_health = (rand()% 10)+1;
	m_damage = rand() % 5+1;
	m_dead = false;
	m_healthStr.setString("Health: ");
	m_damageStr.setString("Damage: ");
}

Monster::~Monster() {
}

void Monster::Set(int a_level) {
	m_level = a_level;
	m_health = (rand() % 10) + m_level * 2;
	m_damage = rand() % m_level + m_level;
	m_dead = false;
	m_healthStr.setString("Health: ");
	m_damageStr.setString("Damage: ");
}

void Monster::TakeDamage(int a_damage, Player &a_playerReff) {
	m_health -= a_damage;
	if (m_health <= 0)
		m_dead = true;
	if (!m_dead)
		a_playerReff.TakeDamage(m_damage);
}

void Monster::DrawInfo(int a_x, int a_y) {
	m_healthStr.setString("Health: ");
	m_damageStr.setString("Damage: ");
	m_levelStr.setString("Level: ");
	//comvert damage it to char
	char damageChar[10];
	//convert from int to char array to append
	_itoa_s(m_damage, damageChar, 10);
	m_damageStr.append(damageChar);

	//comvert health int to char
	char healthChar[10];
	//convert from int to char array to append
	_itoa_s(m_health, healthChar, 10);
	m_healthStr.append(healthChar);

	//comvert health int to char
	char levelChar[10];
	//convert from int to char array to append
	_itoa_s(m_level, levelChar, 10);
	m_levelStr.append(levelChar);

	Render::DrawLine(a_x, a_y, WHITE, m_levelStr.cStr(), 50);
	a_y++;
	Render::DrawLine(a_x, a_y, WHITE, m_healthStr.cStr(), 50);
	a_y++;
	Render::DrawLine(a_x, a_y, WHITE, m_damageStr.cStr(), 50);
}