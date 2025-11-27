#include <stdio.h>
#include <stdlib.h>

struct Estudante {
    char nome[50];
    int matricula;
    float notaMedia;
};

int main() {
    struct Estudante estudante;
    char continuar;
    float *notas;
    float media;
    int n;

    do {
        printf("\n\n----- Bem-Vindo ao Sistema de Gerenciamento de Alunos -----\n\n");

        printf("Digite o nome do estudante: ");
        scanf("%49s", estudante.nome);

        printf("Digite a matricula do aluno: ");
        scanf("%d", &estudante.matricula);

        printf("Digite o numero de notas que deseja inserir: ");
        scanf("%d", &n);

        if (n <= 0) {
            printf("Numero invalido!\n");
            return 0;
        }

       
        notas = (float*) malloc(n * sizeof(float));
        if (notas == NULL) {
            printf("Erro ao alocar memoria!\n");
            return 1;
        }

        media = 0;  

        printf("Serão inseridas %d notas:\n", n);
        for (int i = 0; i < n; i++) {
            printf("Digite a %d nota: ", i + 1);
            scanf("%f", &notas[i]);
            media += notas[i];
        }

        estudante.notaMedia = media / n;

        printf("\n Resultado do Estudante \n");
        printf("Nome: %s\n", estudante.nome);
        printf("Matrícula: %d\n", estudante.matricula);
        printf("Média: %.2f\n", estudante.notaMedia);

        if (estudante.notaMedia >= 6) {
            printf("Estudante aprovado!\n");
        } else {
            printf("Estudante reprovado!\n");
        }

        free(notas); 

        printf("\nDeseja cadastrar outro estudante? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("\nSistema de Gerenciamento de Alunos Encerrado.\nObrigado por usar!\n");

    return 0;
}


