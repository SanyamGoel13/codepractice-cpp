#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int i, j, small, n, k;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (i = 0; i < n; i++)
    {
        small = arr[0];
        k=0;
        for (j = 0; j < n; j++)
        {
            if (small > arr[j])
            {
                small = arr[j];
                k = j;
            }
        }
        arr[k] = INT_MAX;
        cout << ++k;
    }
}