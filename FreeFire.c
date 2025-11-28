#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct {
    char nome[50];
    char tipo[50];
    int quantidade;
} Item;

Item mochila[MAX_ITENS];
int numItens = 0;

void adicionarItem() {
    if (numItens >= MAX_ITENS) {
        printf("Mochila cheia!\n");
        return;
    }

    printf("Nome do item: ");
    scanf(" %49[^\n]", mochila[numItens].nome);

    printf("Tipo do item: ");
    scanf(" %49[^\n]", mochila[numItens].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[numItens].quantidade);

    numItens++;
    printf("Item adicionado!\n");
}

void removerItem() {
    if (numItens == 0) {
        printf("A mochila esta vazia!\n");
        return;
    }

    char nome[50];
    printf("Nome do item a remover: ");
    scanf(" %49[^\n]", nome);

    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < numItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            numItens--;
            printf("Item removido!\n");
            return;
        }
    }

    printf("Item nao encontrado.\n");
}

void listarItens() {
    if (numItens == 0) {
        printf("A mochila esta vazia!\n");
        return;
    }

    printf("-------------------------------\n");
    printf("| %-15s | %-8s |\n", "Nome", "Qtd");
    printf("-------------------------------\n");

    for (int i = 0; i < numItens; i++) {
        printf("| %-15s | %-8d |\n",
               mochila[i].nome,
               mochila[i].quantidade);
    }

    printf("-------------------------------\n");
}

int main() {
    int opcao;

    do {
        printf("\n===== DESAFIO CODIGO DA ILHA – NOVATO =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
