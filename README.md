#Matrix Multiplication Using PThreads


#Description:
Given two matrices, A and B, where matrix A contains M rows and K columns and matrix B contains K rows and N columns, the matrix product of A and B for matrix C,
where C contains M rows and N columns. This program calculates each element C in a separate worker thread.

The values of M, K, and M are declared and initialized using public static integers. The matrices A and B are declared and initialized in the form 
of 2 dimensional arrays with memory being allocated for matrix C. 
These matrices are declared public so that they can be accessed by the workers. 2 classes are used in the implementation, 
the MatrixMultiplication class and the WorkerThread class. 

Using Pthreads
Using pthreads is similar in theory to that of Java but different in execution. 
The entire program is executed in one file, which the calculating construct being a procedure.  
Like in java threads, the values for M, K and N are defined and initialized. The rules for executing Pthreads however, are different.  
Creating a new thread uses the pthread_create() method call. For each call of pthread_create, the thread ID, the function being invoked,  
and the parameter that is being passed in to the thread's function is required. . The Thread IDs are declared as a 3x3 2 dimensional array.  
Each thread invokes the "calc" procedure. Inside this function the value of a position in Matric C is calculated. When all the threads are  
completed, they are rejoined to the main thread by using the pthread_join() method call. The value of Matrix C is then printed to the screen.



#Output:
	takuma@ubuntu:~/Dropbox/Ubuntu$ gcc -pthread -o matrixPthread matrixPthread.c
	takuma@ubuntu:~/Dropbox/Ubuntu$ ./matrixPthread
	Creating Worker threads...
	Joining Worker threads...
	ELements of C Matrix:
	28 23 18 
	41 34 27 
	54 45 36 
	takuma@ubuntu:~/Dropbox/Ubuntu$ 

