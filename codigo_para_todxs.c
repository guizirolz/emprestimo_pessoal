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

	printf("A empresa Cr�ditoParaTodxs � uma empresa multinacional que ajuda milh�es de pessoas a conseguirem cr�dito pessoal.\n");
	printf("O cr�dito pessoal Cr�ditoParaTodXs � uma forma f�cil e r�pida de conseguir um empr�stimo pessoal.\n");
	printf("Aqui voc� encontra as melhores taxas. Juros de apenas 2%% a.m.\n");
	printf("Gostaria de visualizar suas op�oes de cr�dito pessoal? Basta informar seu nome, CPF, sal�rio, e-mail e telefone.\n\n");
	printf("[1] Sim      [2] N�o - Fechar simulador\n\n");
		
}


void dados_cliente()
{
	system("cls");
	printf("Digite seu nome: ");
	scanf("%s", &cliente.nome);
	
	printf("Digite seu CPF: ");
	scanf("%d", &cliente.cpf);
	
	printf("Digite seu sal�rio: ");
	scanf("%f", &cliente.salario);	
	
	printf("Digite seu e-mail: ");
	scanf("%s", &cliente.email);	
	
	printf("Digite seu telefone: ");
	scanf("%d", &cliente.telefone);	
	
}

void selecionar_valor_credito()
{
	system("cls");
	printf("Quanto gostaria de empr�stimo?\n");
	printf("M�nimo de  R$ 500,00 valor m�ximo de %.2f\n",cliente.salario * max_emprestimo);
	scanf("%f", &cliente.valor_emprestimo);
	if(cliente.valor_emprestimo < valor_min || cliente.valor_emprestimo > (cliente.salario * max_emprestimo))
	{
		system("cls");
		printf("Favor selecionar valor correspondente � prop�sta\n\n");
		system("pause");
		selecionar_valor_credito();
	}
		
}

void selecionar_prestacoes()
{
	system("cls");
	printf("Em quantas pacerlas gostaria de pagar?\n");
	printf("M�nima de %d e m�ximo de %d\n",min_prestacoes, max_prestacoes);
	scanf("%d", &cliente.prestacoes);
	if(cliente.prestacoes < min_prestacoes || cliente.prestacoes > max_prestacoes){
		system("cls");
		printf("Favor selecionar uma op��o de parcelamento correspondente � prop�sta\n\n");
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
	printf("\nSal�rio: R$ %.2f", cliente.salario);
	printf("\nValor empr�stimo: R$ %.2f", cliente.valor_emprestimo);
	printf("\nQuantidade de parcelas: %d", cliente.prestacoes);
	printf("\nValor por parcela com juros de 2%% a.m.: R$  %.2f ", cliente.valor_parcela);
	printf("\nValor total a pagar: R$ %.2f \n\n", cliente.total_pagar);
	printf("Informa��es e valores est�o de acordo?\n");
	printf("[1] Sim - Finalizar Contrata��o   [2] N�o - Ajustar informa��es\n");
	scanf("%d", &i);
	if(i == 1){
		printf("Estamos felizes que voc� conseguiu um empr�stimo pessoal sem problema algum!\n");
		printf("Aproveite seu cr�tido como preferir!");
		programa = 0;
	}
	else if (i == 2)
	{
		return;
	}else
	{
		printf("Op��o inv�lida, verifique e tente novamente");
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
			printf("Op��o inv�lida, tente novamente.\n\n");
			system("pause");
			system("cls");
			
		}
	
		
	}
	
	
}
