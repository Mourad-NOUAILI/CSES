/*
    Task: range xor query
    Technique: prefix xor array
    Time complexity of the RMQ: O(1)
    Time complexity of the whole code: O(q)
    Space complexity: O(n): prefix xor array
*/


#include<bits/stdc++.h>


int main(){
    int n,q;
    std::cin >> n >> q;

    int* pre_xors = new int[n+1];
    pre_xors[0] = 0;
    for (int i = 1 ; i <= n ; ++i){
        int ai;
        std::cin >> ai;
        pre_xors[i] = ai ^ pre_xors[i-1];
    }

    for (int i = 1 ; i <= q ; ++i){
        int l,r;
        std::cin >> l >> r;
        std::cout << (pre_xors[--r+1] ^ pre_xors[--l]) << '\n';
    }

    delete [] pre_xors;

    return 0;
}