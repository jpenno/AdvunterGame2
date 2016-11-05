#pragma once
#include "Player.h"
class Monster {
private:
	String m_healthStr;
	String m_damageStr;
	String m_levelStr;

	int m_health;
	int m_damage;
	int m_level;
	bool m_dead;

public:
	Monster();
	~Monster();

	void Set(int);

	int GetDamage() { return m_damage; }

	void TakeDamage(int, Player &);

	void DrawInfo(int, int);

	bool GetDead() { return m_dead; }

};

