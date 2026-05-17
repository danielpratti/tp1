#ifndef TIME_H
#define TIME_H

#define MAX_NOME 50

/* Estrutura que representa um time de futebol */
typedef struct {
    int id;
    char nome[MAX_NOME];
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
} Time;

/* Cria e retorna um Time com estatísticas zeradas */
Time time_criar(int id, const char *nome);

/* Retorna o saldo de gols (GM - GS) */
int time_saldo(const Time *t);

/* Retorna os pontos ganhos (3*V + E) */
int time_pontos(const Time *t);

/* Imprime as estatísticas de um time formatadas */
void time_imprimir(const Time *t);

/* Imprime o cabeçalho da tabela */
void time_imprimir_cabecalho(void);

#endif
