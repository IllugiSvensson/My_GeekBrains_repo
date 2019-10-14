#include <iostream>
#include <cmath>
#include <boost/cstdint.hpp>
using namespace std;

//Задача 2
//Создать объекты для каждого из классов и посмотреть, в какой
//последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти».
class Car {
protected:

    string company;
    string model;

public:

    Car(string c = "someCompany", string m = "someModel"): company(c), model(m) {

        cout << "Company: " << company << " " << "Model: " << model << endl;

    }

};

class PassangerCar : virtual public Car {
public:

    PassangerCar(string c = "someCompany", string m = "someModel"): Car(c, m) {

        cout << "Company: " << company << " " << "Model: " << model << endl;
        cout << "Passanger Car"<< endl;

    }

};

class Bus : virtual public Car {
public:

    Bus(string c = "someCompany", string m = "someModel"): Car(c, m) {

        cout << "Company: " << company << " " << "Model: " << model << endl;
        cout << "Bus" << endl;

    }

};

class Minivan : public PassangerCar, public Bus {       //Появляется конфликт. Нужно явно определять
public:                                                 //свойства какого родителя использовать

    Minivan(string c = "someCompany", string m = "someModel"): Bus(c, m), PassangerCar(c, m), Car(c, m) {

        cout << "Company: " << company << " " << "Model: " << model << endl;
        cout << "Minivan" << endl;
    }

};

int main(int argc, char *argv[]) {

    Car car;                                    //Конструкторы вызываются последовательно от
    cout << endl;                               //самого базового класса до самого дочернего
    PassangerCar passangerCar("Ford", "Focus"); //При ситуации с "алмазом смерти" нужно явно указать
    cout << endl;                               //родителя. В моем случае я вызываю конструктор и свойство родителя Bus
    Bus bus("Ikarus", "Lux");                   //который инициализирует модель минивэна заданным параметром
    cout << endl;                               //Компания же унаследована от PassCar, а она унаследовала от Car и
    Minivan minivan("Dodge", "Caravan");        //она не инициализировалась.

return 0;
}
