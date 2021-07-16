/*Вовочка ломает систему безопасности Пентагона. Для этого ему понадобилось узнать, 
какие символы в секретных зашифрованных посланиях употребляются чаще других. 
Для удобства изучения Вовочка хочет получить графическое представление встречаемости символов. 
Поэтому он хочет построить гистограмму количества символов в сообщении. 
Гистограмма — это график, в котором каждому символу, встречающемуся в сообщении хотя бы один раз, 
соответствует столбик, высота которого пропорциональна количеству этих символов в сообщении.*/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    map<char, int> freq;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    while (!fin.eof()) {
        char c = fin.get();
        if (!fin.eof() && !isspace(c))
            freq[c]++;
    }
    string symbols;
    for (auto& elem : freq)
        symbols += elem.first;
    int max_value = 0;
    for (auto& elem : freq) {
        if (elem.second > max_value)
            max_value = elem.second;
    }
    vector<string> lines;
    for (int i = 0; i < max_value; i++) {
        string line;
        for (auto& elem : freq) {
            if (elem.second != 0) {
                line += '#';
                elem.second--;
            } else {
                line += ' ';
            }
        }
        lines.push_back(line);
    }
    reverse(lines.begin(), lines.end());
    for (string& s : lines)
        cout << s << endl;
    cout << symbols << endl;
    fin.close();
    fout.close();
    return 0;
}

