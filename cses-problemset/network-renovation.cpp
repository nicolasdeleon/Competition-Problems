#include <iostream>
#include <bits/stdc++.h>

// https://cses.fi/problemset/task/1704

using namespace std;

typedef long long ll;


int main2() {
    int n;
    cin >> n;
    vector<int> nodes(n, 0);
    for(int i=0; i<(n-1); i++) {
        int node1, node2;
        cin >> node1;
        cin >> node2;
        nodes[node1-1]++;
        nodes[node2-1]++;
    }
    // for(int i =0; i<n; i++) cout << nodes[i] << " ";
    vector<int> newConn;
    int num_c = 0;
    for(int i=0; i<n; i++){
        if(nodes[i]==1) {
            newConn.push_back(i);
        }
    }
    cout << (newConn.size()+1)/2  << endl;
    for(int i=0; i<newConn.size(); i+=2) {
        cout << newConn[i]+1 << " " << newConn[i+1]+1 << endl;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n, 0);
    for(int i=0; i<(n-1); i++) {
        int node1, node2;
        cin >> node1;
        cin >> node2;
        nodes[node1-1]++;
        nodes[node2-1]++;
    }
    // for(int i =0; i<n; i++) cout << nodes[i] << " ";
    vector<int> newConn;
    int num_c = 0;
    for(int i=0; i<n; i++){
        if(nodes[i]==1) {
            newConn.push_back(i);
        }
    }
    cout << (newConn.size()+1)/2  << endl;
    for(int i=0; i<newConn.size(); i+=2) {
        cout << newConn[i]+1 << " " << newConn[i+1]+1 << endl;
    }
    return 0;
}