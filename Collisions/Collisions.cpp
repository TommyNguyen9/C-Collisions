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

	struct sWorldObject
	{
		olc::vf2d vPos;
		olc::vf2d vVel;
		float fRadius = 0.5f;
	};

	sWorldObject object;

	std::string sWorldMap = 
		"################################"
		"#..............................#"
		"#.......#####.#.....#####......#"
		"#.......#...#.#.....#..........#"
		"#.......#...#.#.....#..........#"
		"#.......#####.#####.#####......#"
		"#..............................#"
		"#.....#####.#####.#####..##....#"
		"#.........#.#...#.....#.#.#....#"
		"#.....#####.#...#.#####...#....#"
		"#.....#.....#...#.#.......#....#"
		"#.....#####.#####.#####.#####..#"
		"#..............................#"
		"#..............................#"
		"#..#.#..........#....#.........#"
		"#..#.#..........#....#.........#"
		"#..#.#.......#####.#######.....#"
		"#..#.#..........#....#.........#"
		"#..#.#.............###.#.#.....#"
		"#..#.##########................#"
		"#..#..........#....#.#.#.#.....#"
		"#..#.####.###.#................#"
		"#..#.#......#.#................#"
		"#..#.#.####.#.#....###..###....#"
		"#..#.#......#.#....#......#....#"
		"#..#.########.#....#......#....#"
		"#..#..........#....#......#....#"
		"#..############....#......#....#"
		"#..................########....#"
		"#..............................#"
		"#..............................#"
		"################################";

	olc::vi2d vWorldSize = { 32, 32 };


public:
	bool OnUserCreate() override
	{
		tv = olc::TileTransformedView({ ScreenWidth(), ScreenHeight() }, { 32, 32 });
		object.vPos = { 3.0f, 3.0f };
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Pan & Zoom:
		if (GetMouse(2).bPressed) tv.StartPan(GetMousePos());
		if (GetMouse(2).bHeld) tv.UpdatePan(GetMousePos());
		if (GetMouse(2).bReleased) tv.EndPan(GetMousePos());
		if (GetMouseWheel() > 0) tv.ZoomAtScreenPos(2.0f, GetMousePos());
		if (GetMouseWheel() < 0) tv.ZoomAtScreenPos(0.5f, GetMousePos());

		// Clear world
		Clear(olc::VERY_DARK_BLUE);
		
		// Draw world:
		olc::vi2d vTL = tv.GetTopLeftTile().max({ 0, 0 });
		olc::vi2d vBR = tv.GetBottomRightTile().min(vWorldSize);
		olc::vi2d vTile;
		for (vTile.y = vTL.y; vTile.y < vBR.y; vTile.y++)
			for (vTile.x = vTL.x; vTile.x < vBR.x; vTile.x++)
			{
				if (sWorldMap[vTile.y * vWorldSize.x + vTile.x] == '#')
				{
					tv.DrawRect(vTile, { 1.0f, 1.0f }, olc::WHITE);
					tv.DrawLine(vTile, vTile + olc::vf2d(1.0f, 1.0f), olc::WHITE); // Drawing diagonals
					tv.DrawLine(vTile + olc::vf2d(0.0f, 1.0f), vTile + olc::vf2d(1.0f, 0.0f), olc::WHITE);
				}
			}


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