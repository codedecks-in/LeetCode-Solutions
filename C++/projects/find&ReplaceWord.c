#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
/*Function to replace a string with another string*/
 
char *rep_str(const char *s, const char *old, const char *new1)
{
    char *ret;
    int i, count = 0;
    int newlen = strlen(new1);
    int oldlen = strlen(old);
 
    for (i = 0; s[i] != '\0'; i++)    
    {
        if (strstr(&s[i], old) == &s[i]) 
        {
            count++;
            i += oldlen - 1;
        }
    }
    ret = (char *)malloc(i + count * (newlen - oldlen));
    if (ret == NULL)
        exit(EXIT_FAILURE);
    i = 0;
    while (*s)
    {
        if (strstr(s, old) == s) //compare the substring with the newstring
        {
            strcpy(&ret[i], new1);
            i += newlen; //adding newlength to the new string
            s += oldlen;//adding the same old length the old string
        }
        else
        ret[i++] = *s++;
    }
    ret[i] = '\0';
    return ret;
}
 
int main(void)
{
    char mystr[100], c[10], d[10];
    printf("Enter a string along with characters to be rep_strd:\n");
    gets(mystr);
    printf("Enter the character to be rep_strd:\n");
    scanf(" %s",c);
    printf("Enter the new character:\n");
    scanf(" %s",d);
    char *newstr = NULL;
 
    puts(mystr);
    newstr = rep_str(mystr, c,d);
    printf("%s\n", newstr);
    free(newstr);
    return 0;
}
