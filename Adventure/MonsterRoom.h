#pragma once
#include "Room.h"
#include "Monster.h"
class MonsterRoom : public Room
{
private:

	String m_info;

	Monster m_monster;


public:
	MonsterRoom(Postion a_postion, int a_w, int a_h, eRoomType a_type, int a_level, Controlls *a_cReff);
	~MonsterRoom();

	void InPut(Player &, String a_inPut);
	void Draw();
	void DrawOptions();
	void DrawRoonInfo();

};

