#include <stdio.h>
#include <stdlib.h>

// linklist with pointer
struct list {
    int number;
    struct list *next;


};
//svhnei to prwto stoixeio ths listas

int pop(struct list **AddressOfHead) {
    struct list *temp = *AddressOfHead;
    struct list *prev=temp;
    while (temp->next) {
                prev=temp;
                temp=temp->next;
    }
    prev->next=temp->next;
    return temp->number;
}


//vazw stoixeia
struct list append(struct list **head, int new_number) {
    //ftiaxnw to size sth mnhmh
    struct list *list = malloc(sizeof(struct list));
    //tsekarw an einai adeia
    int success = list != NULL;
    //an den einai adeia
    if (success) {
        //vazw to kainourio noumero
        list->number = new_number;
        //paw sto epomeno stoixeio sth lista
        while (*head != NULL) head = &(*head)->next;
        *head = list;
    }
    //epistrefw th lista
    return *list;
}

//kanei print olh th lista
void printlist(struct list *next) {
    struct list *ptr = next;
    while (ptr) {
        printf("| %d |", ptr->number);
        ptr = ptr->next;

    }
}

int main() {
    //arxikopoihsh tou pointer
    struct list *next = NULL;
    int choice, number;
    int N;

    while (1) {
        printf("MENU\n");
        printf("*******\n");
        printf("1-Othisi\n");
        printf("2-Eksagwgi\n");
        printf("3-Ektypwsi\n");
        printf("4-Eksodos\n");
        printf("Epilogi?\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Dwse Stoixeio:\n");
                scanf("%d", &number);
                append(&next, number);

                printf("Egine i othisi");

                break;
            case 2:
                N = pop(&next);
                printf("to noumero pou svhsame einai: %d", N);
                break;
            case 3:
                printlist(next);
                break;
            case 4:
                printf("Bye bye!");
                return 0;
            default:
                printf("You entered invalid number");
        }
        printf("\n\n\n");
    }


    return 0;

};
