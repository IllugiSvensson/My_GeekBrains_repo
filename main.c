//Смирнов Александр ДЗ 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARR_SIZE 100

int bin[ARR_SIZE];
int arr[ARR_SIZE];
int size = 0;
int ct = 1;

//1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
void decTObin(long dec) {

	if(dec < 0) 
		
		printf("Получить не удалось"); 
	
    if(dec > 0) {

        bin[size++] = dec % 2;
        dec = dec / 2;
        decTObin(dec);

    }

}

//2. Реализовать функцию возведения числа x в степень y
//a. без рекурсии
int power_a(int x, int y) {

    int pow = 1;
		
		if (x == 0) 
	
			pow = 0;
	
		else if (y == 0) 
	
			pow = 1;
	
		else	
	
        	while(y) {

            	pow = pow * x;
            	y--;

        	}

return pow;
}

//b. рекурсивно
int power_b(int x, int y) {

    int pow = x;
    
    if(x == 0) 
	
		return pow;
	
	if(y == 0) pow = 1;
	
        if(y > 1) {

            pow = x * power_b(pow, y - 1);

        }

return pow;
}

//с. рекурсивно используя свойство четности
//Не совсем понял, о каком свойстве идет речь.
//Это свойство как в примере первой лекции quickPow()?
int power_c(int x, int y) {

    int pow = 1;
	if(x == 0) 
	
		return x;
	
        if (y > 0) {

            if(y % 2) {

               pow = x * power_c(x, y - 1);

            } else {

                pow = power_c(x * x, y / 2);

            }

        }

return pow;
}

//3. Определить, сколько существует программ, которые преобразуют
//число 3 в число 20, используя команды (прибавь 1, умножь на 2).
//(Программа - набор команд). 
//a. Используя массив
int counter_a(int a, int b) {

    int i;
    int cnt;
	
		arr[a] = 1;
		arr[a + 1] = 1;

			for(i = a + 2; i <= b; i++) {
				
				arr[i] = arr[i / 2] + (arr[i - 2]);
				cnt = arr[i];
				
			}

return cnt;
}

//б. Используя рекурсию
int counter_b(int a, int b) {
	
	if((a + 2) >= b) {
	
		ct = 1;
	
	} else {
		
		ct = counter_b(a, b / 2) + counter_b(a , b - 2);
		
	}

return ct;
}

int main(int argc, char *argv[]) {

    int d, i;

        printf("Введите число для перевода: ");
        scanf("%d", &d);
        printf("Двоичное представление: ");
        
        	if(d == 0) 
				
				printf("0");
				
        	else {
			
				decTObin(d);
				
            	for(i = size - 1; i >= 0; i--)
                	printf("%d", bin[i]);
                	
       		}

        puts(" ");

        printf("Введите число: ");
        scanf("%d", &d);
        printf("Введите показатель степени: ");
        scanf("%d", &i);

			if(i >= 0) {
			
            	printf("Степень числа a: %d, b: %d, c: %d\n", power_a(d, i),
            													  power_b(d, i),
            													  power_c(d, i)
															      );
			} else {

				printf("Степень числа a: %f, b: %f, c: %f\n", ((float)1 / power_a(d, abs(i))),
            												  ((float)1 / power_b(d, abs(i))),
            												  ((float)1 / power_c(d, abs(i)))
															  );	
				
			}
				
        puts(" ");

        	printf("Число программ: %d\n", counter_a(3, 20));
			printf("Число программ: %d\n", counter_b(3, 20));
		
        puts(" ");

return 0;
}

//ДЗ 3
//Смирнов Александр
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10000
int array[SIZE] = {0};

void swap(int *a, int *b) {

    int t = *a;

        *a = *b;
        *b = t;

}

int arrsearch(int *c);

int main(int argc, char *argv[]) {

    srand(time(NULL));
    int i, j, t;
    int cnt = 0;
    int arr[SIZE];

    printf("Массив до сортировок: ");

        for(i = 0; i < SIZE; i++) {

            array[i] = rand() % 10;
            arr[i] = array[i];
            printf("%d ", array[i]);

        }

    puts(" ");

//1. Попробовать оптимизировать пузырьковую сортировку.
//Сравнить количество операций сравнения оптимизированной
//и не оптимизированной программы. Написать функции сортировки,
//которые возвращают количество операций.

        for(i = 0; i < SIZE; i++) {

            cnt++;  //Число проходов по массиву

            for(j = 0; j < SIZE - 1; j++) {

                cnt++;  //Количество проверок элементов

                if(arr[j] > arr[j + 1]) {

                    cnt++;  //количество свапов
                    swap(&arr[j], &arr[j + 1]);

                }

            }

        }

        printf("Пузырьковая сортировка: ");

            for(i = 0; i < SIZE; i++) {

                printf("%d ", arr[i]);
                arr[i] = array[i];

            }

        printf("\nЧисло действий: %d\n", cnt);

    puts(" ");

        cnt = 0;
        i = 0;
        t = 1;

    while (t) {

        t = 0;
        cnt++;

        for(j = 0; j < SIZE - 1 - i; j++) {

            cnt++;

            if(arr[j] > arr[j + 1]) {

                swap(&arr[j], &arr[j + 1]);
                t = 1;
                cnt++;

            }

        }

        i = i + 1;

    }

    printf("Оптимизированная сортировка: ");

        for(i = 0; i < SIZE; i++) {

            printf("%d ", arr[i]);
            arr[i] = array[i];

        }

    printf("\nЧисло действий: %d\n", cnt);

    puts(" ");

//2. *Реализовать шейкерную сортировку.

    cnt = 0;
    int L = 1;
    int R = SIZE - 1;

        while(L <= R) {

            cnt++;
            for(i = R; i >= L; i--) {

                cnt++;
                if(arr[i - 1] > arr[i]) {

                    swap(&arr[i - 1], &arr[i]);
                    cnt++;

                }

            }

            L++;

            for(i = L; i <= R; i++) {

                cnt++;
                if(arr[i - 1] > arr[i]) {

                    swap(&arr[i - 1], &arr[i]);
                    cnt++;

                }

            }

            R--;

        }

    printf("Шейкерная сортировка: ");

        for(i = 0; i < SIZE; i++) {

            printf("%d ", arr[i]);

        }

    printf("\nЧисло проходов: %d\n", cnt);

    puts(" ");

//3. Реализовать бинарный алгоритм поиска в виде функции, которой
//передается отсортированный массив. Функция возвращает индекс найденного
//элемента или -1, если элемент не найден.

    t = arrsearch(arr);

        if(t == -1)

            printf("Значение не найдено\n");

        else

            printf("Индекс: %d\n", t);

return 0;
}

int arrsearch(int *c) {

    int s, m;
    int L = 0;
    int R = SIZE - 1;

        printf("Введите число для поиска: ");
        scanf("%d", &s);

           while(L <= R) {

                m =  (L + R) / 2;

                if(c[m] > s) {

                    R = m - 1;

                } else if(c[m] < s) {

                    L = m + 1;

                } else

                    return m;

            }

return -1;
}

//4. *Подсчитать количество операций для каждой из сортировок
//и сравнить его с асимптотической сложностью алгоритма.
