//Árvore Rubro-Negra = RedBlackTree
//Alunas: Ruth e Zhaira
//Atividade 7: Trabalho Final

//Implementação em Dupla de trabalho valendo 40% da nota final que envolve o estudo e implementação sobre:
//Árvore Rubro-negra
//Apenas uma dupla pode desenvolver sobre um determinado tópico
//ou seja, duas duplas não podem realizar trabalho sobre o mesmo assunto. 
//A entrega deve ocorrer por meio de implementação do código no GitHub e PDF 
//Ser entregue via AVA explicando o trabalho e como testar o exemplo
//Data de entrega: 20 jul 2021, terça-feira

#incluem  "RedBlackTree.h" 

//Interface do Usuário
int principal (){
 red_black_tree * t = new_red_black_tree();
  int continuar;

  fazer
  {
	printf("\n\tDigite 0 para fechar\n\t" );
	printf("Digite 1 para adicionar valores\n\t" );
	printf("Digite 2 para excluir um valor informado\n\t" );
	printf("Digite 3 para visualização\n\n\t" );

	scanf(%d", &continuar);
	sistema("cls || claro" );

	switch(continuar)
	{
	  caso 0:
	  quebrar;

	  padrão:
	  printf("opção invalida, tente novamente\n\n" );

	  caso 1:
	  menu_insert(t);
	  quebrar;

	  caso 2:
	  menu_delete(t);
	  quebrar;

	  caso 3:
	  inordene(t, t-> raiz);
	  quebrar;
	}
  } enquanto(continuar);

  retorno 0;
} 

//Inserção do valor pelo informado usuario
menu_insert vazio (red_black_tree *t){
  int adicionar;

  printf("Digite o valor: " );
  scanf("%d",&add);
 tree_node* z = new_tree_node(adicionar);
  inserir(t,z);
}

//função para criar um novo nó
tree_node* new_tree_node(dadosint){
 tree_node *novo = malloc(tamanho de(tree_node));
 novo->esquerda = novo-> àdireita = novo->pai = NULL;
 dados > novo = dados;
 cor novo-> = Vermelho; 
	
  retorno novo; 
}

//função para criação de um novo arvore 
//toda folha (Nil) é preta 
//t: retorna a arvore criado
new_red_black_tree red_black_tree*(){
 red_black_tree *t = malloc(tamanho (red_black_tree));
 tree_node *nil = malloc(tamanho de(tree_node));
 nil->esquerda= nil->direita =zero-> pai =NULO; 
 cor de > zero = Preto; 
 dados de > zero = 0;
  t->NIL = nil;
 raiz t-> = t-> NIL;
  retorno t; 
}

//Cada vez que uma operação para realizada na árvore, o conjunto de propriedades é testado e caso alguma não seja satisfeita, são realizadas rotações ou ajustes de núcleos, de forma que a árvore permaneça balanceada.
//função para rotação para esquerda/esquerda
left_rotate vazio (red_black_tree *t,tree_node *x){
 tree_node *y = x->à direita;    
 x-> àdireita = y->esquerda;        
  se(y->esquerda != t->NIL){
 y->pai -> esquerda= x; 
  }
 y->pai = x->pai;         
  se(x->pai == t->NIL) {         
 raiz de > t =y;
  }                       
  mais se (x==x->pai->esquerda){  
 x->pai->esquerda = y;
  }
  mais {                          
 x->pai->direito = y;
  }
 y->esquerda = x; 
 x->pai = y; 
}

//função para rotação para direita/direita
right_rotate vazio (red_black_tree *t, tree_node *x){
 tree_node *y = x->esquerda; 
 x->esquerda = y-> àdireita; 
  se(y->direito != t->NIL){
 y->direito->pai = x; 
  }
 y->pai = x->pai;
  se(x->pai == t->NIL){ 
 raiz t-> = y; 
  }
  mais se(x == x->pai->direito){ 
 x->pai->direito = y;
  }
  mais{ 
 x->pai->esquerda = y;
  }
 y->direito = x; 
 x->pai = y; 

}

//Um nó é inserido sempre no cor vermelho, assim, não altera a altura negra da árvore. Caso fosse inserido na cor preta, invalidaria a seguinte propriedade: para cada nó, todos os caminhos do nó para folhas descendentes contém o mesmo número de nós PRETOS.

//CASO DE VIOLAÇÃO - INSERÇÃO 
//Pai e Tio Vermelhos
//Irmãos com Cores Diferentes e Pai Vermelho
//Irmãos com Cores Diferentes e Pai Preto
//Cada vez que uma operação para realizada na árvore, o conjunto de propriedades é testado e caso alguma não seja satisfeita, são realizadas rotações ou ajustes de núcleos, de forma que a árvore permaneça balanceada.

//função de inserção 

 inserçãode vazio (red_black_tree *t, tree_node *z){
  tree_node* y = t->NIL;
 tree_node* temp =raiz t->;   

  enquanto(temp != t->NIL){       
	y=temp;
	> <dados < dados < >)  
 temp = temp->esquerda;      
	mais
 temp = temp->direito;      
  }
 z->pai = y; 

 
  se(y == t->NIL)
 raiz t-> = z; 
  <  dados > > z)
 y->esquerda = z; 
  mais
 y->direito = z; 

 z->direita = z->esquerda = t->NIL;

  insertion_fixup(t,z);  
}

//CASO DE VIOLAÇÃO - INSERÇÃO 
//Pai e Tio Vermelhos
//Irmãos com Cores Diferentes e Pai Vermelho
//Irmãos com Cores Diferentes e Pai Preto
//Cada vez que uma operação para realizada na árvore, o conjunto de propriedades é testado e caso alguma não seja satisfeita, são realizadas rotações ou ajustes de núcleos, de forma que a árvore permaneça balanceada. 

insertion_fixup vazio (red_black_tree *t, tree_node *z){
  enquanto (z->cor > pai == Vermelho){  //pai vermelho
	se(z->pai == z->pai->pai->esquerda){   
 tree_node *y= z->pai->direito pai->;  

	  se(y->cor == Vermelho){  //pai e tio vermelho
 z->cor >pai= Preto; 
 cor y-> = Preto; 
 z->pai->cor -> dospais= vermelho; 
 z = z->pai->pai;      
	  }
	  mais {
		se(z===z->pai->direito){ 
 z=z->pai;
		  left_rotate (t,z); 
		}

 z->cor >pai= Preto; 
 z->pai->cor -> dospais= vermelho; 
		right_rotate(t, pai > z->pai);  
	  }
	}
	mais{
	 
 tree_node *y=z->pai->pai->esquerda;    
	  se(cor y-> == Vermelho){ 
 z->cor >pai= Preto; 
 cor y-> = Preto; 
 z->pai->cor -> dospais= vermelho; 
 z=z->pai->pai;            
	  }
	  mais {
		se(z==z->pai->esquerda){ 
 z=z->pai;
		  right_rotate(t,z); 
		}
 z->cor >pai= Preto; 
 z->pai->cor -> dospais= vermelho; 
		left_rotate(t, pai > z->pai); 
	  }
	}
  }
 t-> cor raiz-> = Preto; 
}

//rb_transplant: função transplante 
rb_transplant vazio (red_black_tree *t, tree_node *u, tree_node *v){
  se(u->pai == t->NIL) 
 raiz t-> = v;
  mais se(u == u->pai->esquerda) 
 u->pai->esquerda = v;
  mais 
 u->pai->direito = v;
 v->pai = u->pai;
}

//Localizando o menor valor  
tree_node* mínimo(red_black_tree *t, tree_node *x){
  enquanto(x->esquerda != t->NIL)
 x = x->esquerda;
  retorno x;
}

//A remoção de um nó vermelho não pode violar as regras de uma árvore rubro-negra 
//A remoção de um nó preto certamente causará uma violação preta do mesmo modo que a inserção de um nó preto causaria
//CASO DE VIOLAÇÃO - REMOÇÃO
//Nó Removido Preto com Filho Vermelho
//Nó Removido Irmão Preto e Sobrinho Preto
//Nó Removido Irmão Preto e Sobrinho(s) Vermelho(s)
//Cada vez que uma operação para realizada na árvore, o conjunto de propriedades é testado e caso alguma não seja satisfeita, são realizadas rotações ou ajustes de núcleos, de forma que a árvore permaneça balanceada. 
// Função de remoção
rb_delete vazio (red_black_tree *t, tree_node *z){
  tree_node *y = z; 
  tree_node *x;
  enum COR y_orignal_color =cor y->;

  se(z->esquerda == t->NIL){ 
 x = z->à direita;
	rb_transplant(t, z, z->direito);
  }
  mais se(z->direito == t->NIL){ 
 x = z->esquerda;
	rb_transplant(t, z, z->esquerda);
  }
  mais{ 
 y = mínimo(t, z->direito); 
 y_orignal_color =cor y->;
 x = y->à direita; 
	se(y->pai == z){ 
 x->pai = z;
	}
	mais{ 
	  rb_transplant(t, y, y->direito);
 y->direito = z->direito; 
 y->direito->pai = y;
	}
	rb_transplant(t, z, y); 
 y->esquerda = z->esquerda; 
 y->pai -> esquerda= y;
 cor y-> =cor z->; 
  }
  se(y_orignal_color == Preto) 
  rb_delete_fixup(t, x);
}

// Função para corrigir como núcleos originais 
rb_delete_fixup vazio (red_black_tree *t, tree_node *x){
  enquanto(x != t->raiz && x->cor == Preto){
	se(x == x->pai->esquerda){ 
 tree_node *w = x->pai->direito; 
	  se(cor w-> == Vermelho){ 
 cor w->= Preto;
 x->cor >pai= vermelho; 
		left_rotate(t,x-> pai); 
 w = x->pai->direito; 
	  }
	  se(w->cor esquerda-> == Preto && w->cor ->direita == Preto){ 
 cor w->= Vermelho; 
 x = x->pai; 
	  }
	  mais{
		se(w->direito->cor == Preto){ 
 w->cor esquerda-> = Preto; 
 cor w->= Vermelho;
		  right_rotate(t, w); 
 w = x->pai->direito; 
		}
		
 cor > w= x-> cor pai->; 
 x->cor >pai= Preto; 
 w->cor > direita= Preto; 
		left_rotate(t,x-> pai); 
 x =raiz t->; 
	  }
	}
	mais{ 
 tree_node *w = x->pai->esquerda; 
	  se(cor w-> == Vermelho){ 
 cor w->= Preto;
 x->cor >pai= vermelho; 
		right_rotate(t,x-> pai); 
 w = x->pai->esquerda; 
	  }
	  se(w-> cor> direita==Preto && w->cor esquerda-> == Preto){ 
 cor w->= Vermelho; 
 x = x->pai; 
	  }
	  mais{
		se(w->à esquerda->cor == Preto){ 
 w->cor > direita= Preto;
 cor w->= Vermelho;
		  left_rotate(t, w); 
 w = x->pai->esquerda; 
		}
		
 cor > w= x-> cor pai->; 
 x->cor >pai= Preto; 
 w->cor esquerda-> = Preto; 
		right_rotate(t,x-> pai); 
 x =raiz t->; 
	  }
	}
  }
 x->cor = Preto; 
}

//Organiza a àrvore 
 inordenaçãode vazio (red_black_tree *t, tree_node *n){
  se(n != t->NIL){
	inordene(t, n->esquerda);

	printf(" %d \t",n-> dados);
	inordene(t, n->direito);

  }
}

//busca o nó
tree_node *pesquisa(red_black_tree* t, int valor) {
	tree_node* z = NULL;
 tree_node* ref =raiz t->;
	enquanto (ref != t->NIL){
		se (dados de > do ref == valor) {
 z = árbitro;
		}

		se (dados ref-> <= valor) {
 ref = direito ref->;
		} mais {
 árbitro = ref->esquerda;
		}
	}
	retorno z;
}


//excluir
//encontrar o valor e exclui ou caso seja NULL retorna a informação de que o valor informado não foi encontrado na lista
menu_delete vazio (red_black_tree *t) {
	int del;

	printf("Digite o valor a ser excluido: " );
	scanf("%d", &del);
 tree_node* z = pesquisa(t,del);
	se(z == NULL) {
		printf("O valor informado não está na lista, tente novamente. " );
		retornar;
	}
	rb_delete(t, z);
}

// =================================================================================================
//As operações Inserir e Removedor são mais complicadas nas Árvores Rubro-Negras porque elas podem ferir alguma propriedade deste tipo de árvore.
//Ao fazer essas operações (Inserir e Removedor) devemos respeitar algumas propriedades:
//1. Todo nó é vermelho ou preto 
//2. A raiz é preta 
//3. Toda folha (Nil) é preta 
//4. Se um nó é vermelho, então os seus filhos são pretos 
//5. Para cada nó, todos os caminhos do nó para folhas descendentes contém o mesmo número de nós PRETOS.
//Teste goormide
//é necessario usar um RedBlackTree.c e um RedBlackTree.h
//gcc RedBlackTree.c RedBlackTree.h -o RedBlackTree
//./RedBlackTree
//Para melhor entendimento, recomendamos ao aluno o simulador online de Árvore Rubro-Negra, disponivel em: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
// ==================================================================================================
