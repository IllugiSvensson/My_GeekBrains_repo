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




//Задача с сортировкой м человек на н команд

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int t3v1_0(int s, int e, int p, int m)
{
	int a[100] = { 0 };

	a[s] = 1;

	for (int n = s+p; n <= e; n++)
	{
		a[n] = n % m == 0 ? a[n - p] + a[n / m] : a[n - p];
	}
	
	return a[e];
}

int t3v2_0(int s, int e)
{
	if (e < s)return 0;
	if (e == s)return 1;//??

	return t3v2_0(s + 1, e) + t3v2_0(s * 2, e);
}


int main(int argc, char** args)
{
	printf("\n%d\n\n", t3v2_0(3, 20));
	printf("%d\n\n", t3v2_0(2, 7));





	
	system("pause");
}