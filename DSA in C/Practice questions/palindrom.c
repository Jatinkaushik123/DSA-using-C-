// palindrom with a string comparing both side number.
#include <stdio.h>
#include <string.h>

int main() {
    char num[20];
    int i, len, flag = 1;

    printf("Enter a number: ");
    scanf("%s", num);

    len = strlen(num);

    for(i = 0; i < len / 2; i++) {
        if(num[i] != num[len - 1 - i]) {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}