#include "bot.h"
#include "perfil.h"
#include "placar.h"
#include "versus.h"
#include "auxiliares.h"

int main()
{

    #if WINDOWS
        u_int cpag = 65001;
        u_int cpagDefault = GetConsoleOutputCP;

        SetConsoleOutputCP(cpag);

    #endif // WINDOWS

    setlocale(LC_ALL, "pt_BR.utf8");
    srand(time(NULL));

    perfil *perfis = malloc(sizeof(perfil));
    perfis->nome[0] = '\0';
    perfis->partidasGanhas = 0;
    perfis->partidasTotais = 0;
    perfis->proximo = NULL;

    lerPerfis(perfis);
    int menu;

    while (1)
    {
        printf("\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=\n");
        colorir(ROXO);
        printf("\t                       JOGO DO NIM                       \n");
        colorir(NORMAL);
        printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=\n\n");
        pausar(0.2);
        printf("\tSeja Bem-Vindo! Escolha uma opção para começar:\n");
        pausar(0.2);
        printf("\t\t1 - Visualizar Placar\n");
        pausar(0.2);
        printf("\t\t2 - Editar Usuários\n");
        pausar(0.2);
        printf("\t\t3 - Jogar contra Bot/Tutorial\n");
        pausar(0.2);
        printf("\t\t4 - Jogar modo Versus\n");
        pausar(0.2);
        printf("\t\t0 - Finalizar Programa\n");
        pausar(0.2);
        do
        {
            printf("\tQual opção você deseja? ");
            scanf("%d", &menu);
            limpaBuffer();
            if (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 0)
                printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
        } while (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 0);

        if (menu == 0)
            break;
        switch (menu)
        {
        case 1:
            visualizarPlacar(perfis);
            break;
        case 2:
            editarPerfis(perfis);
            break;
        case 3:
            partidaBot();
            break;
        case 4:
            partidaVersus(perfis);
        }
    }

    salvarPerfis(perfis);
    printf("\n\tObridado por Jogar! :D");
    printf("\n\t(Pressione ");
    colorir(VERMELHO);
    printf("Enter");
    colorir(NORMAL);
    printf(" para finalizar!)");

    if (getchar() != '\n')
        limpaBuffer();
#if WINDOWS
    system("cls");
    SetConsoleOutputCP(cpagDefault);
#else
    system("clear");
#endif
    return 0;
}
