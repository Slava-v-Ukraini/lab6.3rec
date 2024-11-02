#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>
using namespace std;

// Функція без шаблону для генерації масиву
void generateArray(int a[], int size, int index = 0) {
    if (index == size) return;
    a[index] = rand() % 101 - 50; // від -50 до 50
    generateArray(a, size, index + 1);
}

// Функція без шаблону для пошуку максимального значення 
void Min(int* a, const int size, int& max, int& imax, int j)
{
    if (max < a[j])
    {
        max = a[j];
        imax = j;
    }
    if (j < size - 1)
        Min(a, size, max, imax, j + 1);
}

// Функція без шаблону для сортування за спаданням
void Sort(int* a, const int size, int i) {
    int max = a[i];
    int imax = i;
    Min(a, size, max, imax, i + 1);
    a[imax] = a[i];
    a[i] = max;

    if (i < size - 2)
        Sort(a, size, i + 1);
}

// Функція без шаблону для виведення масиву
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// Шаблонні функції

template <typename T>
void generateArrayT(T a[], int size, int i = 0) {
    if (i == size) return;
    a[i] = rand() % 101 - 50;
    generateArrayT(a, size, i + 1);
}

template <typename T>
void MinT(T* a, const int size, T& max, int& imax, int j)
{
    if (max < a[j])
    {
        max = a[j];
        imax = j;
    }
    if (j < size - 1)
        MinT(a, size, max, imax, j + 1);
}

template <typename T>
void SortT(T* a, const int size, int i) {
    T max = a[i];
    int imax = i;
    MinT(a, size, max, imax, i + 1);
    a[imax] = a[i];
    a[i] = max;

    if (i < size - 2)
        SortT(a, size, i + 1);
}

template <typename T>
void PrintT(T* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        PrintT(a, size, i + 1);
    else
        cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 20;
    int a[n];
    generateArray(a, n, 0);
    Print(a, n, 0);
    Sort(a, n, 0);
    Print(a, n, 0);

    // Демонстрація роботи шаблонних функцій
    cout << endl << "Templates:" << endl;
    double b[n];
    generateArrayT(b, n, 0);
    PrintT(b, n, 0);
    SortT(b, n, 0);
    PrintT(b, n, 0);

    return 0;
}
