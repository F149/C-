///////////////////////////////////////////////////////////////////////////////
//
// Задание по программированию: Автобусные остановки — 1
//  Реализуйте систему хранения автобусных маршрутов.
//
// Вам нужно обрабатывать следующие запросы:
//
// NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с
//  названием bus и stop_count остановками с названиями stop1, stop2, ...
// BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса,
//  проходящих через остановку stop.
// STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со
//  списком автобусов, на которые можно пересесть на каждой из остановок.
// ALL_BUSES — вывести список всех маршрутов с остановками.
//
// Формат ввода
//  В первой строке ввода содержится количество запросов Q, затем в Q
//  строках следуют описания запросов.
//
//  Гарантируется, что все названия маршрутов и остановок состоят лишь
//  из латинских букв, цифр и знаков подчёркивания.
//
//  Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется,
//  что маршрут bus отсутствует, количество остановок больше 0, а после
//  числа stop_count следует именно такое количество названий остановок,
//  причём все названия в каждом списке различны.
//
//  Формат вывода
// Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:
//
// На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов,
//  проезжающих через эту остановку, в том порядке, в котором они
//  создавались командами NEW_BUS. Если остановка stop не существует,
//  выведите No stop.
// На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus
//  в отдельных строках в том порядке, в котором они были заданы в
//  соответствующей команде NEW_BUS. Описание каждой остановки stop должно
//  иметь вид Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов,
//  проезжающих через остановку stop, в порядке, в котором они создавались
//  командами NEW_BUS, за исключением исходного маршрута bus. Если через
//  остановку stop не проезжает ни один автобус, кроме bus, вместо списка
//  автобусов для неё выведите no interchange. Если маршрут bus не существует,
//  выведите No bus.
// На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке.
//  Описание каждого маршрута bus должно иметь вид Bus bus:
//  stop1 stop2 ..., где stop1 stop2 ... — список остановок автобуса
//  bus в порядке, в котором они были заданы в соответствующей команде
//  NEW_BUS. Если автобусы отсутствуют, выведите No buses.
//
// Пример:
//  Ввод
//   10
//   ALL_BUSES
//   BUSES_FOR_STOP Marushkino
//   STOPS_FOR_BUS 32K
//   NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
//   NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
//   BUSES_FOR_STOP Vnukovo
//   NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
//   NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
//   STOPS_FOR_BUS 272
//   ALL_BUSES
//
//  Вывод
//   No buses
//   No stop
//   No bus
//   32 32K
//   Stop Vnukovo: 32 32K 950
//   Stop Moskovsky: no interchange
//   Stop Rumyantsevo: no interchange
//   Stop Troparyovo: 950
//   Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
//   Bus 32: Tolstopaltsevo Marushkino Vnukovo
//   Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
//   Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int q;
    cin >> q;
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus;
            cin >> stop_count;
            vector<string> v(stop_count);
            for (string& s : v) {
                cin >> s;
                vector<string> v2;
                v2.push_back(bus);
                if (stops.count(s)) {
                    stops[s].insert(end(stops[s]), begin(v2), end(v2));
                } else {
                    stops[s] = v2;
                }
            }
            buses[bus] = v;
        } else if (operation_code == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (stops[stop].size() == 0) {
                cout << "No stop" << endl;
                stops.erase(stop);
            } else {
                for (const auto& item : stops) {
                    if (item.first == stop) {
                        for (string w : item.second) {
                            cout << w << " ";
                        }
                        cout << endl;
                    }
                }
            }
        } else if (operation_code == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (buses.count(bus) > 0) {
                for (const auto& item : buses) {
                    if (item.first == bus) {
                        for (string w : item.second) {
                            cout << "Stop " << w << ": ";
                            for (const auto& item2 : stops) {
                                if (item2.first == w) {
                                    if (item2.second.size() == 1) {
                                        cout << "no interchange" << endl;
                                    } else {
                                        for (string w2 : item2.second) {
                                            if (w2 != bus) {
                                                cout << w2 << " ";
                                            }
                                        }
                                        cout << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                cout << "No bus" << endl;
            }
        } else if (operation_code == "ALL_BUSES") {
            if (buses.size() == 0) {
                cout << "No buses" << endl;
            } else {
                for (const auto& item : buses) {
                    cout << "Bus " << item.first << ": ";
                    for (string w : item.second) {
                        cout << w << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
    }

    return 0;
}
