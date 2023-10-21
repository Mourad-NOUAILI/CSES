/*
    Task: range sum query
    Technique: prefix sum array
    Time complexity of the RMQ: O(1)
    Time complexity of the whole code: O(q)
    Space complexity: O(n): prefix sum array
*/

#include<bits/stdc++.h>

/**
 * This function return the range sum BTW two positions in a given input array
 * Time complexity: O(1)
 * Auxillary space complexity: O(1)
 * Total space complexity: O(n)
 * @param array PRE - the prefix sum of the input array
 * @param int l - The left boundary of the range query
 * @param int r - The right boundary of the range query
 * @return int - return the sum s = PRE[r+1]-PRE[l] which is s += input[i], l <= i <= r
 */
long range_query(long* PRE,int l,int r){
    return PRE[r+1]-PRE[l];
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n,q;
    std::cin >> n >> q;

    long* PRE = new long[n+1]{0};
    for(int i = 1 ; i <= n ; ++i) {
        long x;
        std::cin >> x;
        PRE[i] = PRE[i-1] + x;
    };
    
    for (int i = 1 ; i <= q ; ++i){
        int l,r;
        std::cin >> l >> r;
        l--;
        r--;
        std::cout << range_query(PRE,l,r) << '\n';
    }

    delete [] PRE;

    return 0;
}