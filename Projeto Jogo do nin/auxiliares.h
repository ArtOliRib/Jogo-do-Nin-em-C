#ifndef AUXILIARES_H
#define AUXILIARES_H

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS 1
#include <windows.h>
#include <conio.h>
#else
#define WINDOWS 0
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Perfil
{
    char nome[30];
    int partidasGanhas;
    int partidasTotais;
    struct Perfil *proximo;
} perfil;

enum cores
{
    VERMELHO,
    AZUL,
    ROXO,
    NORMAL
};

enum ordens
{
    NOME,
    RANK
};

void limpaBuffer(void);

// Faz o programa pausar por um tempo
void pausar(float segundos);

// Usado para organizar a lista de jogadores por Nome com o qsort
int comparaNome(const void *a, const void *b);

// Usado para organizar a lista de jogadores por Partidas Ganhas com o qsort
int comparaRank(const void *a, const void *b);

// Usada para utilizar o qsort na lista encadeada
int ordenaLista(perfil *inicio, int tipo);

// Usado para mudar as cores dos textos no Windows
#if WINDOWS
void textcolor(int color);
#endif

// Usado para mudar as cores dos textos no geral
void colorir(int cor);

#endif
