#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

const int TAM = 10;
int fila[TAM];
int inicio = -1;
int fim = -1;

void enfileirar(int y);
void desinfileirar();
void mostrar();

int main() {
int op,y;
 setlocale(LC_ALL, "Portuguese");
	do
	{
		printf("\n|||MENU|||");
		printf("\n1.Enfileirar\n");
		printf("2.Desinfileirar\n");
		printf("3.Mostrar\n");
		printf("4.Sair\n");
		printf("\nEscolha uma opção : ");
		scanf("%d",&op);
		switch(op) {
			case 1 :
				printf("\nValor que deseja inserir na fila : ");
				scanf("%d", &y);
				enfileirar(y);
				break;
			case 2 :
				desinfileirar();
				break;
			case 3:
				mostrar();
				break;
			case 4:
				break;
			default:
			printf("\nOpção inválida");
			}
		}while(op!=4);
		
		return 0;
}

void enfileirar(int y)
{
	if(inicio == -1 && fim == -1) {     //verifica se a fila está vazia e a inicializa
        inicio = 0;
        fim = 0;
        fila[fim] = y;
    }
    else if((fim + 1)%TAM == inicio) {  //verifica se a fila está cheia
        printf("\nA fila está cheia!\n");
    }
    else { 								//insere os números na fila
        fim = (fim + 1) % TAM;
        fila[fim] = y;
    }
}

void desinfileirar()
{
    if(inicio == -1 && fim == -1) {		//verifica se a fila está vazia
            printf("\nA fila está vazia!\n");
    }
    else if(inicio == fim){			//quando o último número for removido, coloca a fila como vazia novamente
        inicio = -1;
        fim = -1;
    }
    else{							//remove os números da fila
        inicio = (inicio + 1)%TAM;
    }
}

void mostrar() {
	int i = inicio;
	 if(inicio == -1 && fim == -1) {		//verifica se a fila está vazia
            printf("\nA fila está vazia!\n");
    }
    else{
    	printf("Fila: ");
    	while(i != fim){
    		printf("%d \n", fila[i]);
    		i = (i+1)%TAM;
		}
	}
}
