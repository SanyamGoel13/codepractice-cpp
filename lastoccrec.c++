// last occurence of key in array using recursion and linear search
#include <iostream>
using namespace std;
int lastocc(int *arr, int key, int size)
{

    int ans = 0;
    if (size == 0)
    {
        return -1;
    }
    ans = lastocc(arr + 1, key, size - 1) + 1;
    if (ans == 0)
    {
        if (arr[0] == key)
        {
            ans = 0;
        }
        else
        {
            return -1;
        }
    }

    return ans;
}
int main()
{
    int arr[] = {5, 4, 5, 7, 5, 3, 7, 8, 5, 9};
    int size = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    cout << lastocc(arr, key, size);
}