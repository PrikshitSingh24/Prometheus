#pragma once
#include <memory>
#ifdef PT_PLATFORM_WINDOWS
	#ifdef PT_BUILD_DLL
		#define  __declspec(dllexport)
	#else
		#define  __declspec(dllimport)
	#endif
#else
	#error Prometheus only supports Windows!
#endif


#ifdef PT_ENABLE_ASSERTS
	#define PT_ASSERT(x,...) {if(!(x)){PT_ERROR("Assertion failed:{0}",__VA_ARGS__); __debugbreak();}}
	#define PT_CORE_ASSERT(x,...) {if(!(x)){PT_CORE_ERROR("Assertion failed:{0}",__VA_ARGS__); __debugbreak();}}
#else
	#define PT_ASSERT(x,...)
	#define PT_CORE_ASSERT(x,...)
#endif // PT_ENABLE_ASSERTS



#define BIT(x) (1<<x)

#define PT_BIND_EVENT(fn) std::bind(&fn,this,std::placeholders::_1)

namespace Prometheus{
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T,typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ...args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
