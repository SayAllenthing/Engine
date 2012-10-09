#pragma once

#include "Component.h"

class MeshRenderer : public Component //Need to create a mesh component, will do after D3D is implemented
{
public:
	MeshRenderer();
	~MeshRenderer();

	virtual void Update();
	void Draw();
};