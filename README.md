# Campeonato Computacional de Futebol — Parte I

Sistema em C para gerenciamento de partidas e classificação de um campeonato de futebol fictício.

---

## Compilação e Execução

Requisitos: GCC 11+, Linux (Ubuntu 22.04 recomendado)/WSL.

```bash
make          # compila o projeto
./campeonato  # executa o sistema
```

Os arquivos `times.csv` e `partidas.csv` devem estar no **mesmo diretório** do executável.

Para limpar os objetos compilados:
```bash
make clean
```

---

## Estrutura do repositório

```
.
* main.c          # Programa principal e menu interativo
* time.h / time.c           # TAD Time
* bdtimes.h / bdtimes.c     # TAD BDTimes
* partida.h / partida.c     # TAD Partida
* bdpartidas.h / bdpartidas.c # TAD BDPartidas
* Makefile
* times.csv       # Banco de dados dos times
* partidas.csv    # Banco de dados das partidas
```

---

## Principais TADs

### Time (`time.h`)
Representa um time de futebol. Armazena id, nome e estatísticas acumuladas (V, E, D, GM, GS). Os campos derivados (saldo de gols e pontos ganhos) são calculados sob demanda pelas funções `time_saldo()` e `time_pontos()`.

### BDTimes (`bdtimes.h`)
Gerencia o vetor estático de times. Responsável por carregar o `times.csv`, buscar times por ID ou por prefixo de nome (case-insensitive), e imprimir a tabela de classificação.

### Partida (`partida.h`)
Representa uma única partida: ID, IDs dos dois times e placar.

### BDPartidas (`bdpartidas.h`)
Gerencia o vetor estático de partidas. Ao carregar o `partidas.csv`, atualiza automaticamente as estatísticas de cada time no BDTimes. Oferece consulta de partidas por prefixo de nome e modo (mandante, visitante ou qualquer).

---

## Funcionalidades implementadas

| Opção | Descrição |
|-------|-----------|
| 1 | Consultar time por nome ou prefixo |
| 2 | Consultar partidas por time|
| 6 | Imprimir tabela de classificação |
| Q | Encerrar o sistema |

As opções 3, 4 e 5 estão desabilitas.

---

## Principais decisões de implementação

- **Vetores estáticos** para `BDTimes` (MAX 100) e `BDPartidas` (MAX 500).
- **Estatísticas calculadas na carga**: ao ler cada partida, os campos V/E/D/GM/GS dos times são atualizados imediatamente, evitando percorrer o vetor de partidas a cada consulta.
- **Busca por prefixo case-insensitive** usando `strncasecmp` (POSIX), disponível no GCC/Linux.
- **Separação clara de responsabilidades**: cada TAD possui seu próprio par `.h`/`.c` sem dependências cruzadas desnecessárias.
