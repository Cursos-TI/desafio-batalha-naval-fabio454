#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Definições do jogo
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

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

// Função para aplicar uma habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char tipo) {
    int area[5][5] = {0};
    
    if (tipo == 'C') { // Cone
        area[0][2] = 1;
        area[1][1] = area[1][2] = area[1][3] = 1;
        for (int i = 0; i < 5; i++) area[2][i] = 1;
    } else if (tipo == 'X') { // Cruz
        for (int i = 0; i < 5; i++) {
            area[2][i] = 1;
            area[i][2] = 1;
        }
    } else if (tipo == 'O') { // Octaedro
        area[0][2] = 1;
        area[1][1] = area[1][3] = 1;
        area[2][0] = area[2][2] = area[2][4] = 1;
        area[3][1] = area[3][3] = 1;
        area[4][2] = 1;
    }
    
    // Aplicar ao tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = linha + i - 2;
            int y = coluna + j - 2;
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && area[i][j] == 1) {
                if (tabuleiro[x][y] != NAVIO) {
                    tabuleiro[x][y] = HABILIDADE;
                }
            }
        }
    }
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
    
    posicionarNavio(tabuleiro, 2, 3, 'H');
    posicionarNavio(tabuleiro, 5, 6, 'V');
    
    aplicarHabilidade(tabuleiro, 4, 4, 'C');
    aplicarHabilidade(tabuleiro, 6, 6, 'X');
    aplicarHabilidade(tabuleiro, 2, 7, 'O');
    
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
