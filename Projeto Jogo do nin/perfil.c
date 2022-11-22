#include "auxiliares.h"

void adicionarPerfil(perfil *inicio)
{
    // Cria um novo perfil e o adiciona a lista de perfis
    perfil *final = inicio;
    while (final->proximo != NULL)
        final = final->proximo;
    final->proximo = malloc(sizeof(perfil));
    final = final->proximo;
    final->nome[0] = '\0';
    final->proximo = NULL;

    do
    {
        printf("\n\tDigite seu nome: (Até 30 caracteres) ");
        scanf("%29[^\n]", final->nome);
        limpaBuffer();
        pausar(0.2);
        if (final->nome[0] == '\0')
            printf("\tErro, o nome não pode ser vazio, digite algo.\n");
    } while (final->nome[0] == '\0');

    // Substitui todos os espaços por underline, por motivos de leitura do arquivo
    for (int i = 0; final->nome[i] != '\0'; i++)
        if (final->nome[i] == ' ')
            final->nome[i] = '_';

    // Define o valor inicial de partidas ganhas e totais
    final->partidasGanhas = 0;
    final->partidasTotais = 0;

    printf("\n\tNovo perfil adicionado com sucesso.\n");
    pausar(0.5);
}

int apagarPerfil(perfil *inicio)
{
    // Mostra os Perfis
    if (inicio->proximo == NULL)
    {
        printf("\t\nNão há perfis para serem removidos.");
        pausar(0.5);
        return 1;
    }
    int remover;
    printf("\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    colorir(ROXO);
    printf("\t                                        PERFIS                                         \n");
    colorir(NORMAL);
    printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    pausar(0.2);
    printf("\tNo  |              NOME              |  Vitórias   | Partidas Jogadas | Taxa de Vitória\n");

    perfil *atual = inicio->proximo;
    float porcentagemDeVitoria;
    int i = 0;
    for (i; atual != NULL; i++)
    {
        porcentagemDeVitoria = atual->partidasTotais != 0 ? (float)atual->partidasGanhas / atual->partidasTotais * 100 : 0.0;
        printf("\t%03d | %-30s |     %03d     |       %03d        |     %6.2f%%\n", i + 1, atual->nome, atual->partidasGanhas, atual->partidasTotais, porcentagemDeVitoria);
        pausar(0.2);
        atual = atual->proximo;
    }
    int totalDePerfis = i;
    printf("\t\n");

    // Recebe qual perfil será removido
    do
    {
        printf("\tQual perfil deseja remover? (Digite o número do perfil para apagar, ou 0 para cancelar): ");
        scanf("%d", &remover);
        limpaBuffer();
        if (remover < 0 || remover > totalDePerfis)
            printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
    } while (remover < 0 || remover > totalDePerfis);

    // Cancela a remoção
    if (remover == 0)
        return 1;

    // Remove o perfil escolhido da lista
    // O "atual" será um ponteiro para o elemento anterior ao que será excluido
    atual = inicio;
    for (i = 1; i < remover; i++)
        atual = atual->proximo;
    perfil *removido = atual->proximo;
    atual->proximo = atual->proximo->proximo;
    free(removido);

    printf("\n\tPerfil removido com sucesso.\n");
    pausar(0.5);
    return 0;
}

int renomearPerfil(perfil *inicio)
{
    // Mostra os Perfis
    if (inicio->proximo == NULL)
    {
        printf("\t\nNão há perfis para serem renomeados.");
        pausar(0.5);
        return 1;
    }
    int renomear;
    printf("\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    colorir(ROXO);
    printf("\t                                        PERFIS                                         \n");
    colorir(NORMAL);
    printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    pausar(0.2);
    printf("\tNo  |              NOME              |  Vitórias   | Partidas Jogadas | Taxa de Vitória\n");

    perfil *atual = inicio->proximo;
    float porcentagemDeVitoria;
    int i = 0;
    for (i; atual != NULL; i++)
    {
        porcentagemDeVitoria = atual->partidasTotais != 0 ? (float)atual->partidasGanhas / atual->partidasTotais * 100 : 0.0;
        printf("\t%03d | %-30s |     %03d     |       %03d        |     %6.2f%%\n", i + 1, atual->nome, atual->partidasGanhas, atual->partidasTotais, porcentagemDeVitoria);
        pausar(0.2);
        atual = atual->proximo;
    }
    int totalDePerfis = i;
    printf("\t\n");

    // Recebe qual perfil será renomeado
    do
    {
        printf("\tQual perfil deseja renomear? (Digite o número do perfil para renomear, ou 0 para cancelar): ");
        scanf("%d", &renomear);
        limpaBuffer();
        if (renomear < 0 || renomear > totalDePerfis)
            printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
    } while (renomear < 0 || renomear > totalDePerfis);

    // Cancela a renomeação
    if (renomear == 0)
        return 1;

    // Renomeia o perfil
    atual = inicio->proximo;
    for (i = 1; i < renomear; i++)
        atual = atual->proximo;
    atual->nome[0] = '\0';

    do
    {
        printf("\n\tDigite o novo nome: (Até 30 caracteres) ");
        scanf("%29[^\n]", atual->nome);
        limpaBuffer();
        pausar(0.2);
        if (atual->nome[0] == '\0')
            printf("\tErro, o nome não pode ser vazio, digite algo.\n");
    } while (atual->nome[0] == '\0');

    // Substitui todos os espaços por underline, por motivos de leitura do arquivo
    for (i = 0; atual->nome[i] != '\0'; i++)
        if (atual->nome[i] == ' ')
            atual->nome[i] = '_';

    printf("\n\tPerfil renomeado com sucesso.\n");
    pausar(0.5);
    return 0;
}

void editarPerfis(perfil *inicio)
{
    // Menu de edição de perfis
    int menu;
    while (1)
    {
        // Sempre que entra nesse menu, organiza os perfis por Nome
        ordenaLista(inicio, NOME);
        printf("\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=\n");
        colorir(ROXO);
        printf("\t                      EDITAR PERFIS                      \n");
        colorir(NORMAL);
        printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=\n\n");
        pausar(0.2);
        printf("\tSeja Bem-Vindo! Escolha uma opção para começar:\n");
        pausar(0.2);
        printf("\t\t1 - Adicionar Perfil\n");
        pausar(0.2);
        printf("\t\t2 - Apagar Perfil\n");
        pausar(0.2);
        printf("\t\t3 - Renomear Perfil\n");
        pausar(0.2);
        printf("\t\t0 - Sair do Editor\n");
        pausar(0.2);
        do
        {
            printf("\tQual opção você deseja? ");
            scanf("%d", &menu);
            limpaBuffer();
            if (menu != 1 && menu != 2 && menu != 3 && menu != 0)
                printf("\tPerdão, essa opção é inválida! Por favor, tente novamente.\n");
        } while (menu != 1 && menu != 2 && menu != 3 && menu != 0);

        if (menu == 0)
        {
            printf("\n\tVoltando ao Menu Principal!\n");
            pausar(0.5);
            break;
        }
        switch (menu)
        {
        case 1:
            adicionarPerfil(inicio);
            break;
        case 2:
            apagarPerfil(inicio);
            break;
        case 3:
            renomearPerfil(inicio);
        }
    }
}
