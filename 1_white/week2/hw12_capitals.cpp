///////////////////////////////////////////////////////////////////////////////
//
// Тренировочное задание по программированию: Справочник столиц
// Реализуйте справочник столиц стран.
//
// На вход программе поступают следующие запросы:
//
// CHANGE_CAPITAL country new_capital — изменение столицы страны country
//  на new_capital, либо добавление такой страны с такой столицей, если раньше
//  её не было.
// RENAME old_country_name new_country_name — переименование страны из
//  old_country_name в new_country_name.
// ABOUT country — вывод столицы страны country.
// DUMP — вывод столиц всех стран.
//
// Формат ввода
// В первой строке содержится количество запросов Q, в следующих Q
// строках — описания запросов. Все названия стран и столиц состоят лишь
// из латинских букв, цифр и символов подчёркивания.
//
// Формат вывода
// Выведите результат обработки каждого запроса:
//
// В ответ на запрос CHANGE_CAPITAL country new_capital выведите
//
//  Introduce new country country with capital new_capital, если страны country
//  раньше не существовало;
//  Country country hasn't changed its capital, если страна country до текущего
//  момента имела столицу new_capital;
//  Country country has changed its capital from old_capital to new_capital,
//  если страна country до текущего момента имела столицу old_capital, название
//  которой не совпадает с названием new_capital.
//
// В ответ на запрос RENAME old_country_name new_country_name выведите
//
//  Incorrect rename, skip, если новое название страны совпадает со старым,
//  страна old_country_name не существует или страна new_country_name уже существует;
//  Country old_country_name with capital capital has been renamed to
//  new_country_name, если запрос корректен и страна имеет столицу capital.
//
// В ответ на запрос ABOUT country выведите
//
//  Country country doesn't exist, если страны с названием country не существует;
//  существует Country country has capital capital, если страна country существует и имеет столицу capital.
//
// В ответ на запрос DUMP выведите
//
//   There are no countries in the world, если пока не было добавлено ни одной страны;
//   разделённые пробелами пары country/capital, описывающие столицы всех стран и упорядоченные по названию страны, если в мире уже есть хотя бы одна страна.
//
// Пример.
// Ввод:
//   6
//   CHANGE_CAPITAL RussianEmpire Petrograd
//   RENAME RussianEmpire RussianRepublic
//   ABOUT RussianRepublic
//   RENAME RussianRepublic USSR
//   CHANGE_CAPITAL USSR Moscow
//   DUMP
// Вывод:
//   Introduce new country RussianEmpire with capital Petrograd
//   Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
//   Country RussianRepublic has capital Petrograd
//   Country RussianRepublic with capital Petrograd has been renamed to USSR
//   Country USSR has changed its capital from Petrograd to Moscow
//   USSR/Moscow
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <map>

using namespace std;


void PrintMap(const map<string, string>& m) {
    for (const auto& item : m) {
        cout << item.first << "/" << item.second << " ";
    }
    cout << endl;
}

int main() {
    int q;
    cin >> q;
    map<string, string> countries;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (countries[country] == "") {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
                countries.erase(country);
            } else if (countries[country] == new_capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else if (countries[country] != new_capital) {
                cout << "Country " <<  country << " has changed its capital from " << countries[country] << " to " << new_capital << endl;
            }
            countries[country] = new_capital;
        } else if (operation_code == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (new_country_name == old_country_name) {
                cout << "Incorrect rename, skip" << endl;
            } else if (countries.count(new_country_name)) {
                cout << "Incorrect rename, skip" << endl;
            } else if (countries[old_country_name] == "") {
                cout << "Incorrect rename, skip" << endl;
                countries.erase(old_country_name);
            } else {
                cout << "Country " << old_country_name << " with capital " << countries[old_country_name] << " has been renamed to " << new_country_name << endl;
                countries[new_country_name] = countries[old_country_name];
                countries.erase(old_country_name);
            }
        } else if (operation_code == "ABOUT") {
            string country;
            cin >> country;
            if (countries[country] == "") {
                cout << "Country " << country << " doesn't exist" << endl;
                countries.erase(country);
            } else {
                cout << "Country " << country << " has capital " <<  countries[country] << endl;
            }
        } else if (operation_code == "DUMP") {
            if (countries.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                PrintMap(countries);
            }
        }
    }
    return 0;
  }
