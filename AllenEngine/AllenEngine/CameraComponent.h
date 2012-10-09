#pragma once

#include "Component.h"

class CameraComponent : public Component //Not entirely sure what I'm going to do for implementation yet
{
public:
	CameraComponent();
	~CameraComponent();
	void setPlanes(float, float);
	virtual void Update();

	float Near;
	float Far;
};