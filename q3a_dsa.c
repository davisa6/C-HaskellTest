#include <stdio.h> 
#include <stdlib.h>

int lines (FILE *fp)
{
        int count = 0;
        int prev = 0;
        char c;

        for (c = getc(fp); c != EOF; c = getc(fp)) {
                if (c == '\n'){
                        count = count + 1;
                        prev = 0;
                } else {
                        prev = 1;
                }
        }
        if (prev) {
                count++;
        }
        return count;
}
  
int main(int argc, char *argv[])
{

        int count;
        int i, j;
        FILE *fp;
        fp = fopen(argv[1], "r");
        count = lines(fp);
        fseek(fp, 0, SEEK_SET);
        int** mat =malloc(count*sizeof(int*));
        for(i=0;i<count;i++) {
                mat[i]=malloc(count*sizeof(int));
        }
        for(i = 0; i < count; i++) {
                for(j = 0; j < count; j++) {
                        if (!fscanf(fp, "%d", &mat[i][j]))
                                break;
                }
        }
        fclose(fp);
        int* lines = calloc(count,sizeof(int));
        for(i = 0; i < count; i++) {      
                for(j = 0; j < count; j++) {
                        lines[i] = lines[i] + mat[i][j];
                }
        }
        int* columns = calloc(count,sizeof(int));
        for(j = 0; j < count; j++) {
                for(i = 0; i < count; i++) {
                        columns[j] = columns[j] + mat[i][j];
                }
        }
        int win = 0;
        for(j = 0; j < count; j++) {
                for(i = 0; i < count; i++) {
                        if (columns[i] > lines[j]) {
                                win++;
                        }
                }
        }
        printf("%d", win);
        free(columns);
        free(lines);
        for (int i = 0; i < count; i++) {
                free(mat[i]);
        }
        free(mat);
        return 0;
}
