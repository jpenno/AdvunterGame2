#pragma once
#include "Postion.h"
#include "window.h"
#include "Player.h"
#include "string.h"
#include "Controlls.h"
  //define the room typs
enum eRoomType {
	EMPTY,
	LOCKED,
	KEYROOM,
	LOOT,
	MONSTER,
	END,
	START,
	UNLOCKED
};

class BaseRoom {
private:
public:
	BaseRoom();
	~BaseRoom();

};

class Room : public BaseRoom {
protected:
	eRoomType m_type;
	Controlls *m_controllsRef;
	String m_info;
	String m_optinos;
	int m_height;
	int m_width;
	Postion m_postion;
	Postion m_drawPos;
	bool m_playerHere;
	int m_offSetY;
	int m_offSetX;
	int m_infoY;
	int m_optionsY;

	void DrawOptionText(char[]);

public:		 
	Room();	

	Room(Postion a_postion, int a_w, int a_h, eRoomType a_type, Controlls *m_controllsRef);
	~Room();

	void SetPlayerHere() { m_playerHere = true; }

	void SetPlayerNotHere() { m_playerHere = false; }

	int GetWidth() { return m_width; }
	int	 GetHeight() { return m_height;}
	eRoomType GetType() { return m_type; }

	virtual void DrawRoonInfo();
	virtual void DrawOptions();
	virtual void Draw() = 0;
	virtual void InPut(Player &, String a_inPut) = 0;
};
