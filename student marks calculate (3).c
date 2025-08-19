#include <stdio.h>

int main() {
    int roll_no;
    char name[50];
    int marks[25];
    int total = 0;
    int i;

    printf("Enter the roll_no: ");
    scanf("%d", &roll_no);

    printf("Enter name of the student: ");
    scanf(" %[^\n]s", name);  // To read full name including spaces

    for (i = 0; i < 5; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &marks[i]);  // Corrected to &marks[i]
        total += marks[i];
    }

    printf("Total marks: %d\n", total);

    return 0;
}

