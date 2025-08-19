#include <stdio.h>
#define MAX 10

int stack[MAX];
int topA = -1;
int topB = MAX;

// Push into Stack A
void pushA(int val) {
    if (topA == topB - 1) {
        printf("\nOVERFLOW in Stack A\n");
    } else {
        topA++;
        stack[topA] = val;
    }
}

// Pop from Stack A
int popA() {
    int val;
    if (topA == -1) {
        printf("\nUNDERFLOW in Stack A\n");
        val = -999;
    } else {
        val = stack[topA];
        topA--;
    }
    return val;
}

int peekA() {
    if (topA == -1) {
        printf("Stack A is empty\n");
        return -999;
    }
    return stack[topA];
}
// Display Stack A
void display_stackA() {
    int i;
    if (topA == -1) {
        printf("\nStack A is Empty\n");
    } else {
        for (i = topA; i >= 0; i--)
            printf("%d\t", stack[i]);
        printf("\n");
    }
}







// Main function
int main() {
    int option, val;

    do {
        printf("\n***** MENU *****\n");
        printf("1. PUSH in Stack A\n");
       
        printf("2. POP from Stack A\n");
       
        printf("3. DISPLAY Stack A\n");
        printf("4. PEEK Stack A\n");


        
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
    switch (option) {
            case 1:
                printf("Enter value to PUSH in Stack A: ");
                scanf("%d", &val);
                pushA(val);
                break;

            

            case 2:
                val = popA();
                if (val != -999)
                    printf("Value popped from Stack A = %d\n", val);
                break;

            
            case 3:
                printf("Contents of Stack A: ");
                display_stackA();
                break;
                
                
            case 4:
    			val = peekA();
			    if (val != -999)
			 	printf("Top of Stack A = %d\n", val);
			    break;

            
            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 5);

    return 0;
}

