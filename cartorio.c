#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


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
	
	int opcao = 0; //declarão de variáveis
		
	while(1) {
		
		setlocale(LC_ALL, "Portuguese"); //seta pacote de linguagem para Português
		
		//construção do menu
		system("cls"); //limpa tela
		
		printf("############################\n");
		printf("##### Cartório da EBAC #####\n");
		printf("############################\n");
		
		printf("\nEscolha a opção desejada do menu:\n\n");
		printf("\t1. Registrar nomes\n");
		printf("\t2. Consultar nomes\n");
		printf("\t3. Deletar nomes\n");
		printf("\t4. Listar CPF's cadastrados\n");
		printf("\t----------------------\n");
		printf("\t9. Encerrar o programa\n");
		printf("\nOpção: ");
				
		scanf("%d", &opcao); //registra escolha do usuário na variável opcao
		
		system("cls"); 
		
		printf("############################\n");
		printf("##### Cartório da EBAC #####\n");
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
			printf("Opção não disponível!\n");
			system("pause");
		}
	}
}


//=====================
//===== functions =====
//=====================

int registro() {  //função responsável por cadastrar os usuários no sistema
	
	//declaração de variáveis
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
	strcat(arquivo, ".TXT"); //adiciona a extensão '.TXT' ao nome do arquivo
		
	FILE *file; //pointer
	file = fopen(arquivo, "w"); //cria e abre o arquivo no modo 'write' com extensão .TXT
	fprintf(file, "%s,%s,%s,%s", cpf, nome, sobrenome, cargo); //escreve os dados dentro do arquivo
	fclose(file); //fecha o arquivo
	
	printf("\nUsuário ** %s %s ** registrado com sucesso!!!\n\n", nome, sobrenome);
	system("pause");
}

int consulta() {  //função responsável por consultar os usuários no sistema
	
	setlocale(LC_ALL, "Portuguese"); //seta pacote de linguagem para Português
	
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
		printf("\nCPF não cadastrado!! Pressione quaquer tecla para voltar ao menu inicial. \n\n"); 
		system("pause");
	} else {
		fgets(conteudo, 200, file); //lê conteúdo do arquivo e armazena na variável 'conteudo'
		
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
	
		printf("\nCPF encontrado!!! Essas são as informações do usuário: \n\n");
		printf("CPF:        %s\n", user[0]);
		printf("Nome:       %s\n", user[1]);
		printf("Sobrenome:  %s\n", user[2]);
		printf("Cargo:      %s\n\n", user[3]);
		
		system("pause");
	}	
}

int deletar() {  //função responsável por deletar os usuários no sistema
	
	char cpf[40];
	char arquivo[40];
		
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", &cpf);
		
	strcpy(arquivo, cpf);
	strcat(arquivo, ".TXT");
	
	//verifica se o arquivo foi deletado com sucesso ou se não foi encontrado
	remove(arquivo) == 0 ? printf("\nArquivo %s deletado com sucesso!!!\n\n", arquivo) : printf("\nCPF não encontrado.\n\n");
		
	system("pause");
}

int listar() {
	
	printf("Lista de CPF's cadastrados: \n\n");
	system("dir *.TXT /B /ON");
	printf("\n\n");
	system("pause");
}






	



