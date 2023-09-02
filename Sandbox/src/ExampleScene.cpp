#include "ExampleScene.h"

ExampleScene::ExampleScene():
	m_Shader(std::unique_ptr<Rg::Shader>(new Rg::Shader("Shaders/basic.vert", "Shaders/basic.frag"))),
	m_VertexArray(std::unique_ptr<Rg::VertexArray>(new Rg::VertexArray())),
	m_VertexBuffer(std::unique_ptr<Rg::VertexBuffer>(new Rg::VertexBuffer()))
{
}

ExampleScene::~ExampleScene()
{
}

void ExampleScene::OnUpdate()
{
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void ExampleScene::OnImGuiUpdate()
{
}
