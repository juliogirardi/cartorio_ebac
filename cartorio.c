#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


//===============================
//===== functions prototype =====
//===============================

int registro(void);
int consulta(void);
int deletar(void);


//=====================
//===== main code =====
//=====================

int main() {
	
	int opcao = 0; //declar�o de vari�veis
		
	while(1) {
		
		setlocale(LC_ALL, "Portuguese"); //seta pacote de linguagem para Portugu�s
		
		//constru��o do menu
		system("cls"); //limpa tela
		
		printf("############################\n");
		printf("##### Cart�rio da EBAC #####\n");
		printf("############################\n");
		
		printf("\nEscolha a op��o desejada do menu:\n\n");
		printf("\t1. Registrar nomes\n");
		printf("\t2. Consultar nomes\n");
		printf("\t3. Deletar nomes\n");
		printf("\t4. Listar CPF's cadastrados\n");
		printf("\t----------------------\n");
		printf("\t9. Encerrar o programa\n");
		printf("\nOp��o: ");
				
		scanf("%d", &opcao); //registra escolha do usu�rio na vari�vel opcao
		
		system("cls"); 
		
		printf("############################\n");
		printf("##### Cart�rio da EBAC #####\n");
		printf("############################\n\n");
		
		switch(opcao) {
			case 1: registro();	break;
			
			case 2: consulta();	break;
			
			case 3: deletar();	break;
			
			case 4: listar();	break;
			
			case 9: 
			printf("Programa encerrado!! Obrigado por usar nosso sitema.\n");
			exit(0);
			break;
										
			default:
			printf("Op��o n�o dispon�vel!\n");
			system("pause");
		}
	}
}


//=====================
//===== functions =====
//=====================

int registro() {  //fun��o respons�vel por cadastrar os usu�rios no sistema
	
	//declara��o de vari�veis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	
	
	//coleta de dados
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	strcpy(arquivo, cpf);
	strcat(arquivo, ".TXT"); //adiciona a extens�o '.TXT' ao nome do arquivo
		
	FILE *file; //pointer
	file = fopen(arquivo, "w"); //cria e abre o arquivo no modo 'write' com extens�o .TXT
	fprintf(file, "%s,%s,%s,%s", cpf, nome, sobrenome, cargo); //escreve os dados dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("\nUsu�rio ** %s %s ** registrado com sucesso!!!\n\n", nome, sobrenome);
	system("pause");
}

int consulta() {  //fun��o respons�vel por consultar os usu�rios no sistema
	
	setlocale(LC_ALL, "Portuguese"); //seta pacote de linguagem para Portugu�s
	
	char cpf[40];
	char conteudo[200];
	char user[4][40] = {};
	int i = 0;
	int j = 0;
	int k = 0;
		
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen((strcat(cpf, ".TXT")), "r"); //abre o arquivo no modo 'read'
	
	if(file == NULL) {
		printf("\nCPF n�o cadastrado!! Pressione quaquer tecla para voltar ao menu inicial. \n\n"); 
		system("pause");
	} else {
		fgets(conteudo, 200, file); //l� conte�do do arquivo e armazena na vari�vel 'conteudo'
		
		//identifica as virgulas e separa os dados
		while(conteudo[i] != '\0') {
			if(conteudo[i] != ',') {
				user[j][k] = conteudo[i];
				k++;
				i++;
			} else {
				i++;
				j++;
				k=0;
			}
		}
		fclose(file); //fecha o arquivo
	
		printf("\nCPF encontrado!!! Essas s�o as informa��es do usu�rio: \n\n");
		printf("CPF:        %s\n", user[0]);
		printf("Nome:       %s\n", user[1]);
		printf("Sobrenome:  %s\n", user[2]);
		printf("Cargo:      %s\n\n", user[3]);
		
		system("pause");
	}	
}

int deletar() {  //fun��o respons�vel por deletar os usu�rios no sistema
	
	char cpf[40];
	char arquivo[40];
		
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", &cpf);
		
	strcpy(arquivo, cpf);
	strcat(arquivo, ".TXT");
	
	//verifica se o arquivo foi deletado com sucesso ou se n�o foi encontrado
	remove(arquivo) == 0 ? printf("\nArquivo %s deletado com sucesso!!!\n\n", arquivo) : printf("\nCPF n�o encontrado.\n\n");
		
	system("pause");
}

int listar() {
	
	printf("Lista de CPF's cadastrados: \n\n");
	system("dir *.TXT /B /ON");
	printf("\n\n");
	system("pause");
}






	



