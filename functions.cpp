//
// Created by mayra on 2020-04-29.
//

#include "functions.h"

//Exercise 1
void enter_codes(vector<string> &codes){
    string input = " ";
    cout << "Start entering the codes:\n";
    cin >> input;
    do {
        codes.push_back(input);
        cin >> input;
    } while (input != "#");
}

void get_next_permutation(string &text){
    for (int i = 0; text[i+1] != '\0'; i++) {
        if (text[i] < text[i+1]){
            next_permutation(begin(text), end(text));
            return;
        }
    }
    text = "No successor";
}

string exercise_one() {
    vector<string> codes{};
    enter_codes(codes);
    string output = "";
    
    for(auto &code : codes){
        get_next_permutation(code);
        output += code + "\n";
    }

    return output;
}



//Exercise 2
string exercise_two(){
    int N;
    cout << "Start entering the inputs:\n";
    cin >> N;

    vector<pair<int, vector<int>>> cases(N);
    string str;
    int swaps, aux;
    for (int i = 0; i < N; i++) {
        cin >> cases[i].first;
        for (int j = 0; j < cases[i].first; j++) {
                cin >> aux;
                cases[i].second.push_back(aux);
            }
        swaps = 0;
        for (int k = 0; k < cases[i].first-1; k++) {
            for (int j = 0; j < cases[i].first - k - 1; ++j) {
                if (cases[i].second[j] > cases[i].second[j+1]){
                    swap(cases[i].second[j], cases[i].second[j+1]);
                    swaps++;
                }
            }
        }
        str += "Optimal train swapping takes " + to_string(swaps) + " swaps.\n";
    }
    return str;
}

