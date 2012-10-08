#include "Transform.h"

Transform::Transform()
{
	m_type = "Transform";

	Position.x = 0;
	Position.y = 0;
	Position.z = 0;

	Rotation.x = 0;
	Rotation.y = 0;
	Rotation.z = 0;
	
	Scale.x = 1;
	Scale.y = 1;
	Scale.z = 1;
}

Transform::~Transform()
{
}

void Transform::SetPosition(D3DXVECTOR3 v) {Position = v;}
void Transform::SetRotation(D3DXVECTOR3 v) {Rotation = v;}
void Transform::SetScale(D3DXVECTOR3 v) {Scale = v;}