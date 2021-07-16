//Во входной строке записана последовательность чисел через пробел. Для каждого числа выведите слово YES (в отдельной строке), 
//если это число ранее встречалось в последовательности или NO, если не встречалось.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int x;
    while (cin >> x)
        v.push_back(x);
    vector<int> u(100000, 0);
    for (size_t i = 0; i != v.size(); i++) {
        if (u[v[i]] != 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        u[v[i]]++;
    }
    return 0;
}

