#include<bits/stdc++.h>
#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);


typedef unsigned long long ull;

ull solve(ull y,ull x){
    if(y>=x){
        return y%2==0?y*y-x+1:(y-1)*(y-1)+x;
    }
    return x%2==0?(x-1)*(x-1)+y:x*x-y+1;
}

int main(){
    FAST;

    int t;
    std::cin>>t;
    while(t--){
        ull x,y;
        std::cin>>y>>x;
        std::cout<<solve(y,x)<<'\n';
    }
    return 0;
}