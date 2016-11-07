#pragma once
#include "window.h"
#include <vector>
class Render
{
private:
	static int m_width;
	static int m_height;
	static std::vector<std::vector<eColor>> m_bufferColor;
	static std::vector<std::vector<unsigned char>> m_buffer;

public:
	Render();
	~Render();
	 
	static void SetBufferSize(int a_width, int a_height);
	 
	static void Clear();
	static void Draw();
	static void DrawBorder(Rect a_location, eColor a_color);
	static void DrawChar(int pX, int pY, unsigned char pLine, eColor a_color);
	static void DrawLine(int a_x, int a_y, eColor a_color, char *a_line, int a_max);
};

