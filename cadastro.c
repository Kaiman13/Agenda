
#include <math.h>
#include <stdio.h>
#include <string.h>

#define VET_Person 50
typedef struct Person {
    int code;
    char name[50];
    char date[8];
    char phone[19];
    char email[50];
    char obser[100];
} Person;

int add(Person person[VET_Person], int count);
void menu();

int main()
{
    int count = 0;
    int op = 1;
    Person person[VET_Person];
    while (op != 0) {
        menu();
        scanf("%d", &op);
        switch (op) {
        case 1:
            count += add(person, count);
            break;
        }
    }
}

void menu()
{
    printf("\n1 - Adicionar contato");
    printf("\n0 - Sair\n");
}

int add(Person person[VET_Person], int count)
{
    int number;
    printf("Quantas pessoas voce deseja adicionar?");
    scanf("%d", &number);
    if (count + number < VET_Person) {
        for (int i = 0; i < number; i++) {
            printf("Codigo:");
            scanf("%d", &person[i + count].code);
            if (person[i + count].code == 0) {
                printf("Erro, informe um numero maior que 0");
            } else {
                printf("\nNome: ");
                scanf("%s", &person[i + count].name);
                printf("\nEmail:");
                scanf("%s", &person[i + count].email);
                printf("\nData de nascimento: ");
                scanf("%s", &person[i + count].date);
                printf("\nTelefone: ");
                scanf("%s", &person[i + count].phone);
                printf("\nObersacoes:");
                scanf("%s", &person[i + count].obser);
                printf("--------------\n");
            }
        }
        return number;
    } else {
        printf("Numero maximo de contatos atingido");
        return 0;
    }
}