#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define ALUNOS 50 //constante Alunos, caso queira alterar sem precisar mexer no restante do codigo


typedef struct  {
	char nome [50];
	float notas [2];
	int ok; // ok para saber se o aluno ta cadastrado/ sera usado na funcao remover/listar

	
}Aluno;
Aluno alunos[ALUNOS]; //vetor alunos

	// prototipo da funçao, informar o programa que teremos essas funções no problema
void menu();
void cadastrar();
void listar();
void remover();
void media();
void Ranking();
void Ranking2();

//função principal MAIN
int main () {
	menu();

	return 0;
	
}

// função menu - Lista as categorias que deseja realizar
void menu() {
	
	setlocale(LC_ALL,"Portuguese");
	
	int op;
	do {
	system ("cls"); // limpar tela do menu
	printf("* CADASTRAMENTO DE ALUNOS*");
	printf("\n 1- Cadastrar Alunos");
	printf("\n 2- Listar Alunos");
	printf("\n 3- Remover Aluno");
	printf("\n 4- Media dos Alunos");
	printf("\n 5- Ranking 1 - Media <=6");
	printf("\n 6- Ranking 2 - Media >6");
	printf("\n 0- sair \n \n");
	printf("\n Informe opção desejada: ");
	scanf("%d", &op);
	getchar();
		
		switch (op) {
			
			case 1:
				cadastrar();
				break;
			case 2:
			    listar();
			    break;
		    case 3:
			    remover();
				break;
			case 4:
			    media();
				break;
			case 5:
			    Ranking();
				break;
			case 6:
			    Ranking2();
				break;
		}
	
getchar();
	} while(op!=0);
}


// Função cadastrar aluno 
void cadastrar() {
	
		system("cls	");
		char nome [50];
		float notas [2];
		int op;
		do {
			
		fflush(stdin);		
		printf("\n Nome do Aluno: \t");
		gets(nome);
		printf("\n Nota do Aluno: \t");
		scanf("%f", &notas[0]);
		printf("\n Nota do Aluno: \t");
		scanf("%f", &notas[1]);
		
		for (int i=0; i < ALUNOS; i++){
				
				if (alunos[i].ok==0){
					
					alunos[i].notas[0] = notas [0];
					alunos[i].notas[1] = notas [1];
					strcpy(alunos[i].nome, nome); //Realiza a cópia do conteúdo de uma variável a outra.
					alunos[i].ok=1; // aluno cadastrado
					break; // evitar repetir varias vezes o mesmo aluno sempre q ok for igual a 0
				}
				
				getchar();
			}
	
		
		printf("\n 1- Continuar.... \n 0-Sair \n");
		scanf("%d", &op);
			
		
		
		}	while(op!=0);
}

// Listar quantidade de alunos cadastrado.. 
void listar() {
	
	
	system("cls");
	printf("Lista de alunos Cadastrado:\n\n");
	
	
	
	for (int i=0; i< ALUNOS; i++){ 
		
		if(alunos[i].ok ==1) { // verificar se aluno esta cadastrado
		
	    printf("Matricula: %d \n", i+1); //da opção para remover atraves da matricula
		printf("Alunos: %s \n", alunos[i].nome);
		printf("Notas 1: %0.2f \n", alunos[i].notas[0]);
		printf("Notas 2: %0.2f \n\n", alunos[i].notas[1]);
		
					}
	}
}

//remove o cadastro do aluno pela matricula
void remover(){
	 int mat;
	listar(); //listar alunos cadastrado
   	
	printf("\n Informe a matricula que deseja remover: ");
	scanf("%d",&mat);
	--mat; //subtrair numero da variavel
	alunos[mat].ok=0;

	printf("Aluno removido..");
	
    
    
    getchar();
}

void media(){
	
	  system("cls");
	   float media;
	

		printf("Media do aluno:\n");
	
	for (int i=0; i< ALUNOS; i++){
		
		if(alunos[i].ok ==1) {
		
		media=0;
		media = alunos[i].notas[0] + alunos[i].notas[1];
		media = media/2;
	     if (media<=10) { // calc media
		 
		printf("Matricula: %d \n", i);
		printf("Alunos: %s \n", alunos[i].nome);
		printf("Are 1: %0.2f \n", alunos[i].notas[0]);
		printf("Are 2: %0.2f \n", alunos[i].notas[1]);
		
		printf("Media final: %f \n \n", media); 
		 }
	    
	    
		
		}
	}
	
	
}



void Ranking(){ // Exibe aluno se a nota for menor ou igual 6
	
	   system("cls");
	   float media;
	
	
		printf("Lista dos Mehores RANK1 - Notas Abaixo de 6:\n");
			
	for (int i=0; i< ALUNOS; i++){		
		if(alunos[i].ok ==1) {		
				media=0;
				media = alunos[i].notas[0] + alunos[i].notas[1];
				media = media/2;
	     if (media<=6) { // calc media
	     			printf("Matricula: %d \n", i);
					printf("Alunos: %s \n", alunos[i].nome);
					printf("Media: %0.2f \n", media);
				
		 }
	    
	    
		
		}
	}
}
	// Exibe aluno se a media  for superior acima de 6 
void Ranking2(){
	 system("cls");
	   float media;
	
	
		printf("Lista dos Mehores RANK2 - Notas acima de 7:\n");
	
	
	
	for (int i=0; i< ALUNOS; i++){
		
		
		if(alunos[i].ok ==1) {
		
		
		media=0;
		media = alunos[i].notas[0] + alunos[i].notas[1];
		media = media/2;
	     if (media>6) { // calc media
		 
		printf("Matricula: %d \n", i);
		printf("Alunos: %s \n", alunos[i].nome);
		printf("Are 1: %0.2f \n", alunos[i].notas[0]);
		printf("Are 2: %0.2f \n", alunos[i].notas[1]);
			printf("Media: %0.2f \n", media);	
		
		 
		 
		 }
	    
	    
		
		}
	}
	
}
