/*
    Task: point update, range sum query
    Technique: segment tree
    Time complexity of the point update: O(logn)
    Time complexity of the RSQ: O(logn)
    Time complexity of the whole code: O(qlogn)
    Space complexity: O(n): input array,O(n): segment tree
*/

#include<bits/stdc++.h>

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
void build(long* A, long* & seg, int start_pos, int end_pos, int pos ){
    if (start_pos == end_pos){
        seg[pos] = A[start_pos];
        return;
    }
    int mid = (start_pos+end_pos) / 2;
    build(A,seg,start_pos,mid,2*pos+1);
    build(A,seg,mid+1,end_pos,2*pos+2);
    seg[pos] = seg[2*pos+1] + seg[2*pos+2];
}


/**
 * This function return the sum range BTW two positions in a given input array
 * Time complexity: O(logn)
 * Auxillary space complexity: O(n)
 * Total space complexity: O(n)
 * @param array seg_tree - the built segment tree from the input array (Here we use an array to build the segment tree)
 * @param int start_pos - the first boundary of the actual node in the segment tree in the array that represents the segment tree
 * @param int end_pos - the second boundary of the actual node in the segment tree in the array that represents the segment tree
 * @param int l - The left boundary of the range query
 * @param int r - The right boundary of the range query
 * @param int pos - The the index of the actual node of the segment tree in the array that represents the segment tree
 * @return long - return sum in range [l,r]
 */
long range_sum(long* seg, int start_pos, int end_pos, int l, int r, int pos) {
    if (l <= start_pos && r >= end_pos) return seg[pos];
    if (l > end_pos || r < start_pos) return 0;
    int mid = (start_pos+end_pos) / 2;
    return range_sum(seg,start_pos,mid,l,r,2*pos+1) + range_sum(seg,mid+1,end_pos,l,r,2*pos+2);
}


/**
 * This function update the segment tree using the real update position in the given input array
 * Time complexity: O(logn)
 * Auxillary space complexity: O(n)
 * Total space complexity: O(n)
 * @param array seg_tree - the built segment tree from the input array (Here we use an array to build the segment tree)
 * @param int start_pos - the first boundary of the actual node in the segment tree in the array that represents the segment tree
 * @param int end_pos - the second boundary of the actual node in the segment tree in the array that represents the segment tree
 * @param int idx - The left boundary of the range query
 * @param int val - The right boundary of the range query
 * @param int pos - The the index of the actual node of the segment tree in the array that represents the segment tree
 * @return array - return the segment tree after update
 */
void point_update(long* seg, int start_pos, int end_pos, int idx, int val, int pos){
    if (start_pos == end_pos) {
        seg[pos] = val;
        return;
    }
    int mid = (start_pos+end_pos) / 2;
    if (start_pos <= idx && idx <= mid) // if idx lies to left subtree, recurse on the left subtree
        point_update(seg,start_pos,mid,idx,val,2*pos+1);
    else // if idx lies to right subtree, recurse on the right subtree
        point_update(seg,mid+1,end_pos,idx,val,2*pos+2);
        
    seg[pos] = seg[2*pos+1] + seg[2*pos+2];
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

    int m = 2*(1 << (int)ceil(log2(n)))-1;
    long* seg = new long[m];
    for(int i = 0 ; i < m ; ++i) seg[i] = 0;

    build(A,seg,0,n-1,0);

    /*for (int i = 0 ; i < m ; ++i) std::cout << seg[i] << " ";
    std::cout << '\n';*/

    for (int i = 1 ; i <= q ; ++i) {
        int op,a,b;
        std::cin >> op >> a >> b;
        if (op == 1) {
            int k = --a;
            int val = b;
            point_update(seg,0,n-1,k,val,0);
        }
        if (op == 2) {
            int l = --a;
            int r = --b;
            std::cout << range_sum(seg,0,n-1,l,r,0) << '\n';
        }
    }
    
    delete [] seg;
    delete [] A;
    return 0;
}