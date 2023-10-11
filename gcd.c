#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,number1,number2,gcd=1;
    scanf("%d %d",&number1,&number2);
    for(i=2;i <= number1 && i <= number2;i++)
    {
        if(number1%i==0&&number2%i==0)
        {
            gcd=i;
        }
    }
    printf("%d",gcd);
}