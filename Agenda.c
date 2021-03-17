
#include <math.h>
#include <stdio.h>
#include <string.h>

#define VET_Person 50
//struct //
typedef struct Person {
    int code;
    char name[50];
    char date[8];
    char phone[19];
    char email[50];
    char obser[100];
} Person;

int add(Person person[VET_Person], int count);
void list(Person person[VET_Person], int count);
void menu();

int main()
{
    /*Coloquei a variavel count pra controlar o numero de contatos adicionado para não exceder o valor máximo do VET_Person
    e para que fique mais fácil manipular os contatos*/
    int count = 0;
    int op = 1;
    Person person[VET_Person];
    while (op != 0) {
        menu();
        scanf("%d", &op);
        switch (op) {
        case 1:
            count += add(person, count);
        case 2:
            list(person, count);
            break;
        }
    }
}
//Função Menu
void menu()
{
    printf("\n1 - Adicionar contato");
    printf("\n2 - Ver lista de contatos");
    printf("\n0 - Sair\n");
}
//Função para adicionar um contato//
int add(Person person[VET_Person], int count)
{
    /*coloquei essa variavel pra que o usuario informe quantas pessoas ele quer adicionar no vetor que tem o valor máximo de 50
    em vez de adicionar tudo de uma vez ele pergunta quantos o usuário quer adicionar*/
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
//Função para ver a lista de contatos//
void list(Person person[VET_Person], int count)
{
    //Caso a lista esteja vazia//
    if (count == 0) {
        printf("Lista vazia!");
        getch();
    } else {
        for (int i = 0; i < count; i++) {
            printf("----------------------\n");
            printf("%d\n", person[i].code);
            printf("%s\n", person[i].name);
            printf("%s\n", person[i].email);
            printf("%s\n", person[i].date);
            printf("%s\n", person[i].phone);
            printf("%s\n", person[i].obser);
            printf("----------------------\n");
            getch();
        }
    }
}