#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2) 
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
    

int main(int argc, const char *argv[]) 
{	//Расстояние между точками
    double x1;
    double y1;
    double x2;
    double y2;
                
    printf("Input x1:");
    scanf("%lf", &x1);
    printf("Input y1:");
    scanf("%lf", &y1);
    printf("Input x2:");
    scanf("%lf", &x2);
    printf("Input y2:");
    scanf("%lf", &y2);
                                        
    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    printf("Distance: %lf", dist);

    //Периметр прямоугольника
    double x3;
    double y3;
        
    printf("Input x1:");
    scanf("%lf", &x1);
    printf("Input y1:");
    scanf("%lf", &y1);
    printf("Input x2:");
    scanf("%lf", &x2);
    printf("Input y2:");
    scanf("%lf", &y2);
    printf("Input x3:");
    scanf("%lf", &x3);
    printf("Input y3:");
    scanf("%lf", &y3);
                                                    
    double len1 = distance(x1, y1, x2, y2);
    double len2 = distance(x1, y1, x3, y3);
    double len3 = distance(x2, y2, x3, y3);
                                                                    
    printf("Perimetr: %lf", len1 + len2 + len3);
                                                                        
                                                    
return 0;
}
    
#include <stdio.h>	//Расстояние между точками с помощью структуры
#include <math.h>
struct Point 
{
    double x;
    double y;
};
typedef struct Point Point;
        
double distance (Point A, Point B) 
{
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
            
int main(int argc, const char *argv[]) 
{
 Point p1;
 Point p2;
                    
    printf("Input x1:");
    scanf("%lf", &p1.x);
    printf("Input y1:");
    scanf("%lf", &p1.y);
    printf("Input x2:");
    scanf("%lf", &p2.x);
    printf("Input y2:");
    scanf("%lf", &p2.y);
                                            
    printf("Distance: %lf", distance(p1, p2));
                                                            
    return 0;
}
                
                
//Наибольший общий делитель
#include <stdio.h>
// Определение наибольшего общего делителя. Алгоритм Эвклида

int main(int argc, const char *argv[])
{
    int a;
   int b;
printf("%s", "Input a:");
scanf("%d", &a);
 printf("%s", "Input b:");
scanf("%d", &b);
 while (a != b)
  if (a > b)
 a = a - b;
else 
b = b - a;
 printf("GCD: %i", a);
return 0;
}
 #define T long
T gcd(T a, T b) {
 T c;
 while (b) {
 c = a % b;
 a = b;
b = c;
 }
                                                                                                          
 return a;
}
                                                                                                             
//Определим простоту числа
#include <stdio.h>
int main(int argc, char *argv[])
{
    int number;
    printf("Input number:");
    scanf("%d", &number);
    int d = 0;
       int i = 2;
                    
      while (i < number/2  + 1)
      {
        if (number % i == 0){ d++;
       	break;}
      i++;
      }
                                                
 if (d == 0) 
          printf("Number is simple");
          else 
            printf("Number is not simple");
                                                                        
       return 0;
       }
                                                              
//Средняя оценка
#include <stdio.h>
// Вычисление средней оценки инструкцией повторения, управляемой счётчиком

int main(int argc, char *argv[])
{
    unsigned int counter;  // Количество оценок
    int grade;             // Значение оценки
    int sum;               // Сумма оценок
    double average;        // Средняя оценка
                        
    sum = 0;
    counter = 1;
                                
    while (1)
    {
    printf("%s", "Enter grade:");
    scanf("%d", &grade);
    if(grade == -1) break;
    sum = sum + grade;
    counter++;
    }
                                
    if(count != 0){                                            
    average = (double) sum/count;;
    printf("Class average is %lf\n", average);
    } else printf("No grades\n");                                                                                
    return 0;
    }
                                                                                        
//Сумма цифр целого числа
#include <stdio.h>
int sumDigit(long a)
{
    int result = 0;
        while (a > 0)
            {
   result = result + a % 10;
  //result = result * 10 + a % 10;  Можно делить на другое число, получим перевод в другую СС
        a = a / 10;
           }
         return result;
          }
                                    
        int main(int argc, char *argv[])
       {
         int n;
        printf("Input number:");
         scanf("%d", &n);
           printf("Sum digit: %d", sumDigit(n));
                                                    
            return 0;
             }
                                                        
#include <stdio.h>
#define ARR_SIZE 100

// Задаём значение первого элемента, чтобы обнулить остальные
int bin[ARR_SIZE] = {0};
int size = 0;    // Количество реально задействованных элементов массива

void convertToBin(long n)
{
    int i=0;
        while (n > 0)
        {
      bin[i++] = n % 2;
      n /= 2;
              }
        size = i;
        }
         void binPrint()
            {
          int i;
         for(i = size - 1; i >= 0; i--)
         printf("%d", bin[i]);
         printf("\n");
             }
          int main(int argc, char *argv[])
         {
        int N = 13;
        convertToBin(N);
       binPrint();
                                                                    
            N = 8;
           convertToBin(N);
           binPrint();
                                                                                
           return 0;
 	}

//Степень        
long power(int a, int b)
{
   long p = 1;
      while(b)
         {
                p = p * a;
                 b--;
           }
          }
                          
long quickPow(int a, int b) {
    long n = 1;
	while (b) {
	if (b % 2) {
	b--;
	n *= a;
	} else {
	a *= a;
	b /= 2;
	}
	 }
	return n;
	}
											
											                          
//Генератор случайных чисел
#include <stdio.h>
int main(int argc, char *argv[])
{
    int x, a, b, m;
       m = 100; // Вершина последовательности
      b = 3;
       a = 2;
      x = 1;
        int i;
    int modulus = 100;
                            
        for (i = 0; i < modulus; i++)
         {
       x = (a * x + b) % m;
            printf("%d ", x);
              }
                                                            
           return 0;
             }
                                                                                          
//Подсчет производительности
int count = 0;                    // Вводим счётчик количества операций
   for(i = 0; i < N; i++)
          for(j = 0; j < N - 1; j++)
        {
         count++;   
            if (a[j] > a[j + 1])
            {
             count++; 
           swap(&a[j], &a[j + 1]);
                }
              }
               puts("Array after sort");
                     Print(N, a);
                 printf("Count:%d", count);        // Выводим счётчик на экран
                                                                                                           
                                                                                                           
                                                                                                                                   
//Нахождение максимального числа
#include <stdio.h>
#define ARR_SIZE 100 
void arrayPrint(int length, int *a) 
{
    int i;
    for(i = 0; i < length; i++)
    printf("%6i", a[i]);
      printf("\n");
         }
        // Нахождение максимального числа в массиве
      int findMax(int length, int *a)
          {
      // В качестве начального значения максимума берём первое число
     int result = a[0];                
    int i;
     // Просматриваем остальные числа
     for (i = 1; i < length; i++)
     // Если среди них есть число больше max, то берём его в качестве max
    if (a[i] > result) result = a[i];    
     // Возвращаем результат
       return result;
      }
        int main(int argc, char *argv[])
        {
        int array[ARR_SIZE];
        int size = 0;
         FILE *in;
         in = fopen("D:\\temp\\data.txt", "r");
         if (in == NULL)
      {
          puts("Can't open file");
            return 1;
             }
             int data;
            // Пока количество подсчитанных данных больше нуля
           while(fscanf(in, "%d", &data) > 0)
             {
       array[size] = data;
           size++;
         }
      fclose(in);
         printf("Read %d records\n", size);
         // Массив является указателем (хранит адрес), поэтому & не ставится
          arrayPrint(size, array);
            printf("Max = %d", findMax(size, array));
         return 0;
      }
                                                                                                                                            
                                                                                                                                                                    
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        