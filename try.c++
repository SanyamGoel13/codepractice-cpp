#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		long long n,m,i,j,k,o=0,l=0;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>m;
			o+=m;
		}
		for(i=0;i<n;i++){
			cin>>m;
			l=max(l,m);
			o+=m;
		}
		o-=l;
 
		cout<<o<<endl;
	}
}