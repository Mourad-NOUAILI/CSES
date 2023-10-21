/*
    Task: range minimum query (no updates)
    Technique: square root decomposition
    Time complexity of the RMQ: O(sqrt(n))
    Time complexity of the whole code: O(q sqrt(n))
    Space complexity: O(n): input array,O(n): square roots array
*/
#include<bits/stdc++.h>

#define INF std::numeric_limits<long>::max()



/**
 * This function build the blocks array from the input array using an array
 * Time complexity: O(n)
 * Auxillary space complexity: O(n)
 * Total space complexity: 2 x O(n)
 * @param array A - the input array
 * @param int m - The next perfect square root integer >= n
 * @return array blocks - The divided input array in m parts from the input array
 */

void build(long* A,int n, long* & blocks, int m){
    for (int i = 0 ; i < n ; ++i){
        blocks[i/m] = std::min(blocks[i/m],A[i]);
    }
}


/**
 * This function return the minimun value in range BTW two positions in a given input array
 * Time complexity: O(sqrt(n))
 * Auxillary space complexity: O(n)
 * Total space complexity: O(n)
 * @param array A - The input array
 * @param array blocks - The divided array from the input array
 * @param int m - The next perfect square root integer >= n
 * @param int l - The left boundary of the range query
 * @param int r - The right boundary of the range query
 * @return int - return min number in range [l,r]
 */

long range_query(long* A,long* blocks, int m, int l, int r){
    long ans = INF;

    while (l <= r){
        if (l%m == 0 && l+m <= r){
            ans = std::min(ans,blocks[l/m]);
            l += m;
        }
        else{
            ans = std::min(ans,A[l]);
            l++;
        }
    }

    return ans;
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n,q;
    std::cin >> n >> q;

    long *A = new long[n];
    for(int i = 0 ; i < n ; ++i) std::cin >> A[i];

    int m = ceil(sqrt(n));
    long *blocks = new long[m];
    
    for (int i = 0 ; i < m ; ++i) blocks[i] = INF;
  
    build(A,n,blocks,m);
    

    for (int i = 1 ; i <= q ; ++i){
        int l,r;
        std::cin >> l >> r;
        l--;
        r--;

        std::cout << range_query(A,blocks,m,l,r) << '\n';
    }
    
    delete [] blocks;
    delete [] A;

    return 0;
}