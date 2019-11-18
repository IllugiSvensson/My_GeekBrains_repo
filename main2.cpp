#include <iostream>
#include <cmath>
#include <boost/cstdint.hpp>
using namespace std;

//Задача 2
class Fruit {
protected:

    string m_name;
    string m_color;

public:

    Fruit(string n = "somename", string c = "somecolor"): m_color(c), m_name(n) {

    }

    string getName() const { return m_name; }
    string getColor() const { return m_color; }

};

class Apple: public Fruit {
public:

    Apple(string c = "red", string n = "apple"): Fruit(n, c) {

    }

};

class Banana: public Fruit {
public:

    Banana(string n = "banana", string c = "yellow"): Fruit(n, c) {

    }

};

class GrannySmith: public Apple {
public:

    GrannySmith(string n = "Granny Smith", string c = "green"): Apple(c, n) {

    }

};

int main(int argc, char *argv[]) {

    Apple a("red");
    Banana b;
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

return 0;
}
