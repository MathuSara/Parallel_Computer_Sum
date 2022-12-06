#include <stdio.h>
#include <mpi.h>
#define N 1000
int main(int argc,char **argv){
        int pid,nprocs,i,j;
        int sum, start, end, data;
        MPI_Status status;
        MPI_Init(&argc,&argv);
        MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
        MPI_Comm_rank(MPI_COMM_WORLD,&pid );
        sum = 0;

//Logic to print the total values for each slot of partial sum
for (i = 1; i< 101; i++)
{
sum = sum + i + pid * 100;
}
//Printing the partial sum values
printf("Partial sum from process %d of total %d is : %d\n", pid, nprocs, sum);

/*send and receive - blocking */
//Condition to check if the current process is 0
if (pid == 0)
{
for (j = 1; j< 10; j++)
{
//collect the partial sums from other processes
MPI_Recv(&data, 1, MPI_INT, j, 0, MPI_COMM_WORLD, &status);
//Printing the received values from other process to process 0
printf("Receive %d from process %d\n", data, j);
//Calculating the sum
sum = sum + data;
}
//printing the total sum
printf("Total sum is %d", sum);
}
//if the current process is not equal 0
else
{
//Sending the value to process 0
MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
//printing the values that are sent to process 0
printf("Send %d to process 0 by process %d\n", sum,pid);
}
//End of MPI commands
MPI_Finalize();
return 0;
}
           