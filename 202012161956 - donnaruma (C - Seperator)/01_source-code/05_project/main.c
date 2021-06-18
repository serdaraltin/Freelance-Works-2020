#include <stdio.h>
#include <string.h>

#define NODLEN 10
#define MAXLEN 250

int lasLen = 0;

int separator(FILE *fileOutput, char *word, int count)
{
    int i = 0;

    if (word[0] == '\0')
    {
        return 0;
    }

    if (word[0] == '(')
    {
        count += 1;
    }

    if (word[0] == ')')
    {
        count -= 1;
    }

    if (word[-2] != ',' && word[-1] == '(' && word[0] != '(' && word[0] != ',')
    {
        for (i = 0; i < count; ++i)
        {
            fprintf(fileOutput, "-");
        }
        lasLen=0;
    }

    if (word[-1] == ',')
    {
        for (i = 0; i < count; ++i)
        {
            fprintf(fileOutput, "-");
        }
        lasLen=0;
    }

    if (word[0] == ',')
    {
        fprintf(fileOutput, "\n");
    }

    if (word[0] != ',' && word[0] != '(' && word[0] != ')')
    {
        if(lasLen <= 10){
	        fprintf(fileOutput, "%c", word[0]);
	        lasLen++;
    	}else{
    		fclose(fileOutput);
    		FILE *fileOutput = fopen("output.txt", "w");
    		fprintf(fileOutput, "%c", ' ');
    		return 0;
    	}
    }

    return separator(fileOutput, &word[1], count);
}

int main()
{
    FILE *fileInput = fopen("input.txt", "r");

    char word[MAXLEN];
    char *garb;
    int i;
    int len;

    fgets(word, MAXLEN, fileInput);

    len = strlen(word);

    word[len - 1] = '\0';

    for (i = 0; word[i] == ' ' || word[i] == '\t'; i++)
    {
        garb = &word[i];
    }

    FILE *fileOutput = fopen("output.txt", "w");

    separator(fileOutput, word, 0);

    fclose(fileInput);
    fclose(fileOutput);

    return 0;
}