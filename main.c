#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void swap(int *, int *);
int HeapSort(int *, int );

//Быстрая сортировка Хоара.
void quickSort(int *array, int first, int last) {

    int i = first, j = last, x = array[(first + last) / 2];

        do {    //Разбиваем массив на две части и раскладываем
                //на меньше опорного и больше опорного
            while (array[i] < x)
                i++;

            while (array[j] > x)
                j--;

            if(i <= j) {

                if (array[i] > array[j])    //Меняем местами
                    swap(&array[i], &array[j]);

                i++;
                j--;

            }

        } while (i <= j);

        if (i < last)       //Рекурсивно повторяем для каждой части
            quickSort(array, i, last);

        if (first < j)
            quickSort(array, first, j);

}

//Пирамидальная сортировка
int HeapSort(int *a, int n) {

    int i, j, mid, t = n - 1, k;
    mid = n / 2;                                  // Середина массива
    for (i = mid; i >= 1; i--)
    {
        if (a[i - 1] < a[2 * i - 1])              // Условие сравнения, которое
                                                  // соответствует пирамидальной
                                                  // сортировке
            swap(&a[i - 1], &a[2 * i - 1]);
        if (2 * i < n && a[i - 1] < a[2 * i])     // Если n нечётное
            swap(&a[i - 1], &a[2 * i]);
    }
    k = 2 * mid;
    swap(&a[0], &a[t]);
    t--;
    while (t > 0)
    {
        mid = t / 2;                              // Теперь на последнем месте стоит
                                                  // максимальный элемент,
                                                  // его больше не трогаем
        for (i = mid; i >= 1; i--)
        {                                         // и проходимся по коротким ветвям
            if (a[i - 1] < a[2 * i - 1])
                swap(&a[i - 1], &a[2 * i - 1]);
            if (2 * i < n && a[i - 1] < a[2 * i])
                swap(&a[i - 1], &a[2 * i]);
        }
        k += 2 * mid;
        swap(&a[0], &a[t]);
        t--;
    }
    if (n > 0 && a[0] > a[1])                      // Последнее сравнение –
                                                   // нулевого элемента с первым
        swap(&a[0], &a[1]);
    k++;
    return k;
}

int main() {

    srand(time(NULL));
    int a[10], b[10];
    int i;

        printf("Неотсортированный массив: \n");
        for (i = 0; i < 10; i++) {

            a[i] = rand() % 10;
            printf("%d ", a[i]);
            b[i] = a[i];

        }
        puts(" ");

    quickSort(b, 0, 9);

        printf("Быстрая сортировка Хоара: \n");
        for(i = 0; i < 10; i++) {

            printf("%d ", b[i]);
            b[i] = a[i];

        }
        puts(" ");

    HeapSort(b, 10);

        printf("Пирамидальная сортировка: \n");
        for(i = 0; i < 10; i++) {

            printf("%d ", b[i]);
            b[i] = a[i];

        }
        puts(" ");


//    int i, *a, b, s, k, n;
//    FILE *fin, *fout;
//    fin = fopen("input.txt","r");
//    fout = fopen("output.txt","w");
//    a = (int *) malloc(MAX * sizeof(int));        // Выделяем память
//    i = 0;
//    while (fscanf(fin, "%d", &a[i]) == 1)
//        i++;
//    n = i;
//    k = HeapSort(a, n);                           // Количество сравнений
//    fprintf(fout, "Number of  elements: %d\nNumber of compares: %d\n", n, k);
//    fprintf(fout, "n^2 = %d\nn*log(n) = %d\n",
//            n * n, (int) (n*log(n) / log(exp(1))));
//    fprintf(fout, "Sorted Array:\n");
//    for (i = 0; i < n; i++)
//        fprintf(fout, "%d ", a[i]);
//    free(a);
//    fclose(fin);
//    fclose(fout);


return 0;
}

void swap(int *p, int *q) {

    int buf;
    buf = *p;
    *p = *q;
    *q = buf;

}









//const int MAX = 1024;

////Insert sort

////Shell

////Merge
//// Рекурсивная реализация сортировки слиянием
//void MergeSort(int *m, int l, int r)
//{
//    int t;
//    if (l < r)
//// Обрабатываемый фрагмент массива состоит более чем из одного элемента
//        if (r – l == 1) {
//            if (m[r] < m[l])
//// Обрабатываемый фрагмент массива состоит из двух элементов
//            {
//                t = m[l];
//                m[l] = m[r];
//                m[r] = t;
//            }
//        }
//        else
//        {
//// Разбиваем заданный фрагмент на два массива
//// Рекурсивно вызываем функции MergeSort
//            MergeSort(m, l, l + (r - l) / 2);
//            MergeSort(m, r + (r - l) / 2 + 1);
//            Merge(m, l, r);  // Сливаем массивы
//        }
//}


////Counting
//simpleCountingSort(int *A, int k) // где k – длина массива А,
//                                  // а 1000 – его максимальное значение
//{
//    for (i = 0; i < k; i++)
//        C[i] = 0;
//    for (i = 0; i < 1000; i++)
//        C[A[i]]++;
//    b = 0;
//    for (j = 0; j < k; j++)
//        for (i = 0; i < C[j] - 1; i++)
//            A[b++] = j;
//}

//#define SIZE101 101

//int countSort(int *arr, int len)
//{
//	int count = 0; // Счётчик обращений к элементам
//	int *values = (int*)calloc(SIZE101, sizeof(int));

//	if (values == NULL) {
//		puts("Out of memory!");
//		exit(1);
//	}

//	count += len;
//	for (int i = 0; i < len; ++i) {
//		++values[arr[i]];
//	}

//	int k = 0;
//	for (int i = 0; i < SIZE101; ++i) {
//		for (int j = 0; j < values[i]; ++j)
//			arr[k++] = i;
//	}
//	count += len + SIZE101;

//	free(values);
//	return count;
//}


////List
//listCountingSort(T* A, int k)
//{
//    for (i = 0; i < k - 1; i++)
//        C[i] = NULL;
//    for (i = 0; i < n - 1; i++)
//        C[A[i].key].add(A[i]);
//    b = 0;
//    for (j = 0; j < k - 1; i++)
//    {
//        p = C[j];
//        while (p != NULL)
//        {
//            A[b++] = p.data;
//            p = p.next();
//        }
//    }
//}
