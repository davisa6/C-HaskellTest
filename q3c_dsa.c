#include <stdio.h>
#include <stdlib.h>
#include "q3_dsa.h"

int main(int argc, char *argv[]){

        int count;
        int i, j;
        FILE *fp;
        fp = fopen(argv[1], "r");
        count = lines(fp);
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
        win = comparation(count,win,columns,lines);
        printf("%d", win);
        free(columns);
        free(lines);
        libera(mat,count);
        return 0;
}
