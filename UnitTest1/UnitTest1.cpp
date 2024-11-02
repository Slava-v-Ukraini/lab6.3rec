#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.3rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayTests
{
    TEST_CLASS(ArrayTests)
    {
    public:

        TEST_METHOD(TestGenerateaay)
        {
            const int size = 20;
            int a[size];

            // �������� �����
            generateArray(a, size);

            // ����������, �� �������� � ����� �������� [-50, 50]
            for (int i = 0; i < size; i++) {
                Assert::IsTrue(a[i] >= -50 && a[i] <= 50);
            }
        }

        TEST_METHOD(TestMin)
        {
            const int size = 5;
            int a[size] = { 1, 20, -5, 15, 10 };
            int max = std::numeric_limits<int>::min();
            int imax = -1;

            // ��������� ������������ ������� � �����
            Min(a, size, max, imax, 0);

            // ����������, �� ������� ���������� �������� � ���� ������
            Assert::AreEqual(20, max);
            Assert::AreEqual(1, imax);
        }

        TEST_METHOD(TestSort)
        {
            const int size = 5;
            int a[size] = { 1, 20, -5, 15, 10 };

            // ������� �����
            Sort(a, size, 0);

            // ����������, �� ����� ������������ � ������� ��������
            for (int i = 0; i < size - 1; i++) {
                Assert::IsTrue(a[i] >= a[i + 1]);
            }
        }

        TEST_METHOD(TestGenerateaayTemplate)
        {
            const int size = 20;
            double a[size];

            // �������� ����� � ����� double
            generateArrayT(a, size);

            // ����������, �� �������� � ����� �������� [-50.0, 50.0]
            for (int i = 0; i < size; i++) {
                Assert::IsTrue(a[i] >= -50.0 && a[i] <= 50.0);
            }
        }

        TEST_METHOD(TestSortTemplate)
        {
            const int size = 5;
            double a[size] = { 1.1, 20.2, -5.5, 15.3, 10.4 };

            // ������� ����� � ����� double
            SortT(a, size, 0);

            // ����������, �� ����� ������������ � ������� ��������
            for (int i = 0; i < size - 1; i++) {
                Assert::IsTrue(a[i] >= a[i + 1]);
            }
        }
    };
}
