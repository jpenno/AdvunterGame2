#pragma once
#include "Weapon.h"
class Sword : public Weapon {
private:  

public:
	Sword();
	~Sword();
	void Set(int);
	int GetDamage();
	void Draw(int, int);
};

