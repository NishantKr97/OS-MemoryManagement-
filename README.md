# OS-MemoryManagement-
This project is based on memory allocation used in OS. It uses partition allocation technique.
In Partition Allocation, when there are more than one partition freely available to accommodate a process’s request,
a partition must be selected. To choose a particular partition, a partition allocation method is needed. 
A partition allocation method is considered better if it avoids internal fragmentation.

Below are the various partition allocation schemes :

1. First Fit: In the first fit, partition is allocated which is first
    sufficient from the top of Main Memory.

2. Best Fit  Allocate the process to the partition which is first 
    smallest sufficient partition among the free available partition.

3. Worst Fit  Allocate the process to the partition which is largest
    sufficient among the freely available partitions available in
    the main memory. 

4. Next Fit Next fit is similar to the first fit but it will search
    for the first sufficient partition from the last allocation point.
