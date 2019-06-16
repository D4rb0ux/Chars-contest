//Преподаватель Алексей собрался подвести итоги модуля и выставить студентам накопленные оценки. 
//Он скачал из Яндекс.Контеста файлы с итогами домашних и контрольных работ. 
//В файлах построчно записаны логины студентов и набранные баллы. 
//Если студент ничего не сдавал в данном контесте, то записи о нём не будет. 
//В таком случае считается, что он получил за этот контест 0 баллов.
//Напишите программу, строящую итоговую таблицу с результатами.

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, k, mark;
    string name;
    cin >> n;
    set<string> allnames;
    vector<map<string, int>> contest;
    for (int i = 0; i < n; i++) {
        cin >> k;
        map<string, int> result;
        for (int j = 0; j < k; j++) {
            cin >> name >> mark;
            allnames.insert(name);
            result[name] = mark;
        }
        contest.push_back(result);
    }
    vector<string> names;
    for (auto& name : allnames) {
        names.push_back(name);
    }
    sort(names.begin(), names.end());
    for (auto& name : names) {
        cout << name << "\t";
        for (int i = 0; i < n; i++) {
            if (contest[i].find(name) != contest[i].end())
                cout << contest[i][name] << "\t";
            else
                cout << 0 << "\t";
        }
        cout << endl;
    }
    return 0;
}

