//Напишите программу, которая будет по списку поступающих и университетов определять, кто именно поступит в каждый университет.
//В каждом университете есть лимит мест, у каждого абитуриента есть определенный набранный балл и список предпочтений.
//Распределение происходит следующим образом: абитуриенты сортируются по убыванию баллов, при равенстве - по возрастанию
//даты рождения и, затем, по фамилии и имени.
//Далее каждый абитуриент по очереди зачисляется в первый университет из его списка, 
//в котором еще остались места (если таких нет - не зачисляется никуда).

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name, surname;
    size_t day, month, year;
    size_t points;
    vector<string> stud_uni;
};

int main() {
    int n;
    cin >> n;
    map<string, size_t> uni;
    string uni_name;
    size_t num_of_students;
    for (int i = 0; i < n; i++) {
        cin >> uni_name >> num_of_students;
        uni[uni_name] = num_of_students;
    }
    int m;
    cin >> m;
    vector<Student> students(m);
    for (int i = 0; i < m; i++) {
        cin >> students[i].name >> students[i].surname
            >> students[i].day >> students[i].month >> students[i].year
            >> students[i].points;
        int k;
        string uni_name;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> uni_name;
            students[i].stud_uni.push_back(uni_name);
        }
    }
    sort(students.begin(), students.end(), [](Student& s1, Student& s2) {
        if (s1.points != s2.points)
            return s1.points > s2.points;
        else if (s1.year != s2.year)
            return s1.year < s2.year;
        else if (s1.month != s2.month)
            return s1.month < s2.month;
        else if (s1.day != s2.day)
            return s1.day < s2.day;
        else if (s1.surname != s2.surname)
            return s1.surname < s2.surname;
        else
            return s1.name < s2.name;
    });
    map<string, vector<Student>> unis;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < students[i].stud_uni.size(); j++) {
            if (uni[students[i].stud_uni[j]] > 0) {
                unis[students[i].stud_uni[j]].push_back(students[i]);
                uni[students[i].stud_uni[j]]--;
                break;
            }
        }
    }
    for (auto& [key, val] : unis) {
        sort(val.begin(), val.end(), [](Student& s1, Student& s2) {
            if (s1.surname != s2.surname)
                return s1.surname < s2.surname;
            else if (s1.name != s2.name)
                return s1.name < s2.name;
            else if (s1.year != s2.year)
                return s1.year < s2.year;
            else if (s1.month != s2.month)
                return s1.month < s2.month;
            else
                return s1.day < s2.day;
        });
    }
    if (unis.size() < uni.size()) {
        for (auto& u : uni) {
            if (unis.find(u.first) == unis.end()) {
                Student s;
                s.name = "";
                s.surname = "";
                unis[u.first].push_back(s);
            }
        }
    }
    for (auto& uni : unis) {
        cout << uni.first << "\t";
        for (auto& s : uni.second) {
            if (s.name == "")
                cout << s.name << "\t";
            else
                cout << s.name << " " << s.surname << "\t";
        }
        cout << endl;
    }
    return 0;
}
