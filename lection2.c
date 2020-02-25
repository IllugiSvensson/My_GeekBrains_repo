//Правило 1
int findMax(int size, int *array)
{
    int result = array[0];
    int i;
    for (i = 1; i < size; i++)
    if (array[i] > result) 
    result = array[i];
    return result;
    }

//Проверка на повторяющиеся элементы Правило 4    
int FindDublicates(int N, int *array)
{
    int i, j;
    for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
    if (i != j) 
    if (array[i] == array[j]) 
    return 1;
    //Если мы дошли до этого места, значит, дубликатов нет
        return 0;
        }
        
// Пример вывода чисел от a до b с использованием рекурсивного алгоритма
#include <stdio.h>

void loop(int a, int b)
{
    printf("%5d", a);
    if (a < b) 
        loop(a + 1, b);
}

int main(int argc, char *argv[])
{
     loop(0, 10);
     return 0;
}

Сумма цифр числа А
#include <stdio.h>
int sumDigit(long a)
{
   int s = 0;
   while (a > 0)
   {
       s = s + a % 10;
       a = a / 10;
   }
   return s;
}
int main(int argc, char *argv[])
{
    int n;
    printf("Input number:");
    scanf("%d", &n);
    printf("Summ digit: %d", sumDigit(n));

    return 0;
}
#include <stdio.h>
int sumDigit(long a)
{
    if (a == 0) 
        return 0;
    else 
        return sumDigit(a / 10) + a % 10;
}
int main(int argc, char *argv[])
{
    int n;
    printf("Input number:");
    scanf("%d", &n);
    printf("Summ digit:%d", sumDigit(n));
    return 0;
}

int f(int N)
{
	int a = N * N;

	while (N > 0)
	{
		if (N % 10 != a % 10)
		{
			return 0;
		}
		N /= 10;
		a /= 10;
	}
	return 1;
}

void FOR(int start, int end)
{
	if (start < end)FOR(start + 1, end);
	printf("%d \n", start);
}



ЕГЭ!!!
int F(int n) {
    if (n > 2)
        return F(n - 1) + G(n - 2);
    else
        return n;
}

int G(int n) {
    if (n > 2)
        return G(n - 1) + F(n - 2);
    else
        return 3 - n;
}

числа фибоначчи
#include <stdio.h>
int long fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < 20; i++)
        printf("%d ", fib(i));
    return 0;
}
#include <stdio.h>
#define ARR_SIZE 20
int main(int argc, char *argv[])
{
    int f[ARR_SIZE];
    f[0] = 0;
    f[1] = 1;
    int i;
    for (i = 2; i < ARR_SIZE; i++)
        f[i] = f[i - 1] + f[i - 2];
    for (i = 0; i < ARR_SIZE; i++)
        printf("%d ", f[i]);

    return 0;
}

double counterRec = 0;
double counterFor = 0;

///	1 в чат
double FibRec(int N)
{
	counterRec++;

	return (N == 0 || N == 1) ? 1 : FibRec(N - 1) + FibRec(N - 2);
}

///	2 в чат
double FibFor(int N)
{
	counterFor++;

	double f0 = 1;
	double f1 = 1;
	for (int i = 1; i < N; i++)
	{
		int t = f0 + f1;
		f0 = f1;
		f1 = t;
		counterFor++;
	}
	return (double)f1;
}

------------------------------------------------
Перебор
#include <stdio.h>
#include <string.h>

int count = 0;

void more()
{
   char word[] = "...";              // Длина слова. Чем больше точек, тем
                                     // длиннее слово
   findWords("more", word, 0);
}

void findWords(char* A, char *word, int N)
{
    if (N == strlen(word))           // Слово построено
    {
         printf("%d %s\n", ++count, word);
         return;
    }
    int i;
    char *w;
    w = word;
    for(I = 0; I < strlen(A); i++)
    {
         w[N] = A[i];
         findWords(A, w, N + 1);     // Рекурсия
    }
}

int main(int argc, char *argv[])
{
    more();
    return 0;
}


#include <stdio.h>

void TowerOfHanoi(int from, int to, int other, int n)
{
   if (n > 1) TowerOfHanoi(from, other, to, n - 1);
   printf("%d %d\n", from, to);
   if (n > 1) TowerOfHanoi(other, to, from, n - 1);
}

void main()
{
   TowerOfHanoi(1, 2, 3, 3);
}

#include <stdio.h>
#include "mylib.h"

int map[10][10] = {
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
};

int k = 0;
void paint(int x, int y)
{
   if (map[x][y] == 0)
   {
       k++;
       map[x][y] = k;
       Paint(x, y - 1);
       Paint(x - 1, y);
       Paint(x, y + 1);
       Paint(x + 1, y);
   }
}

int main(int argc, char *argv[])
{

   paint(4, 4);
   return 0;
}



#include <stdio.h>
struct State
{
	int n;
	int src;
	int dest;
	int tmp;
	int step;
};
#define T State
#define MaxN 1000
T stack[MaxN];
int N = -1;
void push(T i)
{
	if (N<MaxN)
	{
		N++;
		stack[N] = i;
	}
	else printf("Stack overflow");
}
T pop()
{
	if (N != -1) return stack[N--];
	else printf("Stack is empty");
}
T* back()
{
	if (N != -1) return &stack[N];
	else printf("Stack is empty");
}
void tower(int n, int src, int dest, int tmp)
{
	{
		State state;
		state.n = n;
		state.src = src;
		state.dest = dest;
		state.tmp = tmp;
		state.step = 0;
		push(state);
	}
	while (N != -1)
	{
		State* state = back();
		switch (state->step)
		{
		case 0:
			if (state->n == 0)
				pop();
			else
			{
				++state->step;
				State newState;
				newState.n = state->n - 1;
				newState.src = state->src;
				newState.dest = state->tmp;
				newState.tmp = state->dest;
				newState.step = 0;
				push(newState);
			}
			break;
		case 1:
			printf("%d->%d\n",state->src,state->dest);
			++state->step;
			State newState;
			newState.n = state->n - 1;
			newState.src = state->tmp;
			newState.dest = state->dest;
			newState.tmp = state->src;
			newState.step = 0;
			push(newState);
			break;
		case 2:
			pop();
			break;
		}
	}
}

int main()
{
// Перекладываем с первого на второй штырь
// 1-й параметр – количество колец
	tower(3, 1, 2, 3);
	getchar();
}


int main() {
	setlocale(LC_ALL, "Rus");

	paint(4, 1);


	system("pause");

	const int count = 45;

	for (int i = 20; i < count; i++)
	{

		printf("FibFor(%d) = %0.0lf ", i, FibFor(i));
		printf(" counterFor = %0.0lf \n", counterFor);
		counterFor = 0;
	}
	system("pause");

	for (int i = 20; i < count; i++)
	{
		printf("FibRec(%d) = %0.0lf ", i, FibRec(i));
		printf(" counterRec = %0.0lf \n", counterRec);

		counterRec = 0;
	}

	//paint(4, 1);

	///printf("%d \n", f(225));
	system("pause");
	return 0;
}
        
        
        