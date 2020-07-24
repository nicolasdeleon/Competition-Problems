#include <iostream>
#include <bits/stdc++.h>

// https://csacademy.com/ieeextreme-practice/task/8761fb7efefcf1d890df1d8d91cae241/

using namespace std;

    // sorteo personas por tamaño en un arreglo people
    // itero por el arreglo, si mi altura es igual a la anterior pusheo a mi sub arreglo
    // si mi tamaño es mayor al anterior llamo a sort_and_print() con sub arreglo
    // y con indice.
    // sort_and_print(arr, i) ordena todos los del arr y los imprime y dsps imprime
    // i - group.size() +1 ; i;

bool sortbysec(const pair<string,int> &a,
              const pair<string,int> &b)
{
    return (a.second < b.second);
}

void sort_and_print(vector<string>& group, int i) {
    sort(group.begin(), group.end());
    for(string s : group) {
        cout << s << " ";
    }
    cout << i - group.size() + 1 << " ";
    cout << i << endl;
}

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> people;
    for(int i=0; i<n; i++) {
        string name; cin >> name;
        int h; cin >> h;
        pair <string,int> name_h;
        name_h = make_pair(name, h);
        people.push_back(name_h);
    }

    sort(people.begin(), people.end(), sortbysec);

    vector<string> group;
    group.push_back(people[0].first);
    int prev_h = people[0].second;

    for(int i=1; i<people.size(); i++) {
        if(people[i].second != prev_h) {
            sort_and_print(group, i);
            group.clear();
        }
        prev_h = people[i].second;
        group.push_back(people[i].first);
        if(i == people.size()-1) {
            sort_and_print(group, i+1);
        }
    }

    return 0;
}