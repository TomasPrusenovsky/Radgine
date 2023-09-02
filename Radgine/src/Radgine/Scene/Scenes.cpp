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

	void Scenes::SetCurrentScene(size_t sceneIndex)
	{
		if (sceneIndex > m_ScenesCount)
		{
			std::cerr << "Scene index is outside of the boundary!" << std::endl;
			return;
		}

		m_CurrentScene = m_Scenes[sceneIndex];
	}

	void Scenes::PushScene(Scene* scene)
	{
		m_Scenes.push_back(scene);
	}
}