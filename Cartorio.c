#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es por regi�o
#include <string.h> //biblioteca respons�vel por cuidar da string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{   
    //inicio cria��o de vari�vel/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�vel/string
	
	printf("Digite seu CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); //fechando arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando o nome do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //abrindo arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //abrindo arquivo
	fprintf(file,","); //Adicionando uma v�rgula ao arquivo
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando o sobrenome do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //abrindo arquivo
	fprintf(file,sobrenome); 
	fclose(file);	
	
	file = fopen(arquivo, "a"); //abrindo arquivo
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando o cargo do usu�rio
	scanf("%s",cargo); //entrada de dados do usu�rio
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta()//Fun��o para consultar informa��es de um usu�rio
{  
    setlocale(LC_ALL, "Portuguese"); //Definindo a l�nguagem
	
	char cpf[40]; //cria��o vari�vel/string
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //entrada de dados do usu�rio
	
	FILE *file;
	file = fopen(cpf, "r"); //abrindo "r" lendo o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()//Fun��o para deletar informa��es de um usu�rio
{
	char cpf[40]; //variavel a ser consultada
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //entrada de dados do usu�rio
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //analise do usu�rio inexistente
	{
		printf("Usu�rio n�o encontrado no sistema!.\n");
		system("pause");
	}
	
	}
    

int main()    
{    
    int opcao=0; //Definindo as vari�veis 
    int laco=1;
    
    for(laco=1;laco=1;)
    {  
    
        system("cls"); //responsavel por limpar a tela
	   
	    setlocale(LC_ALL, "Portuguese"); //Definindo a l�nguagem

    	printf("Cart�rio de registro EBAC \n\n"); //inicio do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
 	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
    	printf("Op��o: "); //final do menu
	
    	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
    	system("cls"); //responsavel por limpar a tela
	
	    switch(opcao) //nicio da sele��o de menu
	    {
		    case 1:
    	    registro(); //chamada de fun��es
    	    break; //encerra a execu��o do loop
    	    
    	    case 2:
    	    consulta();
			break;
		
			case 3:
    	    deletar();
    	    break;
    	    
    	    case 4:
    	    printf("Obrigado por utilizar o sistema!\n");
    	    return 0;
    	    break;
    	    
			default:
    	    printf("Est� op��o n�o est� disponivel!\n");
    	    system("pause");
    	    break; //final da sele��o
		
		
		}
		
		
	}
}




