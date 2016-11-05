#pragma once
#include "Empty.h"
#include "Start.h"
#include "End.h"
#include "Locked.h"
#include "KeyRoom.h"
#include "Loot.h"
#include "MonsterRoom.h"

class RoomManager {
private:
	Controlls *m_controllsRef;
	Player *m_playerReff;
	Room **m_rooms;
	int m_width;
	int m_height;
	int m_roomWidth;			
	int m_roomHeight;

	String m_levelString;
	int m_level;

	//max room counte for room types
	int m_maxLockedRooms;
	int m_maxKeyRooms;
	int m_maxLoodRooms;
	int m_maxMonsterRooms;
	int m_maxPossMonsterRooms;
	//conter to see how mant times each room tye has been made
	int m_lockedRooms = 0;
	int m_KeyRooms = 0;
	int m_lootRooms = 0;
	int m_monsterRooms = 0;

	void MakeLockedRooms(Postion &, int &, int &);
public:
	RoomManager();
	~RoomManager();

	int GetHeight() { return m_height; }
	int GetWidth() { return m_width; }
	void SetWidth(int a_width) { m_width = a_width; }
	void SeHeight(int a_Height) { m_height = a_Height; }
	eRoomType GetRoomType(int a_x, int a_y) { return m_rooms[a_y* m_width + a_x]->GetType(); }
	eRoomType GetRoomType(Postion a_pos) { return m_rooms[a_pos.GetY()* m_width + a_pos.GetX()]->GetType(); }
	Room* GetRoom(int a_x, int a_y) { return m_rooms[a_y* m_width + a_x]; }
	Room* GetRoom(Postion a_pos) { return m_rooms[a_pos.GetY()* m_width + a_pos.GetX()]; }
	int GetLevel() { return m_level; }

	void SetRooms();
	void Set(int, int, Player *, Controlls *a_controllsRef);
	void ReSet();

	void InPut(String);
	void UpDate();
	void Draw();		 
};

