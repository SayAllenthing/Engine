#pragma once

#include <Windows.h>

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Init(int, int, HWND);
	void Shutdown();
	bool Update();

private:
	bool Draw();
};