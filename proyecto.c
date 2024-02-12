//Crear el juego de la nave
#include <stdio.h>
#include <stdlib.h>//Libreria para generar numeros aleatorios
#include <time.h> //Libreria para devolver la hora de el sistema
int main(){
    srand(time(NULL));//Definimos la semilla que va cambiando respecto al tiempo de nuestra computadora
    int nave[4];//0.-Vida, 1.-velocidad, 2.-distancia a otros planetas y objetos, 3.-misiles
    int asteroides, objetos,nivel, nivelval, avanzar, hoyosN, planetas[2]; //0.-PLaneta con vida, 1;- Planeta sin vida
    printf("BIENIDO A {NOMBRE DEL JUEGO POR DETERMINAR} |=>\n");
    do
    {
            printf("~~~~~Elige tu dificultad: |=>\n");
            printf("===================\n");
            printf("++++ Nivel Facil ++++\n");
            printf("++++ Nivel Medio ++++\n");
            printf("++++ Nivel Dificil ++++\n");
            printf("===================\n");
            printf("Ingrese el numero del nivel que desea jugar\n|=>");
            scanf("%d", &nivel);
        switch (nivel)
        {
        case 1:
            printf("////////////////NIVEL FACIL////////////////\n");
            //Cantidad de vida y misiles principales 
            nave[0]= 2000;
            nave[1]=0;
            nave[2]=10000;
			nave[3]=8000;
			
			
			//Fase  Final
            printf("¿Desea avanzar al siguiente nivel? 1.-(Si) : Cualquier tecla(NO) \n|=>");
            scanf("%d", &avanzar);
            nivelval = 1;
            if (avanzar == 1)
            {
                printf(".............Redirigiendo al Segundo nivel.............\n\n");
                avanzar = 0;
            }
            else{
                break;
            }
            
        case 2:
            printf("////////////////NIVEL MEDIO////////////////\n");
            nivelval = 1;
            printf("¿Desea avanzar al siguiente nivel? 1.-(Si) : Cualquier tecla(NO) \n|=>");
            scanf("%d", &avanzar);
            nivelval = 1;
            if (avanzar == 1)
            {
                printf(".............Redirigiendo al Tercer nivel nivel.............\n\n");
            }
            else{
                break;
            }
        case 3:
            printf("////////////////NIVEL DIFICIL////////////////\n");
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
    printf("GRACIAS POR JUGAR, VUELVA PRONTO :)");
}
