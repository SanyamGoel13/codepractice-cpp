#include <iostream>
using namespace std;
int main()
{
    long long int testcase, i,l;
    long long int total;
    long long int j, k, number;

    cin >> testcase;
    for (i = 1; i <= testcase; i++)
    {
        total = 0;
        cin >> number;
        long long int health[number];
        long long int spell[number];
        for (j = 0; j < number; j++)
        {
            cin >> health[j];
            total = total + health[j];
        }
        for (j = 0; j < number; j++)
        {
            cin >> spell[j];
            total = total + spell[j];
        }
        l=spell[0];
        for (j = 0; j < number; j++)
        {
            if(l<spell[j])
            {
                l=spell[j];
            }
        }
        total=total-l;
        cout<<total<<endl;
    }
}