/*
A) total venido diariamente (EL HIJO DE PUTA)***
B) total vendido por producto ***
C) Productos mas vendidos ***
D) Menos menos vendido ***
E) Dia del mes en donde el valor total de prodcutos vendidos fue menor***
F) Dia del mes en donde el valor total de prodcutos vendidos fue mayor ***
G) El valor total de las ventas de la compañia***
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main ()
{   
    //Generación de numeros aleatorios de 1 a 10
    srand(time(NULL));
    double num = 1 + rand() % (11 - 1);

    double tienda [15][30]; //Matriz burbuja.
    double precio[15]= {2,3,4,5,6,7,8,9,1,3,5,7,9,1,1.5}; //Lista de precios para cada producto
    double vertical[30] = {0};//Suma de las columnas
    double totalProducido[15]; //Guarda el total de productos vendidos (por producto) al mes
    double totalprecio[15];//Guarda la multiplicacion del precio del producto por la cantidad vendida de este al mes

    cout << "\t\t\t\t***TIENDA LA BURBUJA***\n\n";

    //Se llena la matriz
    for (int i = 0; i<15; i++)
    {
        for (int j = 0; j<30; j++)
        {
            //Se llena por medio de la funcion aleatoria
            num = 1 + rand() % (100 - 1);
            tienda[i][j] =  num;
        }
    }

    //--------------------- Se imprime la matriz ------------------------
    for (int i = 0; i<15; i++)
    {
        for (int j = 0; j<30; j++)
        {
            cout<<tienda[i][j]<<" ";
        }
        cout << "\n";
    }
    
    //------------------ Se suman los diarios --------------------------
    
    for(int i=0; i<15; i++)
    {   
        double auxtotalP = 0; //Total por producto
        for(int j=0; j<30; j++)
        {
            auxtotalP += tienda[i][j];
        }
        totalProducido[i] = auxtotalP;
        double aux=precio[i];
        totalprecio[i] = aux*totalProducido[i];

        
    }
    //Buscar el mayor vendido
    float mayor = 0;
    int posMayor = 0;
    for (int i=0; i<15; i++)
    {
        if(totalProducido[i]>mayor)
        {
            mayor = totalProducido[i];
            posMayor = i;
        }
    }
    //Se busca el menor vendido
    float menor = mayor;
    int posMenor = 0;
    for (int i=0; i<15; i++)
    {
        if(totalProducido[i]<menor)
        {
            menor = totalProducido[i];
            posMenor = i;
        }
            
    }    

    //Suma de columnas
    double suma;
    for (int i = 0; i<30; i++)
    {   
        suma = 0.0;

        for(int j=0; j<15; j++)
        {
            suma += tienda[j][i];
            
        }
        vertical[i] = suma;
    }

    //Ventas por día
    double dia[30];
    double val;
    for (int i = 0; i<30; i++)
    {
        val = 0.0;
        for (int j = 0; j<15; j++){
            val += tienda[j][i]*precio[j];
        }
        dia[i] = val;

    }

    //Dia en que los productos fueron mayores
    float mayorD = 0;
    int PosDiaM = 0;
    for (int i = 0; i<30; i++)
    {       
        if(vertical[i]>mayorD)
        {
            mayorD = vertical[i];
            PosDiaM = i;

        }
    }

    //Dia en que los productos fueron menores
    float menorD = mayorD;
    int PosDiaMen = 0;
    for (int i = 0; i<30; i++)
    {
        if(vertical[i]<menorD)
        {
            menorD = vertical[i];
            PosDiaMen = i;

        }
    }

    // Valor total de las ventas
    double sumaT;
    for (int i = 0; i<15; i++)
    {   
        sumaT += totalprecio[i];

    }

    //Impresión de resultados.

    cout<<"\n\n\t\t---------------RESULTADOS----------------------\n\n";
    cout<<"\n\t*********** Cantidad diaria de dinero ***********\n";
    for (int i=0; i<30; i++)
    {
        cout<<dia[i]<<", ";
    }
    cout<<"\n\n\t*********** Cantidad vendida de cada producto (Mensual) ***********\n";
    for (int i=0; i<15; i++)
    {
        cout<<totalProducido[i]<<", ";
    }
    cout<<"\n\n\t*********** Cantidad de dinero por producto (Mensual) ***********\n";
    for (int i=0; i<15; i++)
    {
        cout<<"$ "<<totalprecio[i]<<", ";
    }

    cout<<"\n\nEL producto mas vendido en el mes fue el #"<<posMayor<<" con un total de "<<mayor<<endl;
    cout<<"\nEL producto menos vendido en el mes fue el #"<<posMenor<<" con un total de "<<menor<<endl;
    cout<<"\nEL dia en que los productos fueron mayores fue el#"<<PosDiaM<<" con un total de "<<mayorD<<endl;
    cout<<"\nEL dia en que los productos fueron menores fue el #"<<PosDiaMen<<" con un total de "<<menorD<<endl;
    cout<<"\nEL dinero total de ventas es $"<<sumaT<<"\n"<<endl;
    
  return 2019;
}