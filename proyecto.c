//Crear el juego de la nave
#include <stdio.h>
#include <stdlib.h>//Libreria para generar numeros aleatorios
#include <time.h> //Libreria para devolver la hora de el sistema
int main(){
    srand(time(NULL));//Definimos la semilla que va cambiando respecto al tiempo de nuestra computadora
    int nave[4];//0.-Vida, 1.-velocidad, 2.-distancia a otros planetas y objetos, 3.-misiles
    int vida = 0, velocidad = 1, distancia = 2,  misiles = 3; // asignamos cada espacio del arreglo a el atributo de la nave correspondiente para no confundirse
    int asteroides,nivel, nivelval, avanzar, hoyosN, i, planeta, kmarte = 0,tobjeto, objeto[2]; //0.-Planeta, 1;- Objeto de interes(capsulas)
    printf("BIENIDO A {NOMBRE DEL JUEGO POR DETERMINAR} |=>\n");
    do
    {
            printf("~~~~~Elige tu dificultad: |=>\n");
            printf("===================\n");
            printf("++++ 1.- Nivel Facil ++++\n");
            printf("++++ 2.- Nivel Medio ++++\n");
            printf("++++ 3.- Nivel Dificil ++++\n");
            printf("===================\n");
            printf("Ingrese el numero del nivel que desea jugar\n|=>");
            scanf("%d", &nivel);
        switch (nivel)
        {
        case 1:
            printf("////////////////NIVEL FACIL////////////////\n");
            //Cantidad de vida y misiles principales 
            nave[vida]= 2000;
            nave[velocidad]=0;
            nave[distancia]=0;
			nave[misiles]=8000;
            
            do
            {
                //Definicion de atributos de la nave
                int rango = 15000-6000;
                int rangod = 11500 - 6000;
                nave[velocidad] = rand()%rango+6000;
                printf("La nave tiene una velocidad de: %dkm/h \n", nave[velocidad]);
                nave[distancia] = rand()%rango+6000;
                //Definidendo el tipo de objeto que encontrara, si nave o capsulas
                tobjeto = rand()%2;
                //Mostrando el tipo de objeto segun lo definido
                if ( tobjeto == 0)
                {
                    objeto[0] = rand()%2; //Tipo de planeta que sera 0 = Sin vida, 1 = Con vida
                    printf("Se aproxima un planeta de tipo %d a una distancia de %dkm\n", objeto[0], nave[distancia]);
                    printf("La velocidad constante de la nave es de: %dkm/h\n", nave[velocidad]);
                }else if (tobjeto == 1)
                {
                    printf("Se ha localizado un objeto a %dkm\n", nave[distancia]);
                }
                
                
                kmarte++;
            } while (nave[misiles] > 7800 && nave[vida] > 1900 && kmarte <=10);
            
            
            planeta = rand()%2;//0.-PLaneta con vida, 1;- Planeta sin vida
            printf("Planeta es: %d", planeta);
            
			
			
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
