#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){ 

    ll a[1005] , i  , l , r , k , n, h  , rblocks;
    cin>>n>>h;
    k = rblocks = 0;
    for( i = 0 ; i < n ; i++)
    cin>>a[i];
    l = r = h;
    for( i = 0 ; i < n ; i++){
        if( l - a[i] >= 0){
            l -= a[i];
            k++;
            rblocks++;
        }
        else if( r - a[i] >= 0 && rblocks > 0){
            r-= a[i];
            k++;
            rblocks--;
        }
        else{
            break;
        }
    }
    cout<<k<<endl;
    return 0;
}