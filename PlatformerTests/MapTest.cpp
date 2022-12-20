#include "pch.h"
#include "CppUnitTest.h"
#include "../Platformer/src/Map.h"
#include "../Platformer/src/Map.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlatformerTests
{
	TEST_CLASS(MapTests)
	{
	public:
		Map* map1;
		Map* map2;
		Shape* shape1;
		Shape* shape2;
		Shape* shape3;

		MapTests() {
			shape1 = new Rectangle(0, 0, 0, 1, 1, 0, 0, 0);
			shape2 = new Rectangle(5, 5, 0, 5, 5, 0, 0, 0);
			shape3 = new Rectangle(2, 4, 0, 6, 3, 0, 0, 0);

			map1 = new Map(10, 10);
			map2 = new Map(10, 10, { shape1 });
		}

		~MapTests() {
			delete map1;
			delete map2;
			delete shape1;
			delete shape2;
			delete shape3;
		}
		TEST_METHOD(Constructor1)
		{
			Assert::AreEqual(10, (int) map1->getBarrier().size());
			Assert::AreEqual(10, (int) map1->getBarrier()[0].size());

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					Assert::IsFalse(map1->getBarrier()[i][j]);
				}
			}
		}

		TEST_METHOD(Constructor2)
		{
			Assert::AreEqual(10, (int) map2->getBarrier().size());
			Assert::AreEqual(10, (int) map2->getBarrier()[0].size());

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0) {
						Assert::IsTrue(map2->getBarrier()[i][j]);
					}
					else {
						Assert::IsFalse(map2->getBarrier()[i][j]);
					}
				}
			}
		}


		TEST_METHOD(AddShape)
		{
			map1->addShape(shape1);

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0) {
						Assert::IsTrue(map1->getBarrier()[i][j]);
					}
					else {
						Assert::IsFalse(map1->getBarrier()[i][j]);
					}
				}
			}

			map1->addShape(shape2);

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0) {
						Assert::IsTrue(map1->getBarrier()[i][j]);
					}
					else if (i >= 5 && j >= 5) {
						Assert::IsTrue(map1->getBarrier()[i][j]);
					}
					else {
						Assert::IsFalse(map1->getBarrier()[i][j]);
					}
				}
			}

			map1->addShape(shape3);

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0) {
						Assert::IsTrue(map1->getBarrier()[i][j]);
					}
					else if (i >= 5 && j >= 5) {
						Assert::IsTrue(map1->getBarrier()[i][j]);
					}
					else if (i >= 4 && i < 7 && j >= 2 && j < 8) {
						Assert::IsTrue(map1->getBarrier()[i][j]);
					}
					else {
						Assert::IsFalse(map1->getBarrier()[i][j]);
					}
				}
			}
		}

	};
}
