#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* b, const int size, const int Low, const int High, int i) {
    b[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(b, size, Low, High, i + 1);
}

void Print(int* b, const int size, int i) {
    cout << setw(4) << b[i];
    if (i < size - 1)
        Print(b, size, i + 1);
    else
        cout << endl;
}

int Count(int* b, const int size, int i, int count) {
    if (i == size)
        return count;
    if (!(b[i] > 0 && b[i] % 5 == 0)) {
        count++;
    }
    return Count(b, size, i + 1, count);
}

int Sum(int* b, const int size, int i, int totalSum) {
    if (i == size)
        return totalSum;
    if (!(b[i] > 0 && b[i] % 5 == 0)) {
        totalSum += b[i];
    }
    return Sum(b, size, i + 1, totalSum);
}

void ReplaceWithZeros(int* b, const int size, int i) {
    if (i == size)
        return;
    if (!(b[i] > 0 && b[i] % 5 == 0)) {
        b[i] = 0;
    }
    ReplaceWithZeros(b, size, i + 1);
}

int main() {
    srand((unsigned)time(NULL));

    const int n = 22;
    int b[n];
    int Low = -40;
    int High = 50;

    Create(b, n, Low, High, 0);
    cout << "Original array: ";
    Print(b, n, 0);

    int count = Count(b, n, 0, 0);
    int totalSum = Sum(b, n, 0, 0);

    ReplaceWithZeros(b, n, 0);

    cout << "Number of elements meeting the criteria: " << count << endl;
    cout << "Sum of these elements: " << totalSum << endl;

    cout << "Modified array: ";
    Print(b, n, 0);

    return 0;
}
