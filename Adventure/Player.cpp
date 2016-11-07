#include "Player.h"
#include "Render.h"

Player::Player() {
	m_postion = Postion(1, 1);
	m_maxHealrh = 20;
	m_health = m_maxHealrh;
	m_floorDone = false;
	m_hasKey = false;
	m_weapon = nullptr;
	m_fullInv = false;
	m_dead = false;
	m_level = 1;
	m_xp = 0;
	m_hStrColro = WHITE;
	//m_maxIteams = 3;
	m_iteams = new Iteam*[m_maxIteams];
	for (int i = 0; i < m_maxIteams; i++) {
		m_iteams[i] = nullptr;
	}

	m_pickUpSelected = -1;
	m_xpToLevel = 2;
	m_fullInvStr.setString("your inventory if full");
}

Player::~Player() {
	if (m_weapon != nullptr)
		delete m_weapon;

	if (m_iteams != nullptr)
		delete[] m_iteams;
}

void Player::Set(){
	//m_iteams = new Iteam*[m_maxIteams];
	//for (int i = 0; i < m_maxIteams; i++) {
	//	m_iteams[i] = nullptr;
	//}
}

void Player::DrawInv() {
	m_iTextY = 35;
	if (m_weapon != nullptr) {
		m_weapon->Draw(2, m_iTextY);
		m_iTextY += 4;
	}

	Render::DrawLine(2, m_iTextY, WHITE, m_info.cStr(), 50);
	m_iTextY += 2;
	int iteamCount = 0;

	//draw items in your inventory
	for (int i = 0; i < m_maxIteams; i++) {
		if (m_iteams[i] != nullptr) {
			if (m_iteams[i]->GetType() < 0) {
				int x = m_iteams[i]->GetType();
				int y = x;
			}
			String Invnumber;
			char ichar[10];
			//convert from int to char array to append 
			_itoa_s(i+1, ichar, 10);
			Invnumber.setString(ichar);
			Invnumber.append(": ");
			Render::DrawLine(2, m_iTextY, WHITE, Invnumber.cStr(), 50);
			m_iteams[i]->Draw(6, m_iTextY);
			m_iTextY += 2;
			iteamCount++;
		}
	}
	if (iteamCount >= m_maxIteams) {
		m_fullInv = true;
		m_fullInvStr.setString("your inventory if full");
		Render::DrawLine(2, m_iTextY, RED, m_fullInvStr.cStr(), 50);
	}
	else
		m_fullInv = false;
}

int Player::GetDamage() {
	//check if the player has a weapon
	if (m_weapon != nullptr) {
		//check if the pickup selected is vialed
		if (m_pickUpSelected >= 0 && m_pickUpSelected < m_maxIteams) {
			//check if the player has a pickup
			if (m_iteams[m_pickUpSelected] != nullptr) {
				//get the added damage from the potion
				int bonusDamage = m_iteams[m_pickUpSelected]->GetUse();
				//delete the potion you just used and set to null
				delete m_iteams[m_pickUpSelected];
				m_iteams[m_pickUpSelected] = nullptr;
				m_pickUpSelected = -1;
				//return the player damage
				return m_weapon->GetDamage() + m_level + bonusDamage;
			}
		}
		//return the player damage
		return m_weapon->GetDamage() + m_level;
	}
	else {
		//check if the pickup selected is vialed
		if (m_pickUpSelected >= 0 && m_pickUpSelected < m_maxIteams) {
			//check if the player has a pickup
			if (m_iteams[m_pickUpSelected] != nullptr) {
				//get the added damage from the potion
				int bonusDamage = m_iteams[m_pickUpSelected]->GetUse();
				//delete the potion you just used and set to null
				delete m_iteams[m_pickUpSelected];
				m_iteams[m_pickUpSelected] = nullptr;
				//return the player damage
				m_pickUpSelected = -1;
				return m_level + bonusDamage;
			}
		}
		//return the player damage
		return m_level;
	}
}

void Player::SetPos(int a_x, int a_y) {
	m_postion.SetX(a_x);
	m_postion.SetY(a_y);
}

void Player::Draw() {
	//draws the players inventory
	DrawInv();

	m_healthStr.setString("Health: ");
	char healthChar[10];
	//convert from int to char array to append 
	_itoa_s(m_health, healthChar, 10);
	m_healthStr.append(healthChar);
	m_healthStr.append(" / ");
	char maxHealthChar[10];
	//convert from int to char array to append 
	_itoa_s(m_maxHealrh, maxHealthChar, 10);
	m_healthStr.append(maxHealthChar);

	Render::DrawLine(45, 3, m_hStrColro, m_healthStr.cStr(), 50);

	String level("Level: ");
	char levelChar[10];
	//convert from int to char array to append 
	_itoa_s(m_level, levelChar, 10);
	level.append(levelChar);
	Render::DrawLine(45, 2, WHITE, level.cStr(), 50);
	//reset the player health text back to white
	m_hStrColro = WHITE;
}

void Player::SetKey(bool a_key) {
	if (a_key) {
		m_info.setString("Player Has a Key");
	}
	else {
		m_info.setString("");
	}
	m_hasKey = a_key;
}

void Player::SetWeapon(Weapon *a_weapon) {
	if (m_weapon != nullptr)
		delete m_weapon;

	m_weapon = a_weapon;
}

void Player::SetIteam(Iteam *a_iteam) {
	for (int i = 0; i < m_maxIteams; i++) {
		if (m_iteams[i] == nullptr) {
			m_iteams[i] = a_iteam;
			return;
		}
	}
}

void Player::TakeDamage(int a_damage) {
	m_health -= a_damage;
	m_hStrColro = RED;
	if (m_health <= 0)
		m_dead = true;
}

void Player::AddXp(int a_xp) {
	m_xp += a_xp;

	if (m_xp >= m_xpToLevel) {
		m_level++;
		m_xpToLevel++;
		m_maxHealrh += 2;
		m_health = m_maxHealrh;
		m_xp = 0;
	}
}

void Player::UseItean(int a_itemNum){
	if (a_itemNum >= 0 && a_itemNum < m_maxIteams) {
		if (m_iteams[a_itemNum] != nullptr) {
			switch (m_iteams[a_itemNum]->GetType()) {
			case HEALTH_POTION:
				m_hStrColro = GREEN;
				m_health += m_iteams[a_itemNum]->GetUse();
				if (m_health > m_maxHealrh)
					m_health = m_maxHealrh;
				if (!m_iteams[a_itemNum]->GetActive()) {
					delete m_iteams[a_itemNum];
					m_iteams[a_itemNum] = nullptr;
				}
				break;
			case DAMAGE_POTION:
				if (m_pickUpSelected == -1) {
					m_iteams[a_itemNum]->Use();
					m_pickUpSelected = a_itemNum;
				}
				break;
			}
		}
	}
}
