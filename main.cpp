#include <iostream>
#include <string>
using namespace std;

class Date {
private:

    int m_day;
    int m_month;
    int m_year;

public:
    Date(int day, int month, int year);

    void setDate(int day, int month, int year);

    int getDay() const { return m_day; }
    int getMonth() const { return m_month; }
    int getYear() const { return m_year; }

};

// Конструктор класса Date
Date::Date(int day, int month, int year)
{
    setDate(day, month, year);
}

// Метод класса Date
void Date::setDate(int day, int month, int year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

class Bar {
private:

    static int number;
    int value;
    int value2;

public:

    Bar() { number++; }
    Bar(int value, int value2) {

        this -> value = value;
        this -> value2 = value2;
        cout << "Constructor" << endl;

    }

    Bar(Bar &b) {

        this -> value = b.value;
        this -> value2 = b.value2;
        number++;
        cout << "Constructor" << endl;

    }

    ~Bar() {

        number--;
        cout << "Destructor" << endl;

    }

    static int getNumber() { return number; }
    int getValue() const { return value; }
    Bar &setValue(int x) { value = x; return *this; }
    int getValue2() const { return value2; }
    Bar &setValue2(int x) { value2 = x; return *this; }

};

int Bar::number = 0;

// Мы передаем объект date по константной ссылке, чтобы избежать создания копии объекта date
//Объект передается по константной ссылке, копия объекта не создается
void printDate(const Date &date)
{
    std::cout << date.getDay() << "." << date.getMonth() << "." << date.getYear() << '\n';
}

class Animal {
protected:
    string name;
    int age;

public:
    Animal(string n, int a) { name = n; age = a; }
    string getName() const { return name; }
    int getAge() const { return age; }
    void setAge(int a) { age = a; }
};

class Pet : public Animal {
private:
    string owner;

public:
    Pet(string o, string n, int a):Animal(n, a) { owner = o; }
    string getOwner() const { return owner;}
    void print() { cout << name << endl << age << endl << owner << endl; }
    friend void resetAge(Pet &pet);
    friend class Dog;
};
void resetAge(Pet &pet) {
    pet.age = 0;
}
class Dog: public Animal {
public:

    Dog(string n, int a):Animal(n, a) { }
    bool compareAge(Pet &pet, Dog &dog) {
        return dog.age<pet.age;
    }

};

class School
{
private:
    int m_number;
        string m_type;
public:
    School(int number, string type) : m_number(number), m_type(type)
    { }
};

class Employee
{
private:
    string m_employer;
    double m_wage;
public:
    Employee(string employer, double wage)
    : m_employer(employer), m_wage(wage)
    { }
};

// класс Teacher открыто наследует свойства классов Human и Employee
class Teacher: public School, public Employee
{
private:
    int m_teachesGrade;
public:
    Teacher(int number, string type, string employer, double wage, int teachesGrade)
    : School(number, type), Employee(employer, wage), m_teachesGrade(teachesGrade)
    { }
};


int main()
{
    Date date(12, 11, 2018);
    printDate(date);


    Bar bar(10, 20);
//    bar.setValue(15).setValue2(25);
//    cout << bar.getValue() << endl;
    Bar bar2(bar);

    Pet cat("Mike", "Tom", 5);
    cat.print();
    Dog dog("Spike", 3);
    dog.compareAge(cat, dog);
    resetAge(cat);
    cat.print();

    Animal *p;
    Animal animal("somepet", 4);
    p = &animal;
    p -> setAge(6);
    p = &dog;
    p -> setAge(10);

    return 0;
}
