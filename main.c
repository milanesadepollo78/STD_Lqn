#include <stdio.h>
#include <stdlib.h>
#include "Actions.h"
#include "Estructuras.h"
#include "Faces.h"
#include "Listas.h"
#include "Colas.h"
#include "Pilas.h"

//Instanciamos las estructuras que vamos a necesitar.
Lista l;
Cola c;
Pila pila;

//funcion que recibe las acciones que queremos hacer, nos ayuda a mantener el main lo mas limpio posible
void Acciones(int opt) {
    switch (opt) {
        case 1:
            //obtenemos los datos del usuario
            printf("\nBienvenido al registro de usuarios\n");
            //para declarar tanta variable, usamos la estructura Participante que ya teniamos declarada
            Participante p;
            printf("Ingrese el ID :");
            scanf("%d", &p.ID);
            printf("Ingrese el nombre del participante: ");
            scanf(" %30[^\n]", &p.nombre);
            printf("Ingrese el alias: ");
            scanf(" %30[^\n]", &p.Alias);
            printf("Ingrese la carrera: ");
            scanf(" %30[^\n]", &p.Carrera);
            //pasamos la lista y la estructura del participante a la funcion de enlistamiento
            enlistar(&l, &p);
            break;
        case 2:
            //Dev-c++ da problemas al declarar variables justo despues del case, por lo tanto agregamos un printf
            printf("\nBienvenido al desregistro de usuarios\n");
            int i;
            printf("Ingrese el ID : ");
            scanf(" %d", &i);
            // si necesitamos quitar una participante la funcion pide el id y la lista
            desenlistar(&l, i);
            break;
        case 3:
            //muestra toda la lista
            showLista(&l);
            break;
        case 4:
            //ordena la lista de participantes por el numero de id
            OrdB(&l, 1);
            break;
        case 5:
            //si la lista esta vacia, no podemos buscar a ningun participante
            if (listaVacia(&l)) {
                printf("la lista se encuentra vacia\n");
            }
            //nos permite buscar al participante que queramos
            printf("---- Busqueda de participantes ----\n");
            printf("Ingrese el ID: ");
            int id;
            scanf(" %d", &id);
            SecuencialL(&l, id, 0);
            break;
        case 6:
            //este case es para que un jugador solicite un turno en la cola de espera
            printf("---- Ingrese el id del participante ----\n");
            int num;
            scanf(" %d", &num);
            enqueue(&l, &c, num);
            break;
        case 7:
            //este otro case es para ver el estado de la cola de participantesw en distintas presentacioews
            printf("---- Mostrar la cola de participantes ----\n");
            int j;
            printf("[1] Para ver el siguiente turno\n");
            printf("[2] Para ver todos los participantes\n");
            printf("[3] Para ver el total de participantes\n");
            printf("Seleccione una opcion: ");
            scanf(" %d", &j);
            MostarCola(&c, j);
            break;
        case 8:
            //este case, llama una funcion, que desencola el participante y cambia su estado a jugando
            dequeue(&l, &c);
            break;
        case 9:
            //Este case nos permite llamar la funcion para finalizar la partida del participante que esta jugadn
            //recibe una pila y un participante, este se retorna de una funcion de busqueda sencuencial, que busca al participante en estado "jgando"
            finalizarP(&pila, BuqusquedaFP(&l));
            break;
        case 10://revertir el ultimo resultado---Norma
        {
        	Resul *ultimo = pop(&pila);
        	
        	if(ultimo != NULL){
        		Participante *aux = l.inicio;
        		
        		while(aux != NULL){
        			
        			if(aux->ID == ultimo->ID){
        				aux->Puntuacion = 0;
        				aux->Estado = Registrado;
        				
        				printf("El resultado fue revertido correctamente\n");
        				break;
					}
					aux = aux->sig;
				}
				free(ultimo);
			}
			break;
		}
        	
        case 11:
            //pa salirnos
            printf("Saliendo del programa\n");
            break;
        default:
            printf("\nEsa opcion no se encuentra disponible\n");
            break;
    }
}

int main() {
    //cuando inicia el programa inicializamos as estructuras que necesitamos
    inicializarLista(&l);
    incializarCola(&c);
    inicializarPila(&pila);
    int opt;

    do {
        opt = Menu();
        Acciones(opt);
    }while (opt != 11);
    return 0;
}
