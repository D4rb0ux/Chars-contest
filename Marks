//Преподаватель Васиной группы наконец-то начал объявлять оценки за прошедшие работы. 
//Так как важен не набор оценок, а средняя, то после каждого объявления студент, которому сообщили новую оценку, 
//хочет знать среднее своих оценок по уже объявленным работам. 
//Напишите программу, которая избавит Васиных одногруппников от лишнего ручного счета.

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n, mark;
    string name;
    cin >> n;
    map<string, pair<long long, long long>> students;
    for (int i = 0; i < n; i++) {
        cin >> name >> mark;
        students[name].first += mark;
        students[name].second++;
        cout << students[name].first / students[name].second << endl;
    }
    return 0;
}
