#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include <string.h>
#include<windows.h>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "menu.h"
#include "resolver.h"


bool switch_jugadores(int opcion, bool* si_no, char *nombre, int *punto)
{
    switch (opcion)
    {
    case 1:
        system("cls");
        int jugadores;
        cout<<"\t Cantidad de jugadores 1/2" << endl<< "\t\t\t\t";
        cin>> jugadores;
        Beep(523,500);
        switch (jugadores)
        {
        case 1:
            system("cls");
            jugar1(nombre, punto);
            *si_no=true;//opcion 3 visible
            system("cls");
            break;
        case 2:
            system("cls");
            jugar2(nombre, punto);
            *si_no=true;//opcion 3 visible
            system("cls");
            break;
        default:
            system("cls");
            cout << endl << "\t Opcion incorrecta"<<endl;
            system("pause");
            system("cls");
            break;
        }
        break;
    case 2:
        reglas();
        break;
    case 3:
        system("cls");
        if (*si_no==true)
        {
            cout<<"\t El Jugador con Mayor Puntaje "<< nombre;
            cout<<endl<<"\t Cantidad de puntos "<< *punto;
            cout<<endl<<endl;
        }
        else
        {
            cout<<"\t Tiene que jugar para poder ver esta opcion"<<endl;
            cout<<endl<<endl;
        }
        system("pause");
        system("cls");
        break;
    case 4:
        return false;
        break;
    default:
        system("cls");
        cout <<endl<< "\t Opcion incorrecta"<<endl<<endl;
        system("pause");
        system("cls");
        break;
    }
    return true;
}

void enVerdadero(bool jugadas [], int t)
{
    int x;
    for(x=0; x<t; x++)
    {
        jugadas[x]=true;
    }
}

void tirarDados(int dados [], int t)
{
    int x;
    bool azar=false;
    if (azar==false)
    {
        srand(time(NULL));
        for(x=0; x<t; x++ )
        {
            dados[x]=(rand()%6)+1;
        }
    }
    else
    {
        cout<<endl<<"dado 1 ";
        cin>>dados[0];
        cout<<endl<<"dado 2 ";
        cin>>dados[1];
        cout<<endl<<"dado 3 ";
        cin>>dados[2];
        cout<<endl<<"dado 4 ";
        cin>>dados[3];
        cout<<endl<<"dado 5 ";
        cin>>dados[4];
    }
}

void mostrarDados(int dados[], int t)
{
   /* int x;
    cout <<endl<< "\t dados \t";
    for (x=0; x<t; x++)
    {
        cout <<" "<< dados[x];
    }*/
    int nroDado=1;
    for(int xp=0;xp<5;xp++){
    int valor=dados[nroDado-1];
    const int Y = 5;
    const int ALTO = 4;
    const int INI = 15;
    const int X = INI + (nroDado * 10);
    const int ANCHO = 8;

    /// Ubicaciones del punto
    const int CENTRO_X = X + ANCHO/2;
    const int CENTRO_Y = Y + ALTO/2;
    const int IZQUIERDA = CENTRO_X - 2;
    const int ARRIBA = CENTRO_Y - 1;
    const int DERECHA= CENTRO_X + 2;
    const int ABAJO= CENTRO_Y + 1;

    /// Reemplazar éstos códigos por los de Windows para correr en Windows.
    const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
    const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
    const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
    const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐
    const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─
    const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │


    /// Borramos el espacio del recuadro
    int i, j;
    for(i=X; i<=X+ANCHO; i++){
        for(j=Y; j<=Y+ALTO; j++){
            setBackgroundColor(RED);
            locate(i, j);
            cout << " ";

        }
    }
    setColor(WHITE);
    /// Líneas horizontales
    for(i=X; i<=X+ANCHO; i++){
        locate(i, Y);
        cout << UI_HORIZONTAL_LINE;
        locate(i, Y+ALTO);
        cout << UI_HORIZONTAL_LINE;
    }
    /// Líneas verticales
    for(i=Y; i<=Y+ALTO; i++){
        locate(X, i);
        cout << UI_VERTICAL_LINE;
        locate(X+ANCHO, i);
        cout << UI_VERTICAL_LINE;
    }
    /// Vértices
    locate(X, Y);
    cout << UI_TOP_LEFT;
    locate(X, Y+ALTO);
    cout << UI_BOTTOM_LEFT;
    locate(X+ANCHO, Y);
    cout << UI_TOP_RIGHT;
    locate(X+ANCHO, Y+ALTO);
    cout << UI_BOTTOM_RIGHT;

    /// Dibujar los puntos
    const char *DOT = "o";

    setBackgroundColor(RED);
    setColor(WHITE);
    switch(valor){
        case 1:
            locate(CENTRO_X, CENTRO_Y);
            cout << DOT;
        break;
        case 2:
            if (nroDado%2 == 0){
                locate(IZQUIERDA, ARRIBA);
                cout << DOT;
                locate(DERECHA, ABAJO);
                cout << DOT;
            }
            else{
                locate(DERECHA, ARRIBA);
                cout << DOT;
                locate(IZQUIERDA, ABAJO);
                cout << DOT;
            }
        break;
        case 3:
            if (nroDado%2 == 0){
                locate(IZQUIERDA, ARRIBA);
                cout << DOT;
                locate(DERECHA, ABAJO);
                cout << DOT;
            }
            else{
                locate(DERECHA, ARRIBA);
                cout << DOT;
                locate(IZQUIERDA, ABAJO);
                cout << DOT;
            }
            locate(CENTRO_X, CENTRO_Y);
            cout << DOT;
        break;
        case 4:
            locate(IZQUIERDA, ARRIBA);
            cout << DOT;
            locate(DERECHA, ABAJO);
            cout << DOT;
            locate(DERECHA, ARRIBA);
            cout << DOT;
            locate(IZQUIERDA, ABAJO);
            cout << DOT;
        break;
        case 5:
            locate(IZQUIERDA, ARRIBA);
            cout << DOT;
            locate(DERECHA, ABAJO);
            cout << DOT;
            locate(DERECHA, ARRIBA);
            cout << DOT;
            locate(IZQUIERDA, ABAJO);
            cout << DOT;
            locate(CENTRO_X, CENTRO_Y);
            cout << DOT;
        break;
        case 6:
            locate(IZQUIERDA, ARRIBA);
            cout << DOT;
            locate(DERECHA, ABAJO);
            cout << DOT;
            locate(DERECHA, ARRIBA);
            cout << DOT;
            locate(IZQUIERDA, ABAJO);
            cout << DOT;
            locate(DERECHA, CENTRO_Y);
            cout << DOT;
            locate(IZQUIERDA, CENTRO_Y);
            cout << DOT;
        break;
    }
    nroDado++;
    }
}

int sumarPuntos(int dados [],int t1,bool jugadas1 [],int t2)
{
    int jugadas [10]= {};
    int x, y;
    int puntos=0;
    // 1 al 6
    for (x=0; x<6; x++)
    {
        if (jugadas1[x]==true)
        {
            for (y=0; y<t1; y++)
            {
                if (dados[y]==x+1)
                {
                    jugadas[x]+=dados[y];
                }
            }
        }
    }
    //ordenamos
    int posmin, aux;
    for(x=0; x<5; x++)
    {
        posmin=x;
        for(y=x+1; y<5; y++)
        {
            if(dados[y]<dados[posmin])
                posmin=y;
        }
        aux=dados[x];
        dados[x]=dados[posmin];
        dados[posmin]=aux;

    }

    //escalera
    int escalera=dados[0],cont=0;
    for(x=0; x<t1; x++)
    {
        if (escalera<dados[x])
        {
            escalera=dados[x];
            cont++;
        }
    }

    if (cont==4 && jugadas1[6]==true)
    {
        jugadas[6]= 25;
    }
    //numero mayor
    int posMax=1;
    for (x=0; x<t1; x++)
    {
        if(dados[x]>dados[posMax])
        {
            posMax=x;
        }
    }
    //numero menor
    int posMin=1;
    for (x=0; x<t1; x++)
    {
        if(dados[x]<dados[posMin])
        {
            posMin=x;
        }
    }
    //cantidad de repetidos mayor
    int repmay=0;
    for (x=0; x<t1; x++)
    {
        if(dados[x]==dados[posMax])
        {
            repmay++;
        }
    }
    //cantidad de repeitdos menor
    int repmin=0;
    for (x=0; x<t1; x++)
    {
        if(dados[x]==dados[posMin])
        {
            repmin++;
        }
    }
    //full
    if (((repmin==3 && repmay==2) || (repmin==2 && repmay==3)) && (jugadas1[7]==true))
    {
        jugadas[7]=30;
    }
    //poker
    if ((repmin==4|| repmay==4) && (jugadas1[8]==true))
    {
        jugadas[8]=40;
    }
    //generala
    if ((repmin==5 || repmay==5) && (jugadas1[9]==true))
    {
        jugadas[9]=50;
    }
    //buscamos el mayor puntaje
    int maximo=0;
    for(x=0; x<t2; x++)
    {
        if(jugadas[x]>jugadas[maximo])
        {
            maximo=x;
        }
    }
    //puntos total
    puntos+=jugadas[maximo];
    jugadas1[maximo]=false;
    return puntos;
}

void cambiarDados(int dados [],int t1, char nombre[],int y)
{
    int x, nd, nt, h;
    for (h=0; h<2; h++)
    {
        cout <<endl<<endl<< "\t cuantos dados quiere cambiar \t";
        cin >> nt;
        Beep(523,500);
        if (nt==0)//si no quiere cambiar dados return
        {
            return;
        }
        int vec[5]= {0};
        for (x=0; x<nt; x++)
        {
            cout<<"\t numero de dado que quiere cambiar \t";
            cin >> nd;
            Beep(523,500);
            if((validar(nd,vec,5))==false)//validacion
                nd=6;
            switch (nd)
            {
            case 1:
                srand (time(NULL));
                dados[0]=(rand()%6)+1;
                break;
            case 2:
                srand (time(NULL));
                dados[1]=(rand()%6)+1;
                break;
            case 3:
                srand (time(NULL));
                dados[2]=(rand()%6)+1;
                break;
            case 4:
                dados[3]=(rand()%6)+1;
                break;
            case 5:
                srand (time(NULL));
                dados[4]=(rand()%6)+1;
                break;
            default:
                cout <<endl<<"\t\t opcion incorrecta, intentelo nuevamente" <<endl<<endl;
                x--;
                break;
            }
        }
        system("cls");
        cout<<endl<<"\t jugador "<<nombre<<endl;
        cout<<"\t Ronda "<<y+1<<" "<<endl;
        mostrarDados(dados, t1);
        locate(22, 9);
    }
}

bool validar(int ingreso,int *vec, int tam)
{
    if(ingreso>5 || ingreso<1)
        return false;
    for(int i=0; i<tam; i++)
    {
        if(vec[i]==0)
        {
            vec[i]=ingreso;
            return true;
        }
        else if(vec[i]==ingreso)
            return false;
    }
    return false;
}

int ganar(char nombre1 [],char nombre2 [],int puntos1,int puntos2,int *punto,char nombre [])
{
    if (puntos1>puntos2)
    {
        cout<<endl<<"\t El Ganador es "<<nombre1<<endl;
        cout<<endl<<"\t\t Sus puntos son "<<puntos1;
        cout<<endl<<endl<<"\t El segundo lugar "<<nombre2<<endl;
        cout<<endl<<"\t\t Sus puntos son "<<puntos2<<endl<<endl;
        //maxima puntuacion
        if (puntos1>*punto)
        {
            strncpy(nombre, nombre1, 25);
            return puntos1;
        }
    }
    else
    {
        if(puntos1<puntos2)
        {
            cout<<endl<<"\t El ganador es "<<nombre2<<endl;
            cout<<endl<<"\t Sus puntos son "<<puntos2;
            cout<<endl<<endl<<"\t El segundo lugar "<<nombre1<<endl;
            cout<<endl<<"\t\t Sus puntos son "<<puntos1<<endl<<endl;
            //maxima puntuacion
            if (puntos2>*punto)
            {
                strncpy(nombre, nombre2, 25);
                return puntos2;
            }
        }
        else
        {
            cout<<endl<<"\t Empataron "<<endl;
            cout<<endl<<"\t con un total de puntos "<<puntos1<<endl<<endl;
        }
    }
    return *punto;
}

