#include <iostream>
#include <cmath>
using namespace std;
bool can_put(int arr[][9], int i, int j, int n, int num)
{
    for (int x = 0; x < n; x++)
    {
        if (arr[i][x] == num || arr[x][j] == num)
        {
            return false;
        }
    }
    int zn=sqrt(n);
    int p = (i / zn) * zn;
    int q = (j / zn) * zn;
    for (int k = p; k < p + sqrt(n); k++)
    {
        for (int l = q; l < q + sqrt(n); l++)
        {
            if (arr[k][l] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudokusol(int arr[][9], int i, int j, int n)
{
    if (i == n)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if (j == n)
    {
        return sudokusol(arr, i + 1, 0, n);
    }
    if (arr[i][j] != 0)
    {
        return sudokusol(arr, i, j + 1, n);
    }
    for (int num = 1; num <= n; num++)
    {
        if (can_put(arr, i, j , n, num))
        {
            arr[i][j] = num;
            bool fs = sudokusol(arr, i, j + 1, n);
            if (fs == true)
            {
                return true;
            }
        }
    }
    arr[i][j] = 0;
    return false;
}
int main()
{
    int arr[9][9] =
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    cout << sudokusol(arr, 0, 0, 9);
    return 0;
}
