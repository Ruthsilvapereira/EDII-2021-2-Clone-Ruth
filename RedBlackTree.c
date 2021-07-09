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

//Árvore Rubro-Negra (Árvores Vermelho-Preto ou Red-black Trees), são árvores binárias de busca, com algumas propriedades definidas: 
//1. Todo nó é vermelho ou preto 
//2. A raiz é preta 
//3. Toda folha (Nil) é preta 
//4. Se um nó é vermelho, então os seus filhos são pretos 
//5. Para cada nó, todos os caminhos do nó para folhas descendentes contém o mesmo número de nós PRETOS.

//simulador online de Árvore Rubro-Negra
//https://www.cs.usfca.edu/~galles/visualization/RedBlack.html

#include "RedBlackTree.h"

//Menu do Usuário
int main (){
  red_black_tree *t = new_red_black_tree();
  int continuar;

  do
  {
	printf("\n\tDigite 0 para fechar\n\t");
	printf("Digite 1 para adicionar valores\n\t");
	printf("Digite 2 para excluir um valor informado\n\t");
	printf("Digite 3 para visualização\n\n\t");

	scanf("%d", &continuar);
	system("cls || clear");

	switch(continuar)
	{
	  case 0:
	  break;

	  default:
	  printf("opção invalida\n\n");

	  case 1:
	  menu_insert(t);
	  break;

	  case 2:
	  menu_delete(t);
	  break;

	  case 3:
	  inorder(t, t->root);
	  break;
	}
  } while(continuar);

  return 0;
} 

//Inserção do valor informado pelo usuario
void menu_insert(red_black_tree *t){
  int add;

  printf("Digite o valor: ");
  scanf("%d",&add);
  tree_node* z = new_tree_node(add);
  insert(t,z);
}

//função para criar um novo nó
//novo: novo nó
tree_node* new_tree_node(int data){
  tree_node *novo = malloc(sizeof(tree_node));
  novo->left = novo->right = novo->parent = NULL;
  novo->data = data;
  novo->color = Red; 
	
  return novo; 
}

//função para criação de uma nova arvore 
//toda folha (Nil) é preta 
//t: retorna a arvore criada
red_black_tree* new_red_black_tree(){
  red_black_tree *t = malloc(sizeof(red_black_tree));
  tree_node *nil = malloc(sizeof(tree_node));
  nil->left= nil->right = nil->parent =NULL; 
  nil->color = Black; 
  nil->data = 0;
  t->NIL = nil;
  t->root = t-> NIL;
  return t; 
}

//Cada vez que uma operação for realizada na árvore, o conjunto de propriedades é testado e caso alguma não seja satisfeita, são realizadas rotações ou ajustes de cores, de forma que a árvore permaneça balanceada.

//função para rotação para esquerda/left
void left_rotate(red_black_tree *t,tree_node *x){
  tree_node *y = x->right;    
  x->right = y->left;        
  if(y->left != t->NIL){
	y->left->parent = x;            
  }
  y->parent = x->parent;         
  if(x->parent == t->NIL) {         
	t->root =y;
  }                       
  else if (x==x->parent->left){  
	x->parent->left = y;
  }
  else {                          
	x->parent->right = y;
  }
  y->left = x;                 
  x->parent = y;              
}

//função para rotação para direita/right
void right_rotate(red_black_tree *t, tree_node *x){
  tree_node *y = x->left; 
  x->left = y->right; 
  if(y->right != t->NIL){
	y->right->parent = x; 
  }
  y->parent = x->parent;
  if(x->parent == t->NIL){ 
	t->root = y; 
  }
  else if(x == x->parent->right){ 
	x->parent->right = y;
  }
  else{ 
	x->parent->left = y;
  }
  y->right = x; 
  x->parent = y; 

}

//Um nó é inserido sempre na cor vermelha, assim, não altera a altura negra da árvore. Caso fosse inserido na cor preta, invalidaria a seguinte propriedade: para cada nó, todos os caminhos do nó para folhas descendentes contém o mesmo número de nós PRETOS.

//CASO DE VIOLAÇÃO - INSERÇÃO 
//Pai e Tio Vermelhos
//Irmãos com Cores Diferentes e Pai Vermelho
//Irmãos com Cores Diferentes e Pai Preto
//Cada vez que uma operação for realizada na árvore, o conjunto de propriedades é testado e caso alguma não seja satisfeita, são realizadas rotações ou ajustes de cores, de forma que a árvore permaneça balanceada.

//função de inserção 
void insert(red_black_tree *t, tree_node *z){
  tree_node* y = t->NIL;
  tree_node* temp = t->root;   

  while(temp != t->NIL){       
	y=temp;
	if(z->data < temp->data)  
	temp = temp->left;      
	else
	temp = temp->right;      
  }
  z->parent = y; 

 
  if(y == t->NIL)
  t->root = z;             
  else if (z->data < y->data)
  y->left = z;             
  else
  y->right = z;            

  z->right = z->left = t->NIL;

  insertion_fixup(t,z);  
}

//CASO DE VIOLAÇÃO - INSERÇÃO 
//Pai e Tio Vermelhos
//Irmãos com Cores Diferentes e Pai Vermelho
//Irmãos com Cores Diferentes e Pai Preto
//Cada vez que uma operação for realizada na árvore, o conjunto de propriedades é testado e caso alguma não seja satisfeita, são realizadas rotações ou ajustes de cores, de forma que a árvore permaneça balanceada. 
void insertion_fixup(red_black_tree *t, tree_node *z){
  while (z->parent->color == Red){   //pai vermelho
	if(z->parent == z->parent->parent->left){   
	  tree_node *y= z->parent->parent->right;  

	  if(y->color == Red){ //pai e tio vermelho
		z->parent->color = Black;   
		y->color = Black;        
		z->parent->parent->color = Red;     
		z = z->parent->parent;      
	  }
	  else {
		if(z==z->parent->right){ 
		  z=z->parent;
		  left_rotate (t,z); 
		}

		z->parent->color = Black;  
		z->parent->parent->color = Red; 
		right_rotate(t, z->parent->parent);  
	  }
	}
	else{
	 
	  tree_node *y=z->parent->parent->left;    
	  if(y->color == Red){      
		z->parent->color = Black;   
		y->color = Black;           
		z->parent->parent->color = Red;  
		z=z->parent->parent;            
	  }
	  else {
		if(z==z->parent->left){ 
		  z=z->parent;
		  right_rotate(t,z); 
		}
		z->parent->color = Black; 
		z->parent->parent->color = Red; 
		left_rotate(t, z->parent->parent); 
	  }
	}
  }
  t->root->color = Black;  
}

//rb_transplant: função transplante 
void rb_transplant(red_black_tree *t, tree_node *u, tree_node *v){
  if(u->parent == t->NIL) 
  t->root = v;
  else if(u == u->parent->left) 
  u->parent->left = v;
  else 
  u->parent->right = v;
  v->parent = u->parent;
}

//Localizando o menor valor  
tree_node* minimum(red_black_tree *t, tree_node *x){
  while(x->left != t->NIL)
  x = x->left;
  return x;
}

//A remoção de um nó vermelho não pode violar as regras de uma árvore rubro-negra 
//A remoção de um nó preto certamente causará uma violação preta do mesmo modo que a inserção de um nó preto causaria
//CASO DE VIOLAÇÃO - REMOÇÃO
//Nó Removido Preto com Filho Vermelho
//Nó Removido Irmão Preto e Sobrinho Preto
//Nó Removido Irmão Preto e Sobrinho(s) Vermelho(s)
//Cada vez que uma operação for realizada na árvore, o conjunto de propriedades é testado e caso alguma não seja satisfeita, são realizadas rotações ou ajustes de cores, de forma que a árvore permaneça balanceada. 
// Função de remoção
void rb_delete(red_black_tree *t, tree_node *z){
  tree_node *y = z; 
  tree_node *x;
  enum COLOR y_orignal_color = y->color;

  if(z->left == t->NIL){ 
	x = z->right;
	rb_transplant(t, z, z->right);
  }
  else if(z->right == t->NIL){ 
	x = z->left;
	rb_transplant(t, z, z->left);
  }
  else{ 
	y = minimum(t, z->right); 
	y_orignal_color = y->color;
	x = y->right; 
	if(y->parent == z){ 
	  x->parent = z;
	}
	else{ 
	  rb_transplant(t, y, y->right);
	  y->right = z->right; 
	  y->right->parent = y;
	}
	rb_transplant(t, z, y); 
	y->left = z->left; 
	y->left->parent = y;
	y->color = z->color; 
  }
  if(y_orignal_color == Black) 
  rb_delete_fixup(t, x);
}

// Função para corrigir as cores originais 
void rb_delete_fixup(red_black_tree *t, tree_node *x){
  while(x != t->root && x->color == Black){
	if(x == x->parent->left){ 
	  tree_node *w = x->parent->right; 
	  if(w->color == Red){ 
		w->color = Black;
		x->parent->color = Red; 
		left_rotate(t, x->parent); 
		w = x->parent->right; 
	  }
	  if(w->left->color == Black && w->right->color == Black){ 
		w->color = Red; 
		x = x->parent; 
	  }
	  else{
		if(w->right->color == Black){ 
		  w->left->color = Black; 
		  w->color = Red;
		  right_rotate(t, w); 
		  w = x->parent->right; 
		}
		
		w->color = x->parent->color; 
		x->parent->color = Black; 
		w->right->color = Black; 
		left_rotate(t, x->parent); 
		x = t->root; 
	  }
	}
	else{ 
	  tree_node *w = x->parent->left; 
	  if(w->color == Red){ 
		w->color = Black;
		x->parent->color = Red; 
		right_rotate(t, x->parent); 
		w = x->parent->left; 
	  }
	  if(w->right->color == Black && w->left->color == Black){ 
		w->color = Red; 
		x = x->parent; 
	  }
	  else{
		if(w->left->color == Black){ 
		  w->right->color = Black;
		  w->color = Red;
		  left_rotate(t, w); 
		  w = x->parent->left; 
		}
		
		w->color = x->parent->color; 
		x->parent->color = Black; 
		w->left->color = Black; 
		right_rotate(t, x->parent); 
		x = t->root; 
	  }
	}
  }
  x->color = Black; 
}

//Organiza a àrvore 
void inorder(red_black_tree *t, tree_node *n){
  if(n != t->NIL){
	inorder(t, n->left);

	printf(" %d  \t", n->data);
	inorder(t, n->right);

  }
}

//busca o nó
tree_node *search(red_black_tree* t, int valor) {
	tree_node* z = NULL;
	tree_node* ref = t->root;
	while (ref != t->NIL){
		if (ref->data == valor) {
			z = ref;
		}

		if (ref->data <= valor) {
			ref = ref->right;
		} else {
			ref = ref->left;
		}
	}
	return z;
}


//Delete
//encontra o valor e exclui ou caso seja NULL retorna a informação que o valor informado não foi encontrado na lista
void menu_delete(red_black_tree *t) {
	int del;

	printf("Digite o valor a ser excluido: ");
	scanf("%d", &del);
	tree_node* z = search(t,del);
	if(z == NULL) {
		printf("O valor informado não está na lista, tente novamente.");
		return;
	}
	rb_delete(t, z);
}

//As operações Inserir e Remover são mais complicadas nas Árvores Rubro-Negras porque elas podem ferir alguma propriedade deste tipo de árvore.
//é necessario usar a RedBlackTree.c e a RedBlackTree.h
//gcc RedBlackTree.c RedBlackTree.h -o RedBlackTree
//./RedBlackTree