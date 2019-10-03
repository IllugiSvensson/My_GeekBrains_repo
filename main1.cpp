#include <iostream>
#include <cmath>
#include <boost/cstdint.hpp>
using namespace std;

//Задача 1
class Power {
private:

    float A = 1;
    float B = 1;

public:

    Power () { //конструктор по умолчанию инициализирует переменные выше

    }

    void set(float a, float b) {

        A = a;
        B = b;

    }

    void calculate() {

        cout << "A ^ B = " << pow(A, B) << endl;

    }

};

//Задача 2
class RGBA {
private:

    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;

public:

    RGBA(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255):
        m_red(r), m_green(g), m_blue(b), m_alpha(a) {

    }

    void print() {

        cout << "Red: " << m_red << endl;
        cout << "Green: " << m_green << endl;
        cout << "Blue: " << m_blue << endl;
        cout << "Alpha: " << m_alpha << endl;

    }

};

//Задача 3
class Stack {
private:

    int array[10];
    int track;

public:

    void reset() {

        track = 0;

            for(int i = 0; i < 10; i++) {

                array[i] = 0;

            }

    }

    void push(int data) {

        if(track < 10) {

            array[track] = data;
            track++;
            //cout << "true" << endl;

        } else

            cout << "false" << endl;

    }

    int pop() {

        int arr;

            if(track > 0) {

                arr = array[track];
                track--;

            } else

                cout << "Стек пуст" << endl;

    return arr;
    }

    void print() {

    cout << "(";

        for(int i = 0; i < track; i++) {

            cout << array[i] << " ";

        }

    cout << ")" << endl;

    }

};

int main(int argc, char *argv[]) {

//Задача 1
    Power pw;
    float a, b;
        cout << "Введите первое число: ";
        cin >> a;
        cout << "Введите второе число: ";
        cin >> b;

            pw.set(a, b);
            pw.calculate();

//Задача 2
    uint8_t r, g, bl, al;
        cout << "Введите уровень красного: ";
        cin >> r;
        cout << "Введите уровень зеленого: ";
        cin >> g;
        cout << "Введите уровень синего: ";
        cin >> bl;
        cout << "Введите уровень альфа: ";
        cin >> al;

    RGBA rgba(r, g, bl, al);

        rgba.print();

//Задача 3
//В курсе по алгоритмам стек делали чуточку по другому.
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

return 0;
}
