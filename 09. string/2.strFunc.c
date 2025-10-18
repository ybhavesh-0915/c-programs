#include <stdio.h>
#include <string.h>

int main(){
    char str[16] = {'b', 'h', 'a', 'v', 'e', 's', 'h', '\0'};
    char str1[8] = "bhavesh";

    strcat(str, str1);


    int n;
    printf("%s", "Enter the value: ");
    scanf("%d", &n);

    char nameBuffer[n + 1];
    printf("%s", "Enter the name: ");
    scanf("%s", nameBuffer);

    int res = strcmp(str1, nameBuffer);

    printf("%zu\n", strlen(str));
    printf("%zu\n", strlen(str1));
    printf("%zu\n", strlen(nameBuffer));
    printf("%d\n", res);

    printf("%s\n", str);


    
    return 0;
}