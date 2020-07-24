#include <iostream>
#include <bits/stdc++.h>

// https://cses.fi/problemset/task/1069

using namespace std;

typedef long long ll;

int main() {

    string ADNchain;
    cin >> ADNchain;
    int max_sub_string = 0;
    int temp = 0;
    char sub_string = ADNchain[0];
    for(unsigned int i=0; i<ADNchain.size(); i++) {
        if(ADNchain[i] == sub_string) {
            temp++;
        } else {
            sub_string = ADNchain[i];
            temp = 1;
        }
        max_sub_string = max(max_sub_string, temp);
    }
    cout << max_sub_string;
    return 0;
}
