#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

#define TAM 1000


int menu();
int submenu();

int main()
{
    char seguir = 's';
    int init;
    int opcordenam;

    eEmpleado empleados[TAM];

    init = inicializarEmpleados(empleados,TAM);
    if (init == -1){
        printf("El tamanio maximo es invalido.");
    }

    do
    {
        switch(menu())
        {
            case 1:
                altaEmpleado(empleados, TAM);
                break;
            case 2:
                bajaEmpleado(empleados,TAM);
                break;
            case 3:
                ModificarEmpleado(empleados, TAM);
                break;
            case 4:
                opcordenam = submenu();
                ordenarEmpleados(empleados, TAM, opcordenam);
                mostrarEmpleados(empleados, TAM);
                system("pause");
                break;
            case 10:
                seguir = 'n';
                break;
        }
    } while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1-  Alta\n");
    printf(" 2-  Baja\n");
    printf(" 3-  Modificacion\n");
    printf(" 4-  Listar empleados\n");
    printf(" 10- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int submenu()
{
    int opcion;

    do{
        printf("\nDesea ordenarlo ascendentemente-0- o descendentemente-1- ?. Ingrese un numero: ");
        fflush(stdin);
        scanf("%d", &opcion);

    }while (opcion != 0 && opcion != 1);

    return opcion;
}








