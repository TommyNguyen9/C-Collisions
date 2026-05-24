#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#define OLC_PGEX_TRANSFORMEDVIEW
#include "olcPGEX_TransformedView.h"

class CircleVsRect : public olc::PixelGameEngine
{
public:
	CircleVsRect()
	{
		sAppName = "Circle vs Rectangle";
	}

private:
	olc::TileTransformedView tv;


public:
	bool OnUserCreate() override
	{
		tv = olc::TileTransformedView({ ScreenWidth(), ScreenHeight() }, { 32, 32 });
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Clear world
		Clear(olc::VERY_DARK_BLUE);
		
		tv.DrawCircle({ 0, 0 }, 20.0f);

		return true;
	}
};

int main()
{
	CircleVsRect demo;
	if (demo.Construct(640, 480, 2, 2))
		demo.Start();
	return 0;

}