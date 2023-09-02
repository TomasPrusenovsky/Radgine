#pragma once

namespace Rg
{
	class Scene
	{
	public:
		Scene(const char* name = "Default") { m_Name = name; }
		~Scene() {};

		virtual void OnUpdate() = 0;
		virtual void OnImGuiUpdate() = 0;

	private:
		const char* m_Name = nullptr;
	};
}