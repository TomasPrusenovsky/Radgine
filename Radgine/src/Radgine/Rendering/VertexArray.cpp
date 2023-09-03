#include "rpch.h"
#include "VertexArray.h"

namespace Rg
{
	VertexArray::VertexArray()
	{
		glCreateVertexArrays(1, &m_ID);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_ID);

	}

	void VertexArray::LinkBuffer(GLuint bindingindex, VertexBuffer buffer, GLintptr offest, GLsizei stride)
	{
		glVertexArrayVertexBuffer(m_ID, bindingindex, buffer.ID(), offest, stride);
	}

	void VertexArray::EnableAtrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLuint relativeOffset)
	{
		glEnableVertexArrayAttrib(m_ID, index);
		glVertexArrayAttribBinding(m_ID, index, 0);
		glVertexArrayAttribFormat(m_ID, index, size, type, normalized, relativeOffset);
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(m_ID);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}
}