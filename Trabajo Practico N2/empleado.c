#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Para indicar que todas las posiciones en la matriz están vacías,
  esta función pone la bandera (isEmpty) en VERDADERO en todos
  posición de la matriz
*/
int inicializarEmpleados(eEmpleado lista[], int tam)
{
    if (tam < 0){
        return -1;
    }
    else {
        for(int i=0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        return 0;
    }
}

/*En esta funcion llama a buscarLibre y en base a la devolucion cargara el nuevo empleado en la lista*/
void altaEmpleado(eEmpleado lista[], int tam)
{
    int indice;
    eEmpleado nuevoEmpleado;

    indice = buscarLibre(lista, tam);

    system("cls");
    printf("*** Alta empleado ***\n\n");

    if(indice == -1)
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        nuevoEmpleado.id = indice+1;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nuevoEmpleado.nombre);
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(nuevoEmpleado.apellido);
        printf("Ingrese sueldo: ");
        fflush(stdin);
        scanf("%f", &nuevoEmpleado.sueldo);
        printf("Ingrese sector: ");
        fflush(stdin);
        scanf("%d", &nuevoEmpleado.sector);

        nuevoEmpleado.isEmpty = 0;

        lista[indice] = nuevoEmpleado;
    }
}

/*En esta funcion se da una baja logica al empleado seleccionado(setea el isEmpty en true)*/
void bajaEmpleado(eEmpleado lista[], int tam)
{

    int id;
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja empelado ***\n\n");

    printf("Ingrese ID: ");
    scanf("%d", &id);

    indice = buscarEmpleado(lista, tam, id);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el ID %d\n\n", id);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice]);

        printf("\nConfima borrado s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Baja cancelada\n\n");

        }
        else

        {
            lista[indice].isEmpty = 1;
            printf("Borrado exitoso\n\n");
        }
        system("pause");
    }

}

/*En esta funcion se modifican los datos elegidos por el usuario*/
void ModificarEmpleado(eEmpleado lista[], int tam)
{
    int id;
    int indice;
    char seguir;
    float nuevoSueldo;
    int nuevoSector;

    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    printf("Ingrese ID: ");
    scanf("%d", &id);

    indice = buscarEmpleado(lista, tam, id);

    if(indice == -1)
    {
        printf("No hay ningun empleado con ese ID %d\n\n", id);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice]);

        printf("\nModifica nombre? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            gets(lista[indice].nombre);

            printf("Modificacion exitosa\n\n");
            system("pause");
            return;
        }

        printf("\nModifica apellido? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo apellido: ");
            fflush(stdin);
            gets(lista[indice].apellido);

            printf("Modificacion exitosa\n\n");
            system("pause");
            return;
        }

        printf("\nModifica sueldo? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            lista[indice].sueldo = nuevoSueldo;

            printf("Modificacion exitosa\n\n");
            system("pause");
            return;
        }

        printf("\nModifica sector? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo sector: ");
            scanf("%d", &nuevoSector);
            lista[indice].sector = nuevoSector;

            printf("Modificacion exitosa\n\n");
            system("pause");
            return;
        }
    }
}
/* En esta funcion se imprime el empleado pasado por el parametro*/
void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d %12s   %8s       %6.2f   %5d\n", unEmpleado.id, unEmpleado.nombre, unEmpleado.apellido, unEmpleado.sueldo, unEmpleado.sector);
}

/*En esta funcion se imprimen todos los empleados que estan cargados. Saca el promedio de los sueldos e indica cuantos superaron dicho monto.*/
void mostrarEmpleados(eEmpleado lista[], int tam)
{
    float totalsueldos = 0;
    float contador = 0;
    float promedio;
    float superados;

    system("cls");
    printf("ID      Nombre    Apellido       Sueldo     Sector   \n\n");

    for(int i=0; i < tam ; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrarEmpleado(lista[i]);
            contador++;
            totalsueldos += lista[i].sueldo;
        }
    }
    printf("\n\n");

    promedio = totalsueldos/contador;

    for(int i=0; i < tam ; i++)
    {
        if(lista[i].sueldo > promedio)
        {
            superados++;
        }
    }
    printf("El promedio de sueldos es: %6.2f \nLa cantidad de empleados que superaron el promedio fueron: %.0f\n", promedio, superados);

}

/*En esta funcion busca la posicion libre en la lista para poder cargar un empleado nuevo*/
int buscarLibre(eEmpleado lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/*En esta funcion se busca el empleado para darlo de baja o modificarlo*/
int buscarEmpleado(eEmpleado lista[], int tam, int id)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].id == id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}
/*Esta funcion ordena los empleados por apellido de manera ascendente o descendente (y por sector de manera ascendente) segun lo indicado por el usuario*/
void ordenarEmpleados(eEmpleado lista[], int tam, int ord)
{
    eEmpleado aux;

    for (int i=0; i < tam -1; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            continue;
        }

        for(int j=i+1; j < tam; j++)
        {
            if((ord == 0 && strcmp(lista[i].apellido, lista[j].apellido)>0) ||
               (ord == 1 && strcmp(lista[i].apellido, lista[j].apellido)<0))
            {
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
            }

            else if (lista[i].sector > lista[j].sector)
            {
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
            }
        }
    }
}
