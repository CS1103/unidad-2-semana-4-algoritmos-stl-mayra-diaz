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
vector<pair<int, vector<int>>> enter_test_cases(){
    int N;
    cout << "Start entering the inputs:\n";
    cin >> N;
    vector<pair<int, vector<int>>> cases(N);
    string order, number;

    for (int i = 0; i < N; i++) {
        cin >> cases[i].first >> order;
        order += " ";
        for (int j = 0; order[j+1] != '\0'; j++) {
            number += order[j];
            if (order[j+1] == ' ') {
                cases[i].second.push_back(stoi(number));
                number = "";
            }
        }
    }
    return cases;
}

string exercise_two() {
    auto cases = enter_test_cases();
    int swaps;
    string str;
    for(auto& cass: cases){
        swaps = 0;
        for (int i = 0; i < cass.first-1; i++) {
            for (int j = 0; j < cass.first-i-1; ++j) {
                if (cass.second[j] > cass.second[j+1]){
                    swap(cass.second[j], cass.second[j+1]);
                    swaps++;
                }
            }
        }
        str += "Optimal train swapping takes " + to_string(swaps) + " swaps.\n";
    }
    return str;
}
