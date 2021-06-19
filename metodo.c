#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main(){

    int opcao = 0 ,k =0 ;
    float x = 0, y = 0, p = 0, M = 0, Fy = 0, Fyy = 0, Fm = 0, aux =0 , aux1=0 , er = 0, e =0.;

 opcao = 0;

 while(opcao != 2){

  printf("\n\n\t\t");
  printf("************\n \n \t");
  printf("MENU DE OPCOES");
  printf("\n\n\t");
  printf("1 - Inserir Chute para o metodo.");
  printf("\n\n\t");
  printf("2 - Sair");
  printf("\n\n\t");
  printf("Escolha Opcao: ");
  scanf("%d", &opcao);

  switch(opcao){

   case 1:{
                    printf("\n\n\t\t");
                    printf("************\n \n \t");
                    printf( "Digite valor de A:" );
                    scanf( "%f", &x );
                    printf("\n\n\t");
                    printf( "Digite valor de B:" );
                    scanf( "%f", &y );
                    printf("\n\n\t");
                    printf( "Digite a precisao desejada:" );
                    scanf( "%f", &p );
                    printf("\n");
                    k=0;

                do{

                    M = ( x + y ) / 2;
                    Fy =  (pow(M_E,-0.005*x)*cos(sqrt(2000-0.01*pow(x,2))*(0.05)))-0.01;
                    Fm = (pow(M_E,-0.005*M)*cos(sqrt(2000-0.01*pow(M,2))*(0.05))) -0.01;
                    Fyy =  (pow(M_E,-0.005*y)*cos(sqrt(2000-0.01*pow(y,2))*(0.05)))-0.01;

                    aux = Fy*Fm ;
                    aux1 = Fyy*Fm ;

                    if ( aux < 0 ){
                        y = M;
                    }
                    else if ( aux1 < 0){
                        x = M;
                    }
                    if (x > 447 || y > 447)
                        break;
                    if (  aux > 0 && aux1 > 0 ){
                        printf("\n\n\t");
                        printf(" Entre as variaveis A e B não possuem raizes  .");
                        break ;
                    }

                    k++;
                    printf("\n\n\t");
                    printf( "iteracao = %d\n", k );
                    printf( "A = %.20f\nB = %.20f\n", x, y );

                } while( y - x >= p || Fy >= p || Fyy >= p  );
                    er = y - x ;
                    e = (y+x)/2;
                    if (er < 0)
                        er = er*-1;

                    printf("\nO erro e  = %.20f\n", er);
                    printf( "A valor de R e: %.20f\n", e );

    break;
   }
            case 2:{

                printf("\n\n\t");
                printf("Voce SAIU com SUCESSO");
                printf("\n\n");

    break;
   }

   default:{

    printf("\n\n\t");
    printf("Opcao INVALIDA");
    printf("\n\n");

   }
  }
 }

}
