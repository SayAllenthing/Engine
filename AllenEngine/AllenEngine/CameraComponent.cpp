#pragma once
#include "CameraComponent.h"

CameraComponent::CameraComponent()
{
	m_type = "Camera";
	Near = 0.001;
	Far = 1000;
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::setPlanes(float n, float f)
{
	Near = n;
	Far = f;
}

void CameraComponent::Update()
{

}

