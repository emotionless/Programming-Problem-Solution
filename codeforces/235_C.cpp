#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long int


using namespace std;



int main()
{
	int n,m;
	cin>>n>>m;
	string ans="";
	while(m>0 && n>0)
	{
		m--,n--;
		ans.push_back('1');
		ans.push_back('0');
	}
	if(m>0)
	{
		ans.push_back('1');
		m--;
		int i=0;
		while(m>0 && i<ans.length())
		{
			ans.insert(i,"1");
			m--;
			i+=3;
		}
		if(m>0)
		{
			cout<<-1;
			return 0;
		}
	}
	if(n>0)
	{
		if(n==1)
			cout<<0<<ans;
		else
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
