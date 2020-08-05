#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// https://csacademy.com/ieeextreme-practice/task/ed8629419f140a5a2c923b049aba1224/

// Classic knapsack problem
/*
Capacity C
Number of gadgets N
Each gadget -> weight (for C) and fight power to max
*/

typedef unsigned long long ll;
typedef vector<vector<int>> d2array;

/*
Thought process

- List of elements of weight and fighting power
- For each element I can choose to take it or not to take it.
- The main problem is set over making the guess that maximizes power in all the elements
- We can divide this to subproblems of n, n-1, n-2 ... 1 elements, with intial conditions
depending of past choices.
Example:
    Capacity: 5, elements: 5.
    {1, 1}, {3, 3}, {4, 4}, {2, 2}, {5, 5}
    
    step1 I can choose to take or not to take {1, 1}, if I choose to take it then my problem
    reduces of maximizing power in the set {3, 3}, {4, 4}, {2, 2}, {5, 5} Elements: n-1, Capacity: 4 Power: 1
    or maximizing power in the set {3, 3}, {4, 4}, {2, 2}, {5, 5} Elements: n-1, Capacity: 5 Power: 0.

Storing information in a map with a value corresponding to the step and capacity (equivalent: sum of weights of taken elements)
Lets us compute faster repeated cases like if i want to know the max power if I decide to take {1, 1}
I can take for instance the max of step2 and sum the value 1 (sum: cause i said i took {1,1}).

This being said, we will first solve the last step with all posible weights, store them and decide for
the previous step between the max if taking or not the item. We will certainly take the values if
we are trying to maximize, but in this problem we are not going to be able to take all of them cause capacity is reached or passed.
Therefor the max value will come of the combination of take/not-take that best fits the bags capacity.

Remove prints to see the sub problems stored in the map and take conclutions of how the computations are made.

    /TAREA:
        Armar DAG, hacer la matriz e iterar

*/

int compute_fighting_power(map<string, int>& dp, d2array& elements, int capacity, int step) {
    string step_capacity = to_string(step) + "_" + to_string(capacity);
    
    if(dp.count(step_capacity)) return dp[step_capacity];
    if(step>=elements.size() || capacity<=0) return 0;

    int res = 0;
    if(elements[step][0]/*weight*/>capacity)
        res = compute_fighting_power(dp, elements, capacity, step+1); // don't take item
    else
    {
        res = max(
            compute_fighting_power(dp, elements, capacity-elements[step][0], step+1) + elements[step][1], // take item
            compute_fighting_power(dp, elements, capacity, step+1) // don't take item
        );
    }
    dp[step_capacity] = res;
    return res;
}



int main() {
    int t; cin >> t;
    vector<int> answers;
    for(int i=0; i<t; i++) {
        d2array elements;
        int c, n; cin >> c >> n;
        for(int j=0; j<n; j++) {
            int w, f; cin >> w >> f;
            elements.push_back({w, f});
        }
        map<string, int> dp = {};
        compute_fighting_power(dp, elements, c, 0);
        // cout << endl;
        // for(pair<string, int> p : dp) {cout << "{" << p.first << ", " << p.second << "} ";}
        // cout << endl;
        answers.push_back(dp[to_string(0) + "_" + to_string(c)]);
    }

    for(int a: answers)
        cout << a << endl;

    return 0;
}