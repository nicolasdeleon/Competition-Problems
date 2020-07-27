#include <iostream>
#include <bits/stdc++.h>

// https://csacademy.com/ieeextreme-practice/task/d48ada9a7213299f1b24b22b2fb9443f/

using namespace std;

typedef unsigned long long vl;

#define LEN_ALPHABET 26

double dist(double r, double theta_1, double theta_2) {
    double x = pow(cos(theta_1*M_PI/180) - cos(theta_2*M_PI/180), 2);
    double y = pow(sin(theta_1*M_PI/180) - sin(theta_2*M_PI/180), 2);

    return r * sqrt(x+y);
}

int main() {
    int r;
    map<char, double> alphabet;
    string frase;
    cin >> r;
    for(int i=0; i<LEN_ALPHABET; i++) {
        char letter; double angle;
        cin >> letter >> angle;
        alphabet[letter] = angle;
    }
    std::getline(std::cin >> std::ws, frase);
    double length = 0;
    char last_letter = ' ';
    for(int i=0; i<frase.size(); i++){
        if(last_letter == ' ' && alphabet.count(toupper(frase[i])) > 0) {
            last_letter = toupper(frase[i]);
            length += r;
        } else if (last_letter != toupper(frase[i]) && alphabet.count(toupper(frase[i])) > 0) {
            length += dist(r, alphabet[last_letter], alphabet[toupper(frase[i])]);
            last_letter = toupper(frase[i]);
        }
    }
    cout << int(length+1) << endl;
    return 0;
}
