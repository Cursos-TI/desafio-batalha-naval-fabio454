#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

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
    // Verifica se o navio cabe no tabuleiro sem ultrapassar os limites
    if ((direcao == 'H' && coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) ||
        (direcao == 'V' && linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)) {
        return 0; // Falha ao posicionar
    }
    
    // Verifica se há sobreposição de navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if ((direcao == 'H' && tabuleiro[linha][coluna + i] == NAVIO) ||
            (direcao == 'V' && tabuleiro[linha + i][coluna] == NAVIO)) {
            return 0; // Falha ao posicionar
        }
    }
    
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
    return 1; // Sucesso
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
    
    // Posiciona um navio horizontalmente na linha 2, coluna 3
    if (!posicionarNavio(tabuleiro, 2, 3, 'H')) {
        printf("Falha ao posicionar o navio horizontal.\n");
    }
    
    // Posiciona um navio verticalmente na linha 5, coluna 6
    if (!posicionarNavio(tabuleiro, 5, 6, 'V')) {
        printf("Falha ao posicionar o navio vertical.\n");
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
