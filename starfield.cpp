#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


class StarField : public olc::PixelGameEngine
{
public:
	StarField()
	{
		sAppName = "StarField";
	}

	int nStars = 1000;

	struct Star {
		float fAngle = 0.0f;
		float fDistance = 0.0f;
		float fSpeed = 0.0f;
		olc::Pixel color = olc::WHITE;
	};
	std::vector<Star> vStars;
	olc::vf2d vOrigin;

public:
	float Random(float a, float b){
		return (b-a) * (float(rand() / float(RAND_MAX))) + a;
	}

	#define randomRGBNumber Random(0.3f, 1.0f)

	bool OnUserCreate() override
	{
		vStars.resize(nStars);
		for(auto& star : vStars){
			star.fAngle = Random(0.0f, 2.0f * 3.1459f);
			star.fSpeed = Random(10.0f, 100.0f);
			star.fDistance = Random(20.0f, 200.0f);
			float randomNumber = Random(0.3f, 1.0f);
			star.color = olc::PixelF(randomNumber, randomNumber, randomNumber); // use randomRGBNumber instead of randomNumber to make it colorfull ;)
		}

		vOrigin = { float(ScreenWidth() / 2), static_cast<float>(ScreenHeight()) / 2 };

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLANK);

		for(auto& star : vStars)
		{
			star.fDistance += star.fSpeed * fElapsedTime * (star.fDistance / 100.0f);
			if(star.fDistance > 1000.0f){
				star.fAngle = Random(0.0f, 2.0f * 3.1459f);
				star.fSpeed = Random(10.0f, 100.0f);
				star.fDistance = Random(1.0f, 100.0f);
				float randomNumber = Random(0.3f, 1.0f);
				star.color = olc::PixelF(randomNumber, randomNumber, randomNumber); // use randomRGBNumber instead of randomNumber to make it colorfull ;)
			}
			Draw(olc::vf2d(cos(star.fAngle), sin(star.fAngle)) * star.fDistance + vOrigin, star.color * (star.fDistance / 100.0f));
		}
		return true;
	}
};

int main()
{
	StarField scene;
	if (scene.Construct(256, 240, 3, 3))
		scene.Start();

	return 0;
}
