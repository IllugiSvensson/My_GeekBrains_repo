#include <iostream>
#include <cmath>
#include <boost/cstdint.hpp>
using namespace std;

//Задача 3
// -, *, /) для выполнения действий с дробями, а также
//унарный оператор (-). Перегрузить логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
//Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
class Fraction {
protected:

    int numerator;
    int denominator;

public:

    Fraction(int n = 0, int d = 1): numerator(n), denominator(d) {

        if(denominator == 0) {

            cout << "Value is infinit. Denominator increased to 1" << endl;
            denominator = 1;

        }

    }

};

class SimpleFraction: public Fraction {
public:

    SimpleFraction(int n = 0, int d = 1): Fraction(n, d) {

    }

    int getNum() const {

        return numerator;

    }

    int getDen() const {

        return denominator;

    }

    friend class MixedFraction;

};

class MixedFraction: public Fraction {
protected:

    int integerpart;

public:

    MixedFraction(int n = 0, int d = 1, int i = 0): Fraction(n, d), integerpart(i) {

        if(integerpart != 0) {

            numerator = denominator * integerpart + numerator;

        }

    }

    int getNum() const {

        return (integerpart * denominator) + numerator;

    }

    int getDen() const {

        return denominator;

    }

    MixedFraction operator+ (SimpleFraction b);

    MixedFraction operator- () {

        return MixedFraction(-numerator, denominator);

    }

    friend MixedFraction operator- (SimpleFraction a, MixedFraction b);
    friend MixedFraction operator*
    void print() {

        cout << numerator << " / " << denominator << endl;

    }

};

MixedFraction MixedFraction::operator+ (SimpleFraction b) {

    int cd = denominator * b.denominator;
    int ns = numerator * b.denominator + b.numerator * denominator;

        MixedFraction sum(ns, cd);

    return sum;

}

int main(int argc, char *argv[]) {

    SimpleFraction simple(3, 2);
    cout << simple.getNum() << " / " << simple.getDen() << endl;

    MixedFraction mixed(3, 4, 2);
    cout << mixed.getNum() << " / " << mixed.getDen() << endl;

    MixedFraction sum;
    sum = mixed + simple;
    sum.print();

return 0;
}
