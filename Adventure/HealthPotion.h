#pragma once
#include "Iteam.h"
class HealthPotion :public Iteam {
private:
	int m_healAmount;

public:
	HealthPotion(ePickUpType, int);
	~HealthPotion();
	
	void Use();

	int GetUse();
};