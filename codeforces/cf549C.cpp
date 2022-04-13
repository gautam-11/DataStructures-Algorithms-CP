#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll sz = 1e5 + 5;

int main()
{   ll par[sz] , n ;
    int i,c[sz];
    cin>>n;
    for(i = 1  ; i <= n ; i++){
        cin>>par[i]>>c[i];
    }
    bool check = false;
    for(i = 1 ; i <= n ; i++){
        if( c[i] == 0 ){
            if(par[i]!= -1 && c[par[i]] == 1){
                c[par[i]] = 2;
            }
        }
        }
    for(i = 1 ; i <= n ; i++){
        if(c[i] == 1){
            cout<<i<<" ";
            check = true;
            }
    }
    if(!check)
        cout<<"-1"<<endl;
    else
        cout<<endl;


    return 0;
}