#include "sample run.h"

int main() {
    printf("Welcome to the Extended CLI!\n");

        while (1) {
        printf("Enter a command (add, subtract, multiply, divide, date, concat, callfile, clear, history, exit): ");
        char user_input[20];
        scanf("%s", user_input);

        // Save command in history
        strcpy(command_history[history_index], user_input);
        history_index = (history_index + 1) % MAX_HISTORY_SIZE;

        if (strcmp(user_input, "exit") == 0) {
            printf("Exiting the CLI. Goodbye!\n");
            break;
        } else if (strcmp(user_input, "help") == 0) {
            displayHelp();
        } else if (strcmp(user_input, "add") == 0 || strcmp(user_input, "subtract") == 0 ||
                   strcmp(user_input, "multiply") == 0 || strcmp(user_input, "divide") == 0) {
            performArithmetic(user_input);
        } else if (strcmp(user_input, "date") == 0) {
            displayDateTime();
        } else if (strcmp(user_input, "concat") == 0) {
            concatenateStrings();
        } else if (strcmp(user_input, "callfile") == 0) {
            callFile();
        } else if (strcmp(user_input, "clear") == 0) {
            clearScreen();
        } else if (strcmp(user_input, "history") == 0) {
            displayHistory(command_history, history_index);
        } else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    return 0;
}
