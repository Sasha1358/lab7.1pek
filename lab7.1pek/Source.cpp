#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>
using namespace std;

void Create(int** r, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    if (i == rowCount) {
        return;
    }

    r[i][j] = Low + rand() % (High - Low + 1);

    if (j == colCount - 1) {
        Create(r, rowCount, colCount, Low, High, i + 1, 0);
    }
    else {
        Create(r, rowCount, colCount, Low, High, i, j + 1);
    }
}

void Print(int** r, const int rowCount, const int colCount, int i, int j) {
    if (i == rowCount) {
        return;
    }

    cout << setw(4) << r[i][j];

    if (j == colCount - 1) {
        cout << endl;
        Print(r, rowCount, colCount, i + 1, 0);
    }
    else {
        Print(r, rowCount, colCount, i, j + 1);
    }
}

void Change(int** r, const int row1, const int row2, const int colCount, int j) {
    if (j == colCount) {
        return;
    }

    int tmp = r[row1][j];
    r[row1][j] = r[row2][j];
    r[row2][j] = tmp;

    Change(r, row1, row2, colCount, j + 1);
}

void Sort(int** r, const int rowCount, const int colCount, int i0, int i1) {
    if (i0 == rowCount - 1) {
        if (i1 < rowCount - i0 - 1) {
            Sort(r, rowCount, colCount, 0, 0);  // Якщо ми досягли кінця масиву за один прохід, скидаємо і продовжуємо наступний прохід.
        }
        return;
    }

    if (i1 < rowCount - i0 - 1) {
        if (r[i1][0] < r[i1 + 1][0] ||
            (r[i1][0] == r[i1 + 1][0] && r[i1][1] > r[i1 + 1][1]) ||
            (r[i1][0] == r[i1 + 1][0] && r[i1][1] == r[i1 + 1][1] && r[i1][3] < r[i1 + 1][3])) {
            Change(r, i1, i1 + 1, colCount, 0);
        }
        Sort(r, rowCount, colCount, i0, i1 + 1);
    }
    else {
        Sort(r, rowCount, colCount, i0 + 1, 0);  // Переходимо до наступного рядка (i0) і починаємо спочатку для i1.
    }
}

void Calc(int** r, const int rowCount, const int colCount, int& S, int& k, int i, int j) {
    if (i == rowCount) {
        return;
    }

    if (r[i][j] % 7 == 0 || (i % 2 != 0 || j % 2 != 0)) {
        S += r[i][j];
        k++;
        r[i][j] = 0;
    }

    if (j == colCount - 1) {
        Calc(r, rowCount, colCount, S, k, i + 1, 0);
    }
    else {
        Calc(r, rowCount, colCount, S, k, i, j + 1);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));
    int Low = 16;
    int High = 97;
    int rowCount = 8;
    int colCount = 6;
    int** r = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        r[i] = new int[colCount];
    }

    Create(r, rowCount, colCount, Low, High, 0, 0);
    cout << "Початковий масив:" << endl;
    Print(r, rowCount, colCount, 0, 0);
    Sort(r, rowCount, colCount, 0, 0);
    cout << "Відсортований масив:" << endl;
    Print(r, rowCount, colCount, 0, 0);
    int S = 0;
    int k = 0;
    Calc(r, rowCount, colCount, S, k, 0, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << "Масив після обчислень:" << endl;
    Print(r, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++) {
        delete[] r[i];
    }
    delete[] r;
    return 0;
}
