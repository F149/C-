////////////////////////////////////////////////////////////////////////////////
//
//  Тренировочное задание по программированию: Список студентов
//    Определите структуру "Студент" с полями имя, фамилия, дата, месяц и
//    год рождения. Создайте вектор из таких структур, заполните его из входных
//    данных и затем по запросам выведите нужные поля.
//
//  Формат ввода
//    Первая строка содержит одно целое число N от 0 до 10000 - число студентов.
//    Далее идут N строк, каждая из которых содержит две строки длиной от 1 до
//    15 символов - имя и фамилия очередного студента, и три целых числа от 0
//    до 1000000000 - день, месяц и год рождения.
//    Следующая строка содержит одно целое число M от 0 до 10000 - число запросов.
//    Следующие M строк содержат строку длиной от 1 до 15 символов - запрос, и
//    целое число от 0 до 1000000000 - номер студента (нумерация начинается с 1).
//
//  Формат вывода
//    Для запроса вида "name K", где K от 1 до N, выведите через пробел имя
//    и фамилию K-го студента.
//    Для запроса вида "date K", где K от 1 до N, выведите через точку число,
//    месяц и год рождения K-го студента.
//    Для остальных запросов выведите "bad request".
//
//  Пример ввода
//      3
//      Ivan Ivanov 1 1 1901
//      Petr Petrox 2 2 1902
//      Alexander Sidorov 3 3 1903
//      3
//      name 1
//      date 3
//      mark 5
//
//  Пример вывода
//      Ivan Ivanov
//      3.3.1903
//      bad request
//
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    Student(string other_firstname, string other_lastname, int other_day, int other_month, int other_year) {
        firstname = other_firstname;
        lastname = other_lastname;
        day = other_day;
        month = other_month;
        year = other_year;
    }
    string firstname = "";
    string lastname = "";
    int day = 0;
    int month = 0;
    int year = 0;
};

int main() {
    string firstname, lastname;
    int day, month, year;
    vector<Student> v;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> firstname >> lastname >> day >> month >> year;
        Student student{firstname, lastname, day, month, year};
        v.push_back(student);
    }

    int m;
    cin >> m;

    for (int j = 0; j < m; ++j) {
        string operation;
        int k;
        cin >> operation >> k;
        if (operation == "name" && k > 0 && k <= v.size()) {
            cout << v[k-1].firstname << " " << v[k-1].lastname << endl;
        } else if (operation == "date" && k > 0 && k <= v.size()) {
            cout << v[k-1].day << "." << v[k-1].month << "." << v[k-1].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}
