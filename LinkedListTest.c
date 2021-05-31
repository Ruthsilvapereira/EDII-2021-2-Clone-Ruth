  
//Olá a todos! Estou adiantando a atividade Lista Simplesmente Ligada, conforme video aula disponivel em:https://drive.google.com/file/d/1U7DY59DzPNdC5vpBSg_brgJ_WAo-NQHU/view
//Estou criando a LinkedListTest.c, disponivel em:http://www.jppreti.com/2019/07/15/lista-simplesmente-ligada/#LinkedListTestc
//LinkedListTest.c ======> postada completa com as operações, conforme proposto no video:https://drive.google.com/file/d/1U7DY59DzPNdC5vpBSg_brgJ_WAo-NQHU/view
//Lembrando a todos que a unica LinkedList que será editada por todos é a LinkedList.c ===>(.c)<====, postada anteriomente.
//ATENÇÃO LinkedList.h  e também a LinkedListTest.c são postada  por apenas um aluno, no caso já postei as duas, by Ruth. A unica que todos vão postar juntos é a LinkedList.c ===>(.c)<====
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;
    
    return (*d1==*d2)?true:false;
}
int main() {
    LinkedList list;
    init(&list);
    
    int *aux = (int *)malloc(sizeof(int));
    *aux=1;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=2;
    enqueue(&list, aux);
    aux = (int *)malloc(sizeof(int));
    *aux=3;
    enqueue(&list, aux);
    
    printf("%d\n",*((int*)first(&list)));
    printf("%d\n",indexOf(&list,aux,compara));
    printf("%d\n",*((int*)getPos(&list,2)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    printf("%d\n",*((int*)dequeue(&list)));
    //printf("%d\n",*((int*)dequeue(&stack)));
    
    return EXIT_SUCCESS;
}