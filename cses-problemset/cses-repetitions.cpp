#include <iostream>
#include <bits/stdc++.h>

// https://cses.fi/problemset/task/1069

using namespace std;

typedef long long ll;


int main() {
    // Para calcular mi numero faltante resto la suma de todos los numeros
    // hasta cierto numero n y con la suma de los numeros que se me pasan
    ll n;
    cin >> n;
    ll total_sum_of_passed_numbers = 0;
    for(int i=0; i<n-1; i++) {
        int number;
        cin >> number;
        total_sum_of_passed_numbers += number;
    }
    ll actual_total = n*(n+1)/2;
    ll missing = actual_total - total_sum_of_passed_numbers;
    cout << missing;
    return 0;
}

