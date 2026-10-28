#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

// --- TRUQUE MULTIPLATAFORMA PARA PAUSAS (WINDOWS / LINUX) ---
#ifdef _WIN32
    #include <windows.h>
    #define PAUSA(segundos) Sleep((segundos) * 1000)
#else
    #include <unistd.h>
    #define PAUSA(segundos) sleep(segundos)
#endif

// Função do mini-game River Raid criado por você (J.Bena)
int river_raid(char pos)
{
    char letra_maiuscula = toupper(pos);
    
    if (letra_maiuscula != 'W' && letra_maiuscula != 'A' && 
        letra_maiuscula != 'S' && letra_maiuscula != 'D')
    {
        return 0;
    }
    else
    {
        // Controle da nave
        static int p_linha = 8, p_coluna = 3;

        if (pos == 'W' || pos == 'w') {
            p_linha--;  
        } 
        else if (pos == 'S' || pos == 's') {
            p_linha++;  
        } 
        else if (pos == 'A' || pos == 'a') {
            p_coluna--; 
        } 
        else if (pos == 'D' || pos == 'd') {
            p_coluna++; 
        }

        // Verificação pra não estourar a lista
        if (p_linha < 0) p_linha = 0;
        if (p_linha > 8) p_linha = 8;
        if (p_coluna < 0) p_coluna = 0;
        if (p_coluna > 6) p_coluna = 6;

        static char rio[9][7];
        static bool inicio = true;
        char nave = '^';
        char inimigo = 'I';
        int coluna_random;

        if (inicio)
        {
            // Criar o rio
            for (int linha = 0; linha < 9; linha++)
            {
                for (int coluna = 0; coluna < 7; coluna++)
                {
                    rio[linha][coluna] = '~';
                }
            }
            inicio = false;
        }

        // Descer rio
        for (int linha = 8; linha > 0; linha--)
        {
            for (int coluna = 0; coluna < 7; coluna++)
            {
                rio[linha][coluna] = rio[linha - 1][coluna]; 
            }
        }

        // Repoe a linha 0
        for (int coluna = 0; coluna < 7; coluna++)
        {
            rio[0][coluna] = '~';
        }

        // Adiciona inimigos em cima
        for (int i = 0; i < 3; i++) 
        {
            coluna_random = rand() % 7;
            rio[0][coluna_random] = inimigo;
        }

        // Verificar colisão
        if (rio[p_linha][p_coluna] == inimigo)
        {
            return -1;
        }

        char tela_visual[9][7];
        for (int linha = 0; linha < 9; linha++)
        {
            for (int coluna = 0; coluna < 7; coluna++)
            {
                tela_visual[linha][coluna] = rio[linha][coluna];
            }
        }

        // Adicionar a nave no rio
        tela_visual[p_linha][p_coluna] = nave;

        // Desenhar rio
        for (int linha = 0; linha < 9; linha++)
        {
            for (int coluna = 0; coluna < 7; coluna++)
            {
                printf("%c ", tela_visual[linha][coluna]);
            }
            printf("\n");
        }

        // Verifica se a nave chegou no topo e encerra
        if (p_linha == 0)
        {
            return 2; // Retorna 2 para Vitória
        }
        return 1;
    }
}

// Função principal da fase da Carol Shaw integrada ao fluxo do projeto
void carol_historia()
{
    char x;

    printf("-------------------------------------------\n");
    printf("     VIAJANDO PARA 1980 - CALIFORNIA       \n");
    printf("-------------------------------------------\n");
    PAUSA(2);
    printf("Epoca em que Carol Shaw, uma das primeiras  \n");
    printf("mulheres programadoras de jogos da industria,\n");
    printf("criou o revolucionario River Raid para o   \n");
    printf("Atari 2600, redefinindo os jogos de tiro e \n");
    printf("scrolling vertical para sempre!            \n");
    printf("-------------------------------------------\n");
    PAUSA(7);

    // Diálogo do player
    printf("\n[Player] (Sussurrando consigo mesmo)\n");
    PAUSA(2);
    printf("Ufa... Ada Lovelace, Grace Hopper, Joan Clarke, Margaret Hamilton...\n");
    PAUSA(3);
    printf("Ja passei por tanta coisa nessa anomalia temporal. So falta a Carol Shaw para fechar o ciclo e salvar o meu presente!\n");
    PAUSA(4);

    // Diálogo com a Carol Shaw
    printf("\n[Carol Shaw olha para tras, intrigada com as suas roupas do futuro]\n");
    PAUSA(3);
    printf("Carol Shaw: 'Hein? Quem e voce? E de onde tirou esse equipamento estranho? Estou a tentar finalizar a logica de scrolling do River Raid, mas esta a dar-me dor de cabeca...'\n");
    PAUSA(4);
    
    printf("\n[Player]\n");
    PAUSA(2);
    printf("Sou um programador do futuro, Carol! Preciso da sua ajuda para estabilizar a linha do tempo... mas para isso, vamos ter de testar e validar o seu jogo agora mesmo!\n");
    PAUSA(4);

    printf("\n[Carol Shaw sorri, segurando o seu bloco de notas]\n");
    PAUSA(3);
    printf("Carol Shaw: 'Um programador do futuro? Adoro desafios. Entao mostra o que sabes sobre matrizes e controle de rio!'\n");
    PAUSA(3);

    // Instruções do jogo
    printf("\n========================================\n");
    printf("           INSTRUCOES DE VOO            \n");
    printf("========================================\n");
    printf(" W -> Cima    (Subir no rio)\n");
    printf(" A -> Esquerda(Desviar para a esquerda)\n");
    printf(" S -> Baixo   (Recuar)\n");
    printf(" D -> Direita (Desviar para a direita)\n");
    printf("========================================\n");
    PAUSA(3);
    printf("\nPreparando o cockpit...\n");
    PAUSA(2);

    while (true)
    {
        printf("\nDIGITE UMA TECLA (W/A/S/D): \n");
        printf("TECLA: ");
        scanf(" %c", &x);
        
        int resultado = river_raid(x);

        if (resultado == 0)
        {
            printf("Tecla invalida! Use apenas W, A, S ou D.\n");
        }
        else if (resultado == -1)
        {
            printf("\n----------------------------------------\n");
            printf(" KABOOM! Bateu no inimigo! A linha do tempo instabilizou...\n");
            printf(" Tente novamente, o futuro depende de voce!\n");
            printf("----------------------------------------\n");
        }
        else if (resultado == 2)
        {
            // Vitória alcançada!
            printf("\n========================================\n");
            printf("   P A R A B E N S ! VOCE VENCEU O RIO! \n");
            printf("========================================\n");
            PAUSA(2);
            break; 
        }
    }

    // Diálogo pós-vitória
    PAUSA(2);
    printf("\n[A matriz do rio estabiliza e o codigo compila com sucesso na tela do Atari]\n");
    PAUSA(3);
    printf("Carol Shaw: 'Incrivel! O algoritmo de scrolling ficou perfeito. Consegues ver? O codigo esta a correr de forma impecavel!'\n");
    PAUSA(4);
    
    printf("\n[Player] (Sorrindo aliviado, sentindo o portal temporal a abrir-se)\n");
    PAUSA(3);
    printf("Consegui... Hora de voltar pro futuro! Obrigado por tudo, Carol. Voce mudou a historia dos videogames para sempre.\n");
    PAUSA(4);

    printf("\n[Carol Shaw acena enquanto uma luz brilhante consome o ambiente]\n");
    PAUSA(3);
    printf("Carol Shaw: 'Boa viagem, programador do futuro! Diz a galera la frente que o nosso codigo e a prova de falhas!'\n");
    PAUSA(4);

    printf("\n=================================================\n");
    printf("    LINHA DO TEMPO SALVA COM SUCESSO!   \n");
    printf("   OBRIGADO POR JOGAR AS BRILHANTES MENTES FEMININAS!   \n");
    printf("===================================================\n");
}