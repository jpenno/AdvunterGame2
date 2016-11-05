#pragma once
#include "Iteam.h"
class AttackPotion :public Iteam {
private:
	int m_attackBonus;

public:
	AttackPotion(ePickUpType, int);
	~AttackPotion();

	void Use();
	int GetUse();
};

