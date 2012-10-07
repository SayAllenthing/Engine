#include "Engine.h"


Engine::Engine()
{
}

Engine::~Engine()
{
}

bool Engine::Init()//Initialize Engine and required components
{
	bool result;
	result = InitWindow();//Create a window
	printf("HEIEIE");
		//return false;

	return true;
}

bool Engine::InitWindow()
{
	/*
	WNDCLASSEX wc; //Information for the window

	m_instance = GetModuleHandle(NULL);
	m_appname = L"AllenEngine";

	//Temp variables, may change to member variables	
	
	int screenWidth = 800;
	int screenHeight = 600;
	int xPos = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) /2;
	int yPos = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;


	// fill in the struct with the needed information
    

	
	*/

	WNDCLASSEX wc;
	//DEVMODE dmScreenSettings;
	int posX, posY,screenWidth,screenHeight;
	bool FULL_SCREEN = false;

	//ApplicationHandle = this;
	
	m_instance = GetModuleHandle(NULL);

	m_appname = L"AllenEngine";

	
	wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WindowProc;
    wc.hInstance = m_instance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);//(HBRUSH)COLOR_WINDOW; //Background Colour
    wc.lpszClassName = m_appname; //Application Name
	wc.cbClsExtra	= 0;
	wc.cbWndExtra	= 0;
	wc.hIcon		= LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm		= wc.hIcon;	
	wc.lpszMenuName = NULL;
	

	RegisterClassEx(&wc);//Windows class needs to be registered
	
	screenWidth = 800;
	screenHeight = 600;

	posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) /2;
	posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	

	m_hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
        m_appname,    // name of the window class
        m_appname, // title of the window
        WS_OVERLAPPEDWINDOW,// | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,    // window style
        posX,    // x-position of the window
        posY,    // y-position of the window
        screenWidth,    // width of the window
        screenHeight,    // height of the window
        NULL,    // we have no parent window, NULL
        NULL,    // we aren't using menus, NULL
        m_instance,    // application handle
        NULL);    // used with multiple windows, NULL

	
	
	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);

	//ShowCursor(false);

	return true;
}

void Engine::CloseWindow()
{
	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	UnregisterClass(m_appname, m_instance);
	m_instance = NULL;
}

bool Engine::Update()
{

	return true;
}

void Engine::Run()
{
	bool quit = false;
	MSG msg;

	ZeroMemory(&msg,sizeof(MSG));

	//Run the engine repeatedly until closed or error
	while(!quit)
	{
		if(PeekMessage(&msg, NULL, 0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if(msg.message == WM_QUIT)
		{
			quit = true;		
		}
		else
		{			
			if(!Update())
			{
				quit = true;
			}
		}
	}
}

void Engine::Exit()
{
	//close all components


	CloseWindow();

	return;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
    {
        // this message is read when the window is closed
        case WM_DESTROY:
            {
                // close the application entirely
                PostQuitMessage(0);
                return 0;
            } break;
    }

    // Handle any messages the switch statement didn't
    return DefWindowProc (hWnd, message, wParam, lParam);
}