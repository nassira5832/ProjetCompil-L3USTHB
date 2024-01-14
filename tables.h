#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct {
    char name[20];
    char code[20];
    char type[20];
    int value;
    float val;
    struct elt_idf_cst* next;  // Pointeur vers le prochain symbole dans la liste
} elt_idf_cst;

   elt_idf_cst* symbolListHead;
// Initialiser la liste des symboles
void initializeSymbolList(elt_idf_cst** head) {
    *head = NULL;
}
initializeSymbolList(&symbolListHead);  
elt_idf_cst* search(elt_idf_cst* head, const char* entity) {
    elt_idf_cst* current = head;
    while (current != NULL) {
        if (strcmp(current->name, entity) == 0) {
            return current;  // Symbole trouvé
        }
        current = current->next;
    }
    return NULL;  // Symbole non trouvé
}
void insert(elt_idf_cst** head, const char* entity, const char* code, const char* type, int value, int t) {
    // Vérifie si l'entité existe déjà dans la liste
    if (search(*head, entity) == NULL) {
        elt_idf_cst* newSymbol = (elt_idf_cst*)malloc(sizeof(elt_idf_cst));
        strncpy(newSymbol->name, entity, sizeof(newSymbol->name) - 1);
        strncpy(newSymbol->code, code, sizeof(newSymbol->code) - 1);
        strncpy(newSymbol->type, type, sizeof(newSymbol->type) - 1);
        newSymbol->value = value;

        // Ajoute le nouveau symbole à la liste
        newSymbol->next = *head;
        *head = newSymbol;
    }
}



void print(elt_idf_cst* head) {
    printf("\n/******************Table des symboles IDF*******************");
    printf("\n-------------------------------------------------------------\n");
    printf("\t|    Name   |      Code    |   Type    |    Value   | \n");
    printf("-------------------------------------------------------------\n");

    elt_idf_cst* current = head;
    while (current != NULL) {
        printf("\t|%10s | %12s |%10s | %10d |\n", current->name, current->code, current->type, current->value);
        current = current->next;
    }
}


void insert_type( elt_idf_cst* head, const char* entity, const char* type) {
     elt_idf_cst* foundSymbol = search(head, entity);
    if (foundSymbol != NULL) {
        strncpy(foundSymbol->type, type, sizeof(foundSymbol->type) - 1);
    }
}

int check_declaration(elt_idf_cst* head, const char* entity) {
    elt_idf_cst* foundSymbol = search(head, entity);
    if (foundSymbol != NULL && strcmp(foundSymbol->type, "") == 0) {
        return 0; // Déclaration trouvée et le type est vide
    }
    return -1; // Non trouvé ou le type n'est pas vide
} 