#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08.1.rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rek
{
	TEST_CLASS(UnitTest81rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			const int arraySize = 101;
			char str[arraySize]{ "one+two+min-e=" };

			int pCount = countSymbolsMinus(str);

			Assert::AreEqual(pCount, 1);

		}
	};
}
