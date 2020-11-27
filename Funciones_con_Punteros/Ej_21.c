  
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ERR_MSJ_NULL_POINTER "ERROR NULL POINTER"

typedef enum {
    OK,
    ERROR_NULL_POINTER
} status_t;

size_t strslen (const char *s);
int strscmp (const char *s_1, const char *s_2);
char * strscat (char *s_1, const char *s_2);
char * strscpy (char *s_1, const char *s_2);
status_t strlwr(char *s);
status_t strupr(char *s);

int main(void){
    char string[] = "Como estas? Mi nombre es Ricardo Fort";
    char str1[] = "Holaa ", str2[] = "Chao", str3 [50];

    size_t len;
    int cmp;
    char *cat, *cpy;
	status_t st;

    len = strslen (string);
    cmp = strscmp (str1, str2);
    cat = strscat (str1, str2);
    cpy = strscpy (str3, str2);
    
    printf("%s%lu\n%s%i\n%s%s\n%s%s\n", "Len: ", len, "Cmp: ", cmp, "*Cat: ", cat, "*Cpy: ", cpy);

    if((st = (strlwr(str1))) != OK){
        fprintf(stderr, "%s\n", ERR_MSJ_NULL_POINTER);
        return st;
    }

    if((st = (strupr(str1))) != OK){
        fprintf(stderr, "%s\n", ERR_MSJ_NULL_POINTER);
        return st;
    }

    return OK;
}

size_t strslen (const char *s){
    size_t len;

    len = strlen(s);

    return len;
}
int strscmp (const char *str1, const char *s2){
    int cmp;

    cmp = strcmp (str1, s2);

    return cmp;
}
char * strscat (char *str1, const char *s2){
    char *cat;

    cat = strcat (str1, s2);

    return cat;
}
char * strscpy (char *s3, const char *s2){
    char *cpy;

    cpy = strcpy (s3, s2);

    return cpy;
}
status_t strlwr(char *str1){
    int i;
    
    if (str1 == NULL){
        return ERROR_NULL_POINTER;
    };

    for (i = 0; *(str1+i); i ++){
        *(str1+i) = tolower(*(str1+i));
    }

    printf("%s%s\n", "lower: ", str1);

    return OK;
}
status_t strupr(char *s2){
    int i;
    
    if (s2 == NULL){
        return ERROR_NULL_POINTER;
    };

    for (i = 0; *(s2+i); i ++){
        *(s2+i) = toupper(*(s2+i));
    }

    printf("%s%s\n", "Upper: ", s2);

    return OK;
}