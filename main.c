#include <stdio.h>
#include <stdlib.h>

int cuadrante(int,int);
int puntaje(int,int,int,int,int);

int main()
{
    int participante,disp,x,y,lugardet,c1=0,c2=0,c3=0,c4=0,c0=0,punt=0,totalcentro=0;
    int primero=1,ganador,nganador;

    printf("Ingrese numero de participante: ");
    scanf("%d",&participante);

    while(participante>=0)
    {
        for(disp=1;disp<=5;disp++)
        {
            printf("Ingrese cordenada X: ");
            scanf("%d",&x);
            fflush(stdin);

            printf("Ingrese cordenada Y: ");
            scanf("%d",&y);
            fflush(stdin);
            printf("\n");

        lugardet=cuadrante(x,y);
        if(lugardet==1)
            c1++;
        if(lugardet==2)
            c2++;
        if(lugardet==3)
            c3++;
        if(lugardet==4)
            c4++;
        if(lugardet==0)
        {
            c0++;
            totalcentro++;
        }
        if(lugardet==-1)
        {
            printf("Error tiro en el eje. Vuelva a ingresar: \n");

            printf("Ingrese cordenada X: ");
            scanf("%d",&x);
            fflush(stdin);

            printf("Ingrese cordenada Y: ");
            scanf("%d",&y);
            fflush(stdin);
            printf("\n");
        }

        punt=puntaje(c1,c2,c3,c4,c0);
        }

        printf("El participante %d hizo: \n",participante);
        printf("Disparos en el primer cuadrante: %d\n",c1);
        printf("Disparos en el segundo cuadrante: %d\n",c2);
        printf("Disparos en el tercer cuadrante: %d\n",c3);
        printf("Disparos en el cuarto cuadrante: %d\n",c4);
        printf("Disparos en el centro: %d\n",c0);

        printf("El puntaje es de: %d\n",punt);

        c1=0;
        c2=0;
        c3=0;
        c4=0;
        c0=0;

        if(primero==1||punt>ganador)
        {
            ganador=punt;
            nganador=participante;
            primero=0;
        }

    printf("Ingrese numero de participante: ");
    scanf("%d",&participante);
    }
    printf("El total de tiros al centro de todos los participantes es de: %d\n",totalcentro);
    if(primero==0)
    {
        printf("El ganador es: %d con puntaje de: %d\n",nganador,punt);
    }


    return 0;
}
int cuadrante(int a,int b)
{
    int cuadrante;

    if(a>0&&b>0)
        {
            cuadrante=1;
        }
    if(a<0&&b>0)
        {
            cuadrante=2;
        }
    if(a<0&&b<0)
        {
            cuadrante=3;

        }
    if(a>0&&b<0)
        {
            cuadrante=4;
        }
    if(a==0&&b==0)
        {
            cuadrante=0;
        }
    if(a==0&&b!=0||a!=0&&b==0)
        {
            cuadrante=-1;
        }

    return cuadrante;
};
int puntaje(int a,int b,int c,int d,int e)
{
    int puntaje=0;

    puntaje=a*50+b*50+c*40+d*40+e*100;

    return puntaje;
};
