#pragma once

#include <D3DX10math.h>
#include <vector>
#include "Transform.h"
#include "World.h"

class World;

class GameObject
{
public:
	std::string name;
	std::string tag;

	Transform *transform;

	GameObject *Parent;

	GameObject(World &w);
	~GameObject();

	GameObject GetChildByName(std::string);

	void AddChild(GameObject &c);
	void RemoveChild(GameObject &c);

	Component GetComponent(std::string);
	bool HasComponent(std::string);
	void AddComponent(Component &c);
	void RemoveComponent(std::string);
	
	std::string GetInstanceName();

	void Update();

private:	
	std::string m_instancename;
	std::vector<GameObject*> m_children;
	std::vector<Component*> m_components;
	
};
