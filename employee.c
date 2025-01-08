#include "employee.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

struct employee e;

void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int idGen() {
    srand(time(NULL));
    int randomPart = rand();
    time_t now = time(NULL);
    return (int)(now - randomPart);
    
}

void insertRec() {

    printf("-------------\n");
    printf("|Departments|\n");
    printf("-------------\n");


    printf("managment\n");
    printf("manufacturing\n");
    printf("research\n");
    printf("sales\n");

    printf("Enter employee department like listed above: ");
    fgets(e.department, sizeof(e.department), stdin);
    trimNewline(e.department);

    while ((strncmp(e.department, "management", 10) != 0) 
        && (strncmp(e.department, "manufacturing", 13) != 0)
        && (strncmp(e.department, "research", 8) != 0) 
        && (strncmp(e.department, "sales", 5) != 0)) {

            printf("Error! Incorrect usage, please enter department as listed above.\n");

            fgets(e.department, sizeof(e.department), stdin);
            trimNewline(e.department);
    }

    

    char filename[20]; // Make sure it's large enough to hold the full filename
    snprintf(filename, sizeof(filename), "%s.txt", e.department); // Department name as filename

    FILE *input; 
    input = fopen(filename, "a");

    if(input == NULL){
        printf("Error opening file.");
        return -1; 
    }

    printf("Enter employee first name: ");
    fgets(e.firstName, sizeof(e.firstName),stdin);
    trimNewline(e.firstName);
    //fprintf(input, "%s",e.firstName);

    printf("Enter employee last name: ");
    fgets(e.lastName, sizeof(e.lastName), stdin);
    trimNewline(e.lastName);
    //fprintf(input, "%s",e.lastName);

    printf("Enter employee age: ");
    scanf("%d", &e.age);

    while (e.age < 1 || e.age > 110) {
        printf("Error, please input valid age.\n");
        printf("Enter employee age: ");
        scanf("%d", &e.age);
        //fprintf(input, "%d",e.age);
    }
    getchar();

    printf("Enter employee address: ");
    fgets(e.address, sizeof(e.address), stdin);
    trimNewline(e.address);
    // fprintf(input, "%s",e.address);

    e.id = idGen();
    printf("Employee ID is: %ld", e.id);
    printf("\n");
    // fprintf(input, "%ld",e.id);

    fprintf(input, "Employee %ld: %s %s\nAge: %d\nAddress: %s\nDepartment: %s\n\n", 
        e.id, e.firstName, e.lastName, e.age, e.address, e.department);


    fclose(input);
    printf("Data written to file: %s\n", filename);
}


/*

*/

void deleteRec();         

void findRec();           

void modifyRec();    