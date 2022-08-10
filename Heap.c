#include<stdio.h>
#include<stdlib.h>

typedef struct ponto{
  int x;
  int y;
}Ponto;

void troca(Ponto * a, Ponto *b){
  Ponto aux = *a;
  *a = *b;
  *b = aux;
}

int compara(Ponto* a, Ponto* b){
     if(a->x > b->x){
        return -1;
     }
     if(a->x == b->x ){
        if(a->y > b->y)
            return -1;
        if(b->y > a->y)
            return 1;
     }
     return 0;
}

void sobe_heap(Ponto *heap, int pos){
	
  if(pos == 0) return;
  int pai = (pos-1)/2;
  int result = compara(&(heap[pos]), &(heap[pai]));
  //EXISTE UMA INVERSAO?
  if(result==-1){
    troca(&(heap[pos]), &(heap[pai]));
    sobe_heap(heap, pai);
  }else{
    //Se não tem inversao nao faz nada.
  }
}

void insere(Ponto *heap, int n, int valorx, int valory){
  heap[n].x = valorx;
  heap[n].y = valory;
  sobe_heap(heap, n);
  return;
}

void desce_heap( Ponto * heap, int n, int pos){
  int esq = 2*pos + 1;
  int dir = 2*pos + 2;
  
  //tenho filhos?
  if(esq >= n) return;
  
  int maior_filho = esq;
  
  int result = compara(&(heap[dir]), &(heap[maior_filho]));
  //verifica se tem filho direito
  // e se ele é maior que o esquerdo
  if(dir < n && result ==-1){
    maior_filho = dir;
  }
  
  int result2 = compara(&(heap[maior_filho]), &(heap[pos]));
  //VERIFICAR SE heap[pos] é maior que O MAIOR  FILHO
  if(result2 == -1){
    troca(&(heap[pos]), &(heap[maior_filho]));
    desce_heap(heap, n, maior_filho);
  }else{
    //se não tem troca, heap[pos] já tá no lugar certo.
  }
}


Ponto extrair(Ponto * heap, int n){
  Ponto maior = heap[0];
  heap[0] = heap[n-1];
  desce_heap(heap, n-1, 0); 
  return maior;
}

void imprime(Ponto * heap, int n){
	int i; 
  for(i = 0; i < n; i++){
   printf("(%d, %d) ", heap[i].x, heap[i].y);
  }
  printf("\n");
}

int main(int argc, char* argv[]){
  int tamanho;
  scanf("%d", &tamanho);
  int n = 0;
  
  Ponto * heap = (Ponto *) malloc(sizeof(Ponto)*tamanho);
  //FAZER: CRIAR/ALOCAR MEMORIA PARA O HEAP

  srand(tamanho);
  printf("Inserindo %d pontos\n", tamanho/2);
  for(int i = 0; i < tamanho/2; i++){
    int x = rand()%tamanho;
    int y = rand()%tamanho;
    insere(heap, n, x, y);
    n++;
    //FAZER: AQUI VOCE INSERE O PONTO (x, y) no heap
  }  


  printf("Extraindo os %d maiores\n", tamanho/4);
  for(int i = 0; i < tamanho/4; i++){
  		Ponto maior = extrair(heap, n);
  		n--;
      //FAZER: Extrair e imprimir
      //Ponto maior;
      printf("(%d, %d) ", maior.x, maior.y);
  }  
  printf("\n");

  printf("Inserindo %d pontos\n", 3*tamanho/4);
  for(int i = 0; i < 3*tamanho/4; i++){
    int x = rand()%tamanho;
    int y = rand()%tamanho;
    insere(heap, n, x, y);
    n++;
    //FAZER: AQUI VOCE INSERE O PONTO (x, y) no heap
  }  

  printf("Extraindo os %d maiores\n", tamanho/2);
  for(int i = 0; i < tamanho/2; i++){
  		Ponto maior = extrair(heap, n);
  		n--;
      //FAZER: Extrair e imprimir
      //Ponto maior;
      printf("(%d, %d) ", maior.x, maior.y);
  }  
  printf("\n");
	
	free(heap);
  //FAZER: Liberar memória
  return 0;
}


