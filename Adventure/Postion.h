#pragma once
class Postion {
	int m_x;
	int m_y;

public:
	Postion();
	Postion(int, int);
	Postion(Postion &a_postion);

	~Postion();

	void SetX(int a_x) { m_x = a_x; }
	void SetY(int a_y) { m_y = a_y; }
	void Set(int a_x, int a_y) {m_x = a_x; 	 m_y = a_y;	}
	void Set(Postion &a_postion);

	int GetX() { return m_x; }
	int GetY() { return m_y; }
};

