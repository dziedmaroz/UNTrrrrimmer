#include <stdio.h>

void tabulation (FILE* fout,int n);
int main(int argc, char *argv[])
{
    FILE* fin = fopen (argv[1],"r");
    FILE* fout = fopen (argv [2],"w");
    int braces = 0;
    int roundBraces = 0;
    bool nothingToChange = false;
    char* currentChar = new char ;
    char* previousChar = new char;
    while (!feof (fin))
    {

        *currentChar=fgetc(fin);
        if (*currentChar!=-1)
        {
            if (*currentChar=='}')
            {
                fprintf (fout,"\n");
                braces--;
                tabulation (fout,braces);
            }
            if (*currentChar=='{')
            {
                fprintf (fout,"\n");
                tabulation (fout,braces);
                braces++;
            }
            if (*currentChar=='(')
            {
                roundBraces++;
            }
            if (*currentChar==')')
            {
                roundBraces--;
            }

            if (!((*previousChar==';' || *previousChar=='}' || *previousChar=='{') && *currentChar==' ')) fputc(*currentChar,fout);

            if (*currentChar==';' && roundBraces==0)
            {
                fprintf (fout,"\n");
                tabulation (fout,braces);
            }
            if (*currentChar=='}')
            {
                fprintf (fout,"\n");
                tabulation (fout,braces);
            }
            if (*currentChar=='{')
            {
                fprintf (fout,"\n");
                tabulation (fout,braces);
            }
        }
        if (*currentChar!=' ') *previousChar = *currentChar;
    }
    fclose (fin);
    fclose (fout);
    delete currentChar;
    delete previousChar;

    return 0;
}

void tabulation (FILE* fout,int n)
{
    for (int i=0;i<n*4;i++) fprintf (fout," ");
}
