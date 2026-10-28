#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "jogo.h"

// --- TRUQUE MULTIPLATAFORMA PARA PAUSAS E TELA ---
#ifdef _WIN32
    #include <windows.h>
    #define PAUSA(segundos) Sleep((segundos) * 1000)
    #define LIMPAR_TELA() system("cls")
#else
    #include <unistd.h>
    #define PAUSA(segundos) sleep(segundos)
    #define LIMPAR_TELA() system("clear")
#endif

// --- PROTÓTIPOS DAS FUNÇÕES DE CADA COLEGA ---
// Isso avisa o compilador que essas funções existem nos outros arquivos
void miguel_historia(void);
void lovelace_historia(void);
void joan_historia(void);
void hopper_historia(void);
void margaret_historia(void);
void carol_historia(void);

int main()
{
    srand(time(NULL));
    LIMPAR_TELA();

    // 1. Prólogo (Miguel Augusto)
    miguel_historia();
    LIMPAR_TELA();

    // 2. Ada Lovelace (Wanderson)
    lovelace_historia();
    LIMPAR_TELA();

    // 3. Joan Clarke (Ana Flávia)
    joan_historia();
    LIMPAR_TELA();

    // 4. Grace Hopper (Breno e Guilherme)
    hopper_historia();
    LIMPAR_TELA();

    // 5. Margaret Hamilton (Victor Borges)
    margaret_historia();
    LIMPAR_TELA();

    // 6. Carol Shaw (J.Bena / Você) - O clímax do jogo!
    carol_historia();

    // --- CRÉDITOS FINAIS DA EQUIPE ---
    LIMPAR_TELA();
    printf("\n==================================================\n");
    printf("         CREDITOS DA EQUIPE - MENTES BRILHANTES     \n");
    printf("==================================================\n");
    PAUSA(2);
    printf(" Prologo      : Miguel Augusto\n");
    PAUSA(1);
    printf(" Ada Lovelace : Wanderson\n");
    PAUSA(1);
    printf(" Joan Clarke  : Ana Flavia\n");
    PAUSA(1);
    printf(" Grace Hopper : Breno e Guilherme\n");
    PAUSA(1);
    printf(" Margaret     : Victor Borges\n");
    PAUSA(1);
    printf(" Carol Shaw   : J.Bena (Jorge)\n");
    printf("==================================================\n");
    PAUSA(4);

    return 0;
}