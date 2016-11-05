#pragma once
#include "Room.h"
class Start : public Room {
public:
	Start();
	Start(Postion a_postion, int a_w, int a_h, eRoomType a_type, Controlls *a_controllsRef);
	~Start();

	virtual void Draw();
	virtual void InPut(Player &, String a_inPut);

};

