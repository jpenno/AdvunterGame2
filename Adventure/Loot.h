#pragma once
#include "Room.h"
#include "Weapon.h"
class Loot : public Room {
private:		
	Weapon *m_weapon;
	bool m_looted;

public:
	Loot(Postion a_postion, int a_w, int a_h, eRoomType a_type, int a_level, Controlls *a_controllsRef);

	~Loot();

	void InPut(Player &, String a_inPut);

	void DrawOptions();
	void Draw();
	void DrawRoonInfo();
};

