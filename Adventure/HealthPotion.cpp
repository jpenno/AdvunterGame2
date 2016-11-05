#include "HealthPotion.h"

HealthPotion::HealthPotion(ePickUpType a_type, int a_level):
				Iteam(a_type){
	m_info.setString("Health Potion: ");
	m_healAmount = rand() % 5 + a_level;
	m_active = true;

	char helleChar[10];
	//convert from int to char array to append
	_itoa_s(m_healAmount, helleChar, 10);
	m_info.append(helleChar);
}

HealthPotion::~HealthPotion(){
}

void HealthPotion::Use(){
	
}

int HealthPotion::GetUse()
{
	m_active = false;
	return m_healAmount;
}
