from ctypes import cdll
from mpi4py import MPI

lib = cdll.LoadLibrary('./wrapper.so')
#mpi set

class Testpy(object):
    def __init__(self,ptr):
        self.obj = lib.Test_new(ptr)

    def print(self):
        return lib.Test_bar()





comm = MPI.COMM_WORLD
#grabbing pointer of communicator
ptr = MPI._addressof(comm)
test = Testpy(ptr)
test.print()
