#include "auxiliares.h"

int lerPerfis(perfil *inicio)
{
    FILE *file;

    // Abre o arquivo
    file = fopen("placar.txt", "r");
    if (file == NULL)
    {
        file = fopen("placar.txt", "w");
        return 1;
    }

    // Define o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Lê os perfis
    perfil *atual = inicio;
    while (ftell(file) < fileSize)
    {
        atual->proximo = malloc(sizeof(perfil));
        atual = atual->proximo;
        fscanf(file, "%s %d %d ", atual->nome, &atual->partidasGanhas, &atual->partidasTotais);
    }
    atual->proximo = NULL;

    // Fecha o arquivo
    fclose(file);
    return 0;
}

int salvarPerfis(perfil *inicio)
{
    FILE *file;

    // Abre o arquivo
    file = fopen("placar.txt", "w");
    if (file == NULL)
    {
        printf("Erro criando o placar.");
        return -1;
    }

    // Ordena os perfis por nome
    ordenaLista(inicio, NOME);

    // Salva os perfis
    perfil *atual = inicio->proximo, *remover;
    while (atual != NULL)
    {
        fprintf(file, "%s %d %d\n", atual->nome, atual->partidasGanhas, atual->partidasTotais);
        remover = atual;
        atual = atual->proximo;
        free(remover);
    }

    // Fecha o arquivo
    fclose(file);
    return 0;
}

int visualizarPlacar(perfil *inicio)
{
    // Sai da função caso o placar esteja vazio
    if (inicio->proximo == NULL)
    {
        printf("\t\nInfelizmente, ainda não existem jogadores cadastrados.\n");
        pausar(0.5);
        printf("\n\t(Pressione Enter para continuar)");
        if (getchar() != '\n')
            limpaBuffer();
        return 1;
    }

    // Ordena os jogadores por número de vitórias
    ordenaLista(inicio, RANK);

    // Mostra o Placar
    printf("\n\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    colorir(ROXO);
    printf("\t                                        PLACAR                                         \n");
    colorir(NORMAL);
    printf("\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    pausar(0.2);
    printf("\tNo  |              NOME              |  Vitórias   | Partidas Jogadas | Taxa de Vitória\n");

    perfil *atual = inicio->proximo;
    float porcentagemDeVitoria;
    for (int i = 0; atual != NULL; i++)
    {
        porcentagemDeVitoria = atual->partidasTotais != 0 ? (float)atual->partidasGanhas / atual->partidasTotais * 100 : 0.0;
        printf("\t%03d | %-30s |     %03d     |       %03d        |     %6.2f%%\n", i + 1, atual->nome, atual->partidasGanhas, atual->partidasTotais, porcentagemDeVitoria);
        pausar(0.2);
        atual = atual->proximo;
    }

    printf("\n\t(Pressione ");
    colorir(VERMELHO);
    printf("Enter");
    colorir(NORMAL);
    printf(" para continuar)");

    if (getchar() != '\n')
        limpaBuffer();
    return 0;
}
