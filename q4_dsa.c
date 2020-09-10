#include <stdio.h>
#include <stdlib.h>
int primo (int n) 
{
        int is = 0;
        if (n == 0 || n == 1) {
                is = 1;
        }
        else {

        }
        for (int i = 2; i< (n-2)+1; i++) {
                if ((n % i)==0) {
                        is = 1;
                        break;
                }
        } 
        return is;
}
int decont (int n) {
        int d = 2;
        int cont = 0;
        while (n != 1 ) {
                if ((n%d) == 0) {
                        cont++;
                        n /= d;
                } else {
                        d++;
                }
        }
        return cont;
}
int *pararray (int n) 
{
        int *array;
        array = calloc(decont(n),sizeof(int));
        int d = 2;
        int cont = 0;
        while (n != 1 ) {
                if ((n%d) == 0) {
                        array[cont] = d;
                        cont++;
                        n /= d;
                } else {
                        d++;
                }
        }
        return array;
}
int yes (int n, int *definitivo)
{
        int checa = 0;
        int is = 0;
        int cont = 0;
        for (int i = 0; i<n; i++ ) {
                checa = primo(definitivo[i]);
                if (checa == 0) {
                        is++;
                } else {
                        break;
                }
        }
        if (is == n) {
                return 0;
        } else {
                return 1;
        }
}
void printa (int arr[], int n) {
        for (int i = 0; i<n; i++) {
                printf("%d ",arr[i]);
        }
}

int check (int *arr, int n) 
{
        int is = 0;
        int aux;
        int flag = 0;
        for (int i = 0; i<n; i++) {
                for (int j = i+1; j<n; j++) {
                        if (arr[i] == arr[j]) {
                                return 1;
                                break;
                        }
                }
        }
        return 0;

}

int main (int argc, char *argv[])
{
        int n = atoi(argv[1]);
        int d = 2;
        int cont = 0;
        while (n != 1 ) {
                if ((n%d) == 0) {
                        cont++;
                        n /= d;
                } else {
                        d++;
                }
        }
        n = atoi(argv[1]);
        cont = 0;
        for (int i = 1; i<n+1; i++) {
                if ((n%i) == 0) {
                        cont++;
                }
        }
        int div [cont];
        n = atoi(argv[1]);
        cont = 0;
        for (int i = 1; i<=n; i++) {
                if ((n%i) == 0) {
                        div[cont] = i;
                        cont++;
                }
        }
        d = 2;
        n = atoi(argv[1]);
        while (n != 1 ) {
                if ((n%d) == 0) {
                        n /= d;
                } else {
                        d++;
                }
        }
        d = 2;
        n = atoi(argv[1]);
        int is = 0;
        cont = 0;
        for (int i = 0; i<sizeof(div)/4; i++ ) {
                is = primo(div[i]);
                if (is == 0) {
                        cont++;
                }
        }
        cont = 0;
        int temp;
        int cont2 = 0;
        n = atoi(argv[1]);
        int *xarray;
        for (int i = 1; i<(sizeof(div)/4); i++) {
                xarray = pararray(div[i]);
                if ( (yes(decont(div[i]),xarray))==0 && (check(xarray,decont(div[i]))==0) && decont(div[i]) > 1) {
                        cont2++;
                }
        }
        printf("%d",cont2);
        free(xarray);
}