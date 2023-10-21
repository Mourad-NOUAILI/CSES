/*
    Task: range update, Access to input[i]
    Technique: segment tree WITH lazy propagation - AC
    Time complexity of the range update: Optimzed O(logn)
    Time complexity of the Access to input[i]: optimized O(logn)
    Time complexity of the whole code: optimized O(qlogn)
    Space complexity: O(n): input array,O(n): segment tree
*/

#include<bits/stdc++.h>

typedef long long ll;

void build(ll* input, ll* & seg, int start_pos, int end_pos, int pos){
    if (start_pos == end_pos) {
        seg[pos] = input[start_pos];
        return;
    }
    int mid = (start_pos+end_pos) >> 1;
    build(input,seg,start_pos,mid,2*pos+1);
    build(input,seg,mid+1,end_pos,2*pos+2);
    seg[pos] = seg[2*pos+1]+seg[2*pos+2];
}


/**
 * This function update the sgement tree of a given range using lazy propagation
 * Time complexity: O(logn)
 * Auxillary space complexity: O(n)
 * Total space complexity: O(n)
 * @param array seg - the built segment tree from the input array (Here we use an array to build the segment tree)
 * @param int start_pos - the first boundary of the actual node in the segment tree in the array that represents the segment tree
 * @param int end_pos - the second boundary of the actual node in the segment tree in the array that represents the segment tree
 * @param int pos - The the index of the actual node of the segment tree in the array that represents the segment tree
 * @param int l - The left boundary of the range query
 * @param int r - The right boundary of the range query
 * @param int val - The value to be added to the elements in range [l,r]
 * @return array - the updated segment tree
 */
void range_update_lazy(ll* & seg, ll* & lazy, int start_pos, int end_pos, int pos, int l, int r, int val){
    if (lazy[pos] != 0){
        seg[pos] += (end_pos-start_pos+1) * lazy[pos];
        if (start_pos != end_pos){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    // No overlap
    if (l > end_pos || r < start_pos) return;

    // Total overlap
    if(l <= start_pos && r >= end_pos){
        seg[pos] += (end_pos-start_pos+1) * val;
        if (start_pos != end_pos){
            lazy[2*pos+1] += val;
            lazy[2*pos+2] += val;
        }
        return;
    }

    // Partial overlap
    int mid = (start_pos+end_pos) >> 1;
    range_update_lazy(seg,lazy,start_pos,mid,2*pos+1,l,r,val);
    range_update_lazy(seg,lazy,mid+1,end_pos,2*pos+2,l,r,val);
    
    seg[pos] = seg[2*pos+1] + seg[2*pos+2];

}


ll range_query_lazy(ll* & seg, ll* & lazy, int start_pos, int end_pos, int pos, int l, int r){
    if (lazy[pos] != 0){
        seg[pos] += (end_pos-start_pos+1)*lazy[pos];
        if (start_pos != end_pos){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    // No overlap
    if (l > end_pos || r < start_pos) return 0;

    // Total overlap
    if( l <= start_pos && r >= end_pos) return seg[pos];

    // Partial overlap
    int mid = (start_pos+end_pos) >> 1;
    return range_query_lazy(seg,lazy,start_pos,mid,2*pos+1,l,r) + range_query_lazy(seg,lazy,mid+1,end_pos,2*pos+2,l,r);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n,q;
    std::cin >> n >> q;

    ll* input = new ll[n];
    for(int i = 0 ; i < n ; ++i){
        std::cin >> input[i];
    }

    int k = ceil(log2(n));
    int m = 2*(1 << k)-1;
    ll* seg = new ll[m];
    ll* lazy = new ll[m];

    build(input,seg,0,n-1,0);
    /*for (int i = 0 ; i < m ; ++i) std::cout << seg[i] << ' ';
    std::cout << '\n';*/

    for (int i = 1 ; i <= q ; ++i){
        int op;
        std:: cin >> op;
        if (op == 1){
            int l,r,v;
            std::cin >> l >> r >> v;
            range_update_lazy(seg,lazy,0,n-1,0,--l,--r,v);
            /*for (int i = 0 ; i < m ; ++i) std::cout << seg[i] << ' ';
            std::cout << '\n';
            for (int i = 0 ; i < m ; ++i) std::cout << lazy[i] << ' ';
            std::cout << '\n';*/
        }
        else {
            int idx;
            std::cin >> idx;
            idx--;
            std::cout << range_query_lazy(seg, lazy, 0, n - 1, 0, idx, idx) << '\n';
        }
    }

    delete[] seg;
    delete[] input;

    return 0;
}