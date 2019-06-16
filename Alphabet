//Археологи обнаружили письмена, возможно, написанные на некотором древнем языке Snake++. 
//Известен алфавит этого языка. Вам нужно выяснить, какие слова действительно записаны символами этого алфавита.

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string str;
    cin >> str;
    map<char, int> alphabet;
    for (char& c : str)
        alphabet[c]++;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        bool is_correct = true;
        for (char& c : str) {
            if (alphabet.find(c) == alphabet.end())
                is_correct = false;
        }
        if (is_correct)
            cout << str << endl;
    }
    return 0;
}

