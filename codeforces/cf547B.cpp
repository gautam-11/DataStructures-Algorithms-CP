#include<bits/stdc++.h>
using namespace std;
bool a[200005];
int main(){
		
	long int n , i , starting_ones , ending_ones , ans , cnt;
	cin>>n;		
	starting_ones = ending_ones = ans = cnt = 0;	
	for( i = 0 ; i < n ; i++){
		cin>>a[i];
		if(a[i] == 0)
			cnt = 0 ;
		else
			cnt++;
		ans = max(ans,cnt);
		
	}		
	i = 0;
	while(a[i]!=0){
		starting_ones++;	
		i++;
	}
	i = n-1;
	while(a[i]!=0){
		ending_ones++;
		i--;	
	}
	
	ans = max(ans , starting_ones + ending_ones);
	
	cout<<ans<<endl;
	
}
