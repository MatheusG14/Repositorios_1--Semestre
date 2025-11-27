#include <stdio.h> //biblioteca padrão de entrada/saída (printf, scanf, FILE, etc)

#include <math.h> //biblioteca matemática (sqrt, pow, sin, cos, tan, log, exp, etc)

#include <stdlib.h> //biblioteca padrão (exit, malloc, etc)

#include <string.h> //biblioteca de manipulação de strings (strlen, strcpy, strncpy)

//constante de PI
#define M_PI 3.14159265358979323846
#define MAX_HISTORICO 200
#define MAX_COLUNAS 10
#define MAX_LINHAS 10

//estrutura para armazenar dados
typedef struct
{
    char descricao[200];
    double operando1;
    double operando2;
    double resultado;
    int id;
} operacao;

// armazena todo o histórico
operacao historico[MAX_HISTORICO];
int total_historico = 0; //conta as operações armazenadas

void adicionarHistorico(const char *descricao)
{
    // verifica se ainda tem espaço no histórico
    if (total_historico < MAX_HISTORICO)
    {
        historico[total_historico].id = total_historico + 1;

        strncpy(historico[total_historico].descricao, descricao, sizeof(historico[total_historico].descricao) - 1);

        historico[total_historico].descricao[sizeof(historico[total_historico].descricao) - 1] = '\0';
        total_historico++;
    }
    else
    {
        printf("\nHistorico cheio!\nLibere o historico para continuar salvando operacoes.\n");
    }
}
//funcao para mostrar o historico
void mostrarHistorico()
{
    //caso nao tenha feito nenhuma operacao
    if (total_historico == 0)
    {
        printf("\nnenhuma operacao realizada ainda! realize alguma para poder mostrar aqui.\n");
        return;
    }
    //caso tenha sido feita sera mostrada as operacoes feitas e o id de cada uma operacao com os devidos resultados
    printf("\nhistorico das operacoes:\n");
    for (int i = 0; i < total_historico; i++)
    {
        printf("ID %d. %s\n", historico[i].id, historico[i].descricao);
    }
}

void limparHistorico()
{

    if (total_historico == 0)
    {
        printf("\nO historico esta vazio!\n");
        return;
    }

    total_historico = 0;
    printf("\nhistorico deletado!\n");
}

//limpa o buffer de entrada para evitar problemas com o scanf
void limparBufferdeEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void saida_calculadora()
{
    double operando1;

    printf("Digite 0 para finalizar a calculadora:\n");
    scanf("%lf", &operando1);

    if (operando1 == 0)
    {
        printf("\n-- finalizando calculadora! --\n");
        exit(0);
    }
    else
    {
        printf("Valor diferente de 0! Calculadora nao finalizada.\n");
    }
}

void lerMatrizes(double matriz[MAX_LINHAS][MAX_COLUNAS], int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Digite o valor da posicao [%d] [%d]:", i + 1, j + 1);
            scanf("%lf", &matriz[i][j]);
        }
    }
}

void mostrarMatrizes(double matriz[MAX_LINHAS][MAX_COLUNAS], int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%.2lf", matriz[i][j]);
        }
        printf("\n");
    }
}
//funcao de soma de matrizes
void somaMatrizes()
{
    int linhas, colunas;
    double A[MAX_LINHAS][MAX_COLUNAS], B[MAX_LINHAS][MAX_COLUNAS], resultado[MAX_LINHAS][MAX_COLUNAS];
    printf("Digite o numero de linhas(max %d)", MAX_LINHAS);
    scanf("%d", &linhas);
    printf("Digite o numero de colunas(max %d)", MAX_COLUNAS);
    scanf("%d", &colunas);

//se o numero de colunas e / ou linhas for menor ou igual a zero
    if (linhas <= 0 || colunas <= 0 || linhas > MAX_LINHAS || colunas > MAX_COLUNAS)
    {
        printf("Tamanho Invalido!\n");
        return;
    }

    printf("\nler matriz A\n");
    lerMatrizes(A, linhas, colunas);
    printf("\nler matriz B\n");
    lerMatrizes(B, linhas, colunas);

    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            resultado[i][j] = A[i][j] + B[i][j];

    printf("\n Resultado da Soma das Matrizes:\n");
    mostrarMatrizes(resultado, linhas, colunas);
    adicionarHistorico("Soma de Matrizes executada com sucesso!");
}

//funcao de multiplicacao de matrizes
void multiplicacaoMatrizes()
{
    int linhasA, colunasA,linhasB, colunasB;
    double A[MAX_LINHAS][MAX_COLUNAS], B[MAX_LINHAS][MAX_COLUNAS], resultado[MAX_LINHAS][MAX_COLUNAS];
    
    printf("Digite o numero de linhas A(max %d)", MAX_LINHAS);
    scanf("%d", &linhasA);
    printf("Digite o numero de colunas A (max %d)", MAX_COLUNAS);
    scanf("%d", &colunasA);
//se o numero de colunas e / ou linhas for menor ou igual a zero
    if (linhasA <= 0 || colunasA <= 0 || linhasA > MAX_LINHAS || colunasA > MAX_COLUNAS)
    {
        printf("Tamanho Invalido para Matriz A!\n");
        return;
    }


    printf("Digite o numero de linhas B (max %d)", MAX_LINHAS);
    scanf("%d", &linhasB);
    printf("Digite o numero de colunas B (max %d)", MAX_COLUNAS);
    scanf("%d", &colunasB);

    if (linhasB <= 0 || colunasB <= 0 || linhasB > MAX_LINHAS || colunasB > MAX_COLUNAS)
    {
        printf("Tamanho Invalido para Matriz B!\n");
        return;
    }
    
    if (colunasA != linhasB) {
        printf("Multiplicacao impossivel! O numero de colunas da matriz A deve ser igual ao numero de linhas da matriz B.\n");
        return;
    }


    printf("\nler matriz A\n");
    lerMatrizes(A, linhasA, colunasA);
    printf("\nler matriz B\n");
    lerMatrizes(B, linhasB, colunasB);

    for (int i = 0; i < linhasA; i++)
        for (int j = 0; j < colunasB; j++)
            resultado[i][j] = 0.0;
            
    for (int i = 0; i < linhasA; i++)
        for (int j = 0; j < colunasB; j++)
            for (int k = 0; k < colunasA; k++)
                resultado[i][j] += A[i][k] * B[k][j];


    printf("\n Resultado da Multiplicacao das Matrizes:\n");
    mostrarMatrizes(resultado, linhasA, colunasB);
    adicionarHistorico("Multiplicacao de Matrizes executada com sucesso!");
}

void soma()
{
    operacao op;
    int i;
    double numeros[2], soma = 0.0;
    for (i = 0; i < 2; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
        soma += numeros[i];
    }

    op.operando1 = numeros[0];
    op.operando2 = numeros[1];

    op.resultado = op.operando1 + op.operando2;
    printf("resultado:%.2lf\n", op.resultado);

    char texto[200];
    snprintf(texto, sizeof(texto), "Soma: %.2lf + %.2lf = %.2lf", op.operando1, op.operando2, op.resultado);
    adicionarHistorico(texto);
}

void subtracao()
{
    operacao op;
    int i;
    double numeros[2];
    for (i = 0; i < 2; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }

    op.operando1 = numeros[0];
    op.operando2 = numeros[1];

    op.resultado = op.operando1 - op.operando2;
    printf("resultado:%.2lf\n", op.resultado);

    char texto[200];
    snprintf(texto, sizeof(texto), "Subtracao: %.2lf - %.2lf = %.2lf", op.operando1, op.operando2, op.resultado);
    adicionarHistorico(texto);
}

void multiplicacao()
{
    operacao op;
    int i;
    double numeros[2];
    for (i = 0; i < 2; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }

    op.operando1 = numeros[0];
    op.operando2 = numeros[1];

    op.resultado = op.operando1 * op.operando2;
    printf("resultado:%.2lf\n", op.resultado);

    char texto[200];
    snprintf(texto, sizeof(texto), "multiplicacao: %.2lf * %.2lf = %.2lf", op.operando1, op.operando2, op.resultado);
    adicionarHistorico(texto);
}

void divisao()
{
    operacao op;
    int i;
    double numeros[2], divisao = 0.0;
    for (i = 0; i < 2; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.operando2 = numeros[1];

    //validacao para evitar divisao por zero
    if (op.operando2 == 0)
    {
        printf("\nErro: Divisao por zero!\n");
        return;
    }

    op.resultado = op.operando1 / op.operando2;
    printf("resultado:%.2lf\n", op.resultado);

    char texto[200];
    snprintf(texto, sizeof(texto), "divisao: %.2lf / %.2lf = %.2lf", op.operando1, op.operando2, op.resultado);
    adicionarHistorico(texto);
}

void potenciacao()
{
    operacao op;
    int i;
    double numeros[2];
    for (i = 0; i < 2; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }

    op.operando1 = numeros[0];
    op.operando2 = numeros[1];

    op.resultado = pow(op.operando1, op.operando2);
    printf("resultado:%.2lf\n", op.resultado);

    char texto[200];
    snprintf(texto, sizeof(texto), "Potenciacao: %.2lf ^ %.2lf = %.2lf", op.operando1, op.operando2, op.resultado);
    adicionarHistorico(texto);
}

void raiz_quadrada()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];

    //so permite operacao com numeros positivos
    if (op.operando1 <= 0)
    {
        printf("\nErro: raiz deve ser positiva!\n");
        return;
    }

    op.resultado = sqrt(op.operando1);
    printf("resultado:%.2lf\n", op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Raiz quadrada: √%.2lf = %.2lf", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void seno()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];

    op.resultado = sin(op.operando1 * M_PI / 180);
    printf("resultado:%.2lf\n", op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Seno(%.2lf°) = %.2lf", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void cosseno()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];

    op.resultado = cos(op.operando1 * M_PI / 180);
    printf("resultado:%.2lf\n", op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Cosseno(%.2lf°) = %.2lf", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void tangente()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];

    op.resultado = tan(op.operando1 * M_PI / 180);
    printf("resultado:%.2lf\n", op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Tangente(%.2lf°) = %.2lf", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void log_base10()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];

    if (op.operando1 < 0)
    {
        printf("\nerro: logaritmo inexistente! numero nao positivo!\n");
        return;
    }
    op.resultado = log10(op.operando1);
    printf("resultado:%.2lf\n", op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Log base 10 de %.2lf = %.2lf", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void logaritmo_neperiano()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];

    if (op.operando1 < 0)
    {
        printf("\nerro: logaritmo inexistente! numero nao positivo!\n");
        return;
    }
    op.resultado = log(op.operando1);
    printf("resultado:%.2lf\n", op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Log de %.2lf = %.2lf", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void exponencial()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];

    op.resultado = exp(op.operando1);
    printf("resultado:%.2lf\n", op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Exponencial: e^(%.2lf) = %.2lf", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void imc()
{
    operacao op;
    int i;
    double numeros[2];
    for (i = 0; i < 2; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.operando2 = numeros[1];

    // IMC = peso / altura²
    if (op.operando1 == 0 || op.operando2 == 0)
    {
        printf("erro: o peso e a altura devem ser positivos!\n");
        return;
    }

    // IMC = peso / altura²
    op.resultado = op.operando1 / (op.operando2 * op.operando2);
    printf("imc: %.2lf\n", op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "IMC: Peso = %.2lf kg, Altura = %.2lf m || IMC = %.2lf", op.operando1, op.operando2, op.resultado);
    adicionarHistorico(texto);
}

void raio_circulo()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }

    op.operando1 = numeros[0];
    if (op.operando1 < 0)
    {
        printf("erro: raio deve ser positivo!\n");
        return;
    }

    op.resultado = M_PI * op.operando1 * op.operando1;
    printf("a area do circulo com raio %.2lf e: %.2lf\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Area do circulo: raio = %.2lf || área = %.2lf", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void minutos_pra_horas()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    if (op.operando1 < 0)
    {
        printf("erro: os minutos devem ser numeros positivos!\n");
        return;
    }

    op.resultado = op.operando1 / 60;
    printf("%.2lf minutos sao equivalentes a %.2lf horas\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversao: %.2lf minutos = %.2lf horas", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void horas_pra_minutos()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    if (op.operando1 < 0)
    {
        printf("erro: as horas devem ser numeros positivos!\n");
        return;
    }

    op.resultado = op.operando1 * 60;
    printf("%.2lf horas sao equivalentes a %.2lf minutos\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversao: %.2lf horas = %.2lf minutos", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void km_em_metros()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    if (op.operando1 < 0)
    {
        printf("erro: os km devem ser numeros positivos!\n");
        return;
    }

    op.resultado = op.operando1 * 1000;
    printf("%.2lf km sao %.2lf metros\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversão: %.2lf Km = %.2lf Metros", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void metros_em_km()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    if (op.operando1 < 0)
    {
        printf("erro: os metros devem ser numeros positivos!\n");
        return;
    }

    op.resultado = op.operando1 / 1000;
    printf("%.2lf metros sao %.2lf km\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversão: %.2lf Metros = %.2lf Km", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void radianos_para_graus()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.resultado = op.operando1 * (180 / M_PI);
    printf("%.2lf radianos sao %.2lf graus\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversao: %.2lf Radianos = %.2lf Graus", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void graus_para_radianos()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.resultado = op.operando1 * (M_PI / 180);
    printf("%.2lf graus sao %.2lf radianos\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversao: %.2lf Graus = %.2lf Radianos", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void celsius_para_fahrenheit()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.resultado = (op.operando1 * 1.8) + 32;
    printf("%.2lf celsius sao %.2lf fahrenheit\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversão: %.2lf Celsius = %.2lf Fahrenheit", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void fahrenheit_para_celsius()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.resultado = (op.operando1 - 32) * (1.0 / 1.8);
    printf("%.2lf fahrenheit sao %.2lf celsius\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversão: %.2lf Fahrenheit = %.2lf Celsius", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void celsius_para_kelvin()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.resultado = op.operando1 + 273.15;
    printf("%.2lf celsius sao %.2lf kelvin\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversão: %.2lf Celsius = %.2lf Kelvin", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void kelvin_para_celsius()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.resultado = op.operando1 - 273;
    printf("%.2lf kelvin sao %.2lf celsius\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversão: %.2lf Kelvin = %.2lf Celsius", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void fahrenheit_para_kelvin()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.resultado = (op.operando1 - 32) * 5 / 9 + 273;
    printf("%.2lf fahrenheit sao %.2lf kelvin\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversão: %.2lf Fahrenheit = %.2lf Kelvin", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void kelvin_para_fahrenheit()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.resultado = (op.operando1 - 273) * 1.8 + 32;
    printf("%.2lf kelvin sao %.2lf fahrenheit\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Conversão: %.2lf Kelvin = %.2lf Fahrenheit", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void area_do_quadrado()
{
    operacao op;
    int i;
    double numeros[1];
    for (i = 0; i < 1; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    if (op.operando1 < 0)
    {
        printf("erro: as medidas devem ser numeros positivos!\n");
        return;
    }

    op.resultado = op.operando1 * op.operando1;
    printf("a area do quadrado de lado %.2lf e %.2lf\n", op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Área do quadrado: lado = %.2lf || área = %.2lf", op.operando1, op.resultado);
    adicionarHistorico(texto);
}

void percentual_de_um_numero()
{
    operacao op;
    int i;
    double numeros[2];
    for (i = 0; i < 2; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.operando2 = numeros[1];

    op.resultado = (op.operando1 * op.operando2) / 100;
    printf("o percentual de %.2lf de %.2lf e: %.2lf\n", op.operando1, op.operando2, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Percentual: %.2lf%% de %.2lf = %.2lf", op.operando1, op.operando2, op.resultado);
    adicionarHistorico(texto);
}

void aumento_percentual()
{
    operacao op;
    int i;
    double numeros[2];
    for (i = 0; i < 2; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.operando2 = numeros[1];

    if (op.operando1 < 0 || op.operando2 < 0)
    {
        printf("erro: os numeros devem ser positivos!\n");
        return;
    }

    op.resultado = op.operando1 + (op.operando1 * op.operando2 / 100);
    printf("O aumento de %.2lf%% sobre %.2lf é: %.2lf\n", op.operando2, op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Aumento percentual: %.2lf + %.2lf%% = %.2lf", op.operando1, op.operando2, op.resultado);
    adicionarHistorico(texto);
}

void desconto_percentual()
{
    operacao op;
    int i;
    double numeros[2];
    for (i = 0; i < 2; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
    }
    op.operando1 = numeros[0];
    op.operando2 = numeros[1];
    if (op.operando1 < 0 || op.operando2 < 0)
    {
        printf("erro: os numeros devem ser positivos!\n");
        return;
    }

    op.resultado = op.operando1 - (op.operando1 * op.operando2 / 100);
    printf("O desconto de %.2lf%% sobre %.2lf é: %.2lf\n", op.operando2, op.operando1, op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Desconto percentual: %.2lf - %.2lf%% = %.2lf", op.operando1, op.operando2, op.resultado);
    adicionarHistorico(texto);
}

void media_aritmetica()
{
    operacao op;
    int i;
    double numeros[5], soma = 0.0;
    for (i = 0; i < 5; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%lf", &numeros[i]);
        soma += numeros[i];
    }
    // média = soma de todos os números/quantidade
    op.resultado = soma / 5.0;
    printf("A media aritmetica entre ");
    for (i = 0; i < 5; i++)
    {
        printf("%.2lf", numeros[i]);
        if (i < 4)
            printf(", ");
    }
    printf(" e: %.2lf\n", op.resultado);
    char texto[200];
    snprintf(texto, sizeof(texto), "Media Aritmetica: [%.2lf, %.2lf, %.2lf, %.2lf, %.2lf] = %.2lf", numeros[0], numeros[1], numeros[2], numeros[3], numeros[4], op.resultado);
    adicionarHistorico(texto);
}

int main()
{
    int op;
    char continuar;

    //loop principal da calculadora
    do
    {
        // exibicao do menu interativo
        printf("\n\n-- Bem Vindos a Calculadora Cientifica! --\n\n");
        printf("\n-- 36 Funcoes --\n");

        printf("\n\n Operacoes Basicas\n\n");
        printf("1 - adicao\n2 - subtracao\n3 - multiplicacao\n4 - divisao\n5 - potenciacao\n6 - raiz quadrada\n");

        printf("\n\n Funcoes Trigonometricas\n\n");
        printf("7 - seno\n8 - cosseno\n9 - tangente\n");

        printf("\n Logaritmos e Exponenciais \n");
        printf("10 - log na base 10\n11 - logaritmo neperiano (ln)\n12 - exponencial (e^x)\n");

        printf("\n\n Conversoes \n\n");
        printf("15 - minutos para horas\n16 - horas para minutos\n");
        printf("17 - km para metros\n18 - metros para km\n");
        printf("19 - graus para radianos\n20 - radianos para graus\n");
        printf("21 - celsius para fahrenheit\n22 - fahrenheit para celsius\n");
        printf("23 - celsius para kelvin \n24 - kelvin para celsius\n");
        printf("25 - fahrenheit para kelvin\n26 - kelvin para fahrenheit\n");

        printf("\n\n Percentuais\n\n");
        printf("28 - percentual de um numero\n29 - aumento percentual\n30 - desconto percentual\n");

        printf("\n\n Calculos diversos\n\n");
        printf("13 - calculo do imc\n14 - area do circulo\n27 - area do quadrado\n31 - media aritmetica (5 numeros)\n");

        printf("\n\n Operacoes com Matrizes \n\n");
        printf("\n32-Soma de Matrizes\n");
        printf("\n33-Multiplicacao com Matrizes\n");

        printf("\n\nSaida da calculadora e Limpeza de Historico\n\n");
        printf("\n34-Mostrar o Historico\n");
        printf("35-Limpar Historico\n");
        printf("0 - sair\n");

        printf("\n\nDigite um numero para a operacao desejada:\n\n");
        scanf("%d", &op);

        //limpa buffer para evitar problemas com scanf
        limparBufferdeEntrada();

        //switch-case para chamar as funcoes
        switch (op)
        {

        case 0:
            saida_calculadora();
            break;

        case 1:
            soma();
            break;

        case 2:
            subtracao();
            break;

        case 3:
            multiplicacao();
            break;

        case 4:
            divisao();
            break;

        case 5:
            potenciacao();
            break;

        case 6:
            raiz_quadrada();
            break;

        case 7:
            seno();
            break;

        case 8:
            cosseno();
            break;

        case 9:
            tangente();
            break;

        case 10:
            log_base10();
            break;

        case 11:
            logaritmo_neperiano();
            break;

        case 12:
            exponencial();
            break;

        case 13:
            imc();
            break;

        case 14:
            raio_circulo();
            break;

        case 15:
            minutos_pra_horas();
            break;

        case 16:
            horas_pra_minutos();
            break;

        case 17:
            km_em_metros();
            break;

        case 18:
            metros_em_km();
            break;

        case 19:
            graus_para_radianos();
            break;

        case 20:
            radianos_para_graus();
            break;

        case 21:
            celsius_para_fahrenheit();
            break;

        case 22:
            fahrenheit_para_celsius();
            break;

        case 23:
            celsius_para_kelvin();
            break;

        case 24:
            kelvin_para_celsius();
            break;

        case 25:
            fahrenheit_para_kelvin();
            break;

        case 26:
            kelvin_para_fahrenheit();
            break;

        case 27:
            area_do_quadrado();
            break;

        case 28:
            percentual_de_um_numero();
            break;

        case 29:
            aumento_percentual();
            break;

        case 30:
            desconto_percentual();
            break;

        case 31:
            media_aritmetica();
            break;

        case 32:
            somaMatrizes();
            break;
            
        case 33:
            multiplicacaoMatrizes();
            break;

        case 34:
            mostrarHistorico();
            break;

        case 35:
            limparHistorico();
            break;
        //default para caso seja selecionado alguma operacao invalida
        default:
            printf("Opção invalida. Por favor, tente novamente.\n");
            break;
        }

        //pergunta se deseja continuar usando a calculadora
        printf("\nDeseja realizar outra operacao? (sim = s / nao = n): ");
        scanf(" %c", &continuar);
        
        //fim do loop
    } while (continuar == 's' || continuar == 'S');
    //mensagem de encerramento da calculadora
    printf("\n-- finalizando calculadora! --\n");

    return 0;
}
