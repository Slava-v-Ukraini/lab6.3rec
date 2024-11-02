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

            // Генеруємо масив
            generateArray(a, size);

            // Перевіряємо, що значення в межах діапазону [-50, 50]
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

            // Знаходимо максимальний елемент у масиві
            Min(a, size, max, imax, 0);

            // Перевіряємо, що знайшли правильний максимум і його індекс
            Assert::AreEqual(20, max);
            Assert::AreEqual(1, imax);
        }

        TEST_METHOD(TestSort)
        {
            const int size = 5;
            int a[size] = { 1, 20, -5, 15, 10 };

            // Сортуємо масив
            Sort(a, size, 0);

            // Перевіряємо, що масив відсортований у порядку спадання
            for (int i = 0; i < size - 1; i++) {
                Assert::IsTrue(a[i] >= a[i + 1]);
            }
        }

        TEST_METHOD(TestGenerateaayTemplate)
        {
            const int size = 20;
            double a[size];

            // Генеруємо масив з типом double
            generateArrayT(a, size);

            // Перевіряємо, що значення в межах діапазону [-50.0, 50.0]
            for (int i = 0; i < size; i++) {
                Assert::IsTrue(a[i] >= -50.0 && a[i] <= 50.0);
            }
        }

        TEST_METHOD(TestSortTemplate)
        {
            const int size = 5;
            double a[size] = { 1.1, 20.2, -5.5, 15.3, 10.4 };

            // Сортуємо масив з типом double
            SortT(a, size, 0);

            // Перевіряємо, що масив відсортований у порядку спадання
            for (int i = 0; i < size - 1; i++) {
                Assert::IsTrue(a[i] >= a[i + 1]);
            }
        }
    };
}
