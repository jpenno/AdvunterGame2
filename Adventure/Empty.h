#pragma once
#include "Room.h"
class Empty : public Room {
private:

public:
	Empty(Postion a_postion, int a_w, int a_h, eRoomType a_type, Controlls *a_controllsRef);
	~Empty();

	void Draw();
	void InPut(Player &, String a_inPut);
};

