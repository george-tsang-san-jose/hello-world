#include <stdio.h>
#include <malloc.h>

typedef enum {RIGHT=0, DOWN=1, LEFT=2, UP=3} dir_t;

void
print_matrix(int **matrix, int n)
{
   int i,j;
   for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
           printf("%04d", matrix[i][j]);
           if (j != n-1) {
                printf(",");
           }
        }
        printf("\n");
   }
   return;
}

int **
spiral(int n)
{
   int **matrix;
   int i,j;
   int counter=1;
   dir_t dir = RIGHT;

   for (i=0;i < n;i++) {
     matrix = (int **) malloc(sizeof(int*)*n);
   }
   for (i=0; i < n; i++) {
       matrix[i] = (int *) malloc(sizeof(int) * n);
   }
   for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
           matrix[i][j]=0;
        }
   }

   for (i=j=0; counter <= n*n ;) {
       if (matrix[i][j] == 0) {
           matrix[i][j] = counter++;
       }
       //printf("%d, %d, %d, %d\n", dir, i, j, matrix[i][j]);
       switch (dir) {
        case RIGHT:
             if (j+1 == n || matrix[i][j+1] != 0) {
                dir = (dir == UP) ? RIGHT : dir+1;
             }
             break;
        case LEFT:
             if (j == 0 || matrix[i][j-1] != 0) {
                dir = (dir == UP) ? RIGHT : dir+1;
             }
             break;
        case DOWN:
             if (i+1 == n || matrix[i+1][j] != 0) {
                dir = (dir == UP) ? RIGHT : dir+1;
             }
             break;
        case UP:
             if (i == 0 || matrix[i-1][j] != 0) {
                dir = (dir == UP) ? RIGHT : dir+1;
             }
             break;
       }
       switch (dir) {
        case RIGHT:
                j++; break;
        case LEFT:
                j--; break;
        case DOWN:
                i++; break;
        case UP:
                i--; break;
       }
   }
   return matrix;
}

int
main()
{
  print_matrix(spiral(1),1);
  print_matrix(spiral(2),2);
  print_matrix(spiral(3),3);
  print_matrix(spiral(4),4);
  print_matrix(spiral(10),10);
}
