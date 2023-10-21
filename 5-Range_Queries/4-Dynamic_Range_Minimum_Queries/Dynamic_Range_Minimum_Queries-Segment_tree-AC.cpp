/*
    Task: point update, range minimum query
    Technique: segment tree
    Time complexity of the point update: O(logn)
    Time complexity of the RMQ: O(logn)
    Time complexity of the whole code: O(qlogn)
    Space complexity: O(n): input array,O(n): segment tree
*/

#include <bits/stdc++.h>

#define INF std::numeric_limits<long>::max()


void build(long* input, long* & seg, int start_pos, int end_pos, int pos){
    if (start_pos == end_pos) {
        seg[pos] = input[start_pos];
        return;
    }
    int mid = (start_pos+end_pos) / 2;
    build(input,seg,start_pos,mid,2*pos+1);
    build(input,seg,mid+1,end_pos,2*pos+2);
    seg[pos] = std::min(seg[2*pos+1],seg[2*pos+2]);
}

void point_update(long* & seg, int start_pos, int end_pos, int idx, int val, int pos){
    if (start_pos == end_pos){
        seg[pos] = val;
        return;
    }
    int mid = (start_pos+end_pos) / 2;
    if (idx >= start_pos && idx <= mid) point_update(seg,start_pos,mid,idx,val,2*pos+1);
    else point_update(seg,mid+1,end_pos,idx,val,2*pos+2);
    seg[pos] = std::min(seg[2*pos+1],seg[2*pos+2]);
}

long range_min(long* seg, int start_pos, int end_pos, int l, int r, int pos){
    if (l <= start_pos && r >= end_pos) return seg[pos];
    if (l > end_pos || r < start_pos) return INF;
    int mid = (start_pos+end_pos) / 2;
    return std::min(range_min(seg,start_pos,mid,l,r,2*pos+1) , range_min(seg,mid+1,end_pos,l,r,2*pos+2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n,q;
    std::cin >> n >> q;

    long* input = new long[n];
    for (int i = 0 ; i < n ; ++i) std::cin >> input[i];

    int m = 2*(1 << (int)ceil(log2(n)))-1;
    long* seg = new long[m];

    build(input,seg,0,n-1,0);

    for (int i = 1 ; i <= q ; ++i){
        int op,a,b;
        std::cin >> op >> a >> b;
        if (op == 1) point_update(seg,0,n-1,--a,b,0);
        else std::cout << range_min(seg,0,n-1,--a,--b,0) << '\n';
    }

    delete [] seg;
    delete [] input;

    return 0;
}