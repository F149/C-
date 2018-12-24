#include <iostream>
#include <sstream>

using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        if (numerator == 0) {
            num = 0;
            den = 1;
        } else {
            int n = Nod(numerator, denominator);
            num = numerator / n;
            den = denominator / n;
            CheckSign();
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        return num;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return den;
    }

private:
    // Добавьте поля
    int num;
    int den;

    int Nod(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (a != 0 && b != 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }
        return (a + b);
    }

    void CheckSign() {
        if ((num < 0 && den < 0) || (num >= 0 && den < 0)) {
            num *= -1;
            den *= -1;
        }
    }
};

bool operator==(Rational rat_1, Rational rat_2) {
    return (rat_1.Numerator() == rat_2.Numerator() && rat_1.Denominator() == rat_2.Denominator());
};

// Реализуйте для класса Rational операторы << и >>

ostream &operator<<(ostream &stream, const Rational &rat) {
    stream << rat.Numerator() << '/' << rat.Denominator();
    return stream;
}

istream &operator>>(istream &stream, Rational &rat) {

    int p = rat.Numerator();
    int q = rat.Denominator();
    //char sep;
    stream >> p;
    stream.ignore(1);
    stream >> q;

    rat = {p, q};

    return stream;
}


int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
