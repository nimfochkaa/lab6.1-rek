#include "pch.h"
#include "CppUnitTest.h"
#include "../6.1 рек/6.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My61
{
	TEST_CLASS(My61)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 5;
			int b[size];
			int Low = -40;
			int High = 50;

			Create(b, size, Low, High, 0);

			for (int i = 0; i < size; i++) {
				Assert::IsTrue(b[i] >= Low && b[i] <= High); 
			}
		}
	};
}
