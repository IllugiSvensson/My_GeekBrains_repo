//Смирнов Александр Урок 4
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define max(a,b) ((a > b) ? a : b)
#define N 4
#define M 5

int var[8][2]= { {2, 1}, {2, -1}, {1, 2}, {1, -2},
				 {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1} };

int lcs_length_array(char *A, char *B) {

	int i, j, n, m, c;
    int array[strlen(A)][strlen(B)];

        n = strlen(A);
        m = strlen(B);
        
    	for(j = 0; j < m; j++) {
    	
    		if(B[j]	==	A[0])
				
				c = 1;
    			
			array[0][j] = c;
    	
		}
	
		c = 0;
	
		for(i = 0; i < n; i++) {
		
	    	if(B[0]	==	A[i]) 
				
				c = 1;
    	
			array[i][0] = c;	
		
		}
	
   		for(i = 1; i < n; i++) {
       
	   		for(j = 1; j < m ; j++) {
       	
       			if(A[i] == B[j]) 
				          			
				   	array[i][j] = 1 + array[i -1][j - 1];
       			
				else 
       		
					array[i][j] = max(array[i - 1][j], array[i][j - 1]);
	
			}
		}
	
	
	    for(i = 0; i < n; i++) {

                puts(" ");

        for(j = 0; j < m; j++)

                printf("%d ", array[i][j]);

    	}
    
    puts(" ");

return array[n - 1][m - 1];
}

int cntsteps(int x, int y, int A[M][M]) {

	int k, xn, yn;
    int count=0;
	    
		if((x < 0 || x >= M || y < 0 || y >= M || A[x][y] != 0)) {
			
        return -1;
        
    	}

    	for(k = 0; k < 8; k++) {
    		
       	 	xn = x + var[k][0];
        	yn = y + var[k][1];
        	
        		if(xn >= 0 && xn < M && yn >= 0 && yn < M && A[xn][yn] == 0) {
        			
            		count++;
            
        		}
   	 	}
   	 	
return count;
}

int main(int argc, char *argv[]) {

//1. Реализовать чтение массива с препятствием и нахождение количества маршрутов.

    int map[N][M] = { {1, 1, 0, 0, 1},
                      {1, 1, 1, 0, 1},
                      {0, 1, 1, 1, 1},
                      {0, 0, 1, 1, 1} };
    int i, j;

        for(i = 0; i < N - 1; i++) {

            if(map[i][0] == 0)

                map[i + 1][0] = 0;

        }

        for(j = 0; j < M - 1; j++) {

            if(map[0][j] == 0)

                map[0][j + 1] = 0;

        }

        for(i = 1; i < N; i++) {

            for(j = 1; j < M; j++) {

                if(map[i][j] == 0) continue;
                map[i][j] = map[i - 1][j] + map[i][j - 1];

            }

        }

        for (i = 0; i < N; i++) {

            for (j = 0; j < M; j++) {

                printf("%3d", map[i][j]);

            }

            puts(" ");

        }

    puts(" ");

//2. Решить задачу о нахождении длины максимальной последовательности
//с помощью матрицы.

        printf("Максимальная длина последовательности: %d\n", lcs_length_array("124421253", "151123"));

//3. Требуется обойти конем доску размером NxM пройдя по каждой клетке не более одного раза.

	int Arr[5][5] = {0};
	int steps[8];
	int x, y ,n, m;
	int sx = 0;
	int cnt = 1;
	 
	
		printf("Введите координату x стартовой позиции: ");
		scanf("%d", &x);
		printf("Введите координату y стартовой позиции: ");
		scanf("%d", &y);
	
	Arr[x][y] = 1;

		do {
			
			for(n = 0; n < 8; n++) {
				
				steps[n] = cntsteps(x + var[n][0], y + var[n][1], Arr);
				 
			}
			
			for(n = 0; n < 8; n++) {
				
				if(steps[n] > 0) {
					
					sx = n;
					break;
					
				}
				
				if(n == 7) {
					
					for(m = 0; m < 8; m++) {
						
						if(steps[m] == 0) {
							
							Arr[x + var[m][0]][y + var[m][1]] = ++cnt;
						}
						
					}
					
					for(i = 0; i < M; i++) {
						
						puts(" ");
						for(j = 0; j < M; j++) {
							
           			 		printf("%4d",Arr[i][j]);
           			 		
       				 	}
        			
    				}    
    				
					return 0;
						
				}
				
			}
			
			for(n = 0; n < 8; n++) {
				
				if(steps[n] < steps[sx] && steps[n] > 0) {
					
					sx = n;
					
				}
				
			}
			
				x += var[sx][0];
				y += var[sx][1];
				Arr[x][y] = ++cnt;
			
		} while (1);
	
return 0;
}

//Смирнов Александр Урок 5
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
