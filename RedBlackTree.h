#define RedBlackTree_h
#include <stdlib.h>
#include <stdio.h>

//cor  vermelha e preta
enum COLOR {Red, Black};

typedef struct tree_node{
    int data;
	struct tree_node *left;
    struct tree_node *right;
    struct tree_node *parent; //parent: pai
    enum COLOR color;
}tree_node;

typedef struct red_black_tree{
    tree_node *root;
    tree_node *NIL; 
}red_black_tree;

tree_node* new_tree_node(int data);

red_black_tree* new_red_black_tree();

tree_node* minimum (red_black_tree *t, tree_node *x);

tree_node* search(red_black_tree *t, int valor);

void left_rotate (red_black_tree *t, tree_node *x); //Rotação

void right_rotate (red_black_tree *t, tree_node *x); //Rotação

void insertion_fixup(red_black_tree *t, tree_node *z);

void insert(red_black_tree *t, tree_node *z);

void rb_transplant (red_black_tree *t, tree_node *u, tree_node *v);

void rb_delete_fixup(red_black_tree *t, tree_node *x); //Excluir

void rb_delete(red_black_tree *t,tree_node *z); //Excluir

void inorder(red_black_tree *t, tree_node *n);

void menu_insert(red_black_tree *t);

void menu_delete(red_black_tree *t);
