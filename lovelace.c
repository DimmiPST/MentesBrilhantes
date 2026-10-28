#include <stdio.h>
#include <stdlib.h>

// --- TRUQUE MULTIPLATAFORMA PARA PAUSAS (WINDOWS / LINUX) ---
#ifdef _WIN32
    #include <windows.h>
    // No Windows, a função é Sleep (com S maiúsculo) e conta em milissegundos
    #define PAUSA(segundos) Sleep((segundos) * 1000)
#else
    #include <unistd.h>
    // No Linux/Mac, a função é sleep (minúsculo) e conta em segundos
    #define PAUSA(segundos) sleep(segundos)
#endif

// --- VARIÁVEIS GLOBAIS DA FASE ---
int soma_global_ada = 0;
int limite_ciclos_ada = 5;

// Função declarada sem parâmetro void
void lovelace_historia() {
    // Reinicia a variável global para garantir consistência caso a fase seja repetida
    soma_global_ada = 0;

    // 1. Apresentação do cenário
    printf("==================================================\n");
    printf("   LONDRES, 1843 - O DESAFIO DE ADA LOVELACE\n");
    printf("==================================================\n");
    PAUSA(2); // Usando a nossa macro mágica
    printf("A Maquina Analitica precisa calcular os ciclos da\n");
    printf("serie para processar os dados corretamente...\n\n");
    PAUSA(2);

    // 3. Laço de repetição com a variável 'i' declarada direto no escopo do for
    for (int i = 1; i <= limite_ciclos_ada; i++) {
        soma_global_ada += i; // Atualiza o valor acumulado globalmente
        
        // Imprime o status do ciclo atual com atraso para efeito visual
        printf("[Ciclo %d] Contador: %d | Soma acumulada: %d\n", i, i, soma_global_ada);
        PAUSA(1); 
    }

    printf("\n--------------------------------------------------\n");
    PAUSA(1);

    // 4. Verificação final com condicional (if/else)
    if (soma_global_ada == 15) {
        printf("SUCESSO: Calculo da Maquina Analitica correto!\n");
        printf("Resultado final: %d (Meta atingida: 15)\n", soma_global_ada);
    } else {
        printf("FALHA: Erro no loop de contagem.\n");
        printf("Resultado obtido: %d (Esperado: 15)\n", soma_global_ada);
    }
    printf("==================================================\n");
    PAUSA(3);
}