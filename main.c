//Смирнов Александр
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4
#define M 5

int lcs_length(char *A, char *B) {

    if (*A == '\0' || *B == '\0')

        return 0;

    else if (*A == *B)

        return 1 + lcs_length(A + 1, B + 1);

    else

        return (lcs_length(A + 1, B) > lcs_length(A, B + 1)) ? lcs_length(A + 1, B) : lcs_length(A, B + 1);

}

int lcs_length_array(char *A, char *B) {

    int i, j, n, m;
    int array[strlen(A) + 2][strlen(B) + 2];

        n = strlen(A);
        m = strlen(B);

    for(i = 0; i < n + 2; i++) {

        for(j = 0; j < m + 2; j++)

            array[i][j] = 0;

    }


    for(i = 0; i < n ; i++) {

        array[i + 2][0] = A[i] - '0';

    }

    for(j = 0; j < m ; j++) {

        array[0][j + 2] = B[j] - '0';

    }

    for(i = 2, j = 2; i < n, j < m; i++, j++) {

        if (array[i][0] == array[0][j]) {

            array[i][j] = 1 + array[i - 1][j - 1];

        } else {

            if(array[i][0] > array[0][j])

                array[i][j] = array[i - 1][j];

            else

                array[i][j] = array[i][j - 1];

        }
    }

    for(i = 0; i < n + 2; i++) {

                puts(" ");

        for(j = 0; j < m + 2; j++)

                printf("%d ", array[i][j]);

    }

puts(" ");

return array[n][m];
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

        printf("Максимальная длина последовательности: %d\n", lcs_length("1245681425", "12851251"));
        lcs_length_array("1245681425", "12851251");


return 0;
}
