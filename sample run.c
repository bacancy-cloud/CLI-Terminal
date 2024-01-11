#include "sample run.h"


 char command_history[MAX_HISTORY_SIZE][20];  // Array to store command history
 int history_index = 0;  // Index to keep track of the current position in history
// Function definitions
void displayHelp() {
    printf("Available commands:\n");
    printf("1. add : \tWill add two numbers and will show the output\n");
    printf("2. subtract : \tWill subtract the two given numbers and show the output\n");
    printf("3. multiply : \tWill multiply the given two numbers and show the output \n");
    printf("4. divide : \tWill divide the two given numbers and provide the output\n");
    printf("5. date : \tDisplay current date and time\n");
    printf("6. concat : \tConcatenate two strings\n");
    printf("7. callfile : \tCall a file on your PC\n");
    printf("8. clear : \tClear the screen\n");
    printf("9. history : \tDisplay command history\n");
    printf("10. exit\n");
}

void performArithmetic(char* operation) {
    double num1, num2;
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    double result;
    if (strcmp(operation, "add") == 0) {
        result = num1 + num2;
    } else if (strcmp(operation, "subtract") == 0) {
        result = num1 - num2;
    } else if (strcmp(operation, "multiply") == 0) {
        result = num1 * num2;
    } else if (strcmp(operation, "divide") == 0) {
        result = (num2 != 0) ? num1 / num2 : 0.0;
        if (num2 == 0) {
            printf("Error: Division by zero is not allowed.\n");
        }
    }

    printf("Result: %.2lf\n", result);
}

void displayDateTime() {
    time_t t;
    struct tm* current_time;

    time(&t);
    current_time = localtime(&t);

    printf("Current date and time: %s", asctime(current_time));
}

void concatenateStrings() {
    char string1[50], string2[50];
    printf("Enter the first string: ");
    scanf("%s", string1);
    printf("Enter the second string: ");
    scanf("%s", string2);

    strcat(string1, string2);
    printf("Concatenated string: %s\n", string1);
}


void callFile() {
    // Update the file name or provide an absolute path to the file
    char file_path[] = "D:\bacancy - git updates\task 2\wow"; // Update the file name or provide the full path

    FILE* file = fopen(file_path, "r");

    if (file != NULL) {
        printf("File content:\n");

        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }

        fclose(file);
    } else {
        perror("Error");
        printf("File path: %s\n", file_path); // Print the file path for debugging
    }
}

void clearScreen() {
    // Clear screen command for Windows and Unix-like systems
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Unix-like systems (Linux, macOS)
    #endif
}

void displayHistory(char command_history[MAX_HISTORY_SIZE][20], int history_index) {
    printf("Command History:\n");
    for (int i = 0; i < MAX_HISTORY_SIZE; i++) {
        if (strlen(command_history[i]) > 0) {
            printf("%d. %s\n", i + 1, command_history[i]);
        }
    }
}
