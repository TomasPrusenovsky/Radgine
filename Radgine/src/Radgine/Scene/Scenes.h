#pragma once
#include "rpch.h"
#include "Scene.h"

namespace Rg
{
	class Scenes
	{
	public:
		Scenes();
		~Scenes();

		void UpdateCurrent();
		void PushScene(Scene* scene);

	private:
		Scene* m_CurrentScene = nullptr;
		std::vector<Scene*> m_Scenes;
	};
}


