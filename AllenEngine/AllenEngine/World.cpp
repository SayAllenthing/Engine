#pragma once

#include "World.h"
#include <iostream>


World::World()
{
}

World::~World()
{
}

void World::Debug()
{
	//std::cout << "HELLO" << m_objects.size();
}

void World::ShutDown()
{
	while(!m_objects.empty())
	{
		m_objects.back() = NULL;
		delete m_objects.back();
		m_objects.pop_back();
	}
}

void World::Update()
{
	GameObject *temp;
	for(int i = 0; i < m_objects.size(); i++)
	{
		temp = m_objects[i];
		temp->Update();
	}
	temp = NULL;
}

std::string World::AddGameObject(GameObject &c)
{
	int i = 0;
	bool found = false;

	while(!found)
	{
		if(!hasObjectName(convertInt(m_objects.size()+i)))
			found = true;
		i++;
	}
	std::string s = "Object_" + convertInt(m_objects.size()+i);
	m_objects.push_back(&c);
	return s;
}

bool World::hasObjectName(std::string s )
{
	for(int i = 0; i < (int)m_objects.size(); i++)
	{
		if(m_objects[i]->GetInstanceName() == s)
			return true;
	}
	return false;
}

std::string World::convertInt(int number)
{
    if (number == 0)
        return "0";
    std::string temp;
    std::string returnvalue;
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}