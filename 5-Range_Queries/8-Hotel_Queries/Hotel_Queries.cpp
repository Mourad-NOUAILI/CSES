/*
    Task: point update, point query 
    Technique: 
    Time complexity of the point update: 
    Time complexity of the query: 
    Time complexity of the whole code: 
    Space complexity: O(n): input array, O(n) segment tree
*/

#include<bits/stdc++.h>

typedef long long ll;

#define INF std::numeric_limits<long>::min()

void build(long *input, ll* & seg, int s, int e, int p){
    if (s==e) {
        seg[p] = input[s];
        return;
    }
    int mid = (s+e) >> 1;
    build(input,seg,s,mid,2*p+1);
    build(input,seg,mid+1,e,2*p+2);
    seg[p] = std::max(seg[2*p+1],seg[2*p+2]);
}


void range_update_lazy(ll* & seg, ll* & lazy, int start_pos, int end_pos, int pos, int l, int r, int val){
    if (lazy[pos] != 0){
        seg[pos] += lazy[pos];
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
        seg[pos] += val;
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
    
    seg[pos] = std::max(seg[2*pos+1],seg[2*pos+2]);

}


bool range_query_lazy(ll* & seg, ll* & lazy, int start_pos, int end_pos, int pos, int val, long & ans){
    if (lazy[pos] != 0){
        seg[pos] += lazy[pos];
        if (start_pos != end_pos){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (seg[pos] < val) return false;

    if (start_pos == end_pos){
        if (seg[pos] >= val) {
            ans =  start_pos+1;
            return true;
        }
    }

    int mid = (start_pos+end_pos) >> 1;
    return range_query_lazy(seg,lazy,start_pos,mid,2*pos+1,val,ans) || range_query_lazy(seg,lazy,mid+1,end_pos,2*pos+2,val,ans);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n,m;
    std::cin >> n >> m;
    long* rooms = new long[n];

    for (int i = 0 ; i < n ; ++i) std::cin >> rooms[i];

    int k = ceil(log2(n));
    int w =  2*(1 << k)-1;
    ll* seg = new ll[w];
    ll* lazy = new ll[w];
    build(rooms,seg,0,n-1,0);

    for (int i = 0 ; i < m ; ++i){
        int room;
        std::cin >> room;
        long ans = range_query_lazy(seg,lazy,0,n-1,0,room,ans)?ans:0;
        if (ans != 0) {
            ans--;
            range_update_lazy(seg,lazy,0,n-1,0,ans,ans,-room);
            std::cout << ans + 1 << ' ';
        }
        else std::cout << 0 << ' ';
    }
    std::cout << '\n';
    return 0;
}