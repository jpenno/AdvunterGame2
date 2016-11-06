#include "Render.h"
#include "window.h"

// These are the static class variables 
int Render::m_width;
int Render::m_height;
std::vector<std::vector<eColor>> Render::m_bufferColor;
std::vector<std::vector<unsigned char>> Render::m_buffer;

Render::Render()
{
}

Render::~Render()
{
}

void Render::SetBufferSize(int a_width, int a_height)
{
	m_width = a_width;
	m_height = a_height;

	for (int i = 0; i < m_height; i++)
	{
		vector<unsigned char> tmp;
		vector<eColor> tmpColor;
		for (int j = 0; j < m_width; j++)
		{
			tmp.push_back(' ');
			tmpColor.push_back(WHITE);
		}
		m_buffer.push_back(tmp);
		m_bufferColor.push_back(tmpColor);
	}
}

void Render::Clear()
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_buffer[i][j] = ' ';
			m_bufferColor[i][j] = WHITE;
		}
	}
}

void Render::DrawBorder(Rect a_location, eColor a_color)
{
	// top corner
	m_buffer[a_location.y][a_location.x] = char(201);													//TOP LEFT CORNER
	m_bufferColor[a_location.y][a_location.x] = a_color;												//TOP LEFT CORNER

	for (int X = a_location.x + 1; X < a_location.x + a_location.width - 1; X++) 						//TOP BORDER
	{
		m_buffer[a_location.y][X] = char(205);	
		m_bufferColor[a_location.y][X] = a_color;
	}

	// top right corner
	m_buffer[a_location.y][a_location.x + a_location.width - 1] = char(187);							//TOP RIGHT CORNER
	m_bufferColor[a_location.y][a_location.x + a_location.width - 1] = a_color;							//TOP RIGHT CORNER

	m_buffer[a_location.y + a_location.height - 2][a_location.x] = char(200);							//BOTTOM LEFT CORNER
	m_bufferColor[a_location.y + a_location.height - 2][a_location.x] = a_color;						//BOTTOM LEFT CORNER


	for (int X = a_location.x + 1; X < a_location.x + a_location.width - 1; X++) 						//BOTTOM BORDER
	{
		m_buffer[a_location.y + a_location.height - 2][X] = char(205);					
		m_bufferColor[a_location.y + a_location.height - 2][X] = a_color;
	}

	m_buffer[a_location.y + a_location.height - 2][a_location.x + a_location.width - 1] = char(188);	//BOTTOM RIGHT CORNER
	m_bufferColor[a_location.y + a_location.height - 2][a_location.x + a_location.width - 1] = a_color;	//BOTTOM RIGHT CORNER

	for (int Y = a_location.y + 1; Y < a_location.y + a_location.height - 2; Y++) {						
		m_buffer[Y][a_location.x] = char(186);															//LEFT BORDER
		m_buffer[Y][a_location.x + a_location.width - 1] = char(186);									//RIGHT BORDER
	
		m_bufferColor[Y][a_location.x] = a_color;														//LEFT BORDER
		m_bufferColor[Y][a_location.x + a_location.width - 1] = a_color;								//RIGHT BORDER
	}
}

void Render::Draw()
{
	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{		
			Window::SetXY(x, y);
			//Window::SetTextColor(m_bufferColor[y][x]);
			Window::SetTextColor((eColor)(rand() % 15));
			cout << m_buffer[y][x];
		}
	}
}

