#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Macros para contagem de métricas
#define COUNT_CMP(m)   ((m)->comparacoes++, (m)->passos++)
#define COUNT_SWAP(m)  ((m)->trocas++, (m)->passos++)

typedef struct {
    long long passos;
    long long comparacoes;
    long long trocas;
    double tempo_ms;
} Metricas;

// FUNÇÃO DE ORDENACAO
void bubble_sort(int v[], int n, Metricas *m) {
    m->passos = m->comparacoes = m->trocas = 0;
    clock_t ini = clock();

    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            COUNT_CMP(m);
            if (v[j] > v[j+1]) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                COUNT_SWAP(m);
            }
        }
    }

    m->tempo_ms = (double)(clock() - ini) * 1000.0 / CLOCKS_PER_SEC;
}

// FUNÇÃO PARA COPIAR VETOR
void copia(int *dest, int *orig, int n) {
    for (int i = 0; i < n; i++) dest[i] = orig[i];
}

// FUNÇÃO PRINCIPAL
int main() {
    char rgm[20]; // buffer maior para capturar entradas inválidas
    int vetor_rgm[8];

    printf("Digite seu RGM (8 digitos): ");
    if (!fgets(rgm, sizeof(rgm), stdin)) {
        printf("ERRO: leitura falhou.\n");
        return 1;
    }

    // remover \n se existir
    rgm[strcspn(rgm, "\n")] = 0;

    // validar tamanho
    if (strlen(rgm) != 8) {
        printf("ERRO: o RGM deve conter exatamente 8 digitos.\n");
        return 1;
    }

    // validar se todos são dígitos
    for (int i = 0; i < 8; i++) {
        if (!isdigit(rgm[i])) {
            printf("ERRO: o RGM deve conter apenas numeros.\n");
            return 1;
        }
        vetor_rgm[i] = rgm[i] - '0';
    }

    Metricas m_bubble;
    int aux[8];

    printf("\n---ORDENANDO O RGM-----\n");

    copia(aux, vetor_rgm, 8);
    bubble_sort(aux, 8, &m_bubble);
    printf("Bubble Sort RGM: ");
    for (int i = 0; i < 8; i++) printf("%d", aux[i]);
    printf("\n");
    printf("Passos: %lld | Comparacoes: %lld | Trocas: %lld | Tempo: %.3f ms\n",
           m_bubble.passos, m_bubble.comparacoes, m_bubble.trocas, m_bubble.tempo_ms);

    // ABRIR ARQUIVO CSV PARA ESCRITA
    FILE *fp = fopen("resultados.csv", "w");
    if (!fp) {
        printf("ERRO: nao foi possivel criar o arquivo resultados.csv\n");
        return 1;
    }
    fprintf(fp, "Metodo,N,Passos,Comparacoes,Trocas,Tempo_ms\n");

    // BENCHMARK AUTOMÁTICO
    int tamanhos[] = {100, 1000, 10000};
    int qtd_t = 3;

    for (int t = 0; t < qtd_t; t++) {
        int N = tamanhos[t];
        int *base = malloc(N * sizeof(int));
        int *v = malloc(N * sizeof(int));
        if (!base || !v) {
            printf("Erro de alocacao de memoria.\n");
            fclose(fp);
            return 1;
        }

        // gerar vetor aleatório
        for (int i = 0; i < N; i++)
            base[i] = rand() % 10000;

        copia(v, base, N);
        bubble_sort(v, N, &m_bubble);

        // escrever no CSV
        fprintf(fp, "Bubble,%d,%lld,%lld,%lld,%.3f\n", N,
                m_bubble.passos, m_bubble.comparacoes, m_bubble.trocas, m_bubble.tempo_ms);

        free(base);
        free(v);
    }

    fclose(fp);
    printf("\nBenchmark concluido! Resultados salvos em resultados.csv\n");

    return 0;
}

