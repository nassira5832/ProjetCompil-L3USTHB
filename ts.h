#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures pour les éléments des listes chaînées
typedef struct ElementIdfCst {
    char name[20];
    char code[20];
    char type[20];
    char value[20];
    struct ElementIdfCst* next;
} ElementIdfCst;

typedef struct ElementSepKw {
    char name[20];
    char code[20];
    struct ElementSepKw* next;
} ElementSepKw;

typedef struct ElementKw {
    char name[20];
    char code[20];
    struct ElementKw* next;
} ElementKw;


// Têtes des listes chaînées
ElementIdfCst* headIdfCst = NULL;
ElementSepKw* headSepKw = NULL;
ElementKw* headKw = NULL;

// Fonction de recherche dans la liste chaînée
int search(char entity[], int t) {
    int i = 0;
    switch (t) {
        case 0: {
            ElementIdfCst* current = headIdfCst;
            while (current != NULL) {
                if (strcmp(entity, current->name) == 0)
                    return i;
                current = current->next;
                i++;
            }
            return -1;
        }
        case 1: {
            ElementSepKw* current = headSepKw;
            while (current != NULL) {
                if (strcmp(entity, current->name) == 0)
                    return i;
                current = current->next;
                i++;
            }
            return -1;
        }
        case 2: {
            ElementKw* current = headKw;
            while (current != NULL) {
                if (strcmp(entity, current->name) == 0)
                    return i;
                current = current->next;
                i++;
            }
            return -1;
        }
    }
}

// Fonction d'insertion dans la liste chaînée des identificateurs et constantes
void insertIdfCst(char entity[], char code[], char type[], char value[]) {
    if (search(entity, 0) == -1) {
        ElementIdfCst* newElement = (ElementIdfCst*)malloc(sizeof(ElementIdfCst));
        strcpy(newElement->name, entity);
        strcpy(newElement->code, code);
        strcpy(newElement->type, type);
        strcpy(newElement->value, value);
        newElement->next = headIdfCst;
        headIdfCst = newElement;
    }
}

// Fonction d'insertion dans la liste chaînée des séparateurs et mots-clés
void insertSepKw(char entity[], char code[]) {
    if (search(entity, 1) == -1) {
        ElementSepKw* newElement = (ElementSepKw*)malloc(sizeof(ElementSepKw));
        strcpy(newElement->name, entity);
        strcpy(newElement->code, code);
        newElement->next = headSepKw;
        headSepKw = newElement;
    }
}

// Fonction d'insertion dans la liste chaînée des mots-clés
void insertKw(char entity[], char code[]) {
    if (search(entity, 2) == -1) {
        ElementKw* newElement = (ElementKw*)malloc(sizeof(ElementKw));
        strcpy(newElement->name, entity);
        strcpy(newElement->code, code);
        newElement->next = headKw;
        headKw = newElement;
    }
}


// Fonction pour afficher la liste chaînée des identificateurs et constantes
void printIdfCstList() {
    printf("\n/******************Table des symboles IDF*******************");
    printf("\n-------------------------------------------------------------\n");
    printf("\t|    Name   |      Code    |   Type    |    Value   | \n");
    printf("-------------------------------------------------------------\n");

    ElementIdfCst* current = headIdfCst;

    while (current != NULL) {
        printf("\t|%10s | %12s |%10s | %10d |\n", current->name, current->code, current->type, current->value);
        current = current->next;
    }
}

// Fonction pour afficher la liste chaînée des séparateurs et mots-clés
void printSepKwList() {
    printf("\n/**Table des symboles Separateurs**");
    printf("\n------------------------------\n");
    printf("\t|    Name   |      Code    |\n");
    printf("------------------------------\n");

    ElementSepKw* current = headSepKw;

    while (current != NULL) {
        printf("\t|%10s | %12s |\n", current->name, current->code);
        current = current->next;
    }
}

// Fonction pour afficher la liste chaînée des mots-clés
void printKwList() {
    printf("\n/**Table des symboles mots clés**");
    printf("\n------------------------------\n");
    printf("\t|    Name   |      Code    |\n");
    printf("------------------------------\n");

    ElementKw* current = headKw;

    while (current != NULL) {
        printf("\t|%10s | %12s |\n", current->name, current->code);
        current = current->next;
    }
}

// Fonction pour afficher les listes chaînées
void print() {
    printIdfCstList();
    printSepKwList();
    printKwList();
    // Ajoutez d'autres fonctions similaires pour les listes chaînées manquantes si nécessaire.
}

// Fonction pour insérer le type dans la liste chaînée des identificateurs et constantes
void insert_type(char entity[], char type[]) {
    int pos = search(entity, 0);
    if (pos != -1) {
        strcpy(headIdfCst[pos].type, type);
    }
}

// Fonction pour vérifier la déclaration dans la liste chaînée des identificateurs et constantes
int check_declaration(char entity[]) {
    int pos = search(entity, 0);
    if (pos != -1 && strcmp(headIdfCst[pos].type, "") == 0)
        return 0;
    return -1;
}
