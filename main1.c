//Смирнов Александр
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//1. Реализовать простейшую хэш-функцию. На вход подается строка, на выходе
//сумма кодов символов.
int hashfunc(char *words) {

    int hash = 0;
    int i;

        for(i = 0; i < strlen(words); i++) {

            hash += words[i];

        }

return hash;
}

typedef int T;
typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;
// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node *root) {
    if (root)
    {
        printf("%d",root->data);
        if (root->left || root->right)
        {
        printf("(");

        if (root->left)
            printTree(root->left);
        else
            printf("NULL");
        printf(",");

        if (root->right)
            printTree(root->right);
        else
            printf("NULL");
        printf(")");
        }
    }
}

// Создание нового узла
Node* getFreeNode(T value, Node *parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

// Вставка узла
void insert(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL)
    {
        *head = getFreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp)
    {
        if (value> tmp->data)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if (value< tmp->data)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        }
        else
        {
            exit(2);                     // Дерево построено неправильно
        }
    }
}

void preOrderTravers(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}




int main(int argc, char *argv[]) {

    char arr[100];

    printf("Введите строку для преобразования: ");
    scanf("%s", arr);

        printf("Hash-код: %d\n", hashfunc(arr));

//2. Переписать программу, реализующее двоичное дерево поиска:
//Добавить в него обход дерева различными способами.
//Реализовать поиск в нём.
//*Добавить в программу обработку командной строки с помощью которой
//можно указывать, из какого файла считывать данные, каким образом обходить дерево.

        Node *Tree = NULL;
        FILE* file = fopen("data.txt", "r");
        if (file == NULL)
        {
            puts("Can't open file!");
            exit(1);
        }
        int count;
        fscanf(file, "%d", &count);          // Считываем количество записей
        int i;
        for(i = 0; i < count; i++)
        {
        int value;
        fscanf(file, "%d", &value);
        insert(&Tree, value);
        }
        fclose(file);
        printTree(Tree);
        printf("\nPreOrderTravers:");
        preOrderTravers(Tree);



return 0;
}


//3. Разработать базу данных студентов, состоящую из полей «Имя», «Возраст»,
//«Табельный номер», в которой использовать все знания, полученные на уроках.
//Данные следует считать в двоичное дерево поиска. Реализовать поиск по какому-нибудь
//полю базы данных.
