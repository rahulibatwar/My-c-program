#include <stdio.h>

int main() {
    int age;

    printf("Apni umar (Age) enter kijiye: ");
    scanf("%d", &age); 

    // Pehli Shart: Kya user 18 ya usse bada hai?
    if (age >= 18) {
        printf("Aap ek adult hain aur vote de sakte hain! \n");
    } 
    // Doosri Shart: Agar pehli galat hai, toh kya user 13 ya usse bada hai?
    else if (age >= 13) {
        printf("Aap ek teenager hain. \n");
    } 
    // Aakhri Rasta: Agar upar ki saari shartein galat hain
    else {
        printf("Aap abhi bacche hain. \n");
    }

    return 0;
}