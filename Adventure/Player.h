#pragma once
#include "Postion.h"
#include "string.h"
#include "Sword.h"
#include "HealthPotion.h"
class Player {		 
private:
	Postion m_postion;
	bool m_hasKey;
	bool m_floorDone;	
	int m_health;
	int m_maxHealrh;
	int m_level;
	int m_xp;
	int m_xpToLevel;
	int m_iTextY;
	bool m_fullInv;
	bool m_dead;
	const int m_maxIteams = 3;
	Iteam **m_iteams;
	int m_iteamSelected;
	int m_pickUpSelected;

	Weapon *m_weapon;
	String m_fullInvStr;
	String m_info;
	String m_healthStr;
	eColor m_hStrColro;
	void DrawInv();
public:
	Player();
	~Player();

	void Set();

	Postion* GetPosReff() { return &m_postion; }
	Postion GetPos() { return m_postion; }
	bool GetFloorDone() { return m_floorDone; }
	bool GetHasKey() { return m_hasKey; }
	int GetDamage();
	bool GetDead() { return m_dead; }
	bool GetFullInv() { return m_fullInv; }

	void SetPos(Postion a_pos) { m_postion = a_pos; }
	void SetPos(int, int);
	void SetFloorDone(bool a_fd) { m_floorDone = a_fd; }
	void SetKey(bool );
	void SetWeapon(Weapon *);
	void SetIteam(Iteam *);

	void TakeDamage(int);
	void AddXp(int a_xp);
	void UseItean(int);

	void Draw(); 
};

