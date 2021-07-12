#definir RedBlackTree_h
#incluir  <stdlib.h> 
#incluir  <stdio.h> 

//arvore vermelho e preta
enum COR {Vermelho, Preto};

typedef struct tree_node{
    int dados;
	estrutura tree_node *esquerda;  //esquerda/esquerda
    struct tree_node *direita;  //direita/direita
    estrutura tree_node *pai;  //pai: pai
    enum COR COLORIDA;
}tree_node;

typedef struct red_black_tree{
 tree_node *raiz;
    tree_node *NIL; 
}red_black_tree;

tree_node* new_tree_node(dadosint);

new_red_black_tree red_black_tree*();

tree_node* mínimo (red_black_tree *t, tree_node *x);

tree_node* pesquisa(red_black_tree *t, int valor);

left_rotate vazio  (red_black_tree *t, tree_node *x);  //Rotação

right_rotate vazio  (red_black_tree *t, tree_node *x);  //Rotação

insertion_fixup vazio (red_black_tree *t, tree_node *z);

 inserçãode vazio (red_black_tree *t, tree_node *z);

rb_transplant vazio  (red_black_tree *t, tree_node *u, tree_node *v);

rb_delete_fixup vazio (red_black_tree *t, tree_node *x);  //Excluir

rb_delete vazio (red_black_tree *t,tree_node *z);  //Excluir

 inordenagemde vazio (red_black_tree *t, tree_node *n);

menu_insert vazio (red_black_tree *t);

menu_delete vazio (red_black_tree *t);
