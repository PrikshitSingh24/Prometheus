#pragma once
#include "Prometheus/Events/Event.h"
#include "Prometheus/Core/Core.h"
#include <Prometheus/Core/Timestep.h>

namespace Prometheus {

	class  Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate(Timestep ts) {};
		virtual void OnImGuiRender() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string& GetName() { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}