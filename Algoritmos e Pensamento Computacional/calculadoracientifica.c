#include <stdio.h>//biblioteca para entrada e saída de dados
#include <math.h>//biblioteca matemática para funções como sqrt, pow, sin, cos, tan, log, exp
#define USE_MATH_DEFINES
#define M_PI 3.14159265358979323846//definindo o valor de PI

//declaraçao de variaveis
int main() {
    double numero1, numero2, resultado;//variavel para numeros double(inteiros ou reais)
    int op; //variavel para menu
    char continuar;//variavel para continuar ou sair da calculadora ao final de uma operaçao

    do{ //uso do "do" para o loop da calculadora
        printf("\n\n-- bem vindos a calculadora cientifica! --\n\n");
        printf("\n-- 31 operacoes --\n");
        printf("\ndigite um numero para a operacao desejada:\n");
        //menu de operacoes basicas
        printf("\n\n operacoes basicas\n\n");
        printf("1 - adicao\n2 - subtracao\n3 - multiplicacao\n4 - divisao\n5 - potenciacao\n6 - raiz quadrada\n");
        //menu de funçoes trigonometricas
        printf("\n\n funcoes trigonometricas\n\n");
        printf("7 - seno\n8 - cosseno\n9 - tangente\n");
        //menu de logaritmos e exponenciais
        printf("\n logaritmos e exponenciais \n");
        printf("10 - log na base 10\n11 - logaritmo neperiano (ln)\n12 - exponencial (e^x)\n");
        //menu de conversoes
        printf("\n\nconversoes\n\n");
        printf("15 - minutos para horas\n16 - horas para minutos\n");
        printf("17 - km para metros\n18 - metros para km\n");
        printf("19 - graus para radianos\n20 - radianos para graus\n");
        printf("21 - celsius para fahrenheit\n22 - fahrenheit para celsius\n");
        printf("23 - celsius para kelvin \n24 - kelvin para celsius\n");
        printf("25 - fahrenheit para kelvin\n26 - kelvin para fahrenheit\n");
        //menu para percentuais
        printf("\n\n percentuais\n\n");
        printf("28 - percentual de um numero\n29 - aumento percentual\n30 - desconto percentual\n");
        //menu para calculos diversos e saida da calculadora
        printf("\n\n calculos diversos\n\n");
        printf("13 - calculo do imc\n14 - area do circulo\n27 - area do quadrado\n31 - media aritmetica (5 numeros)\n");
        printf("32 - sair\n");
        scanf("%d", &op);
        
        //sai do loop se a opcao for 32
        if(op == 32) {
            break;
        }
    //switch para tratar cada operaçao
    switch (op) {
    
    //case 1: adiçao de 2 numeros usando array
        case 1: {
        double numeros[2]; 
        double resultado = 0.0;
    //lendo os numeros e somando
        for(int i = 0; i < 2; i++) {
            printf("Digite o %d numero:\n", i+1);
            scanf("%lf", &numeros[i]);
            resultado += numeros[i];  
    }

            printf("resultado: %.2lf\n", resultado);
            break;
}   //case 2: subtraçao
        case 2: {
            printf("digite o primeiro numero:\n");
            scanf("%lf", &numero1);
            printf("digite o segundo numero:\n");
            scanf("%lf", &numero2);
            resultado = numero1 - numero2;
            printf("resultado: %g\n", resultado);
            break;
        }
    //case 3: multiplicaçao    
        case 3: {
            printf("digite o primeiro numero:\n");
            scanf("%lf", &numero1);
            printf("digite o segundo numero:\n");
            scanf("%lf", &numero2);
            resultado = numero1 * numero2;
            printf("resultado: %g\n", resultado);
            break;
        }
    //case 4: divisao
        case 4: {
            printf("digite o primeiro numero:\n");
            scanf("%lf", &numero1);
            printf("digite o segundo numero:\n");
            scanf("%lf", &numero2);
            if (numero2 == 0) {
                printf("erro: divisao por 0\n");
            } else {
                resultado = numero1 / numero2;
                printf("resultado: %g\n", resultado);
            }
            break;
        }
    //case 5: potenciaçao
        case 5: {
            printf("digite o primeiro numero:\n");
            scanf("%lf", &numero1);
            printf("digite o segundo numero:\n");
            scanf("%lf", &numero2);
            resultado = pow(numero1, numero2);
            printf("%.2lf elevado a %.2lf = %.2lf\n", numero1, numero2, resultado);
            break;
        }
    //case 6: raiz quadrada
        case 6: {
            printf("digite o numero:\n");
            scanf("%lf", &numero1);
            if(numero1 >= 0) {
                resultado = sqrt(numero1);
                printf("resultado: %.2lf\n", resultado);
            } else {
                printf("erro: raiz de numero negativo!\n");
            }
            break;
        }
    //case 7: seno
        case 7: {
            printf("digite o angulo em graus:\n");
            scanf("%lf", &numero1);
            resultado = sin(numero1 * M_PI / 180);
            printf("o seno e: %.2lf\n", resultado);
            break;
        }
    //case 8: cosseno
        case 8: {
            printf("digite o angulo em graus:\n");
            scanf("%lf", &numero1);
            resultado = cos(numero1 * M_PI / 180);
            printf("o cosseno e: %.2lf\n", resultado);
            break;
        }
    //case 9: tangente
        case 9: {
            printf("digite o angulo em graus:\n");
            scanf("%lf", &numero1);
            resultado = tan(numero1 * M_PI / 180);
            printf("a tangente e: %.2lf\n", resultado);
            break;
        }
    //case 10: log de base 10
        case 10: {
            printf("digite o numero:\n");
            scanf("%lf", &numero1);
            if(numero1 > 0) {
                resultado = log10(numero1);
                printf("o log de base 10 e: %.2lf\n", resultado);
            } else {
                printf("erro: logaritmo inexistente - numero nao positivo!\n");
            }
            break;
        }
    //case 11: logaritmo neperiano(ln)
        case 11: {
            printf("digite o numero:\n");
            scanf("%lf", &numero1);
            if(numero1 > 0) {
                resultado = log(numero1);
                printf("o log e: %.2lf\n", resultado);
            } else {
                printf("erro: logaritmo inexistente - numero nao positivo!\n");
            }
            break;
        }
    //case 12: exponecial
        case 12: {
            printf("digite o expoente x para e^x:\n");
            scanf("%lf", &numero1);
            resultado = exp(numero1);
            printf("resultado: %.2lf\n", resultado);
            break;
        }
    //case 13: calculo do imc 
        case 13: {
            printf("digite o peso (em kg):\n");
            scanf("%lf", &numero1);
            printf("digite a altura (em metros):\n");
            scanf("%lf", &numero2);
            if(numero2 > 0){
                resultado = numero1 / (numero2 * numero2);
                printf("seu imc e %.2lf\n", resultado);
            } else {
                printf("erro: numero invalido!\n");
            }
            break;
        }
    //case 14: area do circulo
        case 14: {
            printf("digite o raio do circulo:\n");
            scanf("%lf", &numero1);
            if(numero1 >= 0){
                resultado = M_PI * numero1 * numero1;
                printf("a area do circulo com raio %.2lf e: %.2lf\n", numero1, resultado);
            } else {
                printf("erro: numero invalido!\n");
            }    
            break;
        }
    //cases 15-26: conversoes de tempo, distancia, angulo e temperatura
        case 15: {
            printf("digite o numero em minutos:\n");
            scanf("%lf", &numero1);
            if(numero1 >= 0){
                resultado = numero1 / 60;
                printf("%.2lf minutos sao equivalentes a %.2lf horas\n", numero1, resultado);
            }  else {
                printf("erro: numero invalido!\n");
            }   
            break;
        }
        case 16: {
            printf("digite o numero em horas:\n");
            scanf("%lf", &numero1);
            if(numero1 >= 0){
                resultado = numero1 * 60;
                printf("%.2lf horas sao equivalentes a %.2lf minutos\n", numero1, resultado);
            } else {
                printf("erro: numero invalido!\n");
            }
            break;
        }
        case 17: {
            printf("digite o numero em km:\n");
            scanf("%lf", &numero1);
            if(numero1 >= 0){
                resultado = numero1 * 1000;
                printf("%.2lf km sao %.2lf metros\n", numero1, resultado);
            } else {
                printf("erro: numero invalido!\n");
            }
            break;
        }
        case 18: {
            printf("digite o numero em metros:\n");
            scanf("%lf", &numero1);
            if(numero1 >= 0){
                resultado = numero1 / 1000;
                printf("%.2lf metros sao %.2lf km\n", numero1, resultado);
            } else {
                printf("erro: numero invalido!\n"); 
            }
            break;
        }
        case 19: {
            printf("digite o numero em graus:\n");
            scanf("%lf", &numero1);
            resultado = numero1 * (M_PI / 180);
            printf("%.2lf graus sao %.2lf rad\n", numero1, resultado);
            break;
        }
        case 20: {
            printf("digite o numero em radianos:\n");
            scanf("%lf", &numero1);
            resultado = numero1 * (180 / M_PI);
            printf("%.2lf rad sao %.2lf graus\n", numero1, resultado);
            break;
        }
        case 21: {
            printf("digite o numero em celsius\n");
            scanf("%lf", &numero1);
            resultado = (numero1 * 1.8) + 32;
            printf("%.2lf celsius sao %.2lf fahrenheit\n", numero1, resultado);
            break;
        }
        case 22: {
            printf("digite o numero em fahrenheit\n");
            scanf("%lf", &numero1);
            resultado = (numero1 - 32) * (1.0 / 1.8);
            printf("%.2lf fahrenheit sao %.2lf celsius\n", numero1, resultado);
            break;
        }
        case 23: {
            printf("digite o numero em celsius\n");
            scanf("%lf", &numero1);
            resultado = numero1 + 273;
            printf("%.2lf celsius sao %.2lf kelvin\n", numero1, resultado);
            break;
        }
        case 24: {
            printf("digite o numero em kelvin\n");
            scanf("%lf", &numero1);
            resultado = numero1 - 273;
            printf("%.2lf kelvin sao %.2lf celsius\n", numero1, resultado);
            break;
        }
        case 25: {
            printf("digite o numero em fahrenheit\n");
            scanf("%lf", &numero1);
            resultado = (numero1 - 32) * 5 / 9 + 273;
            printf("%.2lf fahrenheit sao %.2lf kelvin\n", numero1, resultado);
            break;
        }
        case 26: {
            printf("digite o numero em kelvin\n");
            scanf("%lf", &numero1);
            resultado = (numero1 - 273) * 1.8 + 32;
            printf("%.2lf kelvin sao %.2lf fahrenheit\n", numero1, resultado);
            break;
        }
    //case 27: area do quadrado
        case 27: {
            printf("digite o numero em cm ou m:\n");
            scanf("%lf", &numero1);
            if(numero1 >= 0){
                resultado = numero1 * numero1;
                printf("a area do quadrado de lado %.2lf e %.2lf\n", numero1, resultado);
            } else {
                printf("erro: numero invalido!\n");
            }
            break;
        }
    //case 28: percentual de um numero
        case 28: {
            printf("digite o primeiro numero:\n");
            scanf("%lf", &numero1);
            printf("digite o segundo numero:\n");
            scanf("%lf", &numero2);
            resultado = (numero1 * numero2) / 100;
            printf("o percentual de %.2lf de %.2lf e: %.2lf\n", numero1, numero2, resultado);
            break;
        }
    //case 29: acrescimo de percentual em determinado numero
        case 29: {
            printf("digite o primeiro numero:\n");
            scanf("%lf", &numero1);
            printf("digite o segundo numero (percentual):\n");
            scanf("%lf", &numero2);
            resultado = numero1 + (numero1 * numero2 / 100);
            printf("o aumento de %.2lf por %.2lf%% e: %.2lf\n", numero1, numero2, resultado);
            break;
        }
    //case 30: desconto de percentual de determinado numero
        case 30: {
            printf("digite o primeiro numero:\n");
            scanf("%lf", &numero1);
            printf("digite o segundo numero (percentual):\n");
            scanf("%lf", &numero2);
            resultado = numero1 - (numero1 * numero2 / 100);
            printf("o desconto de %.2lf por %.2lf%% e: %.2lf\n", numero1, numero2, resultado);
            break;
        }
    //case 31: media aritmetica utilizando array
        case 31: {
            int i;
            double numeros[5], soma = 0.0;

            for(i = 0; i < 5; i++) {
                printf("Digite o %d numero:\n", i+1);
                scanf("%lf", &numeros[i]);
                soma += numeros[i];  
            }
            resultado = soma / 5.0;
            
            printf("A media aritmetica entre ");
            for(i = 0; i < 5; i++) {
                printf("%.2lf", numeros[i]);
            if(i < 4) printf(", ");
            }
            printf(" e: %.2lf\n", resultado);
            break;
        }
    //default caso o usuario digite alguma opçao de operaçao inexistente
        default:
            printf("o numero escolhido e invalido.\ntente novamente!\n");
            break;
    }
    //pergunta se o usuario quer realizar outra operaçao ou nao 
    printf("\ndeseja realizar outra operacao? (sim = s / nao = n):\n ");
    scanf(" %c", &continuar);
  
    } while(continuar == 's'|| continuar == 'S');
    printf("\n-- finalizando calculadora! --\n");
    
    return 0;
}
