#include <stdio.h>

int main() {
    // Movimento da Torre: 5 casas para a direita
    int movimentoTorre = 5;

    // Estrutura de repetição: for
    printf("Movimento da Torre:\n");
    for (int i = 0; i < movimentoTorre; i++) {
        printf("Direita\n");
    }

    // Movimento do Bispo: 5 casas na diagonal para cima e à direita
    int movimentoBispo = 5;
    int contadorBispo = 0;

    // Estrutura de repetição: while
    printf("\nMovimento do Bispo:\n");
    while (contadorBispo < movimentoBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    // Movimento da Rainha: 8 casas para a esquerda
    int movimentoRainha = 8;
    int contadorRainha = 0;

    // Estrutura de repetição: do-while
    printf("\nMovimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < movimentoRainha);

    return 0;
}
