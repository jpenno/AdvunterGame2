#pragma once
#include "window.h"
#include <vector>
class Render
{
private:
	int m_width, m_height;
	std::vector<std::vector<eColor>> m_bufferColor;
	std::vector<std::vector<unsigned char>> m_buffer;
	//unsigned char *m_buffer = nullptr;

public:
	Render();
	~Render();

	void SetBufferSize(int a_width, int a_height);

	void Clear();
	void Draw();
	void DrawBorder(Rect a_location, eColor a_color);
};

