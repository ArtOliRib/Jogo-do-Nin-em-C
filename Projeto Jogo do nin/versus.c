#include "auxiliares.h"

void jogadorJogaVersus(int *totalDePecas, int totalPorJogada, perfil *jogador, int rodada)
{
    // Define o nome do jogador da vez
    int escolha, i;
    char nome[30];
    if (rodada % 2 == 0)
        jogador->nome[0] == '\0' ? strcpy(nome, "Anônimo_1") : strcpy(nome, jogador->nome);
    else
        jogador->nome[0] == '\0' ? strcpy(nome, "Anônimo_2") : strcpy(nome, jogador->nome);

    // Recebe quantas peças o jogador escolheu retirar
    do
    {
        printf("\n\tVez de \"%s\", digite a quantidade de peças a serem tiradas (Total atual é %d): ", nome, *totalDePecas);
        scanf("%d", &escolha);
        limpaBuffer();
        if (escolha < 1 || escolha > totalPorJogada || escolha > *totalDePecas)
        {
            printf("\n\tOops! Jogada inválida! Tente de novo.\n");
            pausar(0.2);
            if (*totalDePecas == 1)
                printf("\tSó restou uma peça, digite 1 para continuar.\n");
            else
                printf("\tPode escolher apenas um número entre 1 e %d\n", totalPorJogada <= *totalDePecas ? totalPorJogada : *totalDePecas);
            pausar(0.2);
        }
        pausar(0.2);
    } while (escolha < 1 || escolha > totalPorJogada || escolha > *totalDePecas);

    // Remove as peças e avisa isso ao jogador
    *totalDePecas -= escolha;

    if (escolha == 1)
        printf("\tÓtimo! \"%s\" tirou 1 peça!\n\n", nome, escolha);
    else
        printf("\tÓtimo! \"%s\" tirou %d peças!\n\n", nome, escolha);

    // Mostra o número de peças retiradas de forma gráfica na tela

    printf("\t    ============     \n");
    pausar(0.1);
    if (rodada % 2 == 0)
    {
        printf("\t    |   ");
        colorir(VERMELHO);
        printf("oooo");
        colorir(NORMAL);
        printf("   |    \n");
        pausar(0.1);

        printf("\t    |   ");
        colorir(VERMELHO);
        printf("oooo");
        colorir(NORMAL);
        printf("   |    x %d\n", escolha);
        pausar(0.1);

        printf("\t    |   ");
        colorir(VERMELHO);
        printf("oooo");
        colorir(NORMAL);
        printf("   |    \n");
        pausar(0.1);
    }
    else
    {
        printf("\t    |   ");
        colorir(AZUL);
        printf("<><>");
        colorir(NORMAL);
        printf("   |    \n");
        pausar(0.1);

        printf("\t    |   ");
        colorir(AZUL);
        printf("<><>");
        colorir(NORMAL);
        printf("   |    x %d\n", escolha);
        pausar(0.1);

        printf("\t    |   ");
        colorir(AZUL);
        printf("<><>");
        colorir(NORMAL);
        printf("   |    \n");
        pausar(0.1);
    }
    colorir(NORMAL);
    pausar(0.1);
    printf("\t    ============     \n\a");
    pausar(0.1);

    printf("\n\tO total agora é de %d\n", *totalDePecas);
    pausar(0.5);
}

void partidaVersus(perfil *inicio)
{
    // Introdução e Definição de parâmetros iniciais da partida
    int totalDePecas, totalPorJogada, j1Escolha, j2Escolha;
    printf("\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=\n");
    colorir(VERMELHO);
    printf("\t                       MODO VERSUS                       \n");
    colorir(NORMAL);
    printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=\n\n");
    pausar(0.2);
    printf("\tSejam Bem-Vindos! Nesse modo são necessários dois jogadores.\n");
    pausar(0.2);
    printf("\tAs regras são quase as mesmas que o jogo do NIM comum, mas com uma pequena diferença.\n");
    pausar(0.2);
    printf("\tAssim como no jogo comum, algumas peças poderão ser tiradas por vez, quem tirar a última ganhará.\n");
    pausar(0.2);
    printf("\tEntretanto, buscando evitar que um dos jogadores sempre ganhe, um pouco de aleatoriedade foi\n");
    pausar(0.2);
    printf("\timplementado nessa versão!\n");
    pausar(0.2);
    printf("\n\tQuando alguém faz uma jogada, há 50%% de chance dele jogar novamente!\n");
    pausar(0.2);
    printf("\tPorém, nenhum jogador poderá jogar mais de 2 vezes seguidas.\n");
    pausar(0.2);
    printf("\tCaso um jogador jogue 2 vezes seguidas, a próxima jogada será do outro jogador.\n");
    pausar(0.2);
    printf("\tAgora, vamos ao jogo!\n");
    pausar(0.2);

    printf("\n\t(Pressione Enter para continuar)");
    if (getchar() != '\n')
        limpaBuffer();

    // Escolha dos Jogadores
    printf("\n\tPrimeiro, escolhamos os jogadores:\n");
    pausar(0.2);
    if (inicio->proximo != NULL)
    {
        perfil *atual = inicio->proximo;
        int i = 0;
        for (i; atual != NULL; i++)
        {
            printf("\t%03d - %-30s\n", i + 1, atual->nome);
            pausar(0.2);
            atual = atual->proximo;
        }
        int totalDePerfis = i;

        do
        {
            printf("\tQuem será o primeiro jogador? (Digite o número do jogador para escolhe-lo, ou 0 para \"Anônimo_1\"): ");
            scanf("%d", &j1Escolha);
            limpaBuffer();
            if (j1Escolha < 0 || j1Escolha > totalDePerfis)
                printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
        } while (j1Escolha < 0 || j1Escolha > totalDePerfis);
        do
        {
            printf("\tQuem será o segundo jogador? (Digite o número do jogador para escolhe-lo, ou 0 para \"Anônimo_2\"): ");
            scanf("%d", &j2Escolha);
            limpaBuffer();
            if ((j2Escolha < 0 || j2Escolha > totalDePerfis) || (j2Escolha == j1Escolha && j2Escolha != 0))
                printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
        } while ((j2Escolha < 0 || j2Escolha > totalDePerfis) || (j2Escolha == j1Escolha && j2Escolha != 0));
    }
    else
    {
        printf("\tNenhum jogador cadastrado, os jogadores serão \"Anônimo_1\" e \"Anônimo_2\"\n");
        j1Escolha = 0;
        j2Escolha = 0;
    }

    perfil *atual = inicio, *ptrJ1, *ptrJ2;
    for (int i = 0; atual != NULL; i++)
    {
        if (i == j1Escolha)
            ptrJ1 = atual;
        if (i == j2Escolha)
            ptrJ2 = atual;
        atual = atual->proximo;
    }

    // Definindo número de peças e peças por jogada
    printf("\tAgora, qual será a quantia de peças totais da partida? ");
    do
    {
        scanf("%d", &totalDePecas);
        limpaBuffer();
        pausar(0.2);
        if (totalDePecas < 2)
            printf("\tEsse número é inválido! Digite um pelo menos maior que 1: ");
    } while (totalDePecas < 2);
    printf("\n\tMuito bem, agora, até quantas peças poderão ser removidas por turno? ");
    do
    {
        scanf("%d", &totalPorJogada);
        limpaBuffer();
        if (totalPorJogada >= totalDePecas || totalPorJogada < 1)
            printf("\tEsse número é inválido! Digite um maior que 0 e menor que o total de peças: ");
    } while (totalPorJogada >= totalDePecas || totalPorJogada < 1);

    // Loop da partida
    int i = 0, repetir = 0;
    for (i; totalDePecas > 0; i++)
    {
        if (repetir)
            repetir = 0;
        else if (rand() % 2)
        {
            repetir = 1;
            i--;
        }

        if (i % 2 == 0)
            jogadorJogaVersus(&totalDePecas, totalPorJogada, ptrJ1, i);
        else
            jogadorJogaVersus(&totalDePecas, totalPorJogada, ptrJ2, i);
    }

    if (--i % 2 == 0)
    {
        // Jogador 1 vence, atualiza os valores dos perfis e mostra a vitória na tela
        if (j1Escolha > 0)
        {
            ptrJ1->partidasGanhas++;
            ptrJ1->partidasTotais++;
        }
        if (j2Escolha > 0)
            ptrJ2->partidasTotais++;

        colorir(ROXO);
        printf("\n\tFim de jogo! Vitória de %s!\n", j1Escolha == 0 ? "Anônimo_1" : ptrJ1->nome);
        colorir(NORMAL);
    }
    else
    {
        // Jogador 2 vence, atualiza os valores dos perfis e mostra a vitória na tela
        if (j2Escolha > 0)
        {
            ptrJ2->partidasGanhas++;
            ptrJ2->partidasTotais++;
        }
        if (j1Escolha > 0)
            ptrJ1->partidasTotais++;

        colorir(ROXO);
        printf("\n\tFim de jogo! Vitória de %s!\n", j2Escolha == 0 ? "Anônimo_2" : ptrJ2->nome);
        colorir(NORMAL);
    }

    printf("\n\t(Pressione ");
    colorir(VERMELHO);
    printf("Enter");
    colorir(NORMAL);
    printf(" para continuar)");

    if (getchar() != '\n')
        limpaBuffer();
}
