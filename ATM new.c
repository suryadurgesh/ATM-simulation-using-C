#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>  // Include stdlib.h for the exit() function

int main() {
    system("color 3F");
    int pin = 1234, option, enteredPin, count = 0, amount = 1;
    float balance = 5000;
    int continueTransaction = 1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t          %s", ctime(&now));
    printf("\n\t\t\t=====================* Welcome to Surya's ATM *=========================");

    while (pin != enteredPin) {
        printf("\nPlease enter your PIN: ");
        scanf("%d", &enteredPin);
        if (enteredPin != pin) {
            Beep(610, 500);
            printf("Invalid PIN !!!\n");
        }
        count++;
        if (count == 3 && pin != enteredPin) {
            printf("Too many incorrect attempts. Exiting...\n");
            exit(0);  // Exit the program after three incorrect attempts
        }
    }

    while (continueTransaction != 0) {
        printf("\n\t\t\t========================* Available Transactions *====================");
        printf("\n\n\t\t1. Withdrawal");
        printf("\n\t\t2. Deposit");
        printf("\n\t\t3. Check Balance");
        printf("\n\n\tPlease select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                while (amount % 500 != 0) {
                    printf("\n\tEnter the amount: ");
                    scanf("%d", &amount);
                    if (amount % 500 != 0) {
                        printf("\n\tThe amount should be a multiple of 500");
                    }
                    if (balance < amount) {
                        printf("\n\tSorry, insufficient balance");
                        amount = 1;
                        break;
                    } else {
                        balance -= amount;
                        printf("\n\tYou have withdrawn Rs.%d. Your new balance is %.2f", amount, balance);
                        amount = 1;
                        break;
                    }
                }
                break;  // Added break to exit the switch case after completing the withdrawal

            case 2:
                printf("\n\tPlease enter the amount: ");
                scanf("%d", &amount);
                balance += amount;
                printf("\n\tYou have deposited Rs.%d. Your new balance is %.2f", amount, balance);
                amount = 1;
                break;

            case 3:
                printf("\n\tYour balance is Rs.%.2f", balance);
                break;

            default:
                Beep(610, 500);
                printf("\n\tInvalid Option !!!");
                break;
        }

        printf("\n\tDo you wish to perform another transaction? Press 1[Yes], 0[No]: ");
        scanf("%d", &continueTransaction);
    }

    printf("\n\t====================================== Thank you for banking with Surya's ATM =========================");

    return 0;
}

