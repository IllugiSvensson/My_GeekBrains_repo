#include <iostream>
#include <cmath>
using namespace std;

//?????? 3 ????? 3
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

        return numerator;

    }

    int getDen() const {

        return denominator;

    }

    friend class SimpleFraction;

    MixedFraction operator+ (SimpleFraction b);

    MixedFraction operator- () {

        return MixedFraction(-numerator, denominator);

    }

    MixedFraction operator- (SimpleFraction b);

    MixedFraction operator* (SimpleFraction b);

    MixedFraction operator/ (SimpleFraction b);

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

MixedFraction MixedFraction::operator- (SimpleFraction b) {

    int cd = denominator * b.denominator;
    int ns = numerator * b.denominator - b.numerator * denominator;

        MixedFraction subtr(ns, cd);

return subtr;
}

MixedFraction MixedFraction::operator* (SimpleFraction b) {

  int np = numerator * b.numerator;
  int dp = denominator * b.denominator;

return MixedFraction(np, dp);
}

MixedFraction MixedFraction::operator/ (SimpleFraction b) {

  int np = numerator * b.denominator;
  int dp = denominator * b.numerator;

return MixedFraction(np, dp);
}

bool operator== (const MixedFraction &a, const SimpleFraction &b) {

  return bool(a.getNum() * b.getDen() == a.getDen() * b.getNum());

}

bool operator!= (const MixedFraction &a, const SimpleFraction &b) {

  return bool(a.getNum() * b.getDen() != a.getDen() * b.getNum());

}

bool operator> (const MixedFraction &a, const SimpleFraction &b) {

  return bool(a.getNum() * b.getDen() > a.getDen() * b.getNum());

}

bool operator<= (const MixedFraction &a, const SimpleFraction &b) {

  return !bool(a.getNum() * b.getDen() > a.getDen() * b.getNum());

}

bool operator< (const MixedFraction &a, const SimpleFraction &b) {

  return bool(a.getNum() * b.getDen() < a.getDen() * b.getNum());

}

bool operator>= (const MixedFraction &a, const SimpleFraction &b) {

  return !bool(a.getNum() * b.getDen() < a.getDen() * b.getNum());

}

int main(int argc, char *argv[]) {

    SimpleFraction simple(2, 4);
    cout << "Simple Fraction: " << simple.getNum() << " / " << simple.getDen() << endl;

    MixedFraction mixed(3, 4, 1);
    cout << "Mixed Fraction: " << mixed.getNum() << " / " << mixed.getDen() << endl;

    MixedFraction sum, subst, neg, mult, div;
    sum = mixed + simple;
    cout << "Sum: "; sum.print();

    subst = mixed - simple;
    cout << "Subst: "; subst.print();

    neg = -mixed;
    cout << "Neg: "; neg.print();

    mult = mixed * simple;
    cout << "Mult: "; mult.print();

    div = mixed / simple;
    cout << "Div: "; div.print();
    cout << endl;

     cout << "Equal: " << (mixed == simple) << endl;
     cout << "NotEqual: " << (mixed != simple) << endl;
     cout << "More: " << (mixed > simple) << endl;
     cout << "Less-equal: " << (mixed <= simple) << endl;
     cout << "Less: " << (mixed < simple) << endl;
     cout << "More-equal: " << (mixed >= simple) << endl;

return 0;
}
