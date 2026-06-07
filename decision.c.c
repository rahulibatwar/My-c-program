#include <stdio.h>

int main() {
    int age;

    printf("--- Welcome to Dynamic Voter Checker ---\n");
    printf("(Program band karne ke liye Age ko '0' enter karein)\n");

    // while(1) ka matlab hai yeh loop hamesha chalta rahega jab tak hum break nahi karte
    while (1) {
        printf("\nAge enter kijiye: ");
        scanf("%d", &age); 

        // Condition 1: Agar user ne 0 dala, toh loop ko yahin tod do (Exit)
        if (age == 0) {
            break; 
        }

        // Condition 2: Voter checker logic
        if (age >= 18) {
            printf("Aap ek adult hain aur vote de sakte hain! \n");
        } 
        else if (age >= 13) {
            printf("Aap ek teenager hain. \n");
        } 
        else {
            printf("Aap abhi bache hain. \n");
        }
    }

    printf("\nProgram safely closed. Thank you! 🙏\n");
    return 0;
}