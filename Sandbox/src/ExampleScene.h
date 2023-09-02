#pragma once
#include "Radgine.h"

class ExampleScene : public Rg::Scene
{
public:
	ExampleScene();
	~ExampleScene();

	void OnUpdate();
	void OnImGuiUpdate();

private:
	std::unique_ptr<Rg::Shader> m_Shader;
	std::unique_ptr<Rg::VertexArray> m_VertexArray;
	std::unique_ptr<Rg::VertexBuffer> m_VertexBuffer;
};

