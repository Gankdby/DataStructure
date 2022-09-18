#include <stdio.h>
#include <stdlib.h>

typedef struct vol{
    int size, voltou;
    struct vol* next;
    struct vol* prev;
}Voluntario;

//Ref - referencia da lista
Voluntario* inicializaLista(Voluntario* ref){
    ref = (Voluntario*)malloc(sizeof(Voluntario));
    ref->size = 1;
    ref->voltou = 0;
    ref->next = NULL;
    ref->prev = NULL;
    return ref;
}

//preencheLista e criaNo trabalham juntos;
Voluntario* criaNo(Voluntario* aux, Voluntario* ref){
    aux = (Voluntario*)malloc(sizeof(Voluntario));
    aux->prev = ref;
    aux->voltou = 0;
    aux->next = NULL;
    aux->size = ref->size + 1;
    return aux;
}
//Preenchendo a lista para acomodar os possiveis 10ˆ4 voluntarios
Voluntario* preencheLista(Voluntario* ref){
    Voluntario* aux = ref;
    while(aux->size < 10000){
        aux->next = criaNo(aux->next, aux);
        aux = aux->next;
    }
    return ref;
}

Voluntario* liberaMemoria(Voluntario* ref, int nVol){
    Voluntario* aux = ref;
    do{
        aux = aux->next;
    }while(aux->size <= nVol);
    aux->prev->next = NULL;
    free(aux);
    return ref;
}

void naoRetornaram(Voluntario* ref, int ret){
    int v[ret];
    for(int i = 0; i < ret; i++){
        scanf("%d", &v[i]);
        Voluntario* aux = ref;
        if(aux != NULL){
            while(aux->size != v[i]){
                aux = aux->next;
            }
            aux->voltou = 1;
        }
    }
  }

void imprimeNaoRetornou(Voluntario* ref, int n, int r){
    if(n != r){
        while(ref!=NULL){
            if(ref->voltou != 1){
            printf("%d ", ref->size);
        }
            ref = ref->next;
        }
    }
    else{
        printf("*");
    }
}

int main(void) {
    
    Voluntario* ref = inicializaLista(ref);
    ref = preencheLista(ref);

    int n, r;
    scanf("%d %d", &n, &r);

    liberaMemoria(ref, n);

    naoRetornaram(ref, r);
    
    imprimeNaoRetornou(ref, n, r);

    return 0;
}