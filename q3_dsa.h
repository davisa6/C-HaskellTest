#include <stdio.h> 
#include <stdlib.h>
#define INCREMENT(x) ++x
#define SUM(a,b) a+b
#define MAX(a,b) a>b
#define EQUAL(a,b) a==b
#define PLUS(x) x++
#define MIN(a,b) a<b
#define DIF(a,b) a!=b
#define DEBUG 1

int lines (FILE *fp);
int **aloc (int **mat, int count);
int *so (int *lines, int **mat, int count);
int *col (int *columns, int **mat, int count);
int comparation (int count, int win, int *columns, int *lines);
int **sca (int **mat, int count, FILE *fp);
void libera (int ** mat, int count);