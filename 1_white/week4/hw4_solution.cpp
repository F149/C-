////////////////////////////////////////////////////////////////////////////////
//
//  Часть 1
//    Будем считывать из файлового потока по одной строке и сразу выводить
//    их в стандартный поток вывода.
//
//  Часть 2
//    В отличие от предыдущего решения, вывод будет осуществляться
//    в файловый поток.
//
////////////////////////////////////////////////////////////////////////////////
// output.cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    while (getline(input, line)) {
        output << line << endl;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
// input.cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    while (getline(input, line)) {
        cout << line << endl;
    }

    return 0;
}
////////////////////////////////////////////////////////////////////////////////
