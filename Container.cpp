#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
//Можно определить данный класс в заголовочном файле .h

class ArrayInt {
private:

    int length;
    int *data;

public:

    ArrayInt(): length(0), data(nullptr) {
    //Пустой массив
    }

    ArrayInt(int l): length(l) {

        assert(l >= 0);
        if (l > 0) {
            //Выделяем память для заданной длины массива
            data = new int[l];

        } else {

            data = nullptr;

        }

    }

    ~ArrayInt() {
            //Очищаем память
        delete[] data;

    }

    void erase() {  //Метод - аналог clear

        delete[] data;
        data = nullptr;
        length = 0;

    }

    int size() {    //Длина вектора

        return length;

    }

    int& operator[] (int index) {   //Перегрузка индексации
    //Ссылка на элемент, чтобы можно было изменять значения
        assert(index >= 0 && index < length);
        return data[index];

    }

    void resize(int newLength) {

        if (length == newLength) return;    //Проверка на равенство длины

        if (newLength <= 0) {       //Проверка на нулевую длину

            erase();
            return;

        }

        int *d = new int[newLength];    //Создаем новый массив

        if (length > 0) {

            int elements = (newLength > length) ? length : newLength;
                //Копируем все элементы в новый массив
            for (int index = 0; index < elements; index++) {

                d[index] = data[index];

            }


        }

        delete[] data;  //Удаляем старый массив
        data = d;
        length = newLength;

    }

    void insertBefore(int value, int index) {
            //Метод для вставки элемента в заданную позицию
        assert(index >= 0 && index <= length);
        int *d = new int[length + 1]; //Создаем массив больше старого на элемент

            for (int i = 0; i < index; ++i) {
                    //Копируем все элементы до заданной позиции
                d[i] = data[i];

            }

        d[index] = value;   //Вставляем новый элемент

            for(int i = index; i < length; ++i) {
                //Вставляем остальные элементы
                d[i + 1] = data[i];

            }

        delete[] data;  //Удаляем старый массив
        data = d;
        ++length;

    }

    void push_back(int value) { //На основе метода реализуем аналог push_back

        insertBefore(value, length);

    }

    void removeBefore(int index) {  //Аналогично реализуем удаление элемента

        assert(index >= 0 && index <= length);
        int *d = new int[length - 1];

            for(int i = 0; i < index; ++i) {

                d[i] = data[i];

            }

            for(int i = index; i < length ; ++i) {

                d[i] = data[i + 1];

            }

        delete[] data;
        data = d;
        --length;

    }

    void pop_back() {

        removeBefore(length);

    }

    void insertArray(int array[], int index, int quantity) {
        //Добавляем массив аналогично элементу
        assert(index >= 0 && index <= length);
        int *d = new int[length + quantity];

            for(int i = 0; i < index; ++i) {

                d[i] = data[i];

            }

            for(int i = 0; i < quantity; ++i) {

                d[index + i] = array[i];

            }

            for(int i = index + quantity; i < length + quantity; ++i) {

                d[i] = data[i - quantity];

            }

        delete[] data;
        data = d;
        length = length + quantity;

    }

    void sort(int quantity, string direction) {

        if (direction == "backward") {

            for(int i = 1; i < quantity; ++i) {

                for(int r = 0; r < quantity - i; r++) {

                    if(data[r] < data[r + 1]) {

                        int temp = data[r];

                            data[r] = data[r + 1];
                            data[r + 1] = temp;

                    }

                }

            }

        } else if(direction == "forward") {

            for(int i = 1; i < quantity; ++i) {

                for(int r = 0; r < quantity - i; r++) {

                    if(data[r] > data[r + 1]) {

                        int temp = data[r];

                            data[r] = data[r + 1];
                            data[r + 1] = temp;

                    }

                }

            }

        }

        for(int i = 0; i < quantity; ++i) {

            cout << data[i] << " ";

        }

        cout << endl;

    }

};

int main() {

    ArrayInt arr;
//erase, insertarray, removearray, sortup, sortdown
    for(int i = 1; i <= 15; i++) {

        arr.push_back(i * 3 / 2);   //Заполняем массив

    }

    cout << "Pushback:     ";
    for(int i = 0; i < arr.size(); i++) {

        cout << arr[i] << " ";  //Выводим массив

    }

    cout << endl << "Resize:       ";
    arr.resize(12);
    arr.resize(17);
    for(int i = 0; i < arr.size(); i++) {

        cout << arr[i] << " ";

    }

    cout << endl << "InsertBefore: ";
    arr.insertBefore(99, 3);     //Добавим 99 в позицию 4
    for(int i = 0; i < arr.size(); i++) {

        cout << arr[i] << " ";

    }

    cout << endl << "RemoveBefore: ";
    arr.removeBefore(0);       //Уберем элемент с позиции 1
    for(int i = 0; i < arr.size(); i++) {

        cout << arr[i] << " ";

    }

    cout << endl << "Popback:      ";
    arr.pop_back();       //Уберем элемент с конца массива

    for(int i = 0; i < arr.size(); i++) {

        cout << arr[i] << " ";

    }


int array[5] = {11, 12, 13, 10, 8};
    arr.insertArray(array, 1, 5);   //Вставим 5 элементов массива, начиная с позиции 1

        for(int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
            cout << endl;

    arr.sort(arr.size(), "forward");
    arr.sort(arr.size(), "backward");

return 0;
}

