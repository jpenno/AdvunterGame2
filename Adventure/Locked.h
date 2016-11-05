#pragma once
#include "Room.h"
#include "HealthPotion.h"
#include "AttackPotion.h"
class Locked : public Room {
private:
	bool m_playerFullInv;
	bool m_locked;
	bool m_looted;
	void UnLock();
	Iteam *m_itean;
	String m_fullInvStr;

public:
	Locked(Postion a_postion, int a_w, int a_h, eRoomType a_type, int a_level, Controlls *a_cReff);
	~Locked();

	virtual void Draw();
	void DrawOptions();
	void DrawRoonInfo();
	virtual void InPut(Player &, String a_inPut);
};

