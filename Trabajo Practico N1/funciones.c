// entran dos numeros como parametros, adentro hace la logica y muestra en consola el resultado
void suma(int num1, int num2){
    int total = num1 + num2;
    printf("El resultado de la suma es: %d\n", total);
}

// entran dos numeros como parametros, adentro hace la logica y muestra en consola el resultado
void resta(int num1, int num2){
    int total = num1 - num2;
    printf("El resultado de la resta es: %d\n", total);
}

// entran dos numeros como parametros, adentro hace la logica y muestra en consola el resultado
void division(float num1, float num2){
    if(num2 == 0){
        printf("No puede usar 0 como divisor. Ingrese otro numero\n");
        return 0;
    }
    float total = num1 / num2;
    printf("El resultado de la division es: %f\n", total);
}

// entran dos numeros como parametros, adentro hace la logica y muestra en consola el resultado
void multiplicacion(int num1, int num2){
    int total = num1 * num2;
    printf("El resultado de la multiplicacion es: %d\n", total);
}

// entran un numero como parametro, llama a otra funcion para ejecutar la logica y muestra en consola el resultado
void factorial (int num1){
    int total = factorialrecursiva(num1);
    printf("El resultado de la factorial es: %d\n", total);
}

// logica del factorial, retorna el resultado 
int factorialrecursiva(int num){
    int resp;
    if (num==1)
            return 1;
    resp= num * factorialrecursiva(num-1);
    return(resp);

}
// llama a todas las funciones 
void todas(int num1, int num2){
    suma(num1,num2);
    resta(num1, num2);
    division(num1,num2);
    multiplicacion(num1,num2);
    factorial(num1);
}
