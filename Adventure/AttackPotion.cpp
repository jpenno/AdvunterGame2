#include "AttackPotion.h"


AttackPotion::AttackPotion(ePickUpType a_type, int a_level):
							Iteam(a_type){
	m_attackBonus = rand() % 5 + a_level;
	m_info.setString("Attack Potion: ");

	char damageChar[10];
	//convert from int to char array to append
	_itoa_s(m_attackBonus, damageChar, 10);
	m_info.append(damageChar);
}

AttackPotion::~AttackPotion()
{
}

void AttackPotion::Use()
{
	m_active = true;
	m_textColor = GREEN;
}

int AttackPotion::GetUse()
{
	if (m_active) {
		m_active = false;
		 return m_attackBonus;
	}
	return 0;
}
