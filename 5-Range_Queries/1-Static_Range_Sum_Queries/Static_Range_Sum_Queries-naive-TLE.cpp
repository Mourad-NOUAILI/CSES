/*
    Task: range sum query
    Technique: naive
    Time complexity of the RMQ: O(n)
    Time complexity of the whole code: O(q.n)
    Space complexity: O(n): input array
*/

#include<bits/stdc++.h>


/**
 * This function return the sum value in range BTW two positions in a given input array
 * Time complexity: O(n)
 * Auxillary space complexity: O(1)
 * Total space complexity: O(n)
 * @param array A - the input array 
 * @param int l - The left boundary of the range query
 * @param int r - The right boundary of the range query
 * @return int - return the sum s += input[i], l <= i <= r
*/

long range_query(long* A,int l,int r){
    long s = 0;
    for( int i = l ; i <= r ; ++i) s += A[i];
    return s;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n,q;
    std::cin >> n >> q;

    long* A = new long[n];
    for(int i = 0 ; i < n ; ++i) std::cin >> A[i];
    
    for (int i = 1 ; i <= q ; ++i){
        int l,r;
        std::cin >> l >> r;
        l--;
        r--;
        std::cout << range_query(A,l,r) << '\n';
    }

    delete [] A;

    return 0;
}