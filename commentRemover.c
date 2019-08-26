#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 10000
//comment
//comment
/*test
    comment */

void commentRemover();
void removeSingleLineComment(int*, int*, bool*);
void removeMultiLineComment(int*, int*, int*, bool*);

int main()
{
    commentRemover();
    return 0;
}

void commentRemover()
{
    int c, i, backSlash, pChar;
    bool isSingleLine, isMultiLine;

    char s[MAXLINE];
    i = 0;
    backSlash = -1;
    isSingleLine = false;
    isMultiLine = false;

    while ((c = getchar()) != EOF)
    {
        //test comment
        if(isMultiLine == false)
        {
            removeSingleLineComment(&c, &backSlash, &isSingleLine);
        }
        if(isSingleLine == false)
        {
            removeMultiLineComment(&c, &backSlash, &pChar, &isMultiLine);
        }
        //test comment 2
        if(isSingleLine == false && isMultiLine == false && backSlash == - 1){
            s[i] = c;
            i++;
        }
    }
    printf("string: \n%s", s);
    /* test comment */
}

void removeSingleLineComment(
    int *c,
    int *backSlash, 
    bool *isSingleLine
    )
{
    if(*backSlash == -1 && *c == '/'){
            *backSlash = *c;
    } 
    else if (*c == '/')
    {
        *isSingleLine = true;
    }
    //more comments
    else if(*isSingleLine == true && *c == '\n'){
        *c = '\b';
        *isSingleLine = false;
        *backSlash = -1;
    }
}

void removeMultiLineComment(
    int *c,
    int *backSlash,
    int *pChar,
    bool *isMultiline
    )
{
    if(*backSlash == -1 && *c == '/'){
            *backSlash = *c;
    } 
    else if (*isMultiline == false && *c == '*' && *pChar == '/')
    {
        *isMultiline = true;
    }
    else if(*isMultiline == true && *c == '/' && *pChar == '*'){
        *c = '\b';
        *isMultiline = false;
        *backSlash = -1;
    }
    *pChar = *c;
}