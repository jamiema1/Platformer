#include "pch.h"
#include "CppUnitTest.h"
#include "../Platformer/src/Shape.h"
#include "../Platformer/src/Shape.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlatformerTests
{
	TEST_CLASS(ShapeTest)
	{
	public:

		TEST_METHOD(RectangleTest)
		{

			Rectangle* r = new Rectangle(0, 0, 0, 50, 50, 0, 0, 0);
			r->setArea();
			std::vector<std::pair<int, int>> area1 = r->getArea();

			Assert::AreEqual(50 * 50, (int) area1.size());

			for (int i = 0; i < 50; i++) {
				for (int j = 0; j < 50; j++) {
					Assert::IsTrue(std::find(area1.begin(), area1.end(), std::make_pair(j, i)) != area1.end());
				}
			}

			delete r;
		}
	};
}
