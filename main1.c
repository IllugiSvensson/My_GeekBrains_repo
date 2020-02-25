#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int randgen(int q); //13 задача.
int maxnumber(int a, int b, int c); //Задача 12

int main(int argc, char *argv[]) {
	
	//14. Автоморфные числа. Натуральное число называется автоморфным, 
	//если оно равно последним цифрам своего квадрата. Например, 25 \ :sup: 2 = 625. 
	//Напишите программу, которая вводит натуральное число N и выводит на экран 
	//все автоморфные числа, не превосходящие N.
	
		int numeral;
		int n, amnum, k;
		
			printf("Введите любое целое положительное число: ");
			scanf("%d", &numeral);
			printf("Список аморфных чисел: \n");
			
				for(n = 1; n <= numeral; n++) {
					
					amnum = n * n;
					
					for(k = 10; k < n; k *= 10);

						amnum = amnum % k;

					if(amnum == n)
						
						printf("\t%d\n", n);
				
				}
			
	//13. Написать функцию, генерирующую случайное число от 1 до 100.
	//с использованием стандартной функции rand()
	//без использования стандартной функции rand()
	//СРАВНИТЬ С КОНГУЭРТНЫМ МЕТОДОМ

		printf("\n\nСлучайное число: %d \n", randgen(100));
		
	//12. Написать функцию нахождения максимального из трех чисел.
		int a, b ,c;
		printf("Введите число 1: ");
		scanf("%d", &a);
		printf("Введите число 2: ");
		scanf("%d", &b);
		printf("Введите число 3: ");
		scanf("%d", &c);
			printf("\n\nМаксимальное число: %d \n", maxnumber(a, b, c));
			
	//11С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее 
	//арифметическое всех положительных четных чисел, оканчивающихся на 8.
			
		float s = 0;
		n = 1;
		k = 0;
		while (n != 0) {
			
			printf("Введите число: ");
			scanf("%d", &n);
				
				s = s + n;
				k++;
		}
		
			printf("\n%5.2f", s/k);

	//10. Дано целое число N (> 0). С помощью операций деления нацело и взятия 
	//остатка от деления определить, имеются ли в записи числа N нечетные цифры. 
	//Если имеются, то вывести True, если нет — вывести False.
		
		printf("Введите число, больше нуля: ");
		scanf("%d", &n);
		numeral = n;
			for(k = 1; k < n; k *= 10) {
				
					if (numeral%2 == 1) {
						s = 0;
						printf("True\n");
						break; }
					else s = -1;
				numeral = n / (k*10);
				
			}
			if(s == -1) printf("False\n");


	//9.Даны целые положительные числа N и K. Используя только операции сложения 
	//и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
	
	unsigned int N, K;
	printf("Введите N: ");
	scanf("%d", &N);
	printf("Введите K: ");
	scanf("%d", &K);
	n = 0;
		while(K < N) {
			n++;
			N -= K;
		}
	printf("Частное: %d \tОстаток: %d\n", n, N);
		
	//8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
	printf("Введите a: ");
	scanf("%d", &a);
	printf("Введите b: ");
	scanf("%d", &b);
	
		for(k = a; k <= b; k++)
			printf("Квадрат числа %d: %d\t Куб числа %d: %d\n",
			   k, k*k, k, k*k*k);

	//7. С клавиатуры вводятся числовые координаты двух полей шахматной 
	//доски (x1,y1,x2,y2). Требуется определить, относятся ли к поля к одному цвету или нет.
	int x1, y1, x2, y2;
	int board[9][9] = {{0},{0}};
	
		for(n = 0; n < 8; n += 2) {
			for(k = 0; k < 8; k +=2) board[n][k] = 1;
		}
		
		for(n = 1; n < 8; n += 2) {
			for(k = 1; k < 8; k +=2) board[n][k] = 1;
		}

		printf("Введите координаты клетки 1: ");
		scanf("%d", &x1);
		scanf("%d", &y1);
		
		printf("Введите координаты клетки 2: ");
		scanf("%d", &x2);
		scanf("%d", &y2);
		
		printf("%s", (board[x1][y1] == board[x2][y2])? "Один цвет": "Цвета разные");
		
	//6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим 
	//словом «год», «года» или «лет».	
		printf("Введите возраст (от 1 до 150): ");
		scanf("%d" , &n);
			if ((n % 10 == 1)&&(n != 11)) printf("%d год\n", n);
			else if((n%10 >=2)&&(n%10<=4)&&(n<10 || n>=20)) printf("%d года\n",n);
			else printf("%d лет\n",n);

	//5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
	printf("Введите номер месяца: ");
	scanf("%d", &n);
	
		switch(n){
			case 3:
			case 4:
			case 5: printf("Весна\n");
				break;
			case 6:
			case 7:
			case 8: printf("Лето\n");
				break;
			case 9:
			case 10:
			case 11: printf("Осень\n");
				break;
			case 12:
			case 1:
			case 2: printf("Зима\n");
				break;
			default: printf("Неверный ввод\n");
				break;
		}
		
		
	//4. Написать программу нахождения корней заданного квадратного уравнения.
	printf("Введите коэффициенты квадратного уравнения: ");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
		
	double D;
	D = (b * b) - (4 * a * c);				//Расчет дискриминанта
	
		if (a == 0){					//Проверка на квадратное уравнение
			x1 = -c / b;
			printf("В уравнении только один корень: x = %.2f \n", x1);
		} else if (D > 0){				//Расчитываем корни
			x1 = (-b + sqrt(D)) / (2 * a); 	//через дискриминант
			x2 = (-b - sqrt(D)) / (2 * a);
			printf("В уравнении есть два корня: x1 = %.2f, x2 = %.2f \n", x1, x2);
		} else if (D == 0){
			x1 = -b / (2 * a);
			printf("В уравнении только один корень: x = %.2f \n", x1);
		} else
			printf("В уравнении нет вещественных корней. \n");	

	//3. Написать программу обмена значениями двух целочисленных переменных:
	//a. с использованием третьей переменной;
	//b. *без использования третьей переменной.
		printf("Введите два числа: ");
		scanf("%d", &a);
		scanf("%d", &b);
			//D = k;
			//k = n;
			//n = D;
		a = a + b; 
		b = a - b; 
		a = a - b;
			
			printf("Результат %d\t%d\n", a, b);

	//2. Найти максимальное из четырех чисел. Массивы не использовать.
		int maxn, d;
		printf("Введите числа: ");
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		scanf("%d", &d);
		if((a > b) && (a > c) && (a > d)) maxn = a;
		else if ((b > a) && (b > c) && (b > d))maxn = b;
		else if ((c > a) && (c > b) && (c > d)) maxn = c;
		else maxn = d;
				 printf("Максимальное число: %d\n", maxn);

	//1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела 
	//по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
		int m;
		float h;
		printf("Введите рост человека: ");
		scanf("%f", &h);
		printf("Введите вес человека: ");
		scanf("%d", &m);
			printf("Индекс массы тела: %5.2f\n", m/((h/100)*(h/100)));
		
return 0;	
}


int randgen(int q) {	//Задача 13
	
	srand(time(NULL));
	
	//int random = 1 + rand() % q;
	
	int random = time(NULL) % 100;	//Получаем секунды
	int i, sum;
								//Что-то на подобии генератора псевдослучайной последовательности
		sum = random + 1;		//Присвоим число 1..10
		sum += random + 3;			//полученное число "сдвинем"
		
			if(sum >= 10) sum -=10; //Зациклим в пределах 10
						
		for(i = 0; i < pow(random + 1, 2); i++) {
		
			sum = sum + (sum - 1);				//складываем текущее с предыдущим
												//значением.  	
			if(sum >= 100) sum -= 100;
	
		} random = abs(sum % 100);
	
return random;
}

int maxnumber(int a, int b, int c) { //Задача 12
	
	int maxn;
	
		if((a > b) && (a > c)) maxn = a;
		else if ((b > a) && (b > c)) maxn = b;
		else maxn = c;
	
return maxn;	
}

#include <stdio.h>
void solution1();
void solution2();
void solution3();
void menu();

int main()
{
    int sel = 0;
    do
    {
        menu();
        scanf("%i", &sel);
        switch (sel)
        {
            case 1:
                solution1();
                break;
            case 2:
                solution2();
                break;
            case 3:
                solution3();
                break;
            case 0:
                printf("Bye-bye");
                break;
            default:
                printf("Wrong selected\n");
        }
    } while (sel != 0);
    return 0;
}
void solution1()
{
    printf("Solution 1\n");
// Решение
}

void solution2()
{
    printf("Solution 2\n");
// Решение
}

void solution3()
{
    printf("Solution 3\n");
// Решение
}

void menu()
{
  printf("1 - task1\n");
  printf("2 - task2\n");
  printf("3 - task3\n");
  printf("0 - exit\n");
}
