#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.1pek/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71pek
{
    TEST_CLASS(UnitTest71pek)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int rowCount = 3;
            const int colCount = 4;
            int** r = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                r[i] = new int[colCount];
            }

            r[0][0] = 3; r[0][1] = 5; r[0][2] = 1; r[0][3] = 9;
            r[1][0] = 2; r[1][1] = 5; r[1][2] = 7; r[1][3] = 6;
            r[2][0] = 4; r[2][1] = 5; r[2][2] = 3; r[2][3] = 8;

            int S = 0;
            int k = 0;
            Calc(r, rowCount, colCount, S, k, 0, 0);

            Assert::AreEqual(47, S);
            Assert::AreEqual(8, k);

        }
    };
}
