#include <stdio.h>
#include <stdlib.h>

// --- TRUQUE MULTIPLATAFORMA PARA PAUSAS (WINDOWS / LINUX) ---
#ifdef _WIN32
    #include <windows.h>
    #define PAUSA(segundos) Sleep((segundos) * 1000)
#else
    #include <unistd.h>
    #define PAUSA(segundos) sleep(segundos)
#endif

void margaret_historia() {
    // Vetor com os códigos de erro do sistema
    int alarmes[4] = {1101, 1202, 1305, 1400};

    // Variável que indica se o erro foi encontrado
    int encontrou = 0;

    printf("==================================================\n");
    printf("         FASE MARGARET HAMILTON - 1969            \n");
    printf("==================================================\n");
    PAUSA(2);
    printf("Crise no computador de bordo da Apollo 11!\n");
    printf("Verificando os codigos de erro da memoria...\n\n");
    PAUSA(3);

    // Percorre o vetor do inicio ao fim (variável 'i' declarada no for)
    for (int i = 0; i < 4; i++) {
        printf("Verificando alarme: %d\n", alarmes[i]);
        PAUSA(1);

        // Procura o código crítico 1202
        if (alarmes[i] == 1202) {
            encontrou = 1;
        }
    }

    PAUSA(1);
    printf("\n--------------------------------------------------\n");

    // Decide o resultado da missão
    if (encontrou == 1) {
        printf("SUCESSO: Codigo critico 1202 encontrado!\n");
        printf("Margaret Hamilton implementou a execucao assincrona:\n");
        printf("Ignorando tarefas secundarias do radar e priorizando\n");
        printf("o computador de voo para salvar o pouso na Lua!\n");
    } else {
        printf("FALHA: Codigo critico nao encontrado!\n");
        printf("O erro passou despercebido.\n");
        printf("A missao esta em risco!\n");
    }
    printf("==================================================\n");
    PAUSA(4);
}