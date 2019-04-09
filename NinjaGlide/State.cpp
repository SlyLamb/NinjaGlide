#include <iostream>
#include "State.hpp"

using namespace std;

namespace NinjaGlide
{
	class Menu : public IState
	{
	public:
		Menu() {}
		~Menu() {}

		void Init() {}
		void Update() {}
		void Input() {}
		void Draw(float dt) {}
	};

	class Game : public IState
	{
		Game() {}
		~Game() {}

		void Init() {}
		void Update() {}
		void Input() {}
		void Draw(float dt) {}
	};

	class Score : public IState
	{
		Score() {}
		~Score() {}

		void Init() {}
		void Update() {}
		void Input() {}
		void Draw(float dt) {}
	};
}