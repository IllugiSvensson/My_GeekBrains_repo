#include <iostream>
#include <string>
using namespace std;
class Cap {
public:
    string getColor() {
        return color;
    }
private:
    // Пусть все кепки будут красными.
    string color = "красный";
};

class Human
{
public:
    void Think()
    {
        brain.Think();
    }
    void InspectTheCap () {
        cout << "Моя кепка имеет " << cap.getColor() << " цвет.";
    }

private:
    class Brain
    {
    public:
        void Think()
        {
            cout << "Я думаю!" << endl;
        }
    };
    Brain brain;
    Cap cap;
};

int main()
{
    Human human;
    human.Think();
    human.InspectTheCap();
}



//Aggregation
//class Worker
//{
//private:
//    string m_name;

//public:
//    Worker(string name) : m_name(name)
//    { }
//    string getName() { return m_name; }
//};

//class Department
//{
//private:
//    // Для простоты добавим только одного работника
//    Worker *m_worker;
//public:
//    Department(Worker *worker = nullptr) : m_worker(worker)
//    {  }
//};

//int main()
//{
//    // Создаем нового работника
//    Worker *worker = new Worker("Anton");
//    {
//        // Создаем Отдел и передаем Работника в Отдел через параметр конструктора
//        Department department(worker);
//    } // department выходит из области видимости и уничтожается здесь

//    // worker продолжает существовать
//    cout << worker->getName() << " still exists!";
//    delete worker;

//    return 0;
//}


//assotiation
#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string m_name;
    int m_id;

public:
    Car(string name, int id) : m_name(name), m_id(id)
    { }

    string getName() { return m_name; }
    int getId() { return m_id;  }
};


// Данный класс содержит автомобили и имеет функцию для "выдачи" автомобиля
//class CarLot
//{
//private:
//    static Car s_carLot[4];

//public:
//    // Удаляем конструктор по умолчанию, чтобы нельзя было создать объект этого класса
//    CarLot() = delete;

//    static Car* getCar(int id)
//    {
//        for (int count = 0; count < 4; ++count)
//            if (s_carLot[count].getId() == id)
//                return &(s_carLot[count]);

//        return nullptr;
//    }
//};

//Car CarLot::s_carLot[4] = { Car("Camry", 5), Car("Focus", 14), Car("Vito", 73), Car("Levante", 58) };

//class Driver
//{
//private:
//    string m_name;
//    int m_carId; // для связывания классов используется эта переменная

//public:
//    Driver(string name, int carId) : m_name(name), m_carId(carId)
//    {  }
//    string getName() { return m_name; }
//    int getCarId() { return m_carId; }

//};

//int main()
//{
//    Driver d("Ivan", 14); // Ivan ведет машину с ID 14

//    Car *car = CarLot::getCar(d.getCarId()); // Получаем этот Автомобиль из CarLot

//    if (car)
//        cout << d.getName() << " is driving a " << car->getName() << '\n';
//    else
//        cout << d.getName() << " couldn't find his car\n";

//    return 0;
//}

//Car CarLot::s_carLot[4] = { Car("Camry", 5), Car("Focus", 14), Car("Vito", 73), Car("Levante", 58) };

//class Driver
//{
//private:
//    string m_name;
//    int m_carId; // для связывания классов используется эта переменная

//public:
//    Driver(string name, int carId) : m_name(name), m_carId(carId)
//    {  }
//    string getName() { return m_name; }
//    int getCarId() { return m_carId; }

//};



//int main()
//{
//    Driver d("Ivan", 14); // Ivan ведет машину с ID 14

//    Car *car = CarLot::getCar(d.getCarId()); // Получаем этот Автомобиль из CarLot

//    if (car)
//        cout << d.getName() << " is driving a " << car->getName() << '\n';
//    else
//        cout << d.getName() << " couldn't find his car\n";

//    return 0;
//}
