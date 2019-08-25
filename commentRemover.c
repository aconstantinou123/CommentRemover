#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 10000
//comment
//comment

void commentRemover();
void removeSingleLineComment(int*, int, char[], int*, bool*);
int removeMultiLineComment();

int main()
{
    commentRemover();
    return 0;
}

void commentRemover()
{
    int c, i, backSlash;
    bool isSingleLine, isMultiLine;

    char s[MAXLINE];
    i = 0;
    backSlash = -1;
    isSingleLine = false;
    isMultiLine = false;

    while ((c = getchar()) != EOF)
    {
        //test comment
        removeSingleLineComment(&i, c, s, &backSlash, &isSingleLine);
        //test comment 2
    }
    printf("string: \n%s", s);

}

void removeSingleLineComment(
    int *i,
    int c,
    char s[], 
    int *backSlash, 
    bool *isSingleLine
    )
{
    if(*backSlash == -1 && c == '/'){
            *backSlash = c;
        } 
        else if (c == '/')
        {
            *isSingleLine = true;
        }
        else if(*isSingleLine == false){
            s[*i] = c;
            (*i)++;
        }
        else if(*isSingleLine == true && c == '\n'){
            *isSingleLine = false;
            *backSlash = -1;
        }
}