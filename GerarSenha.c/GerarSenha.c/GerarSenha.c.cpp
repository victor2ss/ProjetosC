#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void gerarSenha(int comprimento, int incluirMaiusculas, int incluirMinusculas, int incluirNumeros, int incluirEspeciais) {
	const char caracteresMaiusculos[] = "ABCDEFGHIJKLMNOPARSTUVWXYZ";
	const char caracteresMinusculos[] = "abcdefghijklmnopqrstuvwxyz";
	const char caracteresNumeros[] = "012345";
	const char caracteresEspeciais[] = "!@#$";

	char caracteresPermitidos[20] = "";

	if (incluirMaiusculas)
	{
		strcat(caracteresPermitidos, caracteresMaiusculos);
	}
	if (incluirMinusculas)
	{
		strcat(caracteresPermitidos, caracteresMinusculos);
	}
	if (incluirNumeros)
	{
		strcat(caracteresPermitidos, caracteresNumeros);
	}
	if (incluirEspeciais)
	{
		strcat(caracteresPermitidos, caracteresEspeciais);
	}

	srand(time(0));

	for (int i = 0; i < comprimento; i++)
	{
		int index = rand() % strlen(caracteresPermitidos);
		printf("%c", caracteresPermitidos[index]);
	}
	printf("\n");
}
	int main() {
		int comprimento, incluirMaiusculas, incluirMinusculas, incluirNumeros, incluirEspeciais;

		printf("Bem-vindo ao Gerador de senhas\n");

		printf("Digite o comprimento de senha:");
		scanf("%d", &comprimento);

		printf("Incluir letras maiusculas? (1 - sim / 0 - nao)");
		scanf("%d", &incluirMaiusculas);

		printf("Incluir letras minusculas? (1 - sim / 0 - nao)");
		scanf("%d", &incluirMinusculas);

		printf("Incluir numeros? (1 - sim / 0 - nao)");
		scanf("%d", &incluirNumeros);

		printf("Incluir caracteres especiais? (1 - sim / 0 - nao)");
		scanf("%d", &incluirEspeciais);

		gerarSenha(comprimento, incluirMaiusculas, incluirMinusculas, incluirNumeros, incluirEspeciais);
		return 0;
	}