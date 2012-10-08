#pragma once

#include "Graphics.h"

Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

bool Graphics::Init(int width, int height, HWND hwnd)
{
	return true;
}

void Graphics::Shutdown()
{

}

bool Graphics::Update()
{
	if(!Draw())
		return false;

	return false;
}

bool Graphics::Draw()
{
	return true;
}
