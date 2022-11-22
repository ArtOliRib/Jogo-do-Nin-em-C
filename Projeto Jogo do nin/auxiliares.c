#include "auxiliares.h"

void limpaBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

// Faz o programa pausar por um tempo
void pausar(float segundos)
{
#if WINDOWS
    Sleep((int)(segundos * 1000));
#else
    usleep((int)(segundos * 1000000));
#endif
}

// Usado para organizar a lista de jogadores por Nome com o qsort
int comparaNome(const void *a, const void *b)
{
    return strcmp((*(perfil **)a)->nome, (*(perfil **)b)->nome);
}

// Usado para organizar a lista de jogadores por Partidas Ganhas com o qsort
int comparaRank(const void *a, const void *b)
{
    return (*(perfil **)b)->partidasGanhas - (*(perfil **)a)->partidasGanhas;
}

// Usada para utilizar o qsort na lista encadeada
int ordenaLista(perfil *inicio, int tipo)
{
    perfil *final = inicio->proximo;
    int tamanho = 1;
    for (tamanho; final != NULL; tamanho++)
        final = final->proximo;
    final = inicio->proximo;

    if (--tamanho < 2)
        return 1;

    perfil *ponteiros[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        ponteiros[i] = final;
        final = final->proximo;
    }

    if (tipo == RANK)
        qsort(ponteiros, tamanho, sizeof(perfil *), comparaRank);
    else
        qsort(ponteiros, tamanho, sizeof(perfil *), comparaNome);

    perfil *atual = inicio;
    for (int i = 0; i < tamanho; i++)
    {
        atual->proximo = ponteiros[i];
        atual = atual->proximo;
    }
    atual->proximo = NULL;
    return 0;
}

// Usado para mudar as cores dos textos no Windows
#if WINDOWS
void textcolor(int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (__BACKGROUND << 4));
}
#endif

void colorir(int cor)
{
#if WINDOWS
    switch (cor)
    {
    case VERMELHO:
        textcolor(4);
        break;
    case AZUL:
        textcolor(1);
        break;
    case ROXO:
        textcolor(5);
        break;
    case NORMAL:
        textcolor(7);
    }
#else
    switch (cor)
    {
    case VERMELHO:
        printf("\033[0;31m");
        break;
    case AZUL:
        printf("\033[0;34m");
        break;
    case ROXO:
        printf("\033[0;35m");
        break;
    case NORMAL:
        printf("\033[0m");
    }
#endif
}
