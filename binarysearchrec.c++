// binary search using recursion
#include <iostream>
using namespace std;
int binarysearch(int arr[], int key, int s, int e)
{
    int mid = (s+e)/2;
    if (s <=e)
    {
        if (key == arr[mid])
        {
            return mid+1;
        }
        else if (key > arr[mid])
        {
            return binarysearch(arr, key, mid + 1, e);
        }
        else
        {
            return binarysearch(arr, key, s, mid - 1);
        }
    }
        return -1;
}
int main()
{
    int arr[] = {2, 4, 6, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    cout << binarysearch(arr, key, 0, size - 1);
}