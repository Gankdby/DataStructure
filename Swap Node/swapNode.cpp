#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value, size;
    struct node *next;
    struct node *prev;
} Node;

Node* initializeList(Node* ref)
{
    ref = NULL;
    return ref;
}

Node* insertBegin(Node* ref)
{
    printf("Entre com o valor que deseja inserir no inicio da lista: ");
    int inputValue;
    scanf("%i", &inputValue);
    if (ref == NULL)
    {
        ref = (Node*)malloc(sizeof(Node));
        ref->value = inputValue;
        ref->size = 1;
        ref->next = NULL;
        ref->prev = NULL;

        return ref;
    }

    Node* newNode = NULL;
    if (ref->next == NULL)
    {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->next = ref;
        newNode->prev = NULL;
        newNode->value = inputValue;
        ref->prev = newNode;
        newNode->size = ref->size;
        while(ref!=NULL){
          ref->size++;
          ref = ref->next;
        }

        return newNode;
    }
    
    newNode = (Node*)malloc(sizeof(Node));
    newNode->next = ref;
    newNode->prev = NULL;
    ref->prev = newNode;
    newNode->value = inputValue;
    newNode->size = ref->size;
    while(ref!=NULL){
          ref->size++;
          ref = ref->next;
    }

    return newNode;
}

Node* insertEnd(Node* ref)
{
    printf("Entre com o valor que deseja inserir no fim da lista: ");
    int inputValue;
    scanf("%i", &inputValue);
    if (ref == NULL)
    {
        ref = (Node*)malloc(sizeof(Node));
        ref->value = inputValue;
        ref->size = 1;
        ref->size++;
        ref->next = NULL;
        ref->prev = NULL;

        return ref;
    }

    Node* aux = ref;
    Node* newNode = (Node*)malloc(sizeof(Node));

    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    if (aux->next == NULL){
        aux->next = newNode;
        newNode->value = inputValue;
        newNode->next = NULL;
        newNode->prev = aux;
        newNode->size = aux->size + 1;
        return ref;
    }
    return ref;
}

int searchLarger(Node* searchLarger)
{
    Node* aux = searchLarger;
    int larger = 0;

    while (aux != NULL)
    {
        if (aux->value > larger)
        {
            larger = aux->value;
        }

        aux = aux->next;
    }
    return larger;
}

Node* swapLargerNode(Node *swapLarger, int number)
{
    Node *aux = swapLarger;

    while (aux->value != number)
    {
        aux = aux->next;
    }
    
    Node* store = aux;

    if (aux->prev == NULL)
    {
        printf("\n==O elemento já esta no início da lista==\n");
        return swapLarger;
    }
    else if (aux->next == NULL)
    {
        aux->prev->next = NULL;
        aux->next = swapLarger;
        swapLarger->prev = aux;
        aux->prev = NULL;
        aux->size = 1;
        while(swapLarger!=NULL){
            swapLarger->size++;
            swapLarger = swapLarger->next;
        }
        return aux;
    }
    
    else{
    while (store->next!=NULL){
        store->next->size--;
        store = store->next;
    }
    
    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;
    aux->next = swapLarger;
    swapLarger->prev = aux;
    aux->prev = NULL;
    aux->size = 1;
    while(swapLarger!=NULL){
        swapLarger->size++; 
        swapLarger = swapLarger->next;
    }
    return aux;
    }
    return aux;
}

void printList(Node* ref)
{
    do
    {
        printf("Elemento: [%i] - Posicao[%i]\n", ref->value, ref->size);
        ref = ref->next;
    } while (ref != NULL);
}

int main()
{
    // Function to inicialize list
    Node* ref;
    ref = initializeList(ref);

    // Function to insert Node at the beginning

    ref = insertBegin(ref);
    ref = insertBegin(ref);
    ref = insertBegin(ref);

    // Function to insert Node at the end

    ref = insertEnd(ref);
    ref = insertEnd(ref);
    ref = insertEnd(ref);
    
    // Function to search for the largest number on the list
    int larger = searchLarger(ref);

    // Function to swap Node with the larger number to start of the list
    ref = swapLargerNode(ref, larger);

    // Function to print the list
    printList(ref);
    return 0;
}