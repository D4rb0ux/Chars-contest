//Вам даны слова. Выведите в алфавитном порядке список общих букв всех слов.

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    vector<map<char, int>> freq(1000);
    ifstream fin("input.txt");
    string s;
    int n = 0;
    while (getline(fin, s)) {
        for (char& c : s)
            freq[n][c]++;
        n++;
    }

    for (auto& elem : freq[0]) {
        bool is_found = true;
        for (int i = 0; i < n; i++) {
            if (freq[i].find(elem.first) == freq[i].end())
                is_found = false;
        }
        if (is_found)
            cout << elem.first;
    }
    fin.close();
    return 0;
}

