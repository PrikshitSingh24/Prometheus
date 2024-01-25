#pragma once
#include "RenderCommand.h"
#include "Prometheus/Renderer/OrthographicCamera.h"
#include "Prometheus/Renderer/Shader.h"

namespace Prometheus {
	

	class Renderer {
	public:
		static void Init();
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();
		static void OnWindowResize(uint32_t width, uint32_t height);
		static void Submit(const Ref<Shader>& shader,const Ref<VertexArray>& vertexArray,const glm::mat4& transform=glm::mat4 (1.0f));

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;

	};
}