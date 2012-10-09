#pragma once

#include <string>
//#include "GameObject.h"

//class GameObject;

class Component
{
public:
	virtual std::string GetType();
	virtual void Update();
	//virtual void setParent(GameObject &g);
protected:
	std::string m_type;
	//GameObject *m_parent;
};