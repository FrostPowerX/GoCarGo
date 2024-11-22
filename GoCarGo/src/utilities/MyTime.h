#pragma once

#include <time.h>

#include "base/Singleton.h"

#define GETTER_SETTER(type, field) inline type Get##field() { return (field);}; \
				inline void Set##field(type Var) { (field) = Var;};

namespace game
{
	class MyTime : public Singleton<MyTime>
	{
	private:

		static float deltaTime;

		float startTime;
		float endTime;

	public:

		MyTime();

		void Start();

		void Stop();

		GETTER_SETTER(float, deltaTime);

	};
}

