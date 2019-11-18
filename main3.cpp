#include <iostream>
#include <cmath>
#include <boost/cstdint.hpp>
using namespace std;

//Задача 3
class Array {
protected:

    static const unsigned int N = 5;
    int a[N];
    int am = 0;

public:

    Array() {   //Array(int n): N(n)

        for(int i = 0; i < N; i++) {

            a[i] = 0;

        }

    }

};

enum nominal {

    one = 1,
    five = 5,
    ten = 10,
    fifty = 50,
    oneHundred = 100

};

class Money: public Array {
private:

    nominal on, f, te, fi, oH;
    int s;

public:

    Money() {

        a[0] = one;
        a[1] = five;
        a[2] = ten;
        a[3] = fifty;
        a[4] = oneHundred;

    }

    int getSum(int q, int w, int e, int r, int t) {

        return (a[0] * q) + (a[1] * w) + (a[2] * e) + (a[3] * r) + (a[4] * t);

    }

};

int main(int argc, char *argv[]) {

    Money money;

    cout <<"Cash: " << money.getSum(0, 1, 2, 3, 4) << endl;


return 0;
}
