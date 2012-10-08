#pragma once

#include <vector>
#include "GameObject.h"

class GameObject;

class World
{
public:
	World();
	~World();
	bool FindObjectByName(std::string s);
	std::string AddGameObject(GameObject &c);
	void Debug();
	void ShutDown();
	void Update();
private:
	std::vector<GameObject*> m_objects;
	std::string convertInt(int number);
	bool hasObjectName(std::string s);
};