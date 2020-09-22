#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <locale.h>
#include <Windows.h>



struct node {
    int value;
    struct node* next;
};

struct node* create(struct node* head, int x) {
    struct node* element;
    element = (struct node*)malloc(sizeof(struct node));
    element->next = head;
    element->value = x;
    return element;
}


struct node* getNth(struct node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

void pop(struct node** head) {
    struct node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;

}

void delete_list_nodes_by_count(struct node** head, int position) {
    if (position == 0) {
        return pop(head);
    }
    else {
        struct node* prev = getNth(*head, position - 1);
        struct node* elm = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        free(elm);
    }
}





void printlist(const struct node* head) {
    while (head) {
        printf("%d\n", head->value);
        head = head->next;
    }
}

int main(void)
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    setlocale(LC_ALL, "Rus"); 

    int a, b;
    int menu = 0;
    struct node* head = NULL;

  
    while (menu == 0) {
        printf("1) Добавить элемент\n");
        printf("2) Удалить элемент\n");
        printf("3) Вывести элементы\n");
        printf("4) Выйти\n");
        printf("--->");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("Введите значение элемента\n");
                scanf("%d", &a);
                head = create(head, a);
                printf("Элемент добавлен\n");
                Sleep(1500);
                menu = 0;
                break;
            case 2:
                printf("Введите номер элемента\n");
                scanf("%d", &b);
                b--;
                delete_list_nodes_by_count(&head, b);
                printf("Элемент удален\n");
                Sleep(1500);
                menu = 0;
                break;
            case 3:
                printf("Список элементов:\n");
                printlist(head);
                Sleep(5000);
                menu = 0;
                break;
            case 4: 
                exit;
        }



    }





}