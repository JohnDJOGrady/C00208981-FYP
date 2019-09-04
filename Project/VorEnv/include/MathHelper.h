#ifndef MATH_HELPER_H
#define MATH_HELPER_H

#include <SFML\Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define PI 3.14159265358979323846

namespace sf
{
	inline float Magnitude(Vector2f &vec)
	{
		return sqrtf((vec.x * vec.x) + (vec.y * vec.y));
	}

	inline Vector2f Normalize(Vector2f &vec)
	{
		return vec / Magnitude(vec);
	}

	inline float Distance(Vector2f &vec1, Vector2f &vec2)
	{
		return sqrtf(powf(vec2.x - vec1.x, 2) + powf(vec2.y - vec1.y, 2));
	}

	inline float Dot(Vector2f &a, Vector2f &b)
	{
		return a.x * b.x + a.y + b.y;
	}

	inline float DegreesToRadians(float angle)
	{
		return angle * (PI / 180.0f);
	}

	inline float RadiansToDegrees(float angle)
	{
		return angle * (180.0f / PI);
	}

	inline float RandomFloat(float min, float max)
	{
		return ((float(rand()) / float(RAND_MAX)) * (max - min)) + min;
	}
	inline int RandomInteger(int min, int max)

	{
		return rand() % (max - min + 1) + min;
	}
}
#endif // !MATH_HELPER_H
