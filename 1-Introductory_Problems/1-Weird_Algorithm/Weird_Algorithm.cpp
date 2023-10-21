#include<bits/stdc++.h>

#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);

typedef unsigned long long ull;

int main(){
    FAST;
    
    ull n;
    std::cin>>n;

    while(n!=1){
        std::cout<<n<<" ";
        n=n%2==0?n/2:3*n+1;
    }
    std::cout<<n<<'\n';
    return 0;
}
