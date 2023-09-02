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
		void SetCurrentScene(size_t scene);

	private:
		Scene* m_CurrentScene = nullptr;
		size_t m_ScenesCount = 0;
		std::vector<Scene*> m_Scenes;
	};
}