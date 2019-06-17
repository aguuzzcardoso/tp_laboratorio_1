
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;
} eEmpleado;

/*typedef struct
{
    int id;
    char descripcion[20];
} eSector;*/

int inicializarEmpleados(eEmpleado lista[], int tam);
void mostrarEmpleado(eEmpleado unEmpleado);
int buscarLibre(eEmpleado lista[], int tam);
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
void altaEmpleado(eEmpleado lista[], int tam);
void bajaEmpleado(eEmpleado lista[], int tam);
void ModificarEmpleado(eEmpleado lista[], int tam);
void mostrarEmpleados(eEmpleado lista[], int tam);
void ordenarEmpleados(eEmpleado lista[], int tam, int ord);
