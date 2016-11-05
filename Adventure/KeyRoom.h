#pragma once
#include "Room.h"
class KeyRoom : public Room {
private:
	bool m_hasKey;

public:
	KeyRoom(Postion a_postion, int a_w, int a_h, eRoomType a_type, Controlls *a_cReff);

	~KeyRoom();

	virtual void Draw();
	void DrawOptions();
	virtual void InPut(Player &, String a_inPut);
};