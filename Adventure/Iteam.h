#pragma once
#include "string.h"
enum ePickUpType {
	HEALTH_POTION,
	DAMAGE_POTION,
	END_PICKUP,
};

class Iteam {
protected:
	String m_info;
	eColor m_textColor;
	ePickUpType m_type;

	bool m_active;

public:

	Iteam(ePickUpType);
	~Iteam();
	ePickUpType GetType() { return m_type; }
	virtual void Use();
	virtual void Draw(int, int);
	bool GetActive() { return m_active; }

	virtual int GetUse() = 0;
};

