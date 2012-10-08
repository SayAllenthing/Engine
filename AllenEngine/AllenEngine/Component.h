#pragma once

#include <string>

class Component
{
public:
	virtual std::string GetType();
	virtual void Update();
protected:
	std::string m_type;

};