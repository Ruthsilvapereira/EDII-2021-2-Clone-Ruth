//Árvore Rubro-Negra = RedBlackTree
//Alunas: Ruth e Zhaira
//Atividade 7: Trabalho Final

//Implementação em Dupla de trabalho valendo 40% da nota final que envolve o estudo e implementação sobre:
//Árvore Rubro-negra
//Apenas uma dupla poderá desenvolver sobre um determinado tópico
//ou seja, duas duplas não podem realizar trabalho sobre o mesmo assunto. 
//A entrega deve ocorrer por meio de implementação do código no GitHub e PDF 
//Ser entregue via AVA explicando o trabalho e como testar o exemplo
//Data de entrega: 20 jul 2021, terça-feira

//Árvore Rubro-Negra = RedBlackTree (.h)

//Bibliotecas

#define RedBlackTree_h
#include <stdlib.h>
#include <stdio.h>

//Inicio

enum COLOR {Red, Black};
//definição das structs
typedef struct tree_node{
    int data;
    struct tree_node *right;
    struct tree_node *left;
    struct tree_node *parent;
    enum COLOR color;
}tree_node;

typedef struct red_black_tree{
    tree_node *root;
    tree_node *NIL;  //como se fosse o NULL
}red_black_tree;

//esboço das funções
tree_node* new_tree_node(int data);

red_black_tree* new_red_black_tree();

void left_rotate (red_black_tree *t, tree_node *x);

void right_rotate (red_black_tree *t, tree_node *x);

void insertion_fixup(red_black_tree *t, tree_node *z);

void insert(red_black_tree *t, tree_node *z);

void rb_transplant (red_black_tree *t, tree_node *u, tree_node *v);

tree_node* minimum (red_black_tree *t, tree_node *x);

void rb_delete_fixup(red_black_tree *t, tree_node *x);

void rb_delete(red_black_tree *t,tree_node *z);

void inorder(red_black_tree *t, tree_node *n);

tree_node* search(red_black_tree *t, int valor);

void menu_insert(red_black_tree *t);

void menu_delete(red_black_tree *t);
