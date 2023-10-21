#include<bits/stdc++.h>
#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);

typedef unsigned long long ull;

int main(){
    FAST;
    std::string s;
    std::cin>>s;

    s+='X';

    ull n=s.size();
    ull cnt=1;
    ull ans=0;
    for(ull i=0;i<n-1;++i){
        if(s[i]==s[i+1]) cnt++;
        else {
            ans=std::max(ans,cnt);
            cnt=1;
        }
    }
    std::cout<<ans<<'\n';

    return 0;
}