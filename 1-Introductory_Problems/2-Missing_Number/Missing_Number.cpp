#include<bits/stdc++.h>
#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);

#define LOOP(i,a,b) for(ull i=a;i<=b;++i)

typedef unsigned long long ull;

int main(){
    FAST;

    ull n;
    std::cin>>n;

    /*ull s=0;
    LOOP(i,0,n-2) {
        ull x;
        std::cin>>x;
        s+=x;
    }

    std::cout<<n*(n+1)/2-s<<'\n';*/

    bool* A=new bool[n+1];
    LOOP(i,0,n-1) A[i]=false;

    LOOP(i,0,n-2) {
        ull x;
        std::cin>>x;
        A[x]=true;
    }

    LOOP(i,1,n){
        if(!A[i]) {
            std::cout<<i<<'\n';
            return 0;
        }
    }

    return 0;
}