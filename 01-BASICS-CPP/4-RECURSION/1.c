#include<stdio.h>
#include<stdbool.h>


bool is_palidrome(char str[], int size, int i){
    if(i>= size /2)return true;
    if(str[i] != str[size-i-1])return false;
    return is_palidrome(str, size, i+1);
}
int main() {
    int size;
    scanf("%d",&size);
    char str[size];
    for(int i=0; i<size; i++) {scanf(" %c",&str[i]);}
    if(is_palidrome(str, size, 0)){printf("Ture");}
    else {printf("False");}
    return 0;
}