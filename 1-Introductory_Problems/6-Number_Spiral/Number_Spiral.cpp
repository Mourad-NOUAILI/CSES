#include<bits/stdc++.h>
#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define LOOP(i,a,b) for(ull i=a;i<=b;++i)

typedef unsigned long long ull;

ull solve(ull x,ull y){
    if(x>=y){
        return x%2==0?x*x-y+1:(x-1)*(x-1)+y;
    }
    return y%2==0?(y-1)*(y-1)+x:y*y-x+1;
}

int main(){
    FAST;

    int t;
    std::cin>>t;
    while(t--){
        ull x,y;
        std::cin>>x>>y;
        std::cout<<solve(x,y)<<'\n';
    }
    return 0;
}