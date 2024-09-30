#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
    unsigned int rollno;
    char name[20];
    float marks[3]; // Store marks as a float array
}students;

int main() {
    students *p1;
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    p1 = (students*)malloc(numStudents * sizeof(students));
    char subjects[3][20] = {"Maths", "Science", "Social"};


    printf("Enter the Students details by name,\nRoll no(unsigned int),\nMaths marks, physics marks, chemistry marks\n");

    for (int i = 0; i < numStudents; i++) {
        printf("Enter roll number for student %d: ", i + 1);
        scanf("%u", &(p1 + i)->rollno);

        // Clear input buffer before using fgets
        while(getchar() != '\n');

        printf("Enter name for student %d: ", i + 1);
        fgets((p1 + i)->name, sizeof((p1 + i)->name), stdin);
        // Remove newline character from name if present
        if ((p1 + i)->name[strlen((p1 + i)->name) - 1] == '\n') {
            (p1 + i)->name[strlen((p1 + i)->name) - 1] = '\0';
        }
        for(int j=0;j<3;j++)
        {
            printf("Enter marks for student %d in subject %s: ", i + 1,subjects[j]);
            scanf("%f", &(p1 + i)->marks[j]);
        }
    }

    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Maximum marks in each subject\n");
        printf("2. Minimum marks in each subject\n");
        printf("3. Average marks in each subject\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Find maximum marks in each subject
                float maxMaths = p1[0].marks[0], maxPhysics = p1[0].marks[1], maxChemistry = p1[0].marks[2];
                for (int i = 1; i < numStudents; i++) {
                    if (p1[i].marks[0] > maxMaths) {
                        maxMaths = p1[i].marks[0];
                    }
                    if (p1[i].marks[1] > maxPhysics) {
                        maxPhysics = p1[i].marks[1];
                    }
                    if (p1[i].marks[2] > maxChemistry) {
                        maxChemistry = p1[i].marks[2];
                    }
                }
                printf("\nMaximum marks in Maths: %.2f\n", maxMaths);
                printf("Maximum marks in Physics: %.2f\n", maxPhysics);
                printf("Maximum marks in Chemistry: %.2f\n", maxChemistry);
                break;
            }
            case 2: {
                // Find minimum marks in each subject
                float minMaths = p1[0].marks[0], minPhysics = p1[0].marks[1], minChemistry = p1[0].marks[2];
                for (int i = 1; i < numStudents; i++) {
                    if (p1[i].marks[0] < minMaths) {
                        minMaths = p1[i].marks[0];
                    }
                    if (p1[i].marks[1] < minPhysics) {
                        minPhysics = p1[i].marks[1];
                    }
                    if (p1[i].marks[2] < minChemistry) {
                        minChemistry = p1[i].marks[2];
                    }
                }
                printf("\nMinimum marks in Maths: %.2f\n", minMaths);
                printf("Minimum marks in Physics: %.2f\n", minPhysics);
                printf("Minimum marks in Chemistry: %.2f\n", minChemistry);
                break;
            }
            case 3: {
                // Calculate average marks in each subject
                float sumMaths = 0, sumPhysics = 0, sumChemistry = 0;
                for (int i = 0; i < numStudents; i++) {
                    sumMaths += p1[i].marks[0];
                    sumPhysics += p1[i].marks[1];
                    sumChemistry += p1[i].marks[2];
                }
                float avgMaths = sumMaths / numStudents;
                float avgPhysics = sumPhysics / numStudents;
                float avgChemistry = sumChemistry / numStudents;
                printf("\nAverage marks in Maths: %.2f\n", avgMaths);
                printf("Average marks in Physics: %.2f\n", avgPhysics);
                printf("Average marks in Chemistry: %.2f\n", avgChemistry);
                break;
            }
            
            case 4:
                printf("\nExiting...\n");
                free(p1);
                return 0;
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
