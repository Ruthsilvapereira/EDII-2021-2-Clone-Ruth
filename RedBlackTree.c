#include "RedBlackTree.h"

//função para criação de um novo nó by Katia
tree_node* new_tree_node(int data){
  tree_node *n = malloc(sizeof(tree_node));
  n->left = n->right = n->parent = NULL;
  n->data = data;
  n->color = Red;  //o nó sempre será vermelho

  return n; //retorna o nó criado
}

//função para criação de uma nova arvore by Katia
red_black_tree* new_red_black_tree(){
  red_black_tree *t = malloc(sizeof(red_black_tree));
  tree_node *nil = malloc(sizeof(tree_node));
  nil->left= nil->right = nil->parent =NULL; //não tem nada após o nil
  nil->color = Black; // e ele é sempre preto
  nil->data = 0;
  t->NIL = nil;
  t->root = t-> NIL;
  return t; //retorna a arvore criada
}

//função para rotação para esquerda by Katia
void left_rotate(red_black_tree *t,tree_node *x){
  tree_node *y = x->right;    //y recebe o filho direito de x
  x->right = y->left;        //o filho esquerdo de y, será o filho direito de x
  if(y->left != t->NIL){
    y->left->parent = x;            //mudança do pai de x
  }
  y->parent = x->parent;         //mudança de pai de y
  if(x->parent == t->NIL) {         //se x é raiz
    t->root =y;
  }                       //a raiz se recebe o filho direito de x
  else if (x==x->parent->left){  // x é o filho esquerdo
    x->parent->left = y;
  }
  else {                          // x é o  filho direito
    x->parent->right = y;
  }
  y->left = x;                 //x se torna filho esquerdo de y
  x->parent = y;              // y se torna pai de x
}

//função para rotação para direita
void right_rotate(red_black_tree *t, tree_node *x){
  tree_node *y = x->left; // y recebe o filho esquerdo de x
  x->left = y->right; // o filho direito de y, será o filho esquerdo de x
  if(y->right != t->NIL){
    y->right->parent = x; // mudança do pai de x
  }
  y->parent = x->parent;
  if(x->parent == t->NIL){ // se x é a raiz
    t->root = y; // a raiz recebe o filho esquerdo de x
  }
  else if(x == x->parent->right){ // se x é o filho direito
    x->parent->right = y;
  }
  else{ // se x é o filho esquerdo
    x->parent->left = y;
  }
  y->right = x; // x se torna o filho direito de y
  x->parent = y; // y se torna pai de x

}


void insertion_fixup(red_black_tree *t, tree_node *z){
  while (z->parent->color == Red){   //correção se o pai do nó estiver rubro
    if(z->parent == z->parent->parent->left){   //para quando o pai de z é o filho esquerdo
      tree_node *y= z->parent->parent->right;  //tio de z

      if(y->color == Red){ //caso1: pai e tio são rubros
        z->parent->color = Black;   //pai se torna preto
        y->color = Black;        //tio se torna preto
        z->parent->parent->color = Red;     // avô se torna rubro
        z = z->parent->parent;      // z aponta para o avô para verificação de coloração
      }
      else {
        if(z==z->parent->right){ //caso 2 : tio do nó é preto e o nó é filho direito
          z=z->parent;
          left_rotate (t,z); //rotação para tornar um caso 2 em caso 3
        }

        //caso 3: tio do nó é preto e o nó é filho esquerdo
        z->parent->color = Black;  //faz o nó  pai preto
        z->parent->parent->color = Red; //faz nó-avô rubro
        right_rotate(t, z->parent->parent);  //faz a rotação para direita para correção
      }
    }
    else{
      //para quando o pai do z é o filho direito
      tree_node *y=z->parent->parent->left;     //tio de z
      if(y->color == Red){      //caso 1: pai e tio são rubros
        z->parent->color = Black;    //pai se torna preto
        y->color = Black;           //tio se torna preto
        z->parent->parent->color = Red;  //avô se torna rubro
        z=z->parent->parent;            //aponta para o avô para verificação de coloração
      }
      else {
        if(z==z->parent->left){ //caso 2 : tio do nó é preto e o nó é filho esquerdo
          z=z->parent;
          right_rotate(t,z); //rotação para tornar um caso 2 em caso 3
        }
        z->parent->color = Black; // faz pais negros
        z->parent->parent->color = Red; //faz avôs rubros
        left_rotate(t, z->parent->parent); //faz a rotação para esquerda para correção
      }
    }
  }
  t->root->color = Black;  //raiz se torna preta, pois pode ter se transformado em vermelha no caso 1
}

//função de inserção by Katia
void insert(red_black_tree *t, tree_node *z){
  tree_node* y = t->NIL;
  tree_node* temp = t->root;   //váriavel temporária

  while(temp != t->NIL){       //começa na raiz e vai até encontrar NIL
    y=temp;
    if(z->data < temp->data)  //o nó da arvore < dado que deseja ser inserido
    temp = temp->left;      //insere a esquerda
    else
    temp = temp->right;       //ou a direita, caso seja maior
  }
  z->parent = y; //no caso da arvore não ter nó, o novo nó será a raiz;

  //se tiver nó, ele estará apontado para o último nó
  if(y == t->NIL)
  t->root = z;             //se nulo, o novo nó será a raiz
  else if (z->data < y->data)
  y->left = z;             //se < que o dado existe, vai para esquerda
  else
  y->right = z;            //se > , direita

  //atribuição de NIL para nós sem filhos
  z->right = z->left = t->NIL;

  insertion_fixup(t,z);  //para verificação das regras da coloração
}



// Função de transplante by Mariana
void rb_transplant(red_black_tree *t, tree_node *u, tree_node *v){
  if(u->parent == t->NIL) // se u é a raiz da árvore
  t->root = v;
  else if(u == u->parent->left) // se u é o filho da esquerda
  u->parent->left = v;
  else // se u é o filho da direita
  u->parent->right = v;
  v->parent = u->parent;
}

// Função para encontrar o menor elemento by Mariana
tree_node* minimum(red_black_tree *t, tree_node *x){
  while(x->left != t->NIL)
  x = x->left;
  return x;
}

// Função de deletar by Mariana
void rb_delete(red_black_tree *t, tree_node *z){
  tree_node *y = z; //guarda a cor original de y
  tree_node *x;
  enum COLOR y_orignal_color = y->color;

  if(z->left == t->NIL){ //se for sem filhos ou tiver filhos só na direita
    x = z->right;
    rb_transplant(t, z, z->right);
  }
  else if(z->right == t->NIL){ // se só tem filho na esquerda
    x = z->left;
    rb_transplant(t, z, z->left);
  }
  else{ //se tem filhos para os dois lados
    y = minimum(t, z->right); // marca o menor elemento do galho direito de z
    y_orignal_color = y->color;
    x = y->right; // guarda o filho direito de y
    if(y->parent == z){ // se y é um filho direto de z
      x->parent = z;
    }
    else{ // se não for filho direto
      rb_transplant(t, y, y->right);
      y->right = z->right; // então a direita de y recebe a direita de z
      y->right->parent = y;
    }
    rb_transplant(t, z, y); // neste ponto o y já pode ser transplantado para z
    y->left = z->left; // passa a esquerda de z para a esquerda de y
    y->left->parent = y;
    y->color = z->color; // y recebe a cor de z
  }
  if(y_orignal_color == Black) // conserta a violação se a cor original de y for preto
  rb_delete_fixup(t, x);
}

// Função para corrigir as cores originais by Mariana
// Cada nó deve ser preto ou vermelho, se isso for diferente é porque o nó x agora é "duplo preto" (se fosse preto), ou vermelho e preto (se fosse vermelho )
void rb_delete_fixup(red_black_tree *t, tree_node *x){
  while(x != t->root && x->color == Black){
    if(x == x->parent->left){ // se for irmão da direita
      tree_node *w = x->parent->right; // w é irmão da direita de x
      if(w->color == Red){ // se w é vermelho
        w->color = Black;
        x->parent->color = Red; // troca as cores de w e seu pai
        left_rotate(t, x->parent); // gira para a esquerda o pai de x, trocando as cores de w e x
        w = x->parent->right; // por ter rotacionado, é criado um novo irmão da direita
      }
      if(w->left->color == Black && w->right->color == Black){ // se w é preto e seus filhos também
        w->color = Red; // transforma o w em vermelho
        x = x->parent; // coloca um preto extra no pai de x e marca como novo x
      }
      else{
        if(w->right->color == Black){ // se w é preto, e o filho da direita é preto e o filho da esquerda é vermelho
          w->left->color = Black; // troca as cores de w e seu filho esquerdo
          w->color = Red;
          right_rotate(t, w); // gira w para a direita.
          w = x->parent->right; // w é o novo irmão da direita
        }
        // se w é preto e o filho da direita é vermelho
        w->color = x->parent->color; // w recebe a mesma cor que o pai de x
        x->parent->color = Black; // colore o pai de x de preto
        w->right->color = Black; //colore o filho direito de w de preto
        left_rotate(t, x->parent); // gira o pai de x para a esquerda
        x = t->root; // remove o preto extra de x
      }
    }
    else{ // se for irmão da esquerda
      tree_node *w = x->parent->left; // w é irmão da esquerda de x
      if(w->color == Red){ // se w é vermelho
        w->color = Black;
        x->parent->color = Red; // troca as cores de w e seu pai
        right_rotate(t, x->parent); // gira para a direita o pai de x, trocando as cores de w e x
        w = x->parent->left; // por ter rotacionado, é criado um novo irmão da esquerda
      }
      if(w->right->color == Black && w->left->color == Black){ // se w é preto e seus filhos também
        w->color = Red; // transforma o w em vermelho
        x = x->parent; // coloca um preto extra no pai de x e marca como novo x
      }
      else{
        if(w->left->color == Black){ // se w é preto, e o filho da esquerda é preto e o filho da direita é vermelho
          w->right->color = Black;// troca as cores de w e seu filho direito
          w->color = Red;
          left_rotate(t, w); // gira w para a esquerda.
          w = x->parent->left; // w é o novo irmão da esquerda
        }
        // se w é preto e o filho da esquerda é vermelho
        w->color = x->parent->color; // w recebe a mesma cor que o pai de x
        x->parent->color = Black; // colore o pai de x de preto
        w->left->color = Black; //colore o filho esquerdo de w de preto
        right_rotate(t, x->parent); // gira o pai de x para a direita
        x = t->root; // remove o preto extra de x
      }
    }
  }
  x->color = Black; // cor de x recebe preto
}

// Função para ordenar a árvore by Mariana
void inorder(red_black_tree *t, tree_node *n){
  if(n != t->NIL){
    inorder(t, n->left);

    printf(" %d  \t", n->data);
    inorder(t, n->right);

  }
}

//Função utilitária para recuperar o nó pelo seu valor
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

//Função para a ação de inserir do menu
void menu_insert(red_black_tree *t){
  int add;

  printf("Inserir o valor: ");
  scanf("%d",&add);
  tree_node* z = new_tree_node(add);
  insert(t,z);
}

//Função para a ação de deletar do menu
void menu_delete(red_black_tree *t) {
    int del;

    printf("Qual valor voce deseja deletar?");
    scanf("%d", &del);
    tree_node* z = search(t,del);
    if(z == NULL) {
        printf("O valor não está na lista!");
        return;
    }
    rb_delete(t, z);
}

int main (){
  red_black_tree *t = new_red_black_tree();
  int continuar;

  do
  {
    printf("\n\tOpcoes:\n\n");
    printf("0. Sair\n");
    printf("1. Inserir\n");
    printf("2. Deletar\n");
    printf("3. Listar\n");

    scanf("%d", &continuar);
    system("cls || clear");

    switch(continuar)
    {
      case 1:
      menu_insert(t);
      break;

      case 2:
      menu_delete(t);
      break;

      case 3:
      inorder(t, t->root);
      break;

      case 0:
      break;

      default:
      printf("Digite uma opcao valida\n");
    }
    /*system ("pause");
    system("cls || clear");*/
  } while(continuar);

  return 0;
}
