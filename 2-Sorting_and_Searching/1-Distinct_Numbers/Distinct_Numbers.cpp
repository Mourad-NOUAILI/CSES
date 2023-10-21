/*#include<bits/stdc++.h>
 
#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
 
 
int main(){
    FAST;

    int n;
    std::cin>>n;
 
    std::set<int> s;
    for(int i=0;i<n;++i) {
        int x;
        std::cin>>x;
        s.insert(x);
    }
    
    std::cout<<s.size()<<'\n';
 
    return 0;
}*/

#include<bits/stdc++.h>
 
#define FAST std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
 
int main(){
    FAST;
    int n;
    std::cin>>n;
    
    std::map<int,bool> exists;
    int cnt=0;
    for(int i=0;i<n;++i) {
        int x;
        std::cin>>x;
        if(exists[x]) continue;
        cnt++;
        exists[x]=true; 
    }
    
    std::cout<<cnt<<'\n';
 
  
    return 0;
}

