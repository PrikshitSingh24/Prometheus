#pragma once
#include "Prometheus/Renderer/OrthographicCamera.h"
#include "Texture.h"
namespace Prometheus {

	class Renderer2D
	{
	public:
		static void Init();
		static void End();
		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		//Primitives
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture);

	};
}