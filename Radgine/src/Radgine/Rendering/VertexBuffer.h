#pragma once
#include "glad/glad.h"

namespace Rg
{
	class VertexBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		void BufferData(GLsizeiptr size, const void* data, GLenum usage);

		inline GLuint ID() const { return m_ID; }

	private:
		GLuint m_ID = 0;
	};
}
