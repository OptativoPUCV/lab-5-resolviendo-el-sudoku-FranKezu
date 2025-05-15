#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int i, j, k;

  for(i = 0 ; i < 9 ; i++){
    int n_filas[10] = {0};
    int n_columnas[10] = {0};

    //Verificar filas.
    for(j = 0 ; j < 9 ; j++){
      int val = n->sudo[i][j];
      if(val != 0){
        if(n_filas[val]) return 0;
        n_filas[val] = 1;
      }
    }
    //Verificar columnas.
    for(j = 0 ; j < 9 ; j++){
      int val = n->sudo[j][i];
      if(val != 0){
        if(n_columnas[val]) return 0;
        n_filas[val] = 1;
      }
    }
  }

  return 1;

}


List* get_adj_nodes(Node* n){
    List* list = createList();
    for(int i = 0 ; i < 9 ; i++)
      for(int j = 0 ; j < 9 ; j++)
        if(n->sudo[i][j] == 0){
          for(int val = 1 ; val <= 9 ; val++){
            Node *new = copy(n);
            new->sudo[i][j] = val;
            pushBack(list, new);
          }
          return list;
        }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/