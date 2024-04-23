// В файле .txt записаны символы. Необходимо разработать функцию, которая
// меняет местами пары соседних символов не обращая внимание на символы
// пробел. Если количество символов нечетно (пробелы не считаем), то
// последний символ не меняем. Результат записать в файл .txt.
#include <stdio.h>
#include <string.h>

void swap_simb(char *str)
{
    int i,j;
    i = 0;
    int size = strlen(str);
    char tmp;
    while (i<size)
    {
        while (str[i] == ' ')
            i++;
    j = i+1;
    while (str[j] == ' ')
        j++;
    if (j>=size) 
        break;
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    i = j+1;
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

    swap_simb(str);

    fp = fopen(file_out, "w");
    fprintf(fp, "%s", str);
    fclose(fp);

    return 0;
}