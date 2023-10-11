#include<iostream>
#include<string.h>
using namespace std;
char *mystrtok(char *str,char delim)
{
    static char* input=NULL;
    if(str!=NULL)
    {
        input=str;
    }
    if(input==NULL)
    {
        return NULL;
    }
    char *output=new char[strlen(input)+1];
    int i=0;
    while(input[i]!='\0')
    {
         if(input[i]!=delim)
         {
            output[i]=input[i];
            i++;
         }
         else
         {
              output[i]='\0';
              input=input+i+1;
              return output; 
         }
    }
    output[i]='\0';
    input=NULL;
    return output;
}
int main()
{
    char arr[100]="my name is,sanyam,goel";
    char*ptr=mystrtok(arr,',');
    cout<<ptr<<endl;
    while(ptr!=NULL)
    {
        ptr=mystrtok(NULL,',');
        cout<<ptr<<endl;
    }
    return 0;

}