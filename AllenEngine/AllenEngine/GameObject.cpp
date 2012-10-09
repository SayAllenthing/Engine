#include "GameObject.h"
#include <vector>
//#include "World.h"

GameObject::GameObject(World &w)
{
	Parent = NULL;
	name = "none";
	tag = "none";

	//GameObject *temp = this;
	m_instancename = w.AddGameObject(*this);	

	transform = new Transform();
	AddComponent(*transform);

	meshRenderer = NULL;
	cameraComponent = NULL;
}

GameObject::~GameObject()
{	
	while(!m_components.empty())
	{
		m_components.back() = NULL;
		delete m_components.back();
		m_components.pop_back();
	}
}

std::string GameObject::GetInstanceName()
{
	return m_instancename;
}

void GameObject::Update()
{
	Component *temp;
	for (int i = 0; i < (int) m_components.size(); i++)
	{
		temp = m_components[i];
		m_components[i]->Update();
	}
	temp = NULL;
}

void GameObject::AddComponent(Component &c)
{
	if(!HasComponent(c.GetType()))
	{
		m_components.push_back(&c);
		//c.setParent(*this);
	}
}

void GameObject::AddChild(GameObject &c)
{
	if(c.Parent == NULL)
	{
		m_children.push_back(&c);
		c.Parent = this;
	}
	else if(c.Parent->GetInstanceName() != GetInstanceName())//so it doesn't add the same child twice
	{
		m_children.push_back(&c);
		c.Parent = this;
	}
}

void GameObject::RemoveChild(GameObject &c)
{
	GameObject *temp;
	for (int i = 0; i < (int) m_children.size(); i++)
	{
		temp = m_children[i];
		if(temp->GetInstanceName() == c.GetInstanceName())
		{
			//temp = NULL;
			m_children.erase(m_children.begin()+i, m_children.begin()+i+1);
			delete temp;			
			return;
		}
	}
}

bool GameObject::HasComponent(std::string s)
{
	Component *temp;
	for (int i = 0; i < (int)m_components.size(); i++)
	{
		temp = m_components[i];
		if(temp->GetType() == s)
		{
			temp = NULL;
			delete temp;
			return true;
		}
	}
	temp = NULL;
	delete temp;
	return false;
}

void GameObject::RemoveComponent(std::string s)
{
	
	Component *temp;
	for (int i = 0; i < (int)m_components.size(); i++)
	{
		temp = m_components[i];
		if(temp->GetType() == s)
		{
			//temp = NULL;
			m_components.erase(m_components.begin()+i, m_components.begin()+i+1);
			delete temp;
			
			return;
		}
	}
}
