#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jogo.h"
// --- TRUQUE MULTIPLATAFORMA PARA PAUSAS (WINDOWS / LINUX) ---
#ifdef _WIN32
    #include <windows.h>
    #define PAUSA(segundos) Sleep((segundos) * 1000)
#else
    #include <unistd.h>
    #define PAUSA(segundos) sleep(segundos)
#endif

// Função universal para desenhar a forca (compatível com Linux e Windows)
void desenharForca(int erros) {
    printf("\n");
    if (erros == 0) 
    {
        printf("  _______\n");
        printf("  |     |\n");
        printf("  |\n");
        printf("  |\n");
        printf("__|________\n");
    } 
    else if (erros == 1)
    {
        printf("  _______\n");
        printf("  |     |\n");
        printf("  |     O\n");
        printf("  |\n");
        printf("__|________\n");
    } 
    else if (erros == 2)
    {
        printf("  _______\n");
        printf("  |     |\n");
        printf("  |     O\n");
        printf("  |     |\n");
        printf("__|________\n");
    } 
    else if (erros == 3)
    {
        printf("  _______\n");
        printf("  |     |\n");
        printf("  |     O\n");
        printf("  |    /|\n");
        printf("__|________\n");
    } 
    else if (erros == 4) 
    {
        printf("  _______\n");
        printf("  |     |\n");
        printf("  |     O\n");
        printf("  |    /|\\\n");
        printf("__|________\n");
    } 
    else if (erros == 5) 
    {
        printf("  _______\n");
        printf("  |     |\n");
        printf("  |     O\n");
        printf("  |    /|\\\n");
        printf("  |    /\n");
        printf("__|________\n");
    } 
    else
    {
        printf("  _______\n");
        printf("  |     |\n");
        printf("  |     O\n");
        printf("  |    /|\\\n");
        printf("  |    / \\\n");
        printf("__|________\n");
    }
}

// Função principal da fase integrada (Sem parâmetro void)
void hopper_historia()
{
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif

    srand(time(NULL));

    char *palavras[] = {
        "COMPILADOR",
        "COBOL",
        "COMPUTADOR",
        "CODIGO",
        "PROGRAMA",
        "BINARIO",
        "MEMORIA",
        "TECLADO",
        "ALGORITMO",
        "BUG"
    };
    int totalpalavras = 10; 

    // Apresentação estruturada e imersiva (roda apenas uma vez)
    printf("\n==================================================\n");
    printf("         VIAJANDO PARA 1944 - ESTADOS UNIDOS      \n");
    printf("==================================================\n");
    PAUSA(2);

    printf("Grace Hopper foi uma cientista da computacao e\n");
    printf("contra-almirante da Marinha dos Estados Unidos.\n");
    printf("Pioneira no desenvolvimento de compiladores e\n");
    printf("da linguagem COBOL, que aproximou a linguagem\n");
    printf("dos computadores da linguagem humana!\n");
    printf("==================================================\n");
    PAUSA(4);

    printf("\n[O viajante chega a um laboratorio cheio de maquinas\n");
    printf(" enormes e luzes piscando. Grace Hopper esta trabalhando.]\n");
    PAUSA(3);

    printf("\nGrace Hopper: 'Bem-vindo ao meu laboratorio!'\n");
    printf("Estou trabalhando em maneiras de tornar a programacao\n");
    printf("mais simples e compreensivel para as pessoas.\n");
    PAUSA(3);

    printf("\nGrace Hopper: 'Quero que programar seja mais acessivel.\n");
    printf("Por isso, estou criando sistemas capazes de traduzir\n");
    printf("instrucoes para o computador executar.'\n");
    PAUSA(3);

    printf("\nGrace Hopper: 'Uma mensagem foi codificada em binario\n");
    printf("e precisamos decifra-la. Consegue descobrir as letras\n");
    printf("escondidas antes que o alarme dispare?'\n");
    printf("==================================================\n");
    PAUSA(3);

    printf("\n[Pressione ENTER para comecar o desafio...]\n");
    getchar(); // Consome o enter pendente

    // LOOP INFINITO DE TENTATIVAS: Proibido desistir! O usuário só sai daqui quando vencer.
    while (1)
    {
        int indice = rand() % totalpalavras;
        char *palavraSecreta = palavras[indice];
        int tam = strlen(palavraSecreta);
        int revelada[20] = {0};
        int erros = 0;
        int letrasDescobertas = 0;

        // Limpa o vetor de letras reveladas para a nova tentativa
        for (int i = 0; i < 20; i++) {
            revelada[i] = 0;
        }

        while (erros < 6)
        {
            char tentativa;
            printf("\n--------------------------------------------------\n");
            printf("Digite uma letra: ");
            scanf(" %c", &tentativa);
            tentativa = toupper(tentativa);
            printf("Voce digitou: %c\n", tentativa);

            int acertou = 0;
            
            for (int i = 0; i < tam; i++)
            {
                if (tentativa == palavraSecreta[i] && revelada[i] == 0)
                {
                    acertou = 1;
                    revelada[i] = 1;
                    letrasDescobertas++;
                }
            }

            if (acertou == 1)
            {
                printf("-> Voce acertou uma letra!\n");
            }
            else
            {
                erros++;
                printf("-> Voce errou!\n");
            }

            printf("Erros: %d/6\n", erros);
            desenharForca(erros);

            printf("\nPalavra (com binario para letras ocultas):\n");
            for (int i = 0; i < tam; i++) 
            {
                if (revelada[i] == 1) 
                {
                    printf("%c ", palavraSecreta[i]);
                } 
                else 
                {
                    unsigned char letra = palavraSecreta[i];
                    for (int bit = 7; bit >= 0; bit--) 
                    {
                        int valorBit = (letra >> bit) & 1;
                        printf("%d", valorBit);
                    }
                    printf(" ");
                }   
            }
            printf("\n");

            if (letrasDescobertas == tam)
            {
                printf("\n==================================================\n");
                printf("   PARABENS! VOCE VENCEU O DESAFIO DE GRACE!      \n");
                printf("==================================================\n");
                PAUSA(3);
                return; // Vitória alcançada, sai da função e avança na história!
            }
        }

        // Se chegou aqui, errou 6 vezes, mas a linha temporal exige persistência!
        printf("\n==================================================\n");
        printf("   ALERME DO SISTEMA! A forca cedeu...\n");
        printf("   Grace Hopper: 'Nao desista, agente! Tente outra palavra!'\n");
        printf("   Reiniciando o sistema de decodificacao...\n");
        printf("==================================================\n");
        PAUSA(3);
    }
}