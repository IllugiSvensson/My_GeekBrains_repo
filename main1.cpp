#include <iostream>
#include <cmath>
#include <boost/cstdint.hpp>
using namespace std;

//Задача 1
class Person {
private:

    string m_name;
    int m_age;
    string m_gender;
    int m_weight;

public:

    Person(string n = "Person", int a = 17, string g = "male", int w = 70)
        : m_name(n), m_age(a), m_gender(g), m_weight(w) {

    }

    string getName() const { return m_name; }
    int getAge() const { return m_age; }
    string getGender() const { return m_gender; }
    int getWeight() const { return m_weight; }

    void setName(string n) {

        m_name = n;

    }

    void setAge(int a) {

        m_age = a;

    }

    void setGender(string g) {

        m_gender = g;

    }

    void setWeight(int w) {

        m_weight = w;

    }

};

class Student: public Person {
private:

    int m_year;

public:

    Student(string n = "Person", int a = 17, string g = "male", int w = 70, int y = 2000)
        : Person(n, a, g, w), m_year(y) {

    }

    int getYear() const { return m_year; }

    void setYear(int y) {

        m_year = y;

    }

    void increaseYear() {

        m_year ++;

    }

};

int main(int argc, char *argv[]) {

    Person person;

    cout << person.getName() << " " << person.getGender()
         << " " << person.getAge() << " " << person.getWeight() << endl;

        person.setName("Anna");
        person.setGender("female");
        person.setAge(21);
        person.setWeight(55);

    cout << person.getName() << " " << person.getGender()
         << " " << person.getAge() << " " << person.getWeight() << endl;

    cout << endl;

    Student student;

    cout << student.getName() << " " << student.getGender() << " " << student.getAge()
         << " " << student.getWeight() << " " << student.getYear() << endl;

        student.setYear(2019);

    cout << student.getYear() << endl;

        student.increaseYear();

    cout << student.getYear() << endl << endl;

return 0;
}
