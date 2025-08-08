#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memoria
#include <locale.h> // bilbioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel por cuidar das string


int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coleta informaçoes do usuario
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informaçoes do usuário: ");
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
		printf("O usuario não se encontra no sistema!.\n");
		system("pause");
		
	}
}



int main()
{
	int opcao=0;  //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	setlocale(LC_ALL, "portuguese");  //Definindo a linguagem 
	
	printf("...... CARTÓRIO EBAC ......\n\n");   //inicio do menu
	printf(" escolha a opção desejada do menu:\n\n");
	printf("\t 1-Registrar nomes\n");
	printf("\t 2-consultar nomes\n");
	printf("\t 3-deletar nomes\n\n");
	printf("\t 4-sair do sistema\n\n");
	printf("Opção desejada: ");   //fim do menu
	
	scanf("%d", &opcao);  //armazenando a escolha do usuario
	
	system("cls"); //resposavel por limpar a tela
	
	switch(opcao) //inicio da seleção do menu
	{
		case 1:
		registro(); //chamada de funções
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
		printf("Esta opção não está disponível!\n");
		system("pause");
		break;
		
		//fim da seleção
    }
	
	
	
	


	}
}
