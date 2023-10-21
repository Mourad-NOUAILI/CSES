#include<bits/stdc++.h>
#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define LOOP(i,a,b) for(int i=a;i<=b;++i)

void fill(std::vector<int>& A,int n,int flag){
    LOOP(i,1,n){
        if(i%2==flag) A.push_back(i);
    }
}
void solve(int n){
    if(n==1) {
        std::cout<<"1\n";
        return;
    }
    std::vector<int> A;
    fill(A,n,0);
    int i=A.size()-1;
    int j=i+1;
    fill(A,n,1);
    if(abs(A[i]-A[j])==1) {
        std::cout<<"NO SOLUTION\n";
        return;
    }

    for(auto e: A) std::cout<<e<<" ";
    std::cout<<'\n';
}

int main(){
    FAST;
   
    int n;
    std::cin>>n;
    solve(n);
    return 0;
}