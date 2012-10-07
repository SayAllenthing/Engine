#pragma once

#include "Engine.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Engine* m_Engine;

	m_Engine = new Engine;
	if(!m_Engine)
		return 0;

	m_Engine->Init();

	m_Engine->Run();

	m_Engine->Exit();
	delete m_Engine;
	m_Engine = 0;

	return 0;
}