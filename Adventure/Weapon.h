#pragma once
#include "string.h"
class Weapon {
protected:
	String m_name;
	int m_damage;
	int m_level;

public:
	Weapon();
	~Weapon();

	virtual void Set(int ) = 0;
	
	virtual int GetDamage() = 0;
	virtual void Draw(int, int) = 0;
};

