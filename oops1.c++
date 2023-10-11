#include<iostream>
#include<cstring>
using namespace std;
class student
{
    private:
    char name[100];
    public:
    int year;
    int rollno;
    void getname()
    {
        cin.getline(name,100);
    }
    char* returnname()
    {
        return name;
    }
};
int main()
{
    student sanyam;
    sanyam.getname();
    char *ch=sanyam.returnname();
    sanyam.year=2;
    sanyam.rollno=110;
    cout<<sanyam.rollno<<" "<<sanyam.year<<endl;
    int i;
    for(i=0;ch[i]!='\0';i++)
    {
        cout<<ch[i];
    }
}