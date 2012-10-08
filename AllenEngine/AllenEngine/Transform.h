#pragma once

#include <d3dX10Math.h>
#include "Component.h"

class Transform : public Component
{
public:
	D3DXVECTOR3 Position;
	D3DXVECTOR3 Rotation;
	D3DXVECTOR3 Scale;

	Transform();
	~Transform();

	void SetPosition(D3DXVECTOR3 v);
	void SetRotation(D3DXVECTOR3 v);
	void SetScale(D3DXVECTOR3 v);
};