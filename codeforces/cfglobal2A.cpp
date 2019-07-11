#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int c[N];
int main(){

    int n , i;
    cin>>n;

    for(i = 1 ; i <= n ; i++ ){

        cin>>c[i];
    }
    int l = c[1];
    int r = c[n];

    int ans = 0;

    if(l != r){
        cout<< n-1 <<endl;
    }else{
    for( i = 2 ; i < n ; i++){
        if(c[i]!= l){
            ans = max(ans , i - 1);
        }
        if(c[i]!= r){
            ans = max(ans , n - i);
        }
    }

    cout<<ans<<endl;
    }
    return 0;
}