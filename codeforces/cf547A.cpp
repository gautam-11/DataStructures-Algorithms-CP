#include<bits/stdc++.h>
using namespace std;
int main(){
	
	long long int n , m , x , y ,ans;
	cin>>n>>m;
	bool check = false;
	ans = 0;
	if( n == m )
		cout<<"0\n";
	else if(m%n != 0)
		cout<<"-1\n";
	else{
	
	while( m != n){		
		ans++;	
		x = m / 2;
		y = m / 3; 	
		if(m%2 == 0 && x%n == 0)
			m=x;
		else if(m%3 == 0 && y%n == 0)
			m=y;
		else
		{
		check = true;
		break;		
		}
		
	}
	if(check)
		cout<<"-1\n";
	else
	cout<<ans<<endl;
	}
	
	return 0;

}
