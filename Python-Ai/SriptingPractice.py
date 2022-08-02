import os ,sys
from random import shuffle
from time import perf_counter as time
#cURRENTLY INCOMPLETE
#rEFRENCE IS THIS: https://cppsecrets.com/users/576115105100100104971141161049746100117116116974964115116117100101110116469710910511612146101100117/Python-Program-to-Test-Hard-Disk-Speed.php

class DiskSpeed:
    def __init__(self,path,blocks_count=8,block_size = 4096):
        self.path = path + "\\ScriptinPractice"
        self.results = {}
        self.get_write_speed(blocks_count,block_size)
        self.get_read_speed(blocks_count,block_size)
        os.remove(self.path)

    def get_write_speed(self,blocks_count,block_size):
        f = os.open(self.path,os.O_CREAT | os.O_WRONLY,0o777) #Low Level I/O
        w_times = []
        for i in range(blocks_count):
            sys.stdout.write(']rWriting: {:.2f}%'.format(i+1)* 100/blocks_count)
            sys.stdout.flush()
            buff = os.urandom(block_size)
            start = time()
            os.write(f,buff)
            os.fsynch(f)
            w_times.append(time()-start)
        os.close(f)

        write_speed = blocks_count/sum(w_times) #MB/s
        self.results['Write Speed'] = write_speed

