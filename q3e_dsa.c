#include <stdio.h> 
#include <stdlib.h>
#define INCREMENT(x) ++x
#define SUM(a,b) a+b
#define MAX(a,b) a>b
#define EQUAL(a,b) a==b
#define PLUS(x) x++
#define MIN(a,b) a<b
#define DIF(a,b) a!=b
#define MULT(a,b) a*b
#define DEBUG 1

int lines (FILE *fp)
{
        int count = 0;
        int prev = 0;
        char c;

        for (c = getc(fp); DIF(c,EOF); c = getc(fp)) {
                if (EQUAL (c,'\n')){
                        INCREMENT(count);
                        prev = 0;
                } else {
                        prev = 1;
                }
        }
        if (prev)
                INCREMENT(count);
        return count;
}
int columns (FILE *fp)
{
        int count = 0;
        int prev = 0;
        char c;

        while(MAX(fscanf(fp,"%d",&prev),0)) {
                INCREMENT(count);
        }
        return count;
}
int **aloc (int **mat, int count)
{
        for (int i = 0; MIN(i,count); INCREMENT(i)) {
                mat[i]=malloc(count*sizeof(int));
        }
        return mat;
}
int *so (int *lines, int **mat, int count) {
        for(int i = 0; MIN(i,count); PLUS(i))      
                for(int j = 0; MIN(j,count); PLUS(j))
                        lines[i] = SUM (lines[i], mat[i][j]);
        return lines;     
}
int *col (int *columns, int **mat, int count) {
        for(int j = 0; MIN(j,count); PLUS(j))
                for(int i = 0; MIN(i,count); PLUS(i))
                        columns[j] = SUM (columns[j], mat[i][j]);
        return columns;
}
int comparation (int count, int win, int *columns, int *lines) {
        for(int j = 0; MIN(j,count); PLUS(j))
                for(int i = 0; MIN(i,count); PLUS(i))
                        if (MAX(columns[i],lines[j]))
                                printf("(%d,%d) ",j,i);
                                INCREMENT(win);
        return win;
}
int **sca (int **mat, int count, FILE *fp) {
        for(int i = 0; MIN(i,count); PLUS(i))
                for(int j = 0; MIN(j,count); PLUS(j))
                        if (EQUAL(fscanf(fp, "%d", &mat[i][j]),EOF))
                                break;
        return mat;
}
void libera (int ** mat, int count)
{
        for (int i = 0; MIN(i,count); PLUS(i)) {
                free(mat[i]);
        }
        free (mat);
}


int main(int argc, char *argv[]){

        int count;
        int i, j;
        FILE *fp;
        fp = fopen(argv[1], "r");
        count = lines(fp);
        rewind(fp);
        int count2 = columns(fp);
        rewind(fp);
        fseek(fp, 0, SEEK_SET);
        int** mat=malloc(count*sizeof(int*));
        mat = aloc (mat,count);
        mat = sca(mat,count,fp);
        fclose(fp);
        int* lines = calloc(count,sizeof(int));
        lines = so(lines,mat,count);
        int* columns = calloc(count,sizeof(int));
        columns = col(columns,mat,count);
        int win = 0;
        if (DIF((MULT(count,count)),count2)) {
                printf("Error at matrix format");

        } else {
                win = comparation(count,win,columns,lines);
        }
        free(columns);
        free(lines);
        libera(mat,count);
        return 0;
}
