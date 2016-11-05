#pragma once
#include "Room.h"
class End :public Room {
private:

public:
	End(Postion a_postion, int a_w, int a_h, eRoomType a_type, Controlls *a_cReff);

	~End();

	virtual void Draw();
	virtual void InPut(Player &, String a_inPut);

	void DrawOptions();
};

