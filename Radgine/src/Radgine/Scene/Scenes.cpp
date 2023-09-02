#include "rpch.h"
#include "Scenes.h"

namespace Rg
{
	Scenes::Scenes()
	{

	}

	Scenes::~Scenes()
	{
		for (Scene* scene : m_Scenes)
			delete scene;
	}

	void Scenes::UpdateCurrent()
	{	
		m_CurrentScene->OnUpdate();
	}

	void Scenes::PushScene(Scene* scene)
	{
		m_Scenes.push_back(scene);
		m_CurrentScene = m_Scenes[0];
	}
}