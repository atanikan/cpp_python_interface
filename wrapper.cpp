#include <iostream>
#include <mpi.h>
#include <stdio.h>
#include <vector>

class Test{
    public:
	Test(long int addr)
	{
		MPI_Comm my_comm = *((MPI_Comm*)addr);
	}

	void print(){
		int rank,size;
		rank = -1;
		size = -1;
		if ('a' != my_comm) {
                                MPI_Comm_rank(my_comm, &rank);
                                MPI_Comm_size(my_comm, &size);
                 }
                printf("C++ rank/size: %d/%d \n",rank, size);
        }
    private:
	MPI_Comm my_comm;
};

extern "C" {
    long int addr;
    Test* Test_new(){ return new Test(addr); }
    void Test_bar(Test* test){ test->print(); }
}
