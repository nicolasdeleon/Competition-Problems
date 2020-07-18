#include <iostream>
#include <bits/stdc++.h>

// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387174

using namespace std;


/*
 * | GREEDY SOLUTION |
 * La idea es que contas las rachas ascendentes y descendentes.
 *  Cuando venis con rachas positivas una negativa te corta la racha.
 *  Cuando cortas la racha dividis por 4 y colocas los positivos como una D,
 *  ya que lo mejor que podes ahcer antse de una negativa es empezar en D.
 *  Cuando venis con rachas negativas y comienza uan posiiva, cortas y colocas como una A las negativas q sobran y arrancas con las positivas.
*/

int main(){
    int T; cin >> T;
    for(int i=0; i<T; ++i){
        int N; cin >> N;
        vector<int> notes;
        int error_min = 0;
        int note; cin >> note;
        notes.push_back(note);
        for(int j=1; j<N; j++) {
            int note; cin >> note;
            if(notes.back()!=note) {
            notes.push_back(note);
            }
        }
        int streak_counter = 0;
        bool up = false;
        int prev_note = notes[0];
        for(int k=1; k<notes.size(); k++) {
            int note = notes[k];
            // FIJARME BIEN SI Streak_counter lo tengo q poner en 1 no en 0 con algun caso
            //
            if(up && note > prev_note) {
                streak_counter++;
            } else if( !up && note > prev_note) {
                // not going down anymore
                up = true;
                // GET number of errors
                error_min += streak_counter / 4; // see explanation in GREEDY SOLUTION
                streak_counter = 1;
            } else if(up && note < prev_note) {
                // not going up anymore
                up = false;
                // GET number of errors
                error_min += streak_counter / 4;
                streak_counter = 1;
            } else if(!up && note < prev_note) {
                streak_counter++;
            }
            prev_note = note;
        }
        error_min += streak_counter / 4;
        cout << "Case #" << i+1 << ": " << error_min << endl;
    }
    return 0;
}

/* RECURSIVE: GET SOLUTIONS AND GET MIN AFTER
 * 4 runs for each initial note
 * prev_note = 0, 1, 2, 3
 * error = 0
 * initial i = 1
 * */
void recursive_sol(int& N, int& error_min, vector<int>& notes, int error, int prev_note, int i){
    if(prev_note>=4) {
        error+=1;
        prev_note -= 4;
    } else if(prev_note<0) {
        error+=1;
        prev_note += 4;
    }
    if(error>=error_min) { return; }
    if(i==N) {
        error_min = error;
        return;
    }
    if(notes[i-1]<notes[i]) {
        recursive_sol(N, error_min, notes, error, prev_note+1, i+1);
        if(prev_note!=0) { recursive_sol(N, error_min, notes, error, prev_note+2, i+1); }
        recursive_sol(N, error_min, notes, error, prev_note+3, i+1);
    } else if(notes[i-1]>notes[i]) {
        recursive_sol(N, error_min, notes, error, prev_note-1, i+1);
        if(prev_note!=3) { recursive_sol(N, error_min, notes, error, prev_note-2, i+1); }
        recursive_sol(N, error_min, notes, error, prev_note-3, i+1);
    } else {
        recursive_sol(N, error_min, notes, error, prev_note, i+1);
    }
}

int main_recursive() {
    int T; cin >> T;
    for(int i=0; i<T; ++i){
        int N; cin >> N;
        vector<int> notes;
        vector<int> error_list;
        int error_min = INT_MAX;
        int note; cin >> note;
        notes.push_back(note);
        for(int j=1; j<N; j++) {
            int note; cin >> note;
            //   if(notes.back()!=note) {
            notes.push_back(note);
            // }
        }
        recursive_sol(N, error_min, notes, 0, 0, 1);
        recursive_sol(N, error_min, notes, 0, 1, 1);
        recursive_sol(N, error_min, notes, 0, 2, 1);
        recursive_sol(N, error_min, notes, 0, 3, 1);
        cout << "Case #" << i+1 << ": " << error_min << endl;
    }
    return 0;
}


/*
*
* SOME TEST CASES A B C D
4
1
1
5
1 1 1 1 1
8
2 3 4 5 6 7 8 9
9
9 8 7 6 5 4 5 7 8

1
9
9 8 7 6 5 4 5 7 8

*/
