/*
    Task: range minimum query (no updates)
    Technique: Dynamic programming - MLE
    Time complexity of build the matrix: O(n^2)
    Time complexity of the RMQ: O(1)
    Time complexity of the whole code: O(q)
    Space complexity: O(n): input array,O(n^2): matrix
*/
#include<bits/stdc++.h>

#define INF std::numeric_limits<int>::max()



/**
 * This function build the matrix from the input array
 * Time complexity: O(n^2)
 * Auxillary space complexity: O(n^2)
 * Total space complexity: O(n) + O(n^2)
 * @param array A - the input array
 * @param int k - The next perfect square root integer >= n
 * @return array blocks - The divided input array in k parts from the input array
 */

void build(int* A, int** & M, int n){
   for (int i = 1 ; i <= n ; ++i){
    for (int j = i ; j <= n ; ++j){
        M[i][j] = std::min(M[i][j-1],A[j-1]);
    }
   }
}


/**
 * This function return the minimun value in range BTW two positions in a given input array
 * Time complexity: O(sqrt(n))
 * Auxillary space complexity: O(n)
 * Total space complexity: O(n)
 * @param array A - The input array
 * @param array blocks - The divided array from the input array
 * @param int k - The next perfect square root integer >= n
 * @param int l - The left boundary of the range query
 * @param int r - The right boundary of the range query
 * @return int - return min number in range [l,r]
 */

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n,q;
    std::cin >> n >> q;

    int *A = new int[n];
    for(int i = 0 ; i < n ; ++i) std::cin >> A[i];

    int **M = new int*[n+1];
    for (int i = 0 ; i <= n ; ++i) M[i] = new int[n+1];
    
    for (int i = 0 ; i <=n ; ++i)
        for (int j = 0 ; j <= n ; ++j)
            M[i][j] = INF;
  
    build(A,M,n);

    /*for (int i = 0 ; i <= n ; ++i){
        for (int j = 0 ; j <= n ; ++j){
           if (M[i][j] != INF) std::cout << i <<"/" << j << '\t';
           else std::cout <<'\t';
        }
        std::cout <<'\n';
    }*/
    for (int i = 1 ; i <= q ; ++i){
        int l,r;
        std::cin >> l >> r;


            std::cout << M[l][r] << '\n';
    }

    for (int i = 0; i <= n; ++i) delete [] M[i];
    delete [] M;
    delete [] A;

    return 0;
}