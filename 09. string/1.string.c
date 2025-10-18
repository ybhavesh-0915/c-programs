#include <stdio.h>
#include <string.h>

int main()
{
    char str[8] = {'b', 'h', 'a', 'v', 'e', 's', 'h', '\0'};
    char str1[8] = "bhavesh";

    char str2[] = {'b', 'h', 'a', 'v', 'e', 's', 'h', '\0'};
    char str3[] = "bhavesh";

    char str4[] = "abcd";
    char str5[5];
    strcpy(str5, str4);

    
    // char str6[100] = str4; //throws error

    int n;
    printf("%s", "Enter the value: ");
    scanf("%d", &n);

    char nameBuffer[n + 1];
    printf("%s", "Enter the name: ");
    scanf("%s", nameBuffer);

    printf("%s\n", str);
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%s\n", str4);
    printf("%s\n", str5);
    printf("your name is %s\n", nameBuffer);

    // for (int i = 0; i <= n; i++)
    // {
    //     printf("%c\n", nameBuffer[i]);
    // }

    return 0;
}