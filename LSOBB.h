

#include "Envios.h"
#include <String.h>
#ifndef UNTITLED_LSO_H
#define UNTITLED_LSO_H
#define MAX_Envios 300
#endif //UNTITLED_LSO_H

//  float eExMax=0.0, eExMed=0.0, eFrMax=0.0, eFrMed=0.0, aMax=0.0, aMed=0.0, bMax=0.0, bMed=0.0, celCont=0.0;
//   int eExCant=0,eFrCant=0,aCant=0,bCant=0;

char *Mayusculas(char string[]);
typedef struct {
    Envio envios [MAX_Envios];
    int contador;
   int vector_aux[MAX_Envios];
    float eExMax, eExMed, eFrMax, eFrMed, aMax, aMed, bMax, bMed, celCont,tempa,tempb, eExCant,eFrCant,aCant,bCant,costo,costoEvoE,costoEvoF,tempe,tempef;
}lsobb;


void initLSOBB(lso *lista) {
    lista->eExMax = 0.0;
    lista->eExMed = 0.0;
    lista->eFrMax = 0.0;
    lista->eFrMed = 0.0;
    lista->aMax = 0.0;
    lista->aMed = 0.0;
    lista->bMax = 0.0;
    lista->bMed = 0.0;
    lista->celCont = 0.0;
    lista->eExCant = 0.0;
    lista->eFrCant = 0.0;
    lista->aCant = 0.0;
    lista->bCant = 0.0;
    lista->tempa = 0.0;
    lista->tempb = 0.0;
    lista->tempe= 0.0;
    lista->tempef= 0.0;
}


int LocalizarLSOBB(lsobb *lista, char codigo[], int *pos, int p) {
    int inicio = -1, medio = 0, comparacion = 0;             // Limite inferior exclusivo
    int fin = lista->contador - 1;   // Limite superior inclusivo


    lista->costoEvoE=0.0;
    lista->costoEvoF=0.0;


    float temp =0.0;
    if(lista->contador==0){
        return 0;
    }
    while (inicio < fin) {
        temp++;
        medio = (inicio + fin + 1) / 2;
        comparacion = strcmp(lista->envios[medio].codigo, codigo);
        if (comparacion <= 0) {
            inicio = medio;
        } else {
            fin = medio - 1;
        }
    }
    //vector auxiliar
    if(lista->vector_aux[inicio+1] == 0){
        temp++;
        lista->vector_aux[inicio+1]+=1;

    }
   // Posición de inserción si no se encontró el elemento

    if (strcmp(lista->envios[fin].codigo, codigo) == 0) {
        if(p==0){
            if(lista->eExMax<temp){
                lista->eExMax = temp-1;
            }
            lista->eExCant++;
            lista->costoEvoE+=temp;
            lista->tempe+=lista->costoEvoE;
            lista->eExMed = lista->tempe/(lista->eExCant);
        }
        *pos = fin;
        return 1; // Elemento encontrado
    } else {
        if(p==0){
            if(lista->eFrMax<temp){
                lista->eFrMax = temp;
            }
            lista->eFrCant++;
            lista->costoEvoF+=temp;
            lista->tempef+=lista->costoEvoF;
            lista->eFrMed = lista->tempef/(lista->eFrCant);
        }
        *pos = fin+1;
        return 0; // Elemento no encontrado
    }
}
/*
 *
 *
 * int LocalizarLSOBB(lsobb *lista, char codigo[], int *pos, int p) {
    int inicio = -1, medio = 0, comparacion = 0;             // Limite inferior exclusivo
    int fin = lista->contador - 1;   // Limite superior inclusivo
    if(lista->contador==0){
        return 0;
    }
    while (inicio < fin) {
        medio = (inicio + fin + 1) / 2;
        comparacion = strcmp(lista->envios[medio].codigo, codigo);
        if (comparacion < 0) {
            inicio = medio;
        } else {
            fin = medio - 1;
        }
    }
   // Posición de inserción si no se encontró el elemento
    if (strcmp(lista->envios[fin].codigo, codigo) == 0) {
        *pos = fin;
        return 1; // Elemento encontrado
    } else {
        *pos = fin+1;
        return 0; // Elemento no encontrado
    }
}
 *
 *
 *
int LocalizarLSOBB(lsobb *lista, char codigo[], int *pos) {
    int inicio = -1;  // Limite inferior exclusivo
    int fin = lista->contador;  // Limite superior inclusivo

    while (inicio+1 < fin) {
        int medio = (inicio + fin) / 2;
        int comparacion = strcmp(lista->envios[medio].codigo, codigo);
        if(comparacion < 0) { //cambio
            inicio = medio; //cambio
        } else {
            fin = medio ; //cambio
        }
    }
    *pos = inicio; //cambio
    if (*pos < lista->contador && strcmp(lista->envios[*pos].codigo, codigo) == 0) {
        return 1; // Elemento encontrado
    } else {
        return 0; // Elemento no encontrado
    }
    //preguntar si es el elemento para devolver fracaso
    //consultar si es mayor o no en el fracaso
    return 0;
}

 int LocalizarLSOBB(lsobb *lista, char codigo[], int *pos, int p) {
    int inicio = -1, medio = 0, comparacion = 0;             // Limite inferior exclusivo
    int fin = lista->contador-1;   // Limite superior inclusivo


    lista->costoEvoE=0.0;
    lista->costoEvoF=0.0;


    float temp =0.0;
    if(lista->contador==0){
        return 0;
    }
    while (inicio + 1 < fin) {

        temp++;


        medio = (inicio + fin + 1) / 2;
        comparacion = strcmp(lista->envios[medio].codigo, codigo);
        printf("%d\n", comparacion);
        if (comparacion <= 0) {
            inicio = medio -1;
        } else {
            fin = medio -1;
        }
    }
    //vector auxiliar
    if(lista->vector_aux[inicio+1] == 0){
        temp++;
        lista->vector_aux[inicio+1]+=1;
    }
   // Posición de inserción si no se encontró el elemento
   printf("%d", fin);
    if (strcmp(lista->envios[fin].codigo, codigo) == 0) {
        if(p==0){
            if(lista->eExMax<temp){
                lista->eExMax = temp;
            }
            lista->eExCant++;
            lista->costoEvoE+=temp;
            lista->tempe+=lista->costoEvoE;
            lista->eExMed = lista->tempe/(lista->eExCant);
        }
        *pos = fin;
        return 1; // Elemento encontrado
    } else {
        if(p==0){
            if(lista->eFrMax<temp){
                lista->eFrMax = temp;
            }
            lista->eFrCant++;
            lista->costoEvoF+=temp;
            lista->tempef+=lista->costoEvoF;
            lista->eFrMed = lista->tempef/(lista->eFrCant);
        }
        *pos = fin+1;
        return 0; // Elemento no encontrado
    }
}
*/
int AltaLSOBB(lsobb *lista, Envio envio) {


    lista->costo =0.0;
    int pos=0;

    if (lista->contador == MAX_Envios) {
        return 2; // Lista llena
    }

    if (LocalizarLSOBB(lista, envio.codigo, &pos,1)==0) {

        for (int i = lista->contador - 1; i >= pos; i--) {
            lista->costo++; //corrimiento


            lista->envios[i + 1] = lista->envios[i];
        }
        lista->envios[pos] = envio;
        lista->contador++;



        if (lista->costo > lista->aMax) {

            lista->aMax = lista->costo; //maximo



        }


        lista->tempa+=lista->costo; //promedio

        lista->aMed=lista->tempa/(lista->aCant+1);

        lista->aCant++; //cantidad de altas

        return 0;
    } else {

        return 1;
    }
}

/*
 *
 * int AltaLSOBB(lsobb *lista, Envio envio) {


    lista->costo =0.0;
    int pos=0;

    if (lista->contador == MAX_Envios) {
        return 2; // Lista llena
    }

    if (LocalizarLSOBB(lista, envio.codigo, &pos,1)==0) {

        for (int i = lista->contador - 1; i >= pos; i--) {



            lista->envios[i + 1] = lista->envios[i];
        }
        lista->envios[pos] = envio;
        lista->contador++;



        return 0;
    } else {

        return 1;
    }
}
 *
 * int AltaLSOBB(lsobb *lista, Envio envio) {

    lista->costo =0.0;
    int pos;
    if (lista->contador == MAX_Envios) {
        return 2; // Lista llena
    }
    if (LocalizarLSOBB(lista, envio.codigo, &pos,1)==0) {
        for (int i = lista->contador - 1; i >= pos; i--) {
            lista->envios[i + 1] = lista->envios[i];
        }
        lista->envios[pos] = envio;
        lista->contador++;
        return 0;
    } else {

        return 1;
    }
}
 */

int BajaLSOBB(lsobb *lista, Envio envio) {
    lista->costo =0.0;
    int pos, i;
    int encontrado = LocalizarLSOBB(lista, envio.codigo, &pos,1);

    if( (strcmp(lista->envios[pos].direccion , envio.direccion)==0) && (lista->envios[pos].dni_receptor == envio.dni_receptor)
        && (lista->envios[pos].dni_remitente == envio.dni_remitente) && (strcmp(lista->envios[pos].fecha_envio,envio.fecha_envio)==0)
        && (strcmp(lista->envios[pos].fecha_recepcion,envio.fecha_recepcion)==0) && (strcmp(lista->envios[pos].nombre,envio.nombre)==0)
        && (strcmp(lista->envios[pos].nombre_r,envio.nombre_r)==0)){

        if (encontrado) {
            for (i = pos; i < lista->contador - 1; i++) {
                lista->costo++; //corrimiento
                lista->envios[i] = lista->envios[i + 1];
            }

            pos--;
            lista->contador--;



            if (lista->costo > lista->bMax) {

                lista->bMax = lista->costo; //maximo

            }

            lista->tempb+=lista->costo; //promedio


            lista->bMed=lista->tempb/(lista->bCant+1);


            lista->bCant++; //cantidad de bajas
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}





int evocarLSOBB(lsobb *lista, char codigo[], Envio *envio) {
    int pos;
    int encontrado = LocalizarLSOBB(lista, codigo, &pos,0);

    if (encontrado) {

        *envio = lista->envios[pos];
        return 1;
    } else {
        return 0;
    }
}

