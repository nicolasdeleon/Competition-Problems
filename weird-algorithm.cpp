#include <iostream>
#include <bits/stdc++.h>

// https://cses.fi/problemset/task/1068

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    cout << n << " ";
    while(n>1) {
        if(n%2==0) {
            // si es par tengo que dividirlo por 2
            n = n/2;
        } else {
            // si es impar multiplico por 3 y sumo 1
            n = n*3 + 1;
        }
    cout << n << " ";
    }
    return 0;
}