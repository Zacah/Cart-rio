#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de alocac�es de texto por regi�o
#include <string.h>//Biblioteca respons�vel por cuidar das strings

int registrar()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores das string
	
	FILE *file;//cria arquivo
	file = fopen(arquivo,"w");
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"  Nome completo: ");//Aparecer� antes do Nome
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");//espa�o entre nome e sobre nome
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"  Cargo:  ");//aparecera antes do cargo do usuario
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n\n");
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale (LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF de usuario n�o encontrado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio:  ");
		printf("%s",conteudo);
		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuario n�o encontrado no sitema!\n");
		system("pause");
	}
	
	else
	{
		printf("Usuario foi deletado!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;//definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale (LC_ALL, "Portuguese");//definindo a linguagem
	
		printf("======Cart�rio EBAC=======\n\n");//inicio do menu
		printf("escolha a op��o desejada do menu:\n\n");
		printf("\t1 - registrar nome\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n");
		printf("\t4 - Sair do sistema\n");
		printf("op��o:  ");//fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao)//escolha do usuario
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
		
			default:
			printf("essa op��o n�o esta disponivel\n");
			system("pause");
			
				
				
		}
	
	
	}


}
