#include "RenderTesting.h"
#include "Render.h"


RenderTesting::RenderTesting()
{
	//m_render.SetBufferSize(15, 10);
	//Render::SetBufferSize(52, 80);
}


RenderTesting::~RenderTesting()
{
}

void RenderTesting::Draw()
{
	Render::Clear();
	Rect Border = { 2,2,5,4 };
	Render::DrawBorder(Border, RED);
	//Rect Border2 = { 0,2,3,4 };
	//m_render.DrawBorder(Border2, GREEN);

	Render::Draw();
}
