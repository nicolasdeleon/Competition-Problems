#include <iostream>
#include <bits/stdc++.h>

// https://csacademy.com/ieeextreme-practice/task/9ca8fafd184f553a903734761546a224/

using namespace std;

typedef unsigned long long vl;

int main() {
    int t;
    cin >> t;
    vector<int> ans;
    for(int i=0; i<t; i++) {
        int count = 0;
        vl a, b; cin >> a >> b;
        vector<int> a_bits;
        vector<int> b_bits;
        while(a!=0) {
            a_bits.push_back(a%2);
            a = a/2;
        }
        while(b!=0) {
            b_bits.push_back(b%2);
            b = b/2;
        }
        int max_ = max(b_bits.size(), a_bits.size());
        int min_ = min(b_bits.size(), a_bits.size());
        count += (max_ - min_);
        bool root_split = false;
        for(int i=a_bits.size()-1, j=b_bits.size()-1; i>=0 && j>=0; i--,j--) {
            if(a_bits[i]!=b_bits[j]) root_split = true;
            if(root_split) count+=2;
        }
    ans.push_back(count);
    }

    for(int a : ans)
        cout << a << endl;

    return 0;
}

/*
                            1
                        10     11 
                     100  101 110
                 1000  ...  1010 ...

log2(10^18) ~ 60

caso de 10 a 6
110- -> 6
1010 -> 10
0221 = 5

1001 -> 9
1101 -> 13
0222 = 6
¨*/