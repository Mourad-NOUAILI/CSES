#include<bits/stdc++.h>
#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define LOOP(i,a,b) for(ull i=a;i<=b;++i)

typedef unsigned long long ull;

ull solve(ull* A,ull n){
    if(n==1) return 0;
    ull ans=0;
    LOOP(i,0,n-2){
        if(A[i]>A[i+1]) {
            ull d=A[i]-A[i+1];
            A[i+1]+=d;
            ans+=d;
        }
    }
    return ans;
}

int main(){
    FAST;
    
    ull n;
    std::cin>>n;

    ull* A=new ull[n];
    LOOP(i,0,n-1) std::cin>>A[i];

    ull ans=solve(A,n);

    std::cout<<ans<<'\n';

    delete[] A;
    
    return 0;
}