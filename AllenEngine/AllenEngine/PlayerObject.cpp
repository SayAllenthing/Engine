#pragma once
#include "PlayerObject.h"

PlayerObject::PlayerObject(World &w) 
	: GameObject(w)
{
	MeshRenderer *m = new MeshRenderer();
	AddComponent(*m);

	meshRenderer = m;
}