#include "rpch.h"
#include "Scenes.h"

namespace Rg
{
	Scenes::Scenes()
	{

	}

	Scenes::~Scenes()
	{

	}

	void Scenes::UpdateCurrent()
	{	
		m_CurrentScene->OnUpdate();
	}

	void Scenes::PushScene(Scene* scene)
	{
		m_Scenes.push_back(scene);
	}
}