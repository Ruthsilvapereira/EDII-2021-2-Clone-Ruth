//Definição
//O método da bissecção, que é alternativamente chamado de truncamento binário, divisão da metade, ou método Bolzano
//É um método incremental no qual o intervalo é sempre dividido na metade.
//Se uma função muda de sinal em um intervalo, calcula-se o valor da função em seu ponto médio
//A posição da raíz é então determinada como sendo o ponto médio do subintervalo no qual a mudança de sinal ocorre

//Solução adotada
//PASSO 1: Escolha as aproximações inferior Xl e superior Xu , para a raiz de modo que a função mude o sinal no intervalo. Isso pode ser verificado garantindo que: f(Xl )f(Xu )<0
//PASSO 2: Uma estimativa de raiz é determinada por: Xr=(Xl+Xu)/2
//PASSO 3: Cálculos
//Quando f(Xl)*f(Xr)<0, a raiz está no subintervalo inferior. Portanto, faça Xu = Xr e volte ao passo 2.
//Quando f(Xl)*f(Xr)>0, a raiz está no subintervalo superior. Portanto, faça Xl = Xr e volte ao passo 2.
//Quando f(Xl)*f(Xr)=0, a raiz é igual a Xr ; Pare os cálculos.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float EquaDif(float var){
    float res;
    res=(pow(M_E,-0.005*var)*cos(sqrt(2000-0.01*pow(var,2))*(0.05)))-0.01; // Equacao Diferencial Ordinaria do problema sugerido
    return res;//Retorna o valor substituido na equacao.
}
float bissec(float Xl,float Xu, float precisao){
    float Xr,fa,fb,fc,erro;
    fa=EquaDif(Xl);
    fb=EquaDif(Xu);
    int contIter=0;
    while(fabs(Xu-Xl)>precisao){//Realizada o calculo do erro de aproximacao a cada iteracao.
        Xr=(Xl+Xu)/2;//Encontra o ponto medio do intervalo.
        fc=EquaDif(Xr);
        if(fa*fc<0){//Quando f(Xl)*f(Xr)<0 , a raiz está no subintervalo inferior. Portanto, faça Xu = Xr
            Xu=Xr;
            fb=fc;//O intervalo e atualizado
        }
        else{
            Xl=Xr;//Quando f(Xl)*f(Xr)>0, a raiz está no subintervalo superior. Portanto, faça Xl = Xr
            fa=fc;//O intervalo e atualizado
        }
        contIter++;//Contador de iteracoes necessarias ate a precisao de calcula desejada.
        printf("\n\n\t");
        printf( "iteracao = %d\n", contIter);
        printf( "A = %.20f\nB = %.20f\n", Xl, Xu );//Valores dos intervalos a cada iteracao.
        erro = Xl - Xu;//Calcula o erro da iteracao corrente.
        if (erro < 0)
            erro = erro*-1;
        printf("Erro = %.20f\n", erro);//Imprime o erro da iteracao corrente.
    }
    Xr=(Xl+Xu)/2; //O laço do while se rompe e realiza-se a ultima iteracao.
    erro = Xl - Xu;//Calcula o erro da iteracao final.
    if (erro < 0)
        erro = erro*-1;
    printf("\n\tO erro da ultima iteracao foi de %.20f\n", erro);
    return Xr;//Retorna o valor de Xr.
}
int main()
{
    float a,b,result,precisao;
    int opc;
    while (1)
    {
        printf(" \n::::::::::::::::::::: METODO DA BISSECCAO :::::::::::::::::::::\n\n\n");
        printf("  \t[1] - INSERIR INTERVALO PARA TESTE\n\n");
        printf("  \t[0] - SAIR\n\n");
        printf("\n\n::::::Entre com uma opcao >>>> ");
        scanf ("%d",&opc);
        if (!opc) break;
        switch(opc)
        {
            case 1:
                printf("\n\tEntre com o primeiro numero do intervalo: ");
                scanf("%f",&a);
                printf("\n\tEntre com o segundo numero do intervalo: ");
                scanf("%f",&b);
                printf("\n\tEntre com a precisao desejada: ");
                scanf("%f",&precisao);
                if(EquaDif(a)*EquaDif(b)>0){//Verifica se o intervalo solicitado existe raiz valida.
                    printf("\n\tPara este intervalo nao existe raiz valida. Entre com um novo intervalo.  \n\n");
                    printf("\n\tEntre com o primeiro numero do intervalo: ");
                    scanf("%f",&a);
                    printf("\n\tEntre com o segundo numero do intervalo: ");
                    scanf("%f",&b);
                }
                result=bissec(a,b,precisao);//Resultado aproximado do problema.
                printf("\n\tRaiz aproximada = %.3f\n",result);
                break;
            case 0:
                break;
            default:
                printf("\n\n Opcao invalida!!!\n\n");
                break;
        }
    }
    printf("\n\n ******** Programa finalizado pelo usuario!!! ********\n\n\n");
    return 0;
}
