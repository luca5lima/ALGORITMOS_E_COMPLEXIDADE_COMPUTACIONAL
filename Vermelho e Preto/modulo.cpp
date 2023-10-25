#include "lib.h"

void menu(){
	int op, valor;
	
	//--------- iniciando a estrutura --------------------//
    Tno *arvore = NULL;
    
    do{    
    //--------------- Exibir menu ---------------------//
        system("cls");
        puts("\n\t\t\t\tARVORE BINARIA BALANCEADA - VERMELHO E PRETO\n");
        puts("\t1  - INSERIR ELEMENTO\n \t2  - IMPRIMIR ARVORE\n \n\t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Opção
        
        switch(op)
        {
        //Opção de exibir lista
    		case 1:{
    			printf("Informe um elemento: ");
    			scanf("%d", &valor);
    			arvore = inserir(arvore, valor);
    			imprime(arvore);
				break;
			}
    		
    		case 2:{
    			imprime(arvore);
			}
    			
	    	default:
	    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");break;
	      
	        }
		getch();
	    }while(op!=0);
}


Tno* rotacao_simples_esquerda(Tno* a){//mesmo código da AVL
   Tno *aux;
   aux = a->dir;
   a->dir = aux->esq;
   aux->esq = a;
   a = aux;   
   return a;
}
Tno * rotacao_simples_direita(Tno *a){//mesmo código da AVL
  Tno *aux;
	aux = a->esq;
	a->esq = aux->dir;
	aux->dir = a;
	a = aux;
  return a;
}

Tno* criar(int elemento){//mesmo código da AVL

}
Tno* inserir(Tno* a, int valor){

}
Tno* incluir_no(Tno* a, Tno* dado){

}
int cor(Tno* a){

}
void trocaCor(Tno* a){

}
void imprime(Tno* a){//mesmo código da AVL
    if (a == NULL){
		return;
	}
    printf("%d [cor: %d]",a->elemento, a->cor);
 
    if(a->esq != NULL)
        printf("(E:%d [cor: %d])",a->esq->elemento, a->esq->cor);
    if(a->dir != NULL)
        printf("(D:%d [cor: %d])",a->dir->elemento, a->dir->cor);
    printf("\n");
 
    imprime(a->esq);
    imprime(a->dir);
}