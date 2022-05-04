#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct listas mathitwn
struct studentList{
    char AM[20], name[20], surname[20], patronym[20], address[20];
    int phoneNumber;
    long mobileNumber;
    //pointer gia linked list
    struct studentList *next;
};
//struct gia mathimata
struct class{
    char className[20];
    //dexetai lista mathitwn
    struct studentList studentList;
    struct class* next;
};

//prosthetoume tous kainourgious mathites
struct studentList append(struct studentList **head, char *new_AM, char *new_name, char *new_surname, char *new_patronym, char *new_address, int new_phoneNumber,
           long new_mobileNumber )
{
    //megethos tis listas stin mnimi
    struct studentList *list = malloc(sizeof( struct studentList ) );
    //check an arxikoopoiithike
    int success = list != NULL;

    //dinoume ta values
    if ( success )
    {
        strcpy(list->AM, new_AM);
        strcpy(list->name, new_name);
        strcpy(list->surname, new_surname);
        strcpy(list->patronym, new_patronym);
        strcpy(list->address, new_address);
        list->phoneNumber = new_phoneNumber;
        list->mobileNumber = new_mobileNumber;

        //pame ston epomeno pointer
        while( *head != NULL ) head = &( *head )->next;
        *head = list;
    }
    //epistrefoume lista
    return *list;
}

//prosthetoume tin lista twn mathitwn sto mathima
struct studentList appendList(struct studentList **head,char className, struct studentList studentList)
{
    struct studentList *list = malloc(sizeof( struct studentList ) );
    int success = list != NULL;

    if ( success )
    {
        className = className;
        strcpy(list->AM, studentList.AM);
        strcpy(list->AM, studentList.AM);
        strcpy(list->AM, studentList.AM);
        strcpy(list->AM, studentList.AM);
        strcpy(list->AM, studentList.AM);
        list->phoneNumber = studentList.phoneNumber;
        list->mobileNumber = studentList.mobileNumber;

        while( *head != NULL ) head = &( *head )->next;

        *head = list;
    }

    return *list;
}

//prosthesi stin lista mathimatwn
struct class appendClass(struct class **head, char *className, struct studentList studentList)
{
    struct class *list = malloc(sizeof( struct class ) );
    int success = list != NULL;

    if ( success )
    {
        strcpy(list->className, className);
        struct studentList* head_student = NULL;
        list->studentList = appendList(&head_student, *className, studentList);

        while( *head != NULL ) head = &( *head )->next;

        *head = list;
    }

    return *list;
}


//print tous mathites apo tin lista twn mathitwn
void printStudents(struct studentList *head){

    while (head != NULL){
        printf("O arithmos mitroou einai: %s\nTo onoma tou einai: %s \n"
               "To epitheto tou einai:%s\nTo patronimo tou einai: %s\nExei dieuthinsi: %s\nStathero tilefwno: %d\n"
               "Kinito: %lu \n*****\n", head->AM, head->name, head->surname,
               head->patronym,
               head->address, head->phoneNumber, head->mobileNumber);
        //pame ston epomeno pointer
        head = head->next;
    }
}
//print tin lista twn mathitwn apo to mathima
void printClass(struct studentList *studentListpointer, struct class t){
    printf("Mesa sto mathima:%s oi eggegrammenoi mathites einai : \n", t.className);
    printStudents(studentListpointer);
}
int main() {
    //first bullet
    //kanoume append enan mathiti
    struct studentList* head_student = NULL;
    append(&head_student, "mppl20065", "Michael", "Politakis", "Pavlos",
                  "Piraeus 30", 210341556, 698745362);
//    printStudents(head_student);

    //second bullet
    //append lista mathitwn
    append(&head_student,"mppl20062", "Pavlos", "Lampropoulos", "Pavlos",
                           "Piraeus 21", 210321556, 6987453112);
    append(&head_student,"mppl20063", "Nikos", "Kalatzidis", "Omiros",
                  "Athens 12", 210343556, 6987453992);
    append(&head_student,"mppl20063", "Nikos", "Nikolaou", "Omiros",
           "Athens 2", 210343556, 69874323992);

   // printStudents(head_student);

    //third bullet
    //arxikopoioume lista mathitwn
    struct studentList* head_class_student = NULL;
    //arxikopoioume pointer gia tin lista mathimatwn
    struct class* head_class = NULL;
    struct studentList classList = append(&head_class_student,"mppl20063", "Nikos", "Nikolaou", "Omiros",
            "Athens 2", 210343556, 69874323992);
    classList = append(&head_class_student,"mppl20063", "Nikos", "Kalatzidis", "Omiros",
                              "Athens 12", 210343556, 6987453992);
    char classname[30] = "Domes Dedomenon";
    //dimiourgoume to mathima 1
    struct class t = appendClass(&head_class, classname, classList);
    printClass(head_class_student, t);

    return 0;
}
