#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Definições do jogo
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    if ((direcao == 'H' && coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) ||
        (direcao == 'V' && linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)) {
        return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if ((direcao == 'H' && tabuleiro[linha][coluna + i] == NAVIO) ||
            (direcao == 'V' && tabuleiro[linha + i][coluna] == NAVIO)) {
            return 0;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
    return 1;
}

// Função para posicionar um navio na diagonal
int posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    if ((direcao == 'D' && (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)) ||
        (direcao == 'A' && (linha - TAMANHO_NAVIO < -1 || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO))) {
        return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if ((direcao == 'D' && tabuleiro[linha + i][coluna + i] == NAVIO) ||
            (direcao == 'A' && tabuleiro[linha - i][coluna + i] == NAVIO)) {
            return 0;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 'D') {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        } else {
            tabuleiro[linha - i][coluna + i] = NAVIO;
        }
    }
    return 1;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    
    if (!posicionarNavio(tabuleiro, 2, 3, 'H')) {
        printf("Falha ao posicionar o navio horizontal.\n");
    }
    if (!posicionarNavio(tabuleiro, 5, 6, 'V')) {
        printf("Falha ao posicionar o navio vertical.\n");
    }
    if (!posicionarNavioDiagonal(tabuleiro, 1, 1, 'D')) {
        printf("Falha ao posicionar o navio diagonal para baixo-direita.\n");
    }
    if (!posicionarNavioDiagonal(tabuleiro, 8, 1, 'A')) {
        printf("Falha ao posicionar o navio diagonal para cima-direita.\n");
    }
    
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
