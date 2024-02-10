//Crear el juego de la nave
#include <stdio.h>
#include <stdlib.h>//Libreria para generar numeros aleatorios
#include <time.h> //Libreria para devolver la hora de el sistema
int main(){
    srand(time(NULL));//Definimos la semilla que va cambiando respecto al tiempo de nuestra computadora
    int nave[4];//0.-Vida, 1.-velocidad, 2.-distancia a otros planetas y objetos, 2.-misiles
    int asteroides, objetos,nivel, nivelval, planetas[2]; //0.-PLaneta con vida, 1;- Planeta sin vida, hoyosN;
    printf("BIENIDO A {NOMBRE DEL JUEGO POR DETERMINAR} |=>\n");
    do
    {
            printf("~~~~~Elige tu dificultad: |=>\n");
            printf("===================\n");
            printf("++++ Nivel 1 ++++\n");
            printf("++++ Nivel 2 ++++\n");
            printf("++++ Nivel 3 ++++\n");
            printf("===================\n");
            printf("Ingrese el numero del nivel que desea jugar\n");
            scanf("%d", &nivel);
        switch (nivel)
        {
        case 1:
            printf("NIVEL 1\n");
            nivelval = 1;
            break;
        case 2:
            printf("NIVEL 2\n");
            nivelval = 1;
            break;
        case 3:
            printf("NIVEL 3\n");
            nivelval = 1;
            break;
        default:
            printf("//////////////////////////////////////////////////\n");
            printf("ESE NIVEL NO EXISTE, PORFAVOR INGRESE UNO VALIDO\n");
            printf("//////////////////////////////////////////////////\n\n");
            nivelval = 0;
            break;
        }
    } while (nivelval == 0);
    
}