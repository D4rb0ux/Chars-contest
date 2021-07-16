//Вам дан список всех файлов в файловой системе. Вам необходимо вывести все непустые директории в лексикографическом порядке.
//Гарантируется, что все пути начинаются от корня файловой системы. 
//Гарантируется, что все пути состоят из слешей, латинских символов, цифр и точек. 
//Гарантируется, что два слеша никогда не стоят подряд.

#include <iostream>
#include <string>
#include <set>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    string dir;
    set<string> directories;
    while (getline(fin, dir)) {
        string str;
        for (const char& c : dir) {
            if (c != '/') {
                str += c;
            } else {
                str += c;
                directories.insert(str);
            }
        }
    }
    for (auto& elem : directories)
        cout << elem << endl;
    return 0;
}

