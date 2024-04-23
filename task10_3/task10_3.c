// В файле .txt записан полный адрес файла (возможно, без расширения).
// Необходимо изменить его расширение на ".html" и записать результат в файл
// .txt.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *chng_ext(char *str, char *ext)
{
    size_t size = strlen(str);
    char *tmp = malloc(size+strlen(ext));
    
    for (size_t i = size-1; i>=0; i--)
    {
        if(str[i] == '.')
        {
            strncpy(tmp, str, i);
            tmp[i] = '\0';
            //printf("\n %s %d\n", tmp, i);
            break;
        }
        if (str[i] == '/')
            {
                strcpy(tmp, str);
                //printf("\n %s \n", tmp);
                break;
            }
    }

    strcat(tmp, ext);
    
    return tmp;
}
int main()
{
    char *file_in = "in.txt";
    char *file_out = "out.txt";
    char *res;

    char str[1024];
    FILE *fp;

    fp = fopen(file_in, "r");
    fscanf(fp, "%[^\n]", str);
    fclose(fp);
    res = chng_ext(str, ".html");
    // printf("\n%s", res);
    fp = fopen(file_out, "w");
    fprintf(fp, "%s", res);
    fclose(fp);

    return 0;
}