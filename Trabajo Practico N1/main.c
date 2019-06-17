#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int num1=0;
    int num2=0;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%d)\n", num1);
        printf("2- Ingresar 2do operando (B=%d)\n", num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer numero: ");
                scanf("%d", &num1);
                break;
            case 2:
                printf("Ingrese el segundo numero: ");
                scanf("%d", &num2);
                break;
            case 3:
                suma(num1,num2);
                break;
            case 4:
                resta(num1,num2);
                break;
            case 5:
                division(num1,num2);
                break;
            case 6:
                multiplicacion(num1,num2);
                break;
            case 7:
                factorial(num1);
                break;
            case 8:
                todas(num1,num2);
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }

    return 0;
}
