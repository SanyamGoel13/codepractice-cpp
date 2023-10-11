#include <iostream>
using namespace std;
int binary_search(int arr[7], int n, int key)
{
    if (arr[n / 2] == key)
    {
        int i;
        i= n / 2;
        i++;
        return i;
    }
    else if (arr[n / 2] > key)
    {
        binary_search(arr, n / 2, key);
    }
    else
    {
        int j = (n + n / 2);
        binary_search(arr, j, key);
    }
}
int main()
{
    int i;
    int arr[7];
    int n = 7;
    int key, ans;
    cin >> key;
    for (i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }
    ans = binary_search(arr, n, key);
    cout << ans;
}