//Bibliotecas necess�rias para elaborar o sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

//Estrutura para criar o relat�rio
struct venda{
	char *nome[20];
	int totalVenda;
	float valorPago;
}typedef venda;

//Esse procedimento pega data atual
void data(void){
	
	//uso de fun��o interna da linguagem e um ponteiro para compor a estrutura
	time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informa��es de data e hora
	horarioLocal = localtime( &timer ); // Converte a hora atual para a hora local
	//Fun��es internas para obtermos os valores de data e hora
	int dia = horarioLocal->tm_mday;
	int mes = horarioLocal->tm_mon + 1;
	int ano = horarioLocal->tm_year + 1900;
	int hora = horarioLocal->tm_hour;
	int min = horarioLocal->tm_min;
	int sec = horarioLocal->tm_sec;
	//Aqui iremos apresentar na tela do sistema a data e tamb�m a hora atual
	printf("\tHor�rio: %i:%i:%i\n", hora,min,sec);
	printf("\tData: %i/%i/%i\n" ,dia,mes,ano);
}


int main(void) {
	
	//Aqui chamamos a estrutura venda com o vetor definido como comissao
	venda comissao[50];
	
	//iniciando as vari�veis
	int i , p = 0;
	float valorProduto = 0;
	float pagamento = 0;
	int maiorVenda = 0;
	int menorVenda = 0;
	
	//Customiza��o de software
	system("color 4f");
	setlocale(LC_ALL,"Portuguese");
	SetConsoleTitle("Comissao dos Vendedores");
	printf("\n\tSistema de Pagamento de Comiss�o\n");
	data();
	printf("_________________________________________________________________
	__________________________________________________");
	
	//S�o 10 funcion�rios ent�o o loop percorrera 10 vezes
	for(i = 1; i <= 10; i++)
	{
		//Aqui pegamos os nomes dos vendedores
		printf("\n\n\n\tVendedor %d, entre com seu nome_____: ",i);
		//fazemos uma limpeza de mem�ria
		fflush(stdin);
		//Armazenamos os nomes no vetor
		gets(comissao[i].nome);
		//Aqui pegamos o total de produtos que vendemos no m�s
		printf("\n\tQuantos produtos voc� vendeu no m�s? ");
		//Lemos o total e armazenamos no vetor
		scanf("%d",&comissao[i].totalVenda);
			//O vendedor informa quantos produtos vendeu para assim calcular por cada produto sua comissao de 15%
			//Um if se faz necessario pois n�o se calcula comissao com valor zero ou negativo que significa que n�o vendeu
				if(comissao[i].totalVenda > 0)
				{
				//Aqui vai repetir a instru��o de pedir o valor do pro-
				duto e logo fara o calculo
				do{
				printf("\n\tEntre com o valor do produto vendido:
				");
				scanf("%f",&valorProduto);
				//O calculo da comissao vai armazenar no pagamamento e em seguida o vetor valorPago soma
				//o pagamento das vendas ja com a comissao
				pagamento = valorProduto*1.15;
				comissao[i].valorPago = comissao[i].valorPago + pagamento;
				//Aqui verificamos o valor de maiorVenda e recebe o
				vetor totalVenda
				if(maiorVenda == 0){
				maiorVenda = comissao[i].totalVenda;
				//Ent�o se o vetor for maior, significa que a venda
				foi maior que o maiorVenda
				}
				//Aqui verificamos o valor de menorVenda e recebe o
				vetor totalVenda
				if(menorVenda == 0){
				menorVenda = comissao[i].totalVenda;
				//Ent�o se o vetor for menor, significa que a venda
				foi menor que o menorVenda
				}
				//Fazemos as opera��es l�gicas para atribuirmos os
				valores gerais de venda para a maior venda
				if(comissao[i].totalVenda > maiorVenda)
				{
				maiorVenda = comissao[i].totalVenda;
				}
				//Fazemos as opera��es l�gicas para atribuirmos os
				valores gerais de venda para a menor venda
				if(comissao[i].totalVenda < menorVenda)
				{
				menorVenda = comissao[i].totalVenda;
				}
				p++;
				}while(p < comissao[i].totalVenda);
				//A variavel p ao ser incrementada dentro do loop precisa retornar a zero se n�o fica com valor antigo
				//e n�o cai na condi��o
				p = 0;
				}
				printf("_________________________________________________________________
				______________");
				}
				printf("\n\n");
				printf("_________________________________________________________________
				______________");
				//pequena anima��o do software
				sleep(4);
				system("cls");
				//Apresenta��o do relat�rio
				for(i = 1; i <= 10; i++)
				{
				//Aqui ja definimos os vendedores que mais venderam
				if(comissao[i].totalVenda == maiorVenda){
				printf("\n\tMaior Venda\n\n");
				printf("\n\tNome:________________ %s\n",comissao[i].nome);
				printf("\n\tTotal da venda:______ %d\n",comissao[i].totalVenda);
				printf("\n\tComiss�o da venda:___ %.2f\n\n",comissao[i].valorPago);
				}
				//Aqui ja definimos os vendedores que menos venderam
				if(comissao[i].totalVenda == menorVenda){
				printf("\n\tMenor Venda\n\n");
				printf("\n\tNome:________________ %s\n",comissao[i].nome);
				printf("\n\tTotal da venda:______ %d\n",comissao[i].totalVenda);
				printf("\n\tComiss�o da venda:___ %.2f\n\n",comissao[i].valorPago);
			}
	}
	printf("\n\n");
	system("pause");
	return 0;
}
