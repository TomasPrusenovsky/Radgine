#include "rpch.h"
#include "VertexBuffer.h"

namespace Rg
{
	VertexBuffer::VertexBuffer()
	{
		glCreateBuffers(1, &m_ID);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

	void VertexBuffer::BufferData(GLsizeiptr size, const void* data, GLenum usage)
	{
		glNamedBufferData(m_ID, size, data, usage);
	}
}