#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct employee {               // employee struct
    char firstName[10];
    char lastName[10];
    int age;
    char address[20];
    char department[15];
    long id;

};

int idGen();               // function to generate random id

void insertRec();           // function to add employee

void deleteRec();           // function to remove employee

void findRec();             // function to find employee

void modifyRec();           // function to modify employee record
