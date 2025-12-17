#include <stdio.h>

#define TAM_NAVIO 3
#define TAM_TAB 10

int main() {

    /* =====================================================
       =================== NÍVEL NOVATO ====================
       ===================================================== */

    int navioHorizontal[TAM_NAVIO][2];
    int navioVertical[TAM_NAVIO][2];

    int xH = 2, yH = 3;  // Navio horizontal
    int xV = 5, yV = 6;  // Navio vertical

    // Navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        navioHorizontal[i][0] = xH;
        navioHorizontal[i][1] = yH + i;
    }

    // Navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        navioVertical[i][0] = xV + i;
        navioVertical[i][1] = yV;
    }

    printf("=== NIVEL NOVATO ===\n");
    printf("Navio Horizontal:\n");
    for (int i = 0; i < TAM_NAVIO; i++) {
        printf("(X=%d, Y=%d)\n",
               navioHorizontal[i][0],
               navioHorizontal[i][1]);
    }

    printf("\nNavio Vertical:\n");
    for (int i = 0; i < TAM_NAVIO; i++) {
        printf("(X=%d, Y=%d)\n",
               navioVertical[i][0],
               navioVertical[i][1]);
    }

    /* =====================================================
       ================= NÍVEL AVENTUREIRO =================
       ===================================================== */

    int tabuleiro[TAM_TAB][TAM_TAB];

    // Inicializa tabuleiro com água (0)
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona navio horizontal no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[xH][yH + i] = 3;
    }

    // Posiciona navio vertical no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[xV + i][yV] = 3;
    }

    /* =====================================================
       =================== NÍVEL MESTRE ====================
       ===================================================== */

    // Navio diagonal principal
    int xD1 = 0, yD1 = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[xD1 + i][yD1 + i] = 3;
    }

    // Navio diagonal secundária
    int xD2 = 0, yD2 = 9;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[xD2 + i][yD2 - i] = 3;
    }

    /* =====================================================
       ================ EXIBIÇÃO DO TABULEIRO ===============
       ===================================================== */

    printf("\n=== TABULEIRO 10x10 ===\n\n");

    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
