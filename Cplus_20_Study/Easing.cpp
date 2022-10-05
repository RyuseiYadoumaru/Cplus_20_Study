#include "Easing.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>

using namespace myMath;

int main()
{
	float frame = 0;
	float totalFrame = 60;
	float min = 0;
	float max = 100;
	while (frame <= 60)
	{
		std::cout << frame << ":" << myMath::Easing::CubicIn(frame, totalFrame, min, max) << std::endl;
		frame++;
		std::this_thread::sleep_for(std::chrono::seconds(1/10));
	};

	//Vector2 re = myMath::Easing::Liner(1, 2, Vector2(1, 2), Vector2(3, 4));

	return 0;
}
