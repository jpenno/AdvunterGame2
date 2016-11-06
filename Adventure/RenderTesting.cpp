#include "RenderTesting.h"



RenderTesting::RenderTesting()
{
	//m_render.SetBufferSize(15, 10);
	m_render.SetBufferSize(52, 80);


}


RenderTesting::~RenderTesting()
{
}

void RenderTesting::Draw()
{
	m_render.Clear();
	Rect Border = { 2,2,5,4 };
	m_render.DrawBorder(Border, RED);
	//Rect Border2 = { 0,2,3,4 };
	//m_render.DrawBorder(Border2, GREEN);

	m_render.Draw();
}
