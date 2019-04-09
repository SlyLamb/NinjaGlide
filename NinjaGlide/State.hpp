#pragma once

namespace NinjaGlide
{
	enum EState
	{
		MENU = 0,
		GAME = 1,
		SCORE = 2
	};

	class IState
	{
	public:
		IState() {}
		virtual ~IState() {}

		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Input() = 0;
		virtual void Draw(float dt) = 0;
	};

}