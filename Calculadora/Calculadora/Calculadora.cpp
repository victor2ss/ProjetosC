#include <stdio.h>

int main()
{
    // Declaração de variáveis para armazenar os números e o resultado
    float num1, num2, resultado;

    // Variável para armazenar o operador escolhido pelo usuário
    int operador;

    // Solicitando ao usuário que digite o primeiro número
    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    // Solicitando ao usuário que digite o segundo número
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    // Apresentando as opções de operação ao usuário
    printf("Selecione o operador:\n");
    printf("1 - Adicao\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");

    // Lendo o operador escolhido pelo usuário
    scanf("%d", &operador);

    switch (operador)
    {
        // Estrutura switch para realizar a operação matemática de acordo com o operador escolhido
        switch (operador) {
    case 1:
        resultado= num1 + num2;
        printf("Resultado: %.2f\n", resultado); // Exibindo o resultado com duas casas decimais
        break;
        break;

    case 2:
        resultado= num1 - num2;
        printf("Resultado: %.2f\n", resultado);
        break;

    case 3:
        resultado= num1 * num2;
        printf("Resultado: %.2f\n", resultado);
        break;

    case 4:
        if (num2!=0) // Verificando se o divisor é diferente de zero
        {
            resultado = num1 / num2;
            printf("Resultado: %.2f\n", resultado);
        }
        else
        {
            printf("Divisao por zero nao e permitido.\n"); 
        }
        break;

    default:// Operador inválido
        printf("Operador invalido. \n");
        break;

    }
    return 0;
}

