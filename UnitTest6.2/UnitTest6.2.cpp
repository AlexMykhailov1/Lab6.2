#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.2/Lab6.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62
{
	TEST_CLASS(UnitTest62)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[10] = { 0,-1,-2,-3,-4,-5,6,7,8,9 }, CreateIter = 0, PrintIter = 0;

			SortIter(a, 10);

			Assert::AreEqual(CreateIter, 0);
			Assert::AreEqual(PrintIter, 0);
			Assert::AreEqual(a[0], 9);
			Assert::AreEqual(a[9], -5);
		}
	};
}
