#include <shell.h>
int main()
{
    char str[] = "Geeks-for-Geeks";
 
    // Returns first token
    char *token = strtok(str, "-");
   
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }
 
    return 0;
}