#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h> // Necessário para o sleep() no Linux
#include "jogo.h"
#define TAM_NOME 100

void limparTelaPrólogo(void) {
    printf("\n");
}

void mostrarBanner(void) {
    printf("==================================================\n");
    printf("                                                  \n");
    printf("          SISTEMA DE  LOGIN                  \n");
    printf("      PROJETO MENTES BRILHANTES                      \n");
    printf("                                                  \n");
    printf("==================================================\n");
    printf("        BEM-VINDO(A) AO SISTEMA DE LOGIN       \n");
    printf("==================================================\n\n");
}

int lerOpcao(void) {
    char entrada[50];
    char *fim;
    long numero;

    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        return -1;
    }

    numero = strtol(entrada, &fim, 10);

    while (isspace((unsigned char)*fim)) {
        fim++;
    }

    if (fim == entrada || *fim != '\0') {
        return -1;
    }

    if (numero < 1 || numero > 3) {
        return -1;
    }

    return (int)numero;
}

void mostrarPrologo(const char nome[]) {
    printf("\n==================================================\n");
    printf("                    PROLOGO                       \n");
    printf("==================================================\n");
    sleep(1);
    printf("Estagiario: %s\n\n", nome);
    sleep(1);
    printf("Uma nova jornada esta prestes a comecar!\n");
    sleep(2);
    printf("Voce foi selecionado para participar de uma\n");
    printf("missao especial do nosso centro de operacoes.\n\n");
    sleep(2);
    printf("Prepare-se, siga as instrucoes e mostre suas\n");
    printf("habilidades durante o treinamento.\n");
    sleep(2);
    printf("Boa sorte, agente %s!\n", nome);
    printf("==================================================\n");
    sleep(2);
}

void mostrarManual(void) {
    printf("\n=============== MANUAL E REGRAS =================\n");
    printf("1. SEGUIR ESTRITAMENTE OS COMANDOS DA EQUIPE.\n");
    printf("2. SE DIVERTIR AO MAXIMO DURANTE A JORNADA.\n");
    printf("3. RETIRAR DUVIDAS CASO ELAS SURJAM NO CAMINHO.\n\n");
    printf("INSTRUCOES DO SISTEMA:\n");
    printf("- Digite o numero correspondente a opcao desejada.\n");
    printf("- Informe seu nome ou um codinome.\n");
    printf("- Leia as mensagens apresentadas no terminal.\n");
    printf("- Utilize o menu para navegar pelo programa.\n");
    printf("==================================================\n");
    sleep(3);

}

// Transformado de main() para miguel_historia()
void miguel_historia(void) {
    char nome[TAM_NOME];
    int opcao;
    size_t tamanho;

    mostrarBanner();
    sleep(2);

    printf("Digite seu nome ou codinome: ");

    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        printf("\nErro ao ler o nome.\n");
        return;
    }

    tamanho = strlen(nome);

    if (tamanho > 0 && nome[tamanho - 1] == '\n') {
        nome[tamanho - 1] = '\0';
    } else {
        int caractere;
        while ((caractere = getchar()) != '\n' &&
               caractere != EOF) {
            /* Descarta o restante da entrada */
        }
    }

    if (strlen(nome) == 0) {
        strcpy(nome, "Agente");
    }

    printf("\nAcesso autorizado, %s!\n", nome);
    sleep(2);
    mostrarPrologo(nome);

    do {
        printf("\n\n=============== MENU DO PROLOGO ==================\n");
        printf("Estagiario: %s\n\n", nome);
        printf("1 - INICIAR MISSAO\n");
        printf("2 - MANUAL / REGRAS\n");
        printf("3 - AVANCAR PARA A PROXIMA ETAPA (Sair do prologo)\n");
        printf("==================================================\n");
        printf("Escolha uma opcao: ");

        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                printf("\nMissao iniciada!\n");
                sleep(1);
                mostrarPrologo(nome);
                printf("\nIntegracao concluida com sucesso. Preparando transicao temporal...\n");
                sleep(3);
                // Força a saída do loop do prólogo para avançar na história
                opcao = 3; 
                break;

            case 2:
                mostrarManual();
                break;

            case 3:
                printf("\nFinalizando o prologo de Miguel Augusto...\n");
                sleep(2);
                printf("Bem-vindo a corrente principal do tempo, %s!\n", nome);
                sleep(2);
                break;

            default:
                printf("\nOpcao invalida! Digite 1, 2 ou 3.\n");
                sleep(1);
                break;
        }

    } while (opcao != 3);
}