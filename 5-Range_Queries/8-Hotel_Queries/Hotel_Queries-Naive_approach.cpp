/*
    Task: point update, point query - TLE
    Technique: Naive approach
    Time complexity of the point update: O(n)
    Time complexity of the query: O(n)
    Time complexity of the whole code: O(mxn)
    Space complexity: O(n): input array
*/

#include<bits/stdc++.h>

// o(n)
long query_and_update(long* rooms, int room, int n) {
    int ans = 0;
    int j = 0;
    while (j < n && rooms[j] < room ) j++;
    
    if (j < n) {
        rooms[j]-=room;
        ans = j+1;
    }
    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n,m;
    std::cin >> n >> m;
    long* rooms = new long[n];

    for (int i = 0 ; i < n ; ++i) std::cin >> rooms[i];

    // O(mxn)
    for (int i = 0 ; i < m ; ++i){
        int room;
        std::cin >> room;
        
        std::cout << query_and_update(rooms,room,n) <<' ';
    }
    std::cout << '\n';
    return 0;
}