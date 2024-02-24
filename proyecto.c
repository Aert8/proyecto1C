//Crear el juego de la nave
#include <stdio.h>
#include <stdlib.h>//Libreria para generar numeros aleatorios
#include <time.h> //Libreria para devolver la hora de el sistema
int main(){
    srand(time(NULL));//Definimos la semilla que va cambiando respecto al tiempo de nuestra computadora
    int nave[4];//0.-Vida, 1.-velocidad, 2.-distancia a otros planetas y objetos, 3.-misiles
    int vida = 0, velocidad = 1, distancia = 2,  misiles = 3; // asignamos cada espacio del arreglo a el atributo de la nave correspondiente para no confundirse
    int asteroides,nivel, nivelval, avanzar, hoyosN, i, chocar = 0, desicion, pasar = 0, kmarte = 1,tobjeto, objeto[2]; //0.-Planeta, 1;- Objeto de interes(capsulas)
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
                printf("\n~~~~~~~~ DIA %d ~~~~~~~~\n", kmarte);
                //Definicion de atributos de la nave
                int rango = 15000-8000;
                int rangod = 11500 - 5000;
                nave[velocidad] = rand()%rango+8000;
                nave[distancia] = rand()%rangod+5000;
                //Definidendo el tipo de objeto que encontrara, si nave o capsulas
                tobjeto = rand()%2;
                //Mostrando el tipo de objeto segun lo definido
                if ( tobjeto == 0)
                {
                    objeto[0] = rand()%2; //Tipo de planeta que sera 0 = Con vida, 1 = Sin vida

                    if (objeto[0] == 0)
                    {
                        //Informacion que se le da al usuario para tener conocimiento de los atributos de la nave
                        printf("Se aproxima un planeta con vida a una distancia de %dkm\n", nave[distancia]);
                        printf("La velocidad constante de la nave es de: %dkm/h\n", nave[velocidad]);
                        printf("Capsulas de vida: %d --------- Misiles: %d\n", nave[vida], nave[misiles]);
                        //Acciones que puede hacer la nave en base a sus atributos y las condiciones
                        if (nave[distancia] < 8000)
                        {
                            printf("O no! La nave choco, La nave quedo totalmente DESTRUIDA\n");
                            chocar = 1;
                        }
                        
                        if ((nave[distancia] > 8000 && nave[distancia] < 10000) && nave[velocidad] > 12000)
                        {
                            printf("Fiu!, La nave pudo evadir al planeta\n");
                        }
                        
                        if(nave[distancia] > 10000){
                            printf("La nave siguio su viaje :p\n");
                        } 
                    }
                    else if (objeto[0] == 1)
                    {
                        //Informacion que se le da al usuario para tener conocimiento de los atributos de la nave
                        printf("Se aproxima un planeta sin vida a una distancia de %dkm\n", nave[distancia]);
                        printf("La velocidad constante de la nave es de: %dkm/h\n", nave[velocidad]);
                        printf("Capsulas de vida: %d --------- Misiles: %d\n", nave[vida], nave[misiles]);
                        desicion = rand()%2;
                        switch (desicion)
                        {
                        case 0:
                            printf("La nave decidio atacar\n");
                            if (nave[distancia]<= 8000 && nave[velocidad] >= 12000)
                            {
                                printf("LA NAVE DESTRUYO EL PLANETA!\n");
                                printf("El costo del ataque exitoso fue de 25 capsulas de vida y 50 misiles :O\n");
                                nave[vida] = nave[vida] - 25;
                                nave[misiles] = nave[misiles] - 50;
                            }else{
                                printf("La nave no pudo destruir el planeta :/ \n");
                                printf("El costo del ataque fallido fue de 15 capsulas de vida y 30 misiles :O\n");
                                nave[vida] = nave[vida] - 15;
                                nave[misiles] = nave[misiles] - 30;
                            }
                            
                            break;

                        case 1:
                            printf("La nave decidio no atacar\n");
                            break;
                        
                        default:
                            //no puede dar otra cosa que no sea 0 y 1 debido a que esta reducido a esas 2 opciones
                            break;
                        }
                        //Acciones que puede hacer la nave en base a sus atributos y las condiciones
                        if (nave[distancia] < 8000 && desicion == 1)
                        {
                            printf("O no! La nave choco, La nave quedo totalmente DESTRUIDA\n");
                            chocar = 1;
                        }
                        
                        if ((nave[distancia] > 8000 && nave[distancia] < 10000) && nave[velocidad] > 12000)
                        {
                            printf("Fiu!, La nave pudo evadir al planeta\n");
                        }
                        
                        if(nave[distancia] > 10000){
                            printf("La nave siguio su viaje :p\n");               
                        } 
                    }
                    
                }else if (tobjeto == 1)
                {
                    printf("Se ha localizado un objeto a %dkm\n", nave[distancia]);
                    printf("Capsulas de vida: %d --------- Misiles: %d\n", nave[vida], nave[misiles]);
                    if (nave[distancia] < 6000)
                    {
                        printf("La nave logro obtener el objeto y gano 5 capsulas de vida :)\n");
                        nave[vida] = nave[vida] + 5;
                    }else{
                        printf("La nave no logro obtener el objeto y gasto 3 capsulas de vida :/\n");
                        nave[vida] = nave[vida] - 3;
                    }
                }
                
                if (nave[misiles] > 7800 && nave[vida] > 1900 && kmarte <= 10 && chocar == 0)
                {
                    pasar = 1;
                }else{
                    pasar = 0;
                }
                
                kmarte++;
                
            } while (nave[misiles] > 7800 && nave[vida] > 1900 && kmarte <=7 && chocar == 0);
			//Fase  Final
            if (pasar == 1)
            {
                printf("\n<<<<<<<< FELICIDADES, LA NAVE LOGRO PASAR EL NIVEL 1 >>>>>>>>>\n");
                printf("ENTREGA EXITOSA!!\n");
                printf("ESTADO DE LA NAVE |=> \n");
                printf("Capsulas de vida sobrantes: %d --------- Misiles sobrantes: %d\n", nave[vida], nave[misiles]);
                printf("¿Desea avanzar al siguiente nivel? 1.-(Si) : Cualquier tecla(NO) \n|=>");
                scanf("%d", &avanzar);
                nivelval = 1;
                if (avanzar == 1)
                {
                    printf(".............Redirigiendo al Segundo nivel.............\n\n");
                    avanzar = 0;
                    kmarte = 1;
                    chocar = 0;
                }
                else{
                    kmarte = 1;
                    chocar = 0;
                    break;
                }
            }else{
                if (nave[misiles] < 7800 && nave[vida] < 1900)
                {
                    printf("LA NAVE SE QUEDO CON MENOS MISILES DE LOS NECESARIOS PARA JUGAR Y LA VIDA NO ES LA SUFICIENTE\n");
                }else{
                    if (nave[misiles] < 7800)
                    {
                        printf("LA NAVE SE QUEDO CON MENOS MISILES DE LOS NECESARIOS PARA JUGAR\n");
                    }
                    if (nave[vida] < 1900)
                    {
                        printf("LA VIDA DE LA NAVE NO ES LA SUFICIENTE PARA CONTINUAR\n");
                    }
                }
                printf("xxxxxxxxxxx FIN DEL JUEGO xxxxxxxxxxx\n\n");
                kmarte = 1;
                chocar = 0;
                break;
            }
            
            
            
            
            
            
            
        case 2:
            printf("////////////////NIVEL MEDIO////////////////\n");
            
            nave[vida]= 1900;
            nave[misiles]= 7800;
            nave[velocidad]= 0;
            nave[distancia]= 0;
            do{
            	printf("\n~~~~~~~~ DIA %d ~~~~~~~~\n", kmarte);
                //Definicion de atributos de la nave
                int rango = 21000 - 15000;
                int rangod = 8000 - 6000;
                nave[velocidad] = rand()%rango+15000;
                nave[distancia] = rand()%rangod+6000;
                //Definidendo el tipo de objeto que encontrara, si nave o capsulas
                tobjeto = rand()%2;
                //Mostrando el tipo de objeto segun lo definido
                if ( tobjeto == 0)
                {
                    objeto[0] = rand()%2; //Tipo de planeta que sera 0 = Con vida, 1 = Sin vida

                    if (objeto[0] == 0)
                    {
                        //Informacion que se le da al usuario para tener conocimiento de los atributos de la nave
                        printf("Se aproxima un planeta con vida a una distancia de %dkm\n", nave[distancia]);
                        printf("La velocidad constante de la nave es de: %dkm/h\n", nave[velocidad]);
                        printf("Capsulas de vida: %d --------- Misiles: %d\n", nave[vida], nave[misiles]);
                        //Acciones que puede hacer la nave en base a sus atributos y las condiciones
                        if (nave[distancia] < 6000)
                        {
                            printf("O no! La nave choco, La nave quedo totalmente DESTRUIDA\n");
                            chocar = 1;
                        }
                        
                        if ((nave[distancia] > 6000 && nave[distancia] < 8000) && nave[velocidad] > 20000)
                        {
                            printf("Fiu!, La nave pudo evadir al planeta\n");
                        }
                        
                        if(nave[distancia] > 20000){
                            printf("La nave siguio su viaje :p\n");
                        } 
                    }
                    else if (objeto[0] == 1)
                    {
                        //Informacion que se le da al usuario para tener conocimiento de los atributos de la nave
                        printf("Se aproxima un planeta sin vida a una distancia de %dkm\n", nave[distancia]);
                        printf("La velocidad constante de la nave es de: %dkm/h\n", nave[velocidad]);
                        printf("Capsulas de vida: %d --------- Misiles: %d\n", nave[vida], nave[misiles]);
                        desicion = rand()%2;
                        switch (desicion)
                        {
                        case 0:
                            printf("La nave decidio atacar\n");
                            if (nave[distancia]<= 6000 && nave[velocidad] >= 20000)
                            {
                                printf("LA NAVE DESTRUYO EL PLANETA!\n");
                                printf("El costo del ataque exitoso fue de 25 capsulas de vida y 50 misiles :O\n");
                                nave[vida] = nave[vida] - 30;
                                nave[misiles] = nave[misiles] - 60;
                            }else{
                                printf("La nave no pudo destruir el planeta :/ \n");
                                printf("El costo del ataque fallido fue de 15 capsulas de vida y 30 misiles :O\n");
                                nave[vida] = nave[vida] - 20;
                                nave[misiles] = nave[misiles] - 40;
                            }
                            
                            break;

                        case 1:
                            printf("La nave decidio no atacar\n");
                            break;
                        
                        default:
                            //no puede dar otra cosa que no sea 0 y 1 debido a que esta reducido a esas 2 opciones
                            break;
                        }
                        //Acciones que puede hacer la nave en base a sus atributos y las condiciones
                        if (nave[distancia] < 6000 && desicion == 1)
                        {
                            printf("O no! La nave choco, La nave quedo totalmente DESTRUIDA\n");
                            chocar = 1;
                        }
                        
                        if ((nave[distancia] > 6000 && nave[distancia] < 8000) && nave[velocidad] > 20000)
                        {
                            printf("Fiu!, La nave pudo evadir al planeta\n");
                        }
                        
                        if(nave[distancia] > 20000){
                            printf("La nave siguio su viaje :p\n");               
                        } 
                    }
                    
                }else if (tobjeto == 1)
                {
                    printf("Se ha localizado un objeto a %dkm\n", nave[distancia]);
                    printf("Capsulas de vida: %d --------- Misiles: %d\n", nave[vida], nave[misiles]);
                    if (nave[distancia] < 4000)
                    {
                        printf("La nave logro obtener el objeto y gano 10 capsulas de vida :)\n");
                        nave[vida] = nave[vida] + 10;
                    }else{
                        printf("La nave no logro obtener el objeto y gasto 7 capsulas de vida :/\n");
                        nave[vida] = nave[vida] - 7;
                    }
                }
                
                if (nave[misiles] > 7400 && nave[vida] > 1500 && kmarte <= 7 && chocar == 0)
                {
                    pasar = 1;
                }else{
                    pasar = 0;
                }
                
                kmarte++;
            } while (nave[misiles] > 7400 && nave[vida] > 1500 && kmarte <=7 && chocar == 0);
			//Fase  Final
            if (pasar == 1)
            {
                printf("\n<<<<<<<< FELICIDADES, LA NAVE LOGRO PASAR EL NIVEL 2 >>>>>>>>>\n");
                printf("ENTREGA EXITOSA!!\n");
                printf("ESTADO DE LA NAVE |=> \n");
                printf("Capsulas de vida sobrantes: %d --------- Misiles sobrantes: %d\n", nave[vida], nave[misiles]);
                printf("¿Desea avanzar al siguiente nivel? 1.-(Si) : Cualquier tecla(NO) \n|=>");
                scanf("%d", &avanzar);
                nivelval = 1;
                if (avanzar == 1)
                {
                    printf(".............Redirigiendo al Segundo nivel.............\n\n");
                    avanzar = 0;
                    kmarte = 1;
                    chocar = 0;
                }
                else{
                    kmarte = 1;
                    chocar = 0;
                    break;
                }
            }else{
                if (nave[misiles] < 7400 && nave[vida] < 1500)
                {
                    printf("LA NAVE SE QUEDO CON MENOS MISILES DE LOS NECESARIOS PARA JUGAR Y LA VIDA NO ES LA SUFICIENTE\n");
                }else{
                    if (nave[misiles] < 7400)
                    {
                        printf("LA NAVE SE QUEDO CON MENOS MISILES DE LOS NECESARIOS PARA JUGAR\n");
                    }
                    if (nave[vida] < 1500)
                    {
                        printf("LA VIDA DE LA NAVE NO ES LA SUFICIENTE PARA CONTINUAR\n");
                    }
                }
                printf("xxxxxxxxxxx FIN DEL JUEGO xxxxxxxxxxx\n\n");
                kmarte = 1;
                chocar = 0;
                break;
            }
            //Fase Final 
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
            //Cantidad de vida y misiles principales 
            nave[vida]= 1500;
            nave[velocidad]=0;
            nave[distancia]=0;
			nave[misiles]=7400;
            do
            {
                printf("\n~~~~~~~~ DIA %d ~~~~~~~~\n", kmarte);
                //Definicion de atributos de la nave
                int rango = 30000-8000;
                int rangod =7500-4000;
                nave[velocidad] = rand()%rango+8000;
                nave[distancia] = rand()%rangod+4000;
                //Definidendo el tipo de objeto que encontrara, si nave o capsulas
                tobjeto = rand()%2;
                //Mostrando el tipo de objeto segun lo definido
                if ( tobjeto == 0)
                {
                    objeto[0] = rand()%2; //Tipo de planeta que sera 0 = Con vida, 1 = Sin vida

                    if (objeto[0] == 0)
                    {
                        //Informacion que se le da al usuario para tener conocimiento de los atributos de la nave
                        printf("Se aproxima un hoyo negro a una distancia de %dkm\n", nave[distancia]);
                        printf("La velocidad constante de la nave es de: %dkm/h\n", nave[velocidad]);
                        printf("Capsulas de vida: %d --------- Misiles: %d\n", nave[vida], nave[misiles]);
                        //Acciones que puede hacer la nave en base a sus atributos y las condiciones
                        if (nave[distancia] < 4000)
                        {
                            printf("O no! La nave choco, La nave quedo totalmente DESTRUIDA\n");
                            chocar = 1;
                        }
                        
                        if ((nave[distancia] > 4000 && nave[distancia] < 6000) && nave[velocidad] > 28000)
                        {
                            printf("Fiu!, La nave pudo evadir al planeta\n");
                        }
                        
                        if(nave[distancia] > 28000){
                            printf("La nave siguio su viaje :p\n");
                        } 
                    }
                    else if (objeto[0] == 1)
                    {
                        //Informacion que se le da al usuario para tener conocimiento de los atributos de la nave
                        printf("Se aproxima un hoyo negro sin vida una distancia de %dkm\n", nave[distancia]);
                        printf("La velocidad constante de la nave es de: %dkm/h\n", nave[velocidad]);
                        printf("Capsulas de vida: %d --------- Misiles: %d\n", nave[vida], nave[misiles]);
                        desicion = rand()%2;
                        switch (desicion)
                        {
                        case 0:
                            printf("La nave decidio atacar\n");
                            if (nave[distancia]<= 4000 && nave[velocidad] >= 28000)
                            {
                                printf("LA NAVE DESTRUYO EL HOYO NEGRO!\n");
                                printf("El costo del ataque exitoso fue de 25 capsulas de vida y 50 misiles :O\n");
                                nave[vida] = nave[vida] - 35;
                                nave[misiles] = nave[misiles] - 80;
                            }else{
                                printf("La nave no pudo destruir el hoyo negro :/ \n");
                                printf("El costo del ataque fallido fue de 15 capsulas de vida y 30 misiles :O\n");
                                nave[vida] = nave[vida] - 30;
                                nave[misiles] = nave[misiles] - 50;
                            }
                            
                            break;

                        case 1:
                            printf("La nave decidio no atacar\n");
                            break;
                        
                        default:
                            //no puede dar otra cosa que no sea 0 y 1 debido a que esta reducido a esas 2 opciones
                            break;
                        }
                        //Acciones que puede hacer la nave en base a sus atributos y las condiciones
                        if (nave[distancia] < 6800 && desicion == 1)
                        {
                            printf("O no! La nave choco, La nave quedo totalmente DESTRUIDA\n");
                            chocar = 1;
                        }
                        
                        if ((nave[distancia] > 4000 && nave[distancia] < 6000) && nave[velocidad] > 28000)
                        {
                            printf("Fiu!, La nave pudo evadir el hoyo negro\n");
                        }
                        
                        if(nave[distancia] > 28000){
                            printf("La nave siguio su viaje :p\n");               
                        } 
                    }
                    
                }else if (tobjeto == 1)
                {
                    printf("Se ha localizado un objeto a %dkm\n", nave[distancia]);
                    printf("Capsulas de vida: %d --------- Misiles: %d\n", nave[vida], nave[misiles]);
                    if (nave[distancia] < 2000)
                    {
                        printf("La nave logro obtener el objeto y gano 15 capsulas de vida :)\n");
                        nave[vida] = nave[vida] + 15;
                    }else{
                        printf("La nave no logro obtener el objeto y gasto 35 capsulas de vida :/\n");
                        nave[vida] = nave[vida] - 35;
                    }
                }
                
                if (nave[misiles] > 6900 && nave[vida] > 1000 && kmarte <= 10 && chocar == 0)
                {
                    pasar = 1;
                }else{
                    pasar = 0;
                }
                
                kmarte++;
                
            } while (nave[misiles] > 6900 && nave[vida] > 1000 && kmarte <=7 && chocar == 0);
			//Fase  Final
            if (pasar == 1)
            {
                printf("\n<<<<<<<< FELICIDADES, LA NAVE LOGRO PASAR EL NIVEL DIFICIL >>>>>>>>>\n");
                printf("ENTREGA EXITOSA!!\n");
                printf("ESTADO DE LA NAVE |=> \n");
                printf("Capsulas de vida sobrantes: %d --------- Misiles sobrantes: %d\n", nave[vida], nave[misiles]);
                printf("¿Desea jugar otro nivel? 1.-(Si) : Cualquier tecla(NO) \n|=>");
                scanf("%d", &avanzar);
                nivelval = 1;
                if (avanzar == 1)
                {
                    printf(".............Redirigiendo al Segundo nivel.............\n\n");
                    avanzar = 0;
                    kmarte = 1;
                    chocar = 0;
                }
                else{
                    kmarte = 1;
                    chocar = 0;
                    break;
                }
            }else{
                if (nave[misiles] < 6900 && nave[vida] < 1000)
                {
                    printf("LA NAVE SE QUEDO CON MENOS MISILES DE LOS NECESARIOS PARA JUGAR Y LA VIDA NO ES LA SUFICIENTE\n");
                }else{
                    if (nave[misiles] < 6900)
                    {
                        printf("LA NAVE SE QUEDO CON MENOS MISILES DE LOS NECESARIOS PARA JUGAR\n");
                    }
                    if (nave[vida] < 1000)
                    {
                        printf("LA VIDA DE LA NAVE NO ES LA SUFICIENTE PARA CONTINUAR\n");
                    }
                }
                printf("xxxxxxxxxxx FIN DEL JUEGO xxxxxxxxxxx\n\n");
                kmarte = 1;
                chocar = 0;
                break;
            }
            
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
