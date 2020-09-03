#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <malloc.h>

#define STRLEN 80

typedef struct{
    char *word; //word and corresponding hint
    char *clue;
    int x; //Starting x and y positions
    int y;
    char direction; //H for horizontal, V for vertical
    int f; //solved or not
} Word_t;

Word_t* loadTextFile( FILE* myFile, int nr );
void displayBoard(int rows, int cols, char** myBoard);
int isBoardFilled(int rows, int cols, char** myBoard);
char** createArray(int rows, int cols);
int findIndex(int arr[], int size, int val);
void playGame(char** myBoard, int words, Word_t *word, int x, int y);
char** updateBoard(char** myBoard, Word_t *words, int solve);

int main(void)
{
    FILE *inp;
    char textLine[STRLEN];
    int rows, cols, words;
    Word_t *array;
    char **board;

    printf("CMPE 252 HW1 PUZZLE GAME\n\n");
    printf("Enter the name of the text file:\n");
    scanf("%s",textLine);

    inp = fopen(textLine,"r");

    if(inp == NULL)
	{
        printf("Failed to open file\n");
    }

    fscanf(inp,"%d %d %d", &rows, &cols, &words);
    printf("Game is %d rows x %d cols with %d words\n", rows, cols, words);

    array = (Word_t*)malloc(words * sizeof(Word_t));
    array = loadTextFile(inp,words);

    board = createArray(rows,cols);

    playGame(board, words, array, cols, rows);

    free(inp);
    free(board);
    free(array);

    return 0;
}

Word_t* loadTextFile( FILE* myFile, int nrWords )
{
    Word_t *arr = (Word_t *)malloc(nrWords * sizeof(Word_t));
    char TempW[10];
    char TempC[128];

    int i = 0;
    while(i < nrWords)
    {
        fscanf(myFile, " %c %d %d %s %[^\n]", &arr[i].direction, &arr[i].x, &arr[i].y, TempW, TempC);
        arr[i].f = 0;

        arr[i].clue = (char *)malloc(strlen(TempC) + 1);
        arr[i].word = (char *)malloc(strlen(TempW) + 1);

        strcpy(arr[i].word,	TempW);
        strcpy(arr[i].clue, TempC);

        i++;
    }
    printf("Words and clues are read!\n");
    return arr;
}

char** createArray(int rows, int cols)
{
    char** board = (char**)malloc(sizeof(char*) * cols);

    for(int i = 0; i < cols; ++i) {
        board[i] = (char*)malloc(sizeof(char) * rows);
    }

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            board[i][j] = '#';
        }
    }
    return board;
}

void displayBoard(int rows, int cols, char** myBoard)
{
    printf("\n\t ");
    for(int i = 1; i <= cols; i++)
    {
        printf(" %d ",i);
    }
    printf("\n\t ");
    for(int i = 1; i <= cols; i++)
    {
        printf("-- ");
    }
    printf("\n");
    for(int i = 0; i < cols; i++)
    {
        printf("%d\t|",i+1);
        for(int j = 0; j < rows; j++)
        {
            printf(" %c ",myBoard[i][j]);
        }
        printf("\n");
    }
    printf("\t");
    for(int i = 0; i < rows; i++)
        printf("***");
    printf("\n\n");
}

int isBoardFilled(int rows, int cols, char** myBoard)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(myBoard[i][j] == '_')
            {
                return 0;
            }
        }
    }
    return 1;
}

char** updateBoard(char** myBoard, Word_t *words,int solve)
{
    int temp = 0;
    if(words[solve].f == 1)
    {
        if(words[solve].direction == 'H')
        {
            for(int i=0; i< strlen(words[solve].word); i++)
                myBoard[words[solve].x-1][i + words[solve].y-1]=words[solve].word[temp++];
        }
        else if(words[solve].direction == 'V')
        {
            for(int i=0; i < strlen(words[solve].word); i++)
                myBoard[i+words[solve].x-1][words[solve].y-1]=words[solve].word[temp++];
        }
    }
    else
    {
        if(words[solve].direction=='H')
        {
            for(int i=0; i<strlen(words[solve].word); i++)
                myBoard[words[solve].x-1][i+words[solve].y-1]='_';
        }
        else if(words[solve].direction=='V')
        {
            for(int i=0; i<strlen(words[solve].word); i++)
                myBoard[i+words[solve].x-1][words[solve].y-1]='_';
        }
    }
    return myBoard;
}

void playGame(char** myBoard, int nrWords, Word_t *words, int x,int y)
{
    int count = 0;
    while(count < nrWords)
        updateBoard(myBoard, words, count++);

    printf("Current puzzle:\n");
    displayBoard(x, y, myBoard);
    while(1)
    {

        printf("Ask for hint:\n#  Direction\trow   col\n----------------------------\n");
        count = 0;

		while(!isBoardFilled(x, y, myBoard) && count < nrWords)
        {
            if(!words[count++].f)
                if(words[count-1].direction == 'H')
                    printf("%d: Horizontal\t%d\t%d\n", count, words[count-1].x, words[count-1].y);
                else if(words[count-1].direction =='V')
                    printf("%d: Vertical\t%d\t%d\n", count, words[count-1].x, words[count-1].y);
        }

		int num;

		do
        {
            printf("\nEnter -1 to exit\nWhich word to solve next?: ");

            scanf(" %d", &num);
            if(words[num-1].f == 1)
                printf("That word has been solved before\n");
            if(num == -1)
                return 0;
        }
        while(words[num-1].f == 1);

        printf("Current hint: %s\n", words[num-1].clue);
        printf("Enter your solution: ");

		char solution[10];
        scanf(" %s", solution);

		if(!strcasecmp(words[num-1].word, solution))
        {
            printf("\nCorrect!\n\n");
            words[num-1].f = 1;
            updateBoard(myBoard, words, num-1);
            printf("Current puzzle:\n");
           displayBoard(x, y, myBoard);
        }
        else
            printf("WRONG ANSWER\n");

        if(isBoardFilled(x, y, myBoard))
        {
            printf("Congratulations! You beat the puzzle!\n");
            return 0;
        }

    }
}
