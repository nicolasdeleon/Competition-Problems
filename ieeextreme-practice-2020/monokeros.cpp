#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// https://csacademy.com/ieeextreme-practice/task/monokeros/
/*
En este ej nos pedian que para un arbol binario de busqueda digamos
siempre la profundidad del nodo que insertabamos. Mi resolucion se basa en que podes
particionar el arbol en intervalos arrancando con [-inf, inf] y depth 0.
Despues [-inf, root] depth 1, [root, inf] depth 21 De esta manera y teniendo en cuenta que la parte
mas chica de cada intervalo es unica podes ir trackeando donde cae cada nodo, armando los nuevos
intervalos y saber la profundidad.
*/

typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> answers;
    ll depth = 0;
    map<ll, pair<int, vector<ll>>> tree;
    tree.insert({(ll)-10e9-1, {0, {(ll) -10e9-1, (ll) 10e9+1}}});

    for(int i=0; i<N; i++) {
        ll x; cin >> x;
        const long long int& lower_i = (--tree.lower_bound(x))->first;
        pair<int, vector<ll>> interval = tree[lower_i];
        pair<ll, pair<int, vector<ll>>> new_pair_lower, new_pair_higher;
        new_pair_lower = {lower_i, {interval.first + 1, {interval.second[0], x}}};

        new_pair_higher = {x, {interval.first + 1, {x, interval.second[1]}}};
        if(interval.first + 1 > depth) {
            depth = interval.first + 1;
        }
        tree.erase(lower_i);
        tree.insert(new_pair_lower);
        tree.insert(new_pair_higher);
        answers.push_back(interval.first + 1);
    }

    for(int a: answers)
        cout << a << " ";

    cout << endl;

    return 0;
}