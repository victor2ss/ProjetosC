

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados de um cliente
struct Cliente
{
	char nome[20]; // Nome do cliente (máximo 20 caracteres)
	char email[20]; // Email do cliente (máximo 20 caracteres)
};

int main() {

	// Array para armazenar até 20 clientes
	struct Cliente clientes[20];
	int opcao, numClientes = 0;

	// Loop principal do programa, que se repete até a opção 5 ser selecionada
	do {
		printf("Selecione uma opcao: \n");
		printf("1 - Adicionar cliente\n");
		printf("2 - Visualizar cliente\n");
		printf("3 - Editar cliente\n");
		printf("4 - Excluir cliente\n");
		printf("5 - Sair\n");

		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1: {
			// Verificando se há espaço para mais um cliente
			if (numClientes < 20) {
				// Solicitando o nome do cliente
				printf("Digite o nome do cliente:\n");
				scanf("%s", clientes[numClientes].nome);

				// Solicitando o email do cliente
				printf("Digite o email do cliente:\n");
				scanf("%s", clientes[numClientes].email);

				// Incrementando o contador de clientes
				numClientes++;

				// Mensagem de sucesso
				printf("Cliente adicionado com sucesso.\n");
			}
			else {
				// Mensagem de erro caso o limite de clientes seja atingido
				printf("Limite de clientes atingido. Impossível adicionar mais clientes.\n");
			}
			break;
		}

		case 2: {
			// Verificando se há pelo menos um cliente cadastrado
			if (numClientes > 0) {
				// Título da lista de clientes
				printf("Clientes cadastrados\n");

				// Imprimindo os dados de cada cliente cadastrado
				for (int i = 0; i < numClientes; i++) {
					printf("Nome: %s\n", clientes[i].nome);
					printf("Email: %s\n", clientes[i].email);
					printf("--------------------\n");
				}
			}
			else {
				// Mensagem caso não haja clientes cadastrados
				printf("Nenhum cliente cadastrado.\n");
			}
			break;
		}
		case 3: {

			// Variável para armazenar o nome do cliente a ser editado
			char nome[20];
			printf("Digite o nome do cliente que deseja editar: \n");
			scanf("%s", nome);

			// Buscando o cliente na lista
			for (int i = 0; i < numClientes; i++)
			{
				// Comparando o nome digitado com o nome de cada cliente
				if (strcmp(clientes[i].nome, nome) == 0) {
					printf("Digite o novo nome do cliente:");
					scanf("%s", clientes[i].nome);

					printf("Digite o novo email do cliente:");
					scanf("%s", clientes[i].email);

					printf("Cliente editado com sucesso\n");
					break; 
				}
			}
			break;
		}
		case 4: {
			char nome[20];

			printf("Digite o nome cliente que deseja excluir:");
			scanf("%s", nome);

			for (int i = 0; i < numClientes; i++)
			{
				if (strcmp(clientes[i].nome, nome) == 0) {
					for (int j = i; j < numClientes - 1; j++)
					{
						clientes[j] = clientes[j + 1];
					}

					numClientes--;
					printf("Cliente excluido do cadastro");

					break;
				}
			}
			break;
		}
		case 5: {
			printf("Encerrando o programa...\n");
			break;
		}

		}
	} while (opcao != 5);

	return 0;
}