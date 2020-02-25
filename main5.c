//Смирнов Александр
#include <stdio.h>
#include <stdlib.h>

#define T char  //Для первой задачи поменять на int
#define MaxN 1000

T Stack[MaxN];
int N = -1;
typedef struct TNode {

    T value;
    struct Node *next;

} Node;
struct StackList {

    Node *head;
    int size;
    int maxSize;

};
struct StackList Stck;

void Push(T i) {

    if(N < MaxN) {

        N++;
        Stack[N] = i;

    } else {

        printf("Stack overflow!\n");

    }

}

void PushList(T value) {

//    if(Stck.size >= Stck.maxSize) {
//
//        printf("Error stack size");
//        return;

//    }

    Node *tmp = (Node*)malloc(sizeof(Node));
    if(tmp == NULL) {

        printf("Memory allocation error\n");
        exit(0);

    }

    tmp->value = value;
    tmp->next = Stck.head;
    Stck.head = tmp;
    Stck.size++;

}

T PopList() {

    if(Stck.size == 0) {

        printf("Stack is empty");
        return;

    }

    Node *next = NULL;
    T value;
    value = Stck.head->value;
    next = Stck.head;
    Stck.head = Stck.head->next;
    free(next);
    Stck.size--;

return value;
}

void PrintStack() {

    Node *current = Stck.head;

    while(current != NULL) {

        printf("%d ", current->value);
        current = current->next;

    }

}

T Pop() {

    if(N != -1) {

        return Stack[N--];

    } else {

        printf("Stack is empty!\n");

    }

}

int main(int argc, char *argv[]) {

//1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

    int dec;

        while(1) {

            printf("Введите число для перевода: ");
            scanf("%d", &dec);

                if(dec < 0) {

                    printf("Введите целое положительное число\n");

                } else if (dec == 0) {

                    Push(0);
                    break;

                } else break;

        }

        while(dec != 0) {

            Push(dec % 2);
            dec = dec / 2;

        }

            printf("Двоичное представление: ");

        while(N != -1) {

            printf("%d ", Pop());

        }
        puts(" ");

//2. Добавить в программу «Реализация стека на основе односвязного списка» проверку на выделение
//памяти. Если память не выделяется, то должно выводиться соответствующее сообщение. Постарайтесь
//создать ситуацию, когда память не будет выделяться (добавлением большого количества данных).

    Stck.maxSize = 100;
    Stck.head = NULL;

        for(dec = 0; dec < 90; dec++) {

            PushList(1);

        }

    PrintStack();
    puts(" ");
    puts(" ");

//3. Написать программу, которая определяет, является ли введённая скобочная последовательность
//правильной. Примеры правильных скобочных выражений – (), ([])(), {}(), ([{}]),
//неправильных – )(, ())({), (, ])}), ([(]), для скобок – [, (, {.
//Например: (2+(2*2)) или [2/{5*(4+7)}].

    char *arr;
    int i;
    arr = "[2/{5*(4+7)}]";

       for(i = 0; i < strlen(arr); i++) {

            switch(arr[i]) {

                case '(':
                    Push(arr[i]);
                    break;
                case '{':
                    Push(arr[i]);
                    break;
                case '[':
                    Push(arr[i]);
                    break;
                case ')':
                    if((N == -1)  || (Stack[N] != '('))
                        printf("Wrong )\n");
                    else Pop();
                    break;
                case '}':
                    if((N == -1)  || (Stack[N] != '{'))
                        printf("Wrong }\n");
                    else Pop();
                    break;
                case ']':
                    if((N == -1)  || (Stack[N] != '['))
                        printf("Wrong ]\n");
                    else Pop();
                    break;

            }

        }

       if(N != -1)

           printf("Error!\n");

       else

           printf("Nice!\n");

return 0;
}

//Сделаю потом
/*
4. *Создать функцию, копирующую односвязный список (то есть создающую в памяти копию односвязного списка без удаления первого списка).
5. *Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.
6. Реализовать очередь:
1. С использованием массива.
2. *С использованием односвязного списка.
7. *Реализовать двустороннюю очередь.
*/
