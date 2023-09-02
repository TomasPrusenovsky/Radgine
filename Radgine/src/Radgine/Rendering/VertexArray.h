#pragma once
#include "glad/glad.h"
#include "VertexBuffer.h"

namespace Rg
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind();
		void Unbind();
		void EnableAtrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLuint relativeOffset);
		void LinkBuffer(GLuint bindingindex, VertexBuffer buffer, GLintptr offest, GLsizei stride);
		inline GLuint ID() const { return m_ID; }

	private:
		GLuint m_ID = 0;
	};
}

