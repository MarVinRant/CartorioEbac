#include <stdio.h> //biblioteca de comunica��o com o usuario//
#include <stdlib.h> //blibioteca de aloca��o de espa�o em memoria//
#include <locale.h> //bilbioteca de aloca�ao de texto por regiao//
#include <string.h> //biblioteca responsavel por cuidar das strings//

int registro() //Fun��o que cadastra os usuarios//
{
	//inicio cria��o de variaveis/strings//
	char arquivo[40];
	char cpf[40];;
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/strings//
	
	printf("Digite o CPF que deseja cadastrar: "); //Coletando informa��o do usuario//
	scanf("%s", cpf); //%s refere-se a string//
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings//
	
	FILE *file; //cria o arquivo//
	file = fopen(arquivo, "w"); //cria o arquivo e o "w"significa escrever//
	fprintf (file,cpf); //salvo o valor da variavel//
	fclose(file); //fecho o arquivo//
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobremone que deseja cadastrar: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo que deseja procurar: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar() //
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagens//
	
	char cpf[40];
	char conteudo[200];
	
	printf("Coloque o CPF que deseja consultar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es buscadas: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Qual CPF deseja deletar?");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o encontramos nenhum usuario cadastrado com este CPF!.\n");
		system("pause");
		
	}
	
	
}

int main()
{
	int opcao=0; //Definindo variaveis//
	int laco=1;
	
		for(laco=1; laco=1;)
	{
	
		system("cls");
		
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagens//
	
		printf("### Cartorio da EBAC ###\n\n"); //inicio do menu//
		printf("Escolha o item desejado no menu:\n\n");
		printf("\t1 - Fazer o registro de nome(s):\n");
		printf("\t2 - Fazer a consulta de nome(s):\n");
		printf("\t3 - Remover nomes:\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o "); //fim do menu//
	
		scanf("%d", &opcao);
	
		system("cls"); //Responsavel por limpar a tela//
		
		switch(opcao) //inicio da sele��o do menu//
		{
			case 1:
			registro(); //chamada de fun��es//
			break;
			
			case 2:
			consultar(); //chamada de fun��es//
			break;
			
			case 3:
			deletar(); //chamada de fun��es//
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		} //final da sele��o do menu//
	}
}
