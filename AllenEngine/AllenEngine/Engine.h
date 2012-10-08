#pragma once

#define WINDOWS_LEAN_AND_MEAN

#include <Windows.h>
#include <iostream>
#include "World.h"
#include "Graphics.h"

class Engine
{
public:
	Engine();
	~Engine();
	
	bool Init();

	void Exit();
	void Run();

private:
	bool Update();
	bool InitWindow();
	void CloseWindow();

	HWND m_hwnd;
	HINSTANCE m_instance;
	LPWSTR m_appname;
	World *m_world;
	Graphics *m_graphics;
};

static LRESULT CALLBACK WindowProc(HWND hWnd,
                         UINT message,
                         WPARAM wParam,
                         LPARAM lParam);