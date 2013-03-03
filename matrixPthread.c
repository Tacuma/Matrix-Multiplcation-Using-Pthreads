//Tacuma Solomon
//@02580808
//Operating Systems
//Lab 2 Part B - 2) Pthreads on a Unix machine.
    	
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
    	
//defines the variables for dimensions
#define M 3
#define K 2
#define N 3
   	
// Initalizes the arrays for A and B and space for Array C
int A [M][K] = { {1,4}, {2,5}, {3,6} };
int B [K][N] = { {8,7,6}, {5,4,3} };
int C [M][N];
   	
//Function Prototype for calc function
void *calc(void *param);
   	
/* structure for passing data to threads*/
struct v
{
	int i; /*row*/
  	int j; /*column*/
};
   
   	
int main() {
   	
	//Declares thread Ids for 9 Worker threads
   	pthread_t thread[3][3];	
   	int i,j;
   	printf("Creating Worker threads...\n");
   	
	for (i=0;i<M;i++){// Nested Loop creates a thread for each space of Matrix C
   		for(j=0;j<N;j++){
   			struct v *data = (struct v *) malloc(sizeof(struct v)); //Dynamically creates a struct called data
   			data->i = i;// Assigns a row value
   			data->j = j;// Assigns a column value
   			pthread_create(&thread[i][j], NULL, calc,(void*) data); // Creates a thread
   		}
   	}
   	
   	printf("Joining Worker threads...\n");
   	
   	for (i=0;i<M;i++){ //Nested Loop Joins all the Worker threads After completion
   		for(j=0;j<N;j++){	
   			pthread_join( thread[i][j],NULL);
   		}
   	}
  	
   	printf("ELements of C Matrix:\n");
   	
   	for (i=0;i<M;i++){// Prints the Values of Array C
   		for(j=0;j<N;j++){	
   			printf("%d ",C[i][j]);
   			//printf("%d%d\n\n",i,j);
  		}
   		printf("\n");
   	}
   	return 0;
}
   	
   	
void *calc(void *param)//Function Calculates Values for each space in Matrix C
{
   	struct v *data;
   	data = (struct v *)param; 
   	int row = data->i;
   	int col = data->j;
   	C[row][col] = (A[row][0]*B[0][col]) + (A[row][1]*B[1][col]);
   	pthread_exit(0);
}

