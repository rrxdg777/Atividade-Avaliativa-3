#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
    struct Produto* proximo;
} Produto;

Produto* inicializar() {
    return NULL;
}

Produto* adicionar(Produto* estoque) {
    Produto* novo_produto = (Produto*) malloc(sizeof(Produto));
    printf("Digite o codigo do produto: ");
    scanf("%d", &novo_produto->codigo);
    printf("Digite a descricao do produto: ");
    scanf("%s", novo_produto->descricao);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novo_produto->quantidade);
    printf("Digite o valor do produto: ");
    scanf("%f", &novo_produto->valor);
    novo_produto->proximo = estoque;
    return novo_produto;
}

void relatorio(Produto* estoque) {
    Produto* p;
    for (p = estoque; p != NULL; p = p->proximo) {
        printf("Codigo: %d\n", p->codigo);
        printf("Descricao: %s\n", p->descricao);
        printf("Quantidade: %d\n", p->quantidade);
        printf("Valor: %.2f\n", p->valor);
    }
}

Produto* pesquisar(Produto* estoque, int codigo) {
    Produto* p;
    for (p = estoque; p != NULL; p = p->proximo) {
        if (p->codigo == codigo)
            return p;
    }
    return NULL;
}

Produto* remover(Produto* estoque, int codigo) {
    Produto* anterior = NULL;
    Produto* atual = estoque;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Produto nao encontrado.\n");
        return estoque;
    }

    if (anterior == NULL) {
        estoque = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return estoque;
}

int main() {
    Produto* estoque = inicializar();
    int opcao, codigo;

    do {
        printf("1. Adicionar produto\n");
        printf("2. Gerar relatorio\n");
        printf("3. Pesquisar produto\n");
        printf("4. Remover produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                estoque = adicionar(estoque);
                break;
            case 2:
                relatorio(estoque);
                break;
            case 3:
                printf("Digite o codigo do produto a ser pesquisado: ");
                scanf("%d", &codigo);
                Produto* produto = pesquisar(estoque, codigo);
                if (produto != NULL) {
                    printf("Produto encontrado: %s\n", produto->descricao);
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;
            case 4:
                printf("Digite o codigo do produto a ser removido: ");
                scanf("%d", &codigo);
                estoque = remover(estoque, codigo);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    return 0;
}
