#include "employee.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

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
    return abs((int)(now - randomPart));
    
}

void insertRec() {

    printf("-------------\n");
    printf("|Departments|\n");
    printf("-------------\n");


    printf("management\n");
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

            printf("Error! Incorrect usage, please enter department as listed above:\n");

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

void deleteRec() {
    // want to be able find employee in department, or insert name and list employees with that name in departments

    printf("-------------\n");
    printf("|Departments|\n");
    printf("-------------\n");


    printf("management\n");
    printf("manufacturing\n");
    printf("research\n");
    printf("sales\n");

    printf("Enter department name listed above of employee to delete:");

    fgets(e.department, sizeof(e.department), stdin);
    trimNewline(e.department);

    while ((strncmp(e.department, "management", 10) != 0) 
        && (strncmp(e.department, "manufacturing", 13) != 0)
        && (strncmp(e.department, "research", 8) != 0) 
        && (strncmp(e.department, "sales", 5) != 0)) {

            printf("Error! Incorrect usage, please enter department as listed above:\n");

            fgets(e.department, sizeof(e.department), stdin);
            trimNewline(e.department);
    }

    

    char filename[20]; // Make sure it's large enough to hold the full filename
    snprintf(filename, sizeof(filename), "%s.txt", e.department); // Department name as filename

    FILE *delete; 
    delete = fopen(filename, "r+");

    if(delete == NULL){
        printf("Error opening file.");
        return -1; 
    }

    printf("Enter employee name to be removed: ");
    char name[40];
    fgets(name, sizeof(name), stdin);

    trimNewline(name);

    char line[256];
    long pos = ftell(delete);

    FILE *temp;
    temp = fopen("temp.txt", "w");

    if(temp == NULL){
        printf("Error opening file.");
        return -1; 
    }

    while (fgets(line, sizeof(line), delete) != NULL) {
        if (strstr(line, name) != NULL) {
            printf("Deleting line with name: %s\n", line);
            
            // Skip next 3 lines
            for (int i = 0; i < 4; i++) {
                if (fgets(line, sizeof(line), delete) == NULL) {
                    break;  // If there are fewer than 4 lines remaining, break out of the loop
                }
            }
        } 
        else {
            fputs(line, temp);
        }
    }
    
    fclose(temp);
    fclose(delete);

    if(remove(filename) == 0){
        if(rename("temp.txt", filename) == 0){
            printf("Employee and old log deleted successfully.\n");
        }
        else{
            printf("Error renaming new log file.\n");
        }
    }
    else{
        printf("Error removing employee and old log file.\n");
    }

}         

void findRec();           

void modifyRec();    