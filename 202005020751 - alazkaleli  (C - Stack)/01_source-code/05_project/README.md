libraries ->

    stdio.h
    stdlib.h
    string.h
    mylib.h


functions ->

    struct  stack* newStack(int size);
    void deleteStack(stack* s);
    int pop (stack *s);
    int push(stack * s, int value);
    void display( stack *s);
    void stringReverse(char *str, stack *s);
    int peek(stack* s);
    int isEmpty(stack* s);
    int isFull(stack* s);

test ->

    #define TEST2 0
    to
    #define TEST2 1


compile command ->

    Linux/Unix
        $ gcc project1.c -o [output name]
    Windows
        copy project file here
        C:\MinGW\bin\gcc
        open terminal here(cmd/powershell)
        > gcc project1.c -o [output name]


run command ->

    Linux/Unix
        open terminal
        $ [output name]
    Windows
        open terminal(cmd/powershell)
        > [output name]

