# SearchAndSortAlgorithms
### Description
Here are a few small projects that make use of a few different algorithms used for searches and sorts.

### Breadth-First Search
Make sure that BFS.h, mainBFS.cpp, and BFS.cpp are present in current directory.
To compile, use command: g++ *.cpp.
Once compiled, to execute, use command: ./a.out.

The program assumes that the read in file 'data2.txt' is available in the current directory
and will output to out2.txt when ran.
This effectively overwrites any data that was previously in out2.txt.

out2.txt is formatted to just state if the graph is connected or not.
The same output will be printed to the terminal.

Will work with graphs up to 50 nodes.

### HeapSort
Make sure that HeapSort.h and HeapSort.cpp are present in current directory
To compile, use command: g++ *.cpp
Once compiled, to execute, use command: ./a.out

The program assumes that the read in file 'data3.txt' is available in the current directory
and will output to output3.txt when ran.
This effectively overwrites any data that was previously in output3.txt.

output3.txt is formatted to be similar to data3.txt just printed in a sorted order.

Will work with line numbers up to 100 numbers; delimited by spaces.

### Merge + Insertion
PartA.cpp uses merge sort only.
PartB.cpp is implemented to use merge sort until the number of items to be merged in the current set is <= 8. It will sort those 8 or fewer items with insertion sort.

Make sure that MergeSort.h is present in current directory
To compile PartA.cpp, use command: g++ PartA.cpp
Once compiled, to execute PartA.cpp, use command: ./a.out

To compile PartB.cpp, use command: g++ PartB.cpp
Once compiled, to execute PartB.cpp, use command: ./a.out

Both programs assume that the read in file 'data1.txt' is available in the current directory
and both will output to out1.txt when ran.
This effectively overwrites any data that was previously in out1.txt.

out1.txt is formatted to be the same as data1.txt just printed in a sorted order.

Will work with line numbers up to 500 words; delimited by spaces.

