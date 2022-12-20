#include "pch.h"
#include "CppUnitTest.h"
#include "../Platformer/src/Player.h"
#include "../Platformer/src/Player.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlatformerTests
{
	TEST_CLASS(PlayerTests)
	{
	public:

		TEST_METHOD(ConstructorTest)
		{
			Player* p = new Player(123, 432, 3, 2.3, 0.5, 4.2, NULL, NULL);
			Assert::AreEqual(123.0, p->getXPosition());
			Assert::AreEqual(432.0, p->getYPosition());
			Assert::AreEqual(3.0, p->getXVelocity());
			Assert::AreEqual(2.3, p->getYVelocity());
			
		}
	};
}
