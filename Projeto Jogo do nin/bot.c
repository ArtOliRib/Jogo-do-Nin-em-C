#include "auxiliares.h"

void jogadorJogaVSBot(int *totalDePecas, int totalPorJogada)
{
    // Função usada pelo Jogador durante a partida contra o Bot
    int escolha;
    do
    {
        printf("\n\tAgora, digite a quantidade de peças a serem tiradas (Total atual é %d): ", *totalDePecas);
        scanf("%d", &escolha);
        limpaBuffer();
        if (escolha < 1 || escolha > totalPorJogada || escolha > *totalDePecas)
        {
            printf("\n\tOops! Jogada inválida! Tente de novo.\n");
            pausar(0.2);
            if (*totalDePecas == 1)
                printf("\tSó restou uma peça, digite 1 para continuar.\n");
            else
                printf("\tPode escolher apenas um número entre 1 e %d.\n", totalPorJogada <= *totalDePecas ? totalPorJogada : *totalDePecas);
            pausar(0.2);
        }
        pausar(0.2);
    } while (escolha < 1 || escolha > totalPorJogada || escolha > *totalDePecas);

    *totalDePecas -= escolha;
    if (*totalDePecas == 1)
        printf("\n\tÓtimo! Você tirou %d peça, o total agora é de %d\n", escolha, *totalDePecas);
    else
        printf("\n\tÓtimo! Você tirou %d peças, o total agora é de %d\n", escolha, *totalDePecas);
    pausar(0.5);
}

void computadorJoga(int *totalDePecas, int totalPorJogada)
{
    // Função usada pelo Bot
    int escolha;
    escolha = *totalDePecas % (totalPorJogada + 1);
    *totalDePecas -= escolha;
    if (*totalDePecas == 1)
        printf("\n\tComo só restou 1 peça, o Bot a retirará agora.\n", *totalDePecas + escolha, escolha);
    else
        printf("\n\tComo só restam %d peças, o Bot retirará %d peças agora.\n", *totalDePecas + escolha, escolha);
    pausar(0.2);
    if (*totalDePecas > totalPorJogada)
        printf("\tDessa forma, sobrará um total de peças que é múltiplo de %d e, no final, o Bot poderá pegar a última peça e vencer! :)\n", totalPorJogada + 1);
    else
        printf("\tComo agora só sobraram %d peças, o Bot pegará as que restam e ganhará!\n", *totalDePecas + escolha);
    pausar(0.2);
    printf("\tO Bot tirou %d peças, o total agora é de %d\n", escolha, *totalDePecas);
    pausar(0.5);
}

void partidaBot()
{
    // Introdução e Definição de parâmetros iniciais da partida
    int totalDePecas, totalPorJogada, jogadorComeca;
    printf("\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=\n");
    colorir(VERMELHO);
    printf("\t              MODO BOT (Explicação do Jogo)              \n");
    colorir(NORMAL);
    printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=\n\n");
    pausar(0.2);
    printf("\tSeja Bem-Vindo! Nesse modo você irá perder!\n");
    pausar(0.2);
    printf("\tMas não se preocupe! Isso já é esperado.\n");
    pausar(0.2);
    printf("\tNesse jogo, ao se jogar de forma perfeita, é possível que um dos jogadores sempre ganhe.\n");
    pausar(0.2);
    printf("\tIndepentente do que o outro faça!\n");
    pausar(0.2);
    printf("\n\tNesse modo você jogará contra um Bot, que o vencerá, mas explicará o que está fazendo.\n");
    pausar(0.2);
    printf("\tMas primeiro, qual a quantia de peças totais que você deseja para a partida? ");
    do
    {
        scanf("%d", &totalDePecas);
        limpaBuffer();
        pausar(0.2);
        if (totalDePecas < 2)
            printf("\n\tEsse número é inválido! Digite um pelo menos maior que 1: ");
    } while (totalDePecas < 2);
    printf("\n\tMuito bem, agora diga, até quantas peças poderão ser removidas por turno do jogo: ");
    do
    {
        scanf("%d", &totalPorJogada);
        limpaBuffer();
        pausar(0.2);
        if (totalPorJogada >= totalDePecas || totalPorJogada < 1)
            printf("\n\tEsse número é inválido! Digite um maior que 0 e menor que o total de peças: ");
    } while (totalPorJogada >= totalDePecas || totalPorJogada < 1);

    // Definição de quem terá a iniciativa na partida
    if (totalDePecas % (totalPorJogada + 1) == 0)
    {
        printf("\n\tMuito bem, como você escolheu um número de peças totais\n");
        printf("\tque é multiplo do total de peças por turno mais 1, você começará!\n");
        jogadorComeca = 1;
    }
    else
    {
        printf("\n\tMuito bem, como você escolheu um número de peças totais\n");
        printf("\tque não é multiplo do total de peças por turno mais 1, o Bot começará!\n");
        jogadorComeca = 0;
    }
    pausar(0.5);

    // Loop da partida
    int i = 1;
    for (i; totalDePecas > 0; i++)
    {
        if (i % 2 == jogadorComeca)
            jogadorJogaVSBot(&totalDePecas, totalPorJogada);
        else
            computadorJoga(&totalDePecas, totalPorJogada);
    }

    if (--i % 2 == jogadorComeca)
        // Esse print nunca é executado
        printf("\n\tFim de jogo! Você ganhou! (C-como você fez isso? Você roubou né?)\n");
    else
        printf("\n\tFim de jogo! O Bot ganhou! [ Como esperado ;) ]\n");

    printf("\n\t(Pressione ");
    colorir(VERMELHO);
    printf("Enter");
    colorir(NORMAL);
    printf(" para continuar)");

    if (getchar() != '\n')
        limpaBuffer();
}
