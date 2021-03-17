#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.4(1)/Subtraction_Comparison_Norm.cpp"
#include "../Lab_2.4(1)/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab241
{
	TEST_CLASS(UnitTestLab241)
	{
	public:
		
		TEST_METHOD(Test_Calculation_Norm_Matrices)
		{
			Matrix A(2);
			A[0][0] = 5; A[0][1] = 4;
			A[1][0] = 8; A[1][1] = 4;

			Assert::AreEqual(A.Calculation_Norm_Matrices(), 11.0);
		}
	};
}
