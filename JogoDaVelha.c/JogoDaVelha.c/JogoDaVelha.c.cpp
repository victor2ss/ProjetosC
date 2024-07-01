#include <stdio.h>


char tabuleiro[3][3] = {
	{'-', '-', '-'},
	{'-', '-', '-'},
	{'-', '-', '-'}
};

char jogadorAtual = 'X';
int jogoAcabou = 0;

// Função para iniciar o tabuleiro
void iniciadorTabulerio() {
	// Definindo o caractere 'X' na posição central (linha 1, coluna 1)
	tabuleiro[0][0] = 'X';
	// Preenchendo o restante do tabuleiro com '-'
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) {
				continue; // Pule a posição central já preenchida
			}
			tabuleiro[i][j] = '-';
		}
	}
}

void exibirTabuleiro() {
	printf("   |   |   \n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf(" %c |", tabuleiro[i][j]);
		}
		printf("\n   |   |   \n");
	}
}
/*void exibirTabuleiro() {
	printf("-----\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c", tabuleiro[i][j]);
		}
	}printf("\n");

	printf("-----\n");
}*/

// Função para fazer uma jogada
void fazerJogada() {
	int linha, coluna;

	// Solicitando a linha e coluna da jogada ao jogador atual
	printf("Jogador %c, faça sua jogada: \n", jogadorAtual);
	printf("Digite a linha (0, 1 ou 2): ");
	scanf("%d", &linha);
	printf("Digite a coluna (0, 1 ou 2): ");
	scanf("%d", &coluna);

	// Validando se a linha e coluna digitadas são válidas
	if (tabuleiro[linha][coluna] == '-')
	{
		tabuleiro[linha][coluna] = jogadorAtual;
	}
	else {
		printf("Essa posicao ja esta ocupada, tente outra\n");
		fazerJogada();
	}
}

// Função para verificar se há um vencedor
int verificarVencedor() {
	for (int i = 0; i < 3; i++) {
		if (tabuleiro[i][0] == jogadorAtual && tabuleiro[i][1] == jogadorAtual && tabuleiro[i][2] == jogadorAtual) //Verificar Linhas
		{
			return 1;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (tabuleiro[0][i] == jogadorAtual && tabuleiro[1][i] == jogadorAtual && tabuleiro[2][i] == jogadorAtual) //Verificar Colunas
		{
			return 1;
		}

		// Verificando as diagonais
		if ((tabuleiro[0][0] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][2] == jogadorAtual) || (tabuleiro[0][2] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][0] == jogadorAtual))
		{
			return 1;
		}
		return 0;
	}
}
// Função para verificar se há empate
	int verificarEmpate() {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (tabuleiro[i][j] = '-') {
					return 0;
				}
			}
		}
		return 1;
	}


	void alternarJogador(){
		jogadorAtual = (jogadorAtual == 'X') ? '0' : 'X';
	}

	int main() {
		iniciadorTabulerio();

		while (!jogoAcabou)
		{
			exibirTabuleiro();
			fazerJogada();

			if (verificarVencedor())
			{
				exibirTabuleiro();
				printf("Jogador %c venceu!\n", jogadorAtual);
				jogoAcabou = 1;
			}
			else if (verificarEmpate())
			{
				exibirTabuleiro();
				printf("O jogo empatou.\n");
				jogoAcabou = 1;
			}
			alternarJogador();
		}
		return 0;
	}

