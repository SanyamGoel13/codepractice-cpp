#include<stdio.h>
void main()
{
    char s[10]={'S','A','N','Y','A','M','\0'};
    int i,j;
    puts(s);
    for(i=0;i<=7;i++)
    {
        printf("%c",s[i]);
    }
    printf("hello");
}