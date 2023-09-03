#include "ExampleScene.h"

ExampleScene::ExampleScene():
	m_Shader(std::unique_ptr<Rg::Shader>(new Rg::Shader("Shaders/basic.vert", "Shaders/basic.frag"))),
	m_VertexArray(std::unique_ptr<Rg::VertexArray>(new Rg::VertexArray())),
	m_VertexBuffer(std::unique_ptr<Rg::VertexBuffer>(new Rg::VertexBuffer()))
{
	GLfloat vertices[] = {
		0.5f, 0.5f,
		-0.5f , -0.5f,
		0.5f, -0.5f
	};

	m_VertexBuffer->BufferData(sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	m_VertexArray->EnableAtrib(0, 3, GL_FLOAT, GL_FALSE, 0);
	m_VertexArray->LinkBuffer(0, *m_VertexBuffer, 0, 2 * sizeof(GLfloat));
}

ExampleScene::~ExampleScene()
{
}

void ExampleScene::OnUpdate()
{
	glViewport(0, 0, 800, 800);
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	m_Shader->Activate();
	m_VertexArray->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void ExampleScene::OnImGuiUpdate()
{
}
