#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- TRUQUE MULTIPLATAFORMA PARA PAUSAS (WINDOWS / LINUX) ---
#ifdef _WIN32
    #include <windows.h>
    #define PAUSA(segundos) Sleep((segundos) * 1000)
#else
    #include <unistd.h>
    #define PAUSA(segundos) sleep(segundos)
#endif

void joan_historia()
{
    char mensagem[] = "DWDTXH";
    char tentativa[10];
    int vidas = 3;
    int acertou = 0;
    int erros = 0;

    printf("\n");
    printf("        A HISTORIA DE JOAN CLARKE\n\n");
    PAUSA(2);

    printf("Era a decada de 1940, durante a Segunda\n");
    printf("Guerra Mundial (1939-1945). A Inglaterra\n");
    printf("enfrentava a Alemanha nazista, que enviava\n");
    printf("mensagens secretas pela maquina Enigma.\n\n");
    PAUSA(3);

    printf("Joan Clarke, uma matematica britanica,\n");
    printf("trabalhou em Bletchley Park, centro secreto\n");
    printf("de inteligencia do Reino Unido. Ao lado de\n");
    printf("Alan Turing e outros especialistas, ajudou\n");
    printf("a decifrar mensagens alemas e descobrir\n");
    printf("estrategias militares do inimigo.\n\n");
    PAUSA(4);

    printf("Apesar de enfrentar preconceito por ser\n");
    printf("mulher em uma area dominada por homens,\n");
    printf("Joan destacou-se por sua inteligencia e\n");
    printf("habilidade matematica.\n\n");
    PAUSA(3);

    printf("Seu trabalho contribuiu para os Aliados\n");
    printf("durante a guerra, mostrando que o\n");
    printf("conhecimento pode mudar a historia.\n\n");
    PAUSA(3);

    printf("====================================\n");
    printf("        INICIO DA MISSAO SECRETA\n");
    printf("====================================\n\n");
    PAUSA(2);

    printf("Mensagem interceptada: %s\n", mensagem);

    // Variável 'i' declarada direto no escopo do for (boas práticas)
    for (int i = 0; i < strlen(mensagem); i++)
    {
        mensagem[i] = mensagem[i] - 3;
    }

    while (vidas > 0 && acertou == 0)
    {
        printf("\nVoce tem %d vidas.\n", vidas);
        printf("Digite a palavra decodificada: ");

        scanf("%9s", tentativa);

        if (strcmp(tentativa, mensagem) == 0)
        {
            acertou = 1;

            printf("\n");
            printf("====================================\n");
            printf("         CODIGO DECIFRADO!\n");
            printf("====================================\n\n");
            PAUSA(1);

            printf("Voce conseguiu! A palavra era ATAQUE.\n\n");
            PAUSA(2);

            printf("Joan Clarke analisou as informacoes e\n");
            printf("percebeu que elas revelavam planos\n");
            printf("militares importantes dos nazistas.\n\n");
            PAUSA(3);

            printf("Rapidamente, as informacoes foram\n");
            printf("encaminhadas aos Aliados, ajudando-os\n");
            printf("a compreender as estrategias inimigas.\n\n");
            PAUSA(3);

            printf("Gracas a sua inteligencia e persistencia,\n");
            printf("a missao foi concluida com sucesso!\n\n");
            PAUSA(2);

            printf("Seu trabalho entrou para a historia,\n");
            printf("mostrando que o conhecimento pode\n");
            printf("mudar o rumo de uma guerra.\n\n");
            printf("        MISSAO CONCLUIDA!\n\n");
            PAUSA(3);
        }
        else
        {
            vidas--;
            erros++;

            printf("\nRESPOSTA INCORRETA!\n\n");
            PAUSA(1);

            if (erros == 1)
            {
                printf("A mensagem ficou parcialmente comprometida.\n");
                printf("Algumas informacoes importantes continuam\n");
                printf("incompletas. Tente novamente!\n\n");

                printf("Dica 1: A cifra foi deslocada em 3\n");
                printf("posicoes na tabela ASCII.\n");
                printf("Tente recuar cada letra 3 casas.\n");
            }
            else if (erros == 2)
            {
                printf("A equipe esta ficando preocupada!\n");
                printf("O atraso na decodificacao pode dificultar\n");
                printf("a descoberta dos planos inimigos.\n\n");

                printf("Dica 2: E o que um exercito faz de\n");
                printf("surpresa contra o inimigo.\n");
                printf("A palavra comeca com a letra A.\n");
                printf("Um soldado disse que talvez\n");
                printf("se tentar tudo maiusculo funcione\n");
            }

            if (vidas > 0)
            {
                printf("\nVidas restantes: %d\n", vidas);
            }
            else
            {
                printf("\n");
                printf("====================================\n");
                printf("      ALARME TEMPORAL ACIONADO!\n");
                printf("====================================\n");
                printf("\n");

                printf("Voce perdeu todas as vidas!\n");
                printf("A mensagem secreta nao foi descoberta.\n");

                printf("\n");
                printf("====================================\n");
                printf("   GAME OVER - Missao fracassada!\n");
                printf("====================================\n");
                PAUSA(3);
            }
        }
    }
}