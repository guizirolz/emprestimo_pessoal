#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define juros 2
#define max_prestacoes 48
#define min_prestacoes 1
#define valor_min 500 
#define max_emprestimo 10

int programa = 1;


typedef struct CLIENTE {
	
	char nome;
	int cpf;
	float salario;
	float valor_emprestimo;
	float total_pagar;
	int prestacoes;
	char email;
	int telefone;
	float valor_parcela;
	
}CLIENTE;

CLIENTE cliente;



	
void mostrar_menu()
{

	printf("A empresa CréditoParaTodxs é uma empresa multinacional que ajuda milhões de pessoas a conseguirem crédito pessoal.\n");
	printf("O crédito pessoal CréditoParaTodXs é uma forma fácil e rápida de conseguir um empréstimo pessoal.\n");
	printf("Aqui você encontra as melhores taxas. Juros de apenas 2%% a.m.\n");
	printf("Gostaria de visualizar suas opçoes de crédito pessoal? Basta informar seu nome, CPF, salário, e-mail e telefone.\n\n");
	printf("[1] Sim      [2] Não - Fechar simulador\n\n");
		
}


void dados_cliente()
{
	system("cls");
	printf("Digite seu nome: ");
	scanf("%s", &cliente.nome);
	
	printf("Digite seu CPF: ");
	scanf("%d", &cliente.cpf);
	
	printf("Digite seu salário: ");
	scanf("%f", &cliente.salario);	
	
	printf("Digite seu e-mail: ");
	scanf("%s", &cliente.email);	
	
	printf("Digite seu telefone: ");
	scanf("%d", &cliente.telefone);	
	
}

void selecionar_valor_credito()
{
	system("cls");
	printf("Quanto gostaria de empréstimo?\n");
	printf("Mínimo de  R$ 500,00 valor máximo de %.2f\n",cliente.salario * max_emprestimo);
	scanf("%f", &cliente.valor_emprestimo);
	if(cliente.valor_emprestimo < valor_min || cliente.valor_emprestimo > (cliente.salario * max_emprestimo))
	{
		system("cls");
		printf("Favor selecionar valor correspondente à propósta\n\n");
		system("pause");
		selecionar_valor_credito();
	}
		
}

void selecionar_prestacoes()
{
	system("cls");
	printf("Em quantas pacerlas gostaria de pagar?\n");
	printf("Mínima de %d e máximo de %d\n",min_prestacoes, max_prestacoes);
	scanf("%d", &cliente.prestacoes);
	if(cliente.prestacoes < min_prestacoes || cliente.prestacoes > max_prestacoes){
		system("cls");
		printf("Favor selecionar uma opção de parcelamento correspondente à propósta\n\n");
		system("pause");
		selecionar_prestacoes();
	}

}

void calcular_total()
{
	
	cliente.total_pagar = cliente.valor_emprestimo +  (cliente.valor_emprestimo * juros / 100 * cliente.prestacoes);
	cliente.valor_parcela = cliente.total_pagar / cliente.prestacoes;
	
}

void rever_info()
{
	int i;
	system("cls");
	printf("Nome: %c", cliente.nome);
	printf("\nCPF: %d", cliente.cpf);
	printf("\nE-mail: %c", cliente.email);
	printf("\nTelefone: %d", cliente.telefone);
	printf("\nSalário: R$ %.2f", cliente.salario);
	printf("\nValor empréstimo: R$ %.2f", cliente.valor_emprestimo);
	printf("\nQuantidade de parcelas: %d", cliente.prestacoes);
	printf("\nValor por parcela com juros de 2%% a.m.: R$  %.2f ", cliente.valor_parcela);
	printf("\nValor total a pagar: R$ %.2f \n\n", cliente.total_pagar);
	printf("Informações e valores estão de acordo?\n");
	printf("[1] Sim - Finalizar Contratação   [2] Não - Ajustar informações\n");
	scanf("%d", &i);
	if(i == 1){
		printf("Estamos felizes que você conseguiu um empréstimo pessoal sem problema algum!\n");
		printf("Aproveite seu crétido como preferir!");
		programa = 0;
	}
	else if (i == 2)
	{
		return;
	}else
	{
		printf("Opção inválida, verifique e tente novamente");
		rever_info();
	}

	
}

int main ()
{
	setlocale(LC_ALL, "Portuguese");
	
	
	
	int opcao_menu;
	while (programa == 1)
	{
		mostrar_menu();
		scanf("%d", &opcao_menu);
			
		if(opcao_menu == 1)
		{
			dados_cliente();
			selecionar_valor_credito();
			selecionar_prestacoes();
			calcular_total();
			rever_info();
				
		}
		else if(opcao_menu == 2)
		{
			system("cls");
			printf("Programa encerrado!\n\n");
			programa = 0;
			
		}
		else
		{
			system("cls");
			printf("Opção inválida, tente novamente.\n\n");
			system("pause");
			system("cls");
			
		}
	
		
	}
	
	
}
