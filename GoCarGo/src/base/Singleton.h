#pragma once

#include <memory>
#include <mutex>

template <typename T>

class Singleton
{
protected:

	Singleton() = default;
	virtual ~Singleton() = default;

public:

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T& Instance();

};

template<typename T>
inline T& Singleton<T>::Instance()
{
	static std::unique_ptr<T> instance;

	static std::once_flag flag;

	std::call_once(flag, []() { instance = std::make_unique<T>(); });

	return *instance;
}
