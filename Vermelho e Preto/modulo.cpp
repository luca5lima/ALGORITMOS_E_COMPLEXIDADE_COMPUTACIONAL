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
  Tno* dado = (Tno*) malloc(sizeof(Tno));
  dado->elemento = elemento;
  dado->esq = NULL;
  dado->dir = NULL;
  dado->cor = vermelho;
  return dado;
}
Tno* inserir(Tno* a, int valor){
  Tno* dado = criar(valor);
  a = incluir_no(a, dado);
  if (a != NULL)
    a->cor = preto;
  return a;
}
Tno* incluir_no(Tno* a, Tno* dado){
  if(a == NULL)
    return dado;
  else
  {
    if (a->elemento > a->elemento)
      a->esq = incluir_no(a->esq, dado);
    else
      a->dir = incluir_no(a->dir, dado);
    //Analisar a cor
    if ((cor(a->esq) == vermelho) && (cor(a->dir) == vermelho))
      trocaCor(a);
    //Analisar as rotações
    if( (cor(a->dir) == vermelho) && (cor(a->dir->dir) == vermelho)){  //Mesmo lado dir->dir
      a->cor = vermelho;
      a->dir->cor = preto;
      a = rotacao_simples_esquerda(a);
    }
    if( (cor(a->dir) == vermelho) && (cor(a->dir->esq) == vermelho)){  //Lados opostos
      //Rotação Dupla
      a->dir = rotacao_simples_direita(a->dir);
      a->cor = vermelho;
      a->dir->cor = preto;
      a = rotacao_simples_esquerda(a);
    }
    if( (cor(a->esq) == vermelho) && (cor(a->esq->esq) == vermelho)){  //Mesmo lado esq->esq
      a->cor = vermelho;
      a->esq->cor = preto;
      a = rotacao_simples_direita(a);
    }
    if( (cor(a->esq) == vermelho) && (cor(a->esq->dir) == vermelho)){  //Lados opostos 
      //Rotação Dupla
      a->esq = rotacao_simples_esquerda(a->esq);
      a->cor = vermelho;
      a->esq->cor = preto;
      a = rotacao_simples_direita(a);
    }
  }
}
int cor(Tno* a){
  if (a == NULL)
    return preto;
  else
    return a->cor;  
}
void trocaCor(Tno* a){
  a->cor = !a->cor;
  if(a->cor != NULL)
    a->esq->cor = !a->esq->cor;
  if(a->cor != NULL)
    a->dir->cor = !a->dir->cor;

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