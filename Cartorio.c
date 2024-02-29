#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações por região
#include <string.h> //biblioteca responsável por cuidar da string

int registro() //Função responsavel por cadastrar os usuários no sistema
{   
    //inicio criação de variável/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variável/string
	
	printf("Digite seu CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); //fechando arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando o nome do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //abrindo arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //abrindo arquivo
	fprintf(file,","); //Adicionando uma vírgula ao arquivo
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando o sobrenome do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //abrindo arquivo
	fprintf(file,sobrenome); 
	fclose(file);	
	
	file = fopen(arquivo, "a"); //abrindo arquivo
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando o cargo do usuário
	scanf("%s",cargo); //entrada de dados do usuário
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta()//Função para consultar informações de um usuário
{  
    setlocale(LC_ALL, "Portuguese"); //Definindo a línguagem
	
	char cpf[40]; //criação variável/string
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //entrada de dados do usuário
	
	FILE *file;
	file = fopen(cpf, "r"); //abrindo "r" lendo o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()//Função para deletar informações de um usuário
{
	char cpf[40]; //variavel a ser consultada
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //entrada de dados do usuário
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //analise do usuário inexistente
	{
		printf("Usuário não encontrado no sistema!.\n");
		system("pause");
	}
	
	}
    

int main()    
{    
    int opcao=0; //Definindo as variáveis 
    int laco=1;
    
    for(laco=1;laco=1;)
    {  
    
        system("cls"); //responsavel por limpar a tela
	   
	    setlocale(LC_ALL, "Portuguese"); //Definindo a línguagem

    	printf("Cartório de registro EBAC \n\n"); //inicio do menu
	    printf("Escolha a opção desejada no menu:\n\n");
 	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
    	printf("Opção: "); //final do menu
	
    	scanf("%d", &opcao); //armazenando a escolha do usuário
	
    	system("cls"); //responsavel por limpar a tela
	
	    switch(opcao) //nicio da seleção de menu
	    {
		    case 1:
    	    registro(); //chamada de funções
    	    break; //encerra a execução do loop
    	    
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
    	    printf("Está opção não está disponivel!\n");
    	    system("pause");
    	    break; //final da seleção
		
		
		}
		
		
	}
}




