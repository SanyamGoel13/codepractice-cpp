#include<iostream>
using namespace std;
int main()
{

        string n;
	    cin>>n;
	    int l;
	    for(l=0;n[l]!='\0';l++);
        //cout<<l<<endl;
	    int i=n[l-2]-'0';
        //cout<<i<<endl;
	    i=i*10;
        //cout<<i<<endl;
	    int k=n[l-1]-'0';
        //cout<<k<<endl;
	    i=i+k;
	    cout<<i<<endl;
}