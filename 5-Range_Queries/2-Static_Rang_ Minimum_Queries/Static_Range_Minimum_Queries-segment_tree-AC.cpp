/*
    Task: range minimum query (no updates queries)
    Technique: segment tree
    Time complexity of the RMQ: O(logn)
    Time complexity of the whole code: O(qlogn)
    Space complexity: O(n): input array,O(n): segment tree
*/
#include<bits/stdc++.h>

#define INF std::numeric_limits<long>::max()

/**
 * This function return the minimun value in range BTW two positions in a given input array
 * Time complexity: O(logn)
 * Auxillary space complexity: O(n)
 * Total space complexity: O(n)
 * @param array seg_tree - the built segment tree from the input array (Here we use an array to build the segment tree)
 * @param int start_pos - the first boundary of the actual node in the segment tree in the array that represents the segment tree
 * @param int end_pos - the second boundary of the actual node in the segment tree in the array that represents the segment tree
 * @param int l - The left boundary of the range query
 * @param int r - The right boundary of the range query
 * @param int pos - The the index of the actual node of the segment tree in the array that represents the segment tree
 * @return long - return min number in range [l,r]
 */
long range_query(long* seg_tree, int start_pos, int end_pos, int l, int r, int pos){
    // No overlap
    if (l > end_pos || r < start_pos) return INF;

    // Total overlap
    if (l <= start_pos && r >= end_pos) return seg_tree[pos];

    // Partial overlap
    int mid = (start_pos+end_pos) / 2;
    return std::min(
                    range_query(seg_tree,start_pos,mid,l,r,2*pos+1),
                    range_query(seg_tree,mid+1,end_pos,l,r,2*pos+2)
                );
}


/**
 * This function build a segment tree from the input array using an array
 * Time complexity: O(logn)
 * Auxillary space complexity: O(n)
 * Total space complexity: 2 x O(n)
 * @param array A - the input array
 * @param int start_pos - the first boundary of the actual node in the segment tree in the array that represents the segment tree
 * @param int end_pos - the second boundary of the actual node in the segment tree in the array that represents the segment tree
 * @param int pos - The the index of the actual node of the segment tree in the array that represents the segment tree
 * @return array seg_tree - return the segment tree
 */
/*void build_segment_tree(long* A,long* & seg_tree, int start_pos, int end_pos, int pos){
    if (start_pos == end_pos) {
        seg_tree[pos] = A[start_pos];
        return;
    }

    int mid = (start_pos+end_pos) / 2;
    build_segment_tree(A,seg_tree,start_pos,mid,2*pos+1);
    build_segment_tree(A,seg_tree,mid+1,end_pos,2*pos+2);

    seg_tree[pos] = std::min(seg_tree[2*pos+1],seg_tree[2*pos+2]);
}*/

int build_segment_tree(long* A,long* & seg_tree, int start_pos, int end_pos, int pos){
    // If we reach a leaf node, means the input array is divided into subarrays of size one
    if (start_pos == end_pos) {
        return seg_tree[pos] = A[start_pos];
    }

    // Otherwise, keep dividing
    int mid = (start_pos+end_pos) / 2;

    return seg_tree[pos] =  std::min(build_segment_tree(A,seg_tree,start_pos,mid,2*pos+1),build_segment_tree(A,seg_tree,mid+1,end_pos,2*pos+2));
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n,q;
    std::cin >> n >> q;

    long* A = new long[n];
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> A[i];
    };
    
    int m = n;
    double k = log2(n);
    if (k-(int)k != 0) m = pow(2,ceil(k));
    m = 2 * m - 1;
    long *seg_tree = new long[m];
    for (int i = 0 ; i < m ; ++i) seg_tree[i] = INF;
    
    int z = build_segment_tree(A,seg_tree,0,m-1,0);

    /*for(int i = 0 ; i < 2*m-1 ; ++i) std::cout << seg_tree[i] << " ";
    std::cout << '\n';*/

    for (int i = 1 ; i <= q ; ++i){
        int l,r;
        std::cin >> l >> r;
        l--;
        r--;
        std::cout << range_query(seg_tree,0,m-1,l,r,0) << '\n';
    }

    delete [] A;
    delete [] seg_tree;
    return 0;
}