#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cassert>

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



    void removeBefore(int index) {

        assert(index >=0 && index <=length);

        int *d = new int[length - 1];

            for(int i = 0; i < index; ++ i) {

                d[i] = data[i];

            }

            for(int i = index; i < length; ++i){

                d[i] = data[i + 1];

            }

        delete[] data;
        data = d;
        --length;

    }

    void pop_back() {
        removeBefore (length);
    }

    void insertArray(int array[], int index) {

        assert(index >= 0 && index <= length);

        int arrlength = sizeof(array) / sizeof(array[0]);

        int *d = new int[length + arrlength];

            for(int i = 0; i < index; ++i){

                d[i] = data[i];

            }

            for(int i = 0; i < arrlength; i++) {

                d[index + i] = array[i];

            }

        for(int i = index + arrlength; i < length; ++i){
            d[i ] = data[i];
        }

        delete[] data;
        data = d;
        length = length + arrlength;
    }

};

int main() {

    ArrayInt arr;
    int array[3] = {11, 12, 13};

    for(int i = 0; i < 5; i++) {

        arr.push_back(i);

    }

    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    arr.insertBefore(9, 4);

    for(int i = 0; i < 6; i++) cout << arr[i] << " ";
    cout << endl;

//    arr.removeBefore(2);

//    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
//    cout << endl;

//    arr.pop_back();
//    arr.pop_back();
//    arr.removeBefore(0);

//    for(int i = 0; i < 2; i++) cout << arr[i] << " ";
//    cout << endl;

    arr.insertArray(array, 1);

    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;


return 0;
}
