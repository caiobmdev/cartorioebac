#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // bilbioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das string


int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coleta informa�oes do usuario
	scanf("%s", cpf); // %s referece a string
	
	strcpy(arquivo, cpf);  //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");	
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");  //Definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf ("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa�oes do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");
		
	}
}



int main()
{
	int opcao=0;  //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	setlocale(LC_ALL, "portuguese");  //Definindo a linguagem 
	
	printf("...... CART�RIO EBAC ......\n\n");   //inicio do menu
	printf(" escolha a op��o desejada do menu:\n\n");
	printf("\t 1-Registrar nomes\n");
	printf("\t 2-consultar nomes\n");
	printf("\t 3-deletar nomes\n\n");
	printf("\t 4-sair do sistema\n\n");
	printf("Op��o desejada: ");   //fim do menu
	
	scanf("%d", &opcao);  //armazenando a escolha do usuario
	
	system("cls"); //resposavel por limpar a tela
	
	switch(opcao) //inicio da sele��o do menu
	{
		case 1:
		registro(); //chamada de fun��es
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:	
		deletar();
		break;
		
		case 4:
		printf("obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("Esta op��o n�o est� dispon�vel!\n");
		system("pause");
		break;
		
		//fim da sele��o
    }
	
	
	
	


	}
}
