#include <stdio.h>

#define DIM 5
void printField(int field[DIM][DIM])
{
    int i = 0,j = 0;
    for (i = 0;i < DIM;i++) {
        for (j = 0;j < DIM;j++) {
            if (field[i][j] == 1) {
                printf("●");
            } else {
                printf("□");
            }
        }
        printf("\n");
    }
}

int checkOtherStone(int field[DIM][DIM],int i,int j)
{
    int u = 0,v = 0;
    for (u = 0;u < DIM;u++) {
        if (field[u][j] == 1) return 1;
    }
    for (u = i,v = j;u >= 0 && v >= 0;u--,v--) {
        if (field[u][v] == 1) return 1;
    }
    for (u = i,v = j;u < DIM && v < DIM;u++,v++) {
        if (field[u][v] == 1) return 1;
    }
    for (u = i,v = j;u >= 0 && v < DIM;u--,v++) {
        if (field[u][v] == 1) return 1;
    }
    for (u = i,v = j;u >= DIM && v >= 0;u++,v--) {
        if (field[u][v] == 1) return 1;
    }
    return 0;
}

void searchAnswer(int field[DIM][DIM],int i)
{
    int j = 0;
    static int answer_number = 0;
    if (i == DIM) {
        printf("<%d>\n",++answer_number);
        printField(field);
        return;
    }
    for (j = 0;j < DIM;j++) {
        if (!checkOtherStone(field,i,j)) {
            field[i][j] = 1; /* put */
            searchAnswer(field,i + 1);
            field[i][j] = 0; /* remove */
        }
    }
    return;
}


int main()
{
    int i = 0,j = 0;
    int field[DIM][DIM];
    for (i = 0;i < DIM;i++) {
        for (j = 0;j < DIM;j++) {
            field[i][j] = 0;
        }
    }
    searchAnswer(field,0);
    return 0;
}

