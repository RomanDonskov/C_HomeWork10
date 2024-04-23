// В файле .txt необходимо удалить все лишние пробелы (в начале предложения
// и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
// записать в .txt.

#include <stdio.h>
#include <string.h>

void del_dbl_sps(char *str)
{
        
    int size = strlen(str);
    int i,j;

    for (i = 0; i<size; i++)
    {
        if (str[0] == ' ')
        {
            for (i = 0; i<size - 1; i++)
                str[i] = str[i+1];
            str[i] = '\0';
            size--;
            i = 0;
            continue;
        }

        if (str[i] == ' ' && str[i+1] == ' ')
        {
            for(j = i; j<size-1; j++)
                str[j] = str[j+1];
            str[j] = '\0';
            size--;
            i--;
        }
    }
}

int main()
{
    char *file_in = "in.txt";
    char *file_out = "out.txt";
    char str[1024];
    FILE *fp;

    fp = fopen(file_in, "r");
    fscanf(fp, "%[^\n]", str);
    fclose(fp);
    
    del_dbl_sps(str);

    fp = fopen(file_out, "w");
    fprintf(fp, "%s", str);
    fclose(fp);

    return 0;
}