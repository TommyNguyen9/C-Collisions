#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class CircleVsRect : public olc::PixelGameEngine
{
public:
	CircleVsRect()
	{
		sAppName = "Circle vs Rectangle";
	}
private:


public:
	bool OnUserCreate() override
	{

	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		return true;
	}
};