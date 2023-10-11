#include <stdio.h>
int main()
{
    int i, j, number, flag = 0;
    scanf("%d", &number);
    for (i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            printf("number is not prime");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("number is prime");
    }
    return 0;
}