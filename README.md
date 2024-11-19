
Normal merge sort which is calling the recursive function for left and right one by one (means in a single thread)

![normalmergesort](https://github.com/user-attachments/assets/17b26930-1471-4e80-9cee-0c42b419b1c6)

===> include the pthread library 
then create a thread 

![creatingthread](https://github.com/user-attachments/assets/0f2645f6-fe30-4390-b9a4-0232e04d24a6)

through arg1, arg2 we are passing the instance , left and right so that we can call the recursiveSort function and can pass the left and right arguments

![creatingnewthread](https://github.com/user-attachments/assets/b4226221-2df8-4ac3-84bf-b978fa42a70d)

![threadfunction](https://github.com/user-attachments/assets/027bd136-6e0a-4b35-8cbf-fa0fab5f92cf)

then we have to join the thread so that one thread will wait for the other thread to complete execute 
Joining a thread makes one thread of execution wait for another thread to finish running

![joiningthethreads](https://github.com/user-attachments/assets/8935297e-558a-4f0a-9ad7-1dd84824b0d7)

then we have to define the threshold for make a thread like if the size of the array is less then 5000 then we simply sort them in T.C -- N(logN) 

but if array size is exceeded then we make a thread

![thresholdthread](https://github.com/user-attachments/assets/6789f4b7-0ef9-4fe5-8e92-8ce79a815217)


here is the comparsion btw multithreaded mergesort and simple mergesort 

![multithrededmergesort](https://github.com/user-attachments/assets/4cfcff5e-7e89-4afb-9677-4ccbac1eb551)
