#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cassert>
#include <iterator>

using namespace std;

class ArrayInt {
private:
    int length;
    int *data;
public:
    ArrayInt() : length(0), data(NULL) { }
    ArrayInt(int l) : length(l) {
        assert(l>=0);

        if (l > 0)
            data = new int[l];
        else
            data = NULL;
    }
    ~ArrayInt() { delete[] data; }
    void erase() {
        delete[] data;
        data = NULL;
        length = 0;
    }
    int size() {
        return length;
    }
    int& operator[] (int index) {
        assert(index >=0 && index<length);
        return data[index];
    }
    void resize(int newLength){
        if (length==newLength) return;
        if (newLength <=0){
            erase();
            return;
        }
        int *d = new int[newLength];
        if (length>0){
            int elements = (newLength>length) ? length : newLength;
            for (int index=0; index<elements; ++index){
                d[index] = data[index];
            }
        }
        delete[] data;
        data = d;
        length = newLength;
    }
    void insertBefore(int value, int index){
        assert(index >=0 && index <=length);
        int *d = new int[length+1];
        for (int i = 0; i<index; ++i){
            d[i] = data[i];
        }
        d[index] = value;
        for(int i = index; i<length; ++i){
            d[i+1] = data[i];
        }
        delete[] data;
        data = d;
        ++length;
    }
    void push_back(int value) {
        insertBefore(value, length);
    }

    //Методы для ДЗ.

    void removeBefore(int index) {

        assert(index >= 0 && index <= length);

            int *d = new int[length - 1];

            for(int i = 0; i < index; ++ i) {

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

        assert(index >= 0 && index <= length);

//        for(int i = 0; i < quantity; ++i) {       //Работает, но трудозатратно

//            insertBefore(array[i], index + i);

//        }

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

    int getLength() {

        return length;

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
    int array[5] = {11, 12, 13, 10, 8};

        for(int i = 0; i < 5; i++) {

        arr.push_back(i);

    }

        for(int i = 0; i < arr.getLength(); i++)
            cout << arr[i] << " ";
            cout << endl;

    arr.insertBefore(9, 4);   //Добавим 9 в позицию 4

        for(int i = 0; i < arr.getLength(); i++)
            cout << arr[i] << " ";
            cout << endl;

    arr.removeBefore(1);       //Уберем элемент с позиции 1

        for(int i = 0; i < arr.getLength(); i++)
            cout << arr[i] << " ";
            cout << endl;

    arr.pop_back();             //Два раза уберем последний элемент
    arr.pop_back();

        for(int i = 0; i < arr.getLength(); i++)
            cout << arr[i] << " ";
            cout << endl;

    arr.insertArray(array, 1, 5);   //Вставим 5 элементов массива, начиная с позиции 1

        for(int i = 0; i < arr.getLength(); i++)
            cout << arr[i] << " ";
            cout << endl;

    arr.sort(arr.getLength(), "forward");
    arr.sort(arr.getLength(), "backward");

return 0;
}
