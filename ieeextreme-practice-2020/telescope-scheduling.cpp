#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> data;
    for(int i=0; i<N; i++) {
        int s, f, d; cin >> s >> f >> d;
        data.push_back({s, f, d});
    }

   sort(data.begin(), data.end(), [](const vector<int>& starl, const vector<int>& starh) {
        // sort by finish hour
        return starl[1] < starh[1];
   });

    vector<int> dpit(data.size(), 0);
    for(int i=0; i<data.size(); i++)
        dpit[i] = data[i][2];

    for(int i=1; i<data.size(); i++) {
        for(int j=0; j<i; j++) {
            if(data[j][1] >= data[i][0]) break;
            if(dpit[i]<dpit[j]+data[i][2]) {
                dpit[i] = dpit[j]+data[i][2];
            }
        }
    }

    cout << *max_element(dpit.begin(), dpit.end()) << endl;

    return 0;
}
