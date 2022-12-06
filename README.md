# Parallel_Computer_Sum
Task III (150 points): Get the sum of n intergers (You are going to use 8 nodes to do this task.) All nodes except processing node 0 send their partial sums to node 0 and node 0 add up all the partial sums.

(1)	Create a new directory with the name of lab13 and then get into this directory. What will be the command?

(2)	Write a program named Sum.c such that 
a.	Each process will compute and print out a partial sum of N numbers. 
(Note: This is same as task II. In this program, you can declare a constant N=1000 or use preprocessing statement #define N 1000.)

b.	all processes except process 0 send their partial sum to process 0 and print this message

c.	after process 0 receive the partial sums from other processes, process 0 will print out the confirmation that it received the value, add up all the partial sums including its own partial sum, and print out the total sum, that is, the value of 1+2+3+… +1000(that is,  ).

(3)	Compile your program, using the following command:
mpicc  Sum.c –o Sum

(4)	create a job script named job5 and make sure 10 nodes will be applied for your program. You can copy the job script file given in lab0 and then modify it. 

(5)	Then run command:
sbatch job5

(6)	 run the following command to check the status of your program:
qstat

(7)	When your program is finished, check in the current directory whether you have the related output file produced. Then open this file and check the content. You should have the following content:

Java module loaded - the system's JAVA is replaced by JDK 1.8.0_211

Partial sum from process 0 of total 10 is : 5050.<br>
Receive 15050 from process 1<br>
Receive 25050 from process 2<br>
Receive 35050 from process 3<br>
Receive 45050 from process 4<br>
Receive 55050 from process 5<br>
Receive 65050 from process 6<br>
Partial sum from process 2 of total 10 is : 25050.<br>
Send 25050 to process 0 by process 2<br>
Partial sum from process 1 of total 10 is : 15050.<br>
Partial sum from process 6 of total 10 is : 65050.<br>
Partial sum from process 4 of total 10 is : 45050.<br>
Send 45050 to process 0 by process 4<br>
Partial sum from process 5 of total 10 is : 55050.<br>
Send 55050 to process 0 by process 5<br>
Partial sum from process 3 of total 10 is : 35050.<br>
Send 15050 to process 0 by process 1<br>
Send 65050 to process 0 by process 6<br>
Send 35050 to process 0 by process 3<br>
Receive 75050 from process 7<br>
Partial sum from process 7 of total 10 is : 75050.<br>
Send 75050 to process 0 by process 7<br>
Partial sum from process 9 of total 10 is : 95050.<br>
Send 95050 to process 0 by process 9<br>
Partial sum from process 8 of total 10 is : 85050.<br>
Receive 85050 from process 8<br>
Receive 95050 from process 9<br>
Total sum is 500500<br>
Send 85050 to process 0 by process 8

(8)	Revise your program and script file appropriately so that your program is working for 16 nodes, and then run your program. Name this job job6.<br>
(9)	Revise your program such that blocking send and blocking receive are replaced with nonblocking send and nonblocking receive. Change your script file to run this program. Name this job job7.
