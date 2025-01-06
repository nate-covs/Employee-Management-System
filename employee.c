#include "employee.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee e;

void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void idGen() {
    srand(time(NULL));
    int randomPart = rand();
    time_t now = time(NULL);
    e.id = now - randomPart;
}

void insertRec() {

    printf("Enter employee first name: ");
    fgets(e.firstName, sizeof(e.firstName),stdin);
    trimNewline(e.firstName);

    printf("Enter employee last name: ");
    fgets(e.lastName, sizeof(e.lastName), stdin);
    trimNewline(e.lastName);

    printf("Enter employee age: ");
    scanf("%d", &e.age);
    if(e.age < 1 || e.age > 110) {
        printf("Error, please input valid age.\n");
        printf("Enter employee age: ");
        scanf("%d", &e.age);
    }
    getchar();

    printf("Enter employee address: ");
    fgets(e.address, sizeof(e.address), stdin);
    trimNewline(e.address);

    printf("Enter employee department: ");
    fgets(e.department, sizeof(e.department), stdin);
    trimNewline(e.department);

    printf("Employee ID is: %ld", e.id);

}

void deleteRec();         

void findRec();           

void modifyRec();    