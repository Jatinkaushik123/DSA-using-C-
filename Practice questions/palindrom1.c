// this is how you will check with reversing weather the number is palindrom or not 
#include <stdio.h>
int main (){
    int x ;
    int reverse =0 ;
    printf("Enter the nUMBER");
    scanf("%d", &x);
    int original=x;
    while(x>0){
        int digit= x%10;
        reverse= reverse*10 + digit;
        x= x/10;
    }
    if(reverse==original){
        printf("PALINDROME!");
    }
    else{
        printf("NOT A PALINDROME !");
    }
    return 0; 
}
