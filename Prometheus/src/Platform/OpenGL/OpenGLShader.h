#pragma once
#include "Prometheus/Renderer/Shader.h"
#include <string>
#include <glm/glm.hpp>

typedef unsigned int GLenum;

namespace Prometheus {

	class OpenGLShader: public Shader
	{
	public:
		OpenGLShader(const std::string& filepath);
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();
		void Bind() const override;
		void Unbind() const override;

		void UploadUniformInt(const std::string& name,int values);
		void UploadUniformFloat(const std::string& name,float values);
		void UploadUniformFloat2(const std::string& name, const glm::vec2& values);
		void UploadUniformFloat3(const std::string& name, const glm::vec3& values);
		void UploadUniformFloat4(const std::string& name, const glm::vec4& values);
		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum,std::string> Preprocess(const std::string& source);
		void Compile(std::unordered_map<GLenum, std::string>& shaderSources);
	private:
		uint32_t m_RendererID;
	};
}