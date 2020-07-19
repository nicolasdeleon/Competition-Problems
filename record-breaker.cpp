#include <iostream>
#include <bits/stdc++.h>

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171

using namespace std;

int main() {
    int T; cin >> T;
    for(int i; i<T; i++){
        int day_count; cin >> day_count;
        int breaking_days = 0;
        int day; cin >> day;
        int max = 0;
        for(int j=1; j<day_count; j++) {
            int next_day;
            cin >> next_day;
            if (j < (day_count - 1) && day > next_day && day > max) {
                // si mi next_day no es mi ultimo && ....
                breaking_days++;
                max = day;
            } else {
                // si mi next_day es mi ultimo
                if (day > next_day && day > max ) {
                    // si mi day es mayor al max y mayor al siguiente dia
                    breaking_days++;
                    max = day;
                } else {
                    // mi day es menor que mi dia siguiente o que mi max
                    max = std::max(day, max);
                    // me fijo si mi ultimo dia es mayor que todos los otros
                    if (next_day > max) {
                        breaking_days++;
                    }
                }
            }
            // avanzo mi dia al dia siguiente
            day = next_day;
        }
        if (day_count == 1) {
            // si solo tengo un dia entonces es breaking day
            breaking_days = 1;
        }
        cout << "Case #" << i + 1 << ": " << breaking_days << '\n';
    }
}
