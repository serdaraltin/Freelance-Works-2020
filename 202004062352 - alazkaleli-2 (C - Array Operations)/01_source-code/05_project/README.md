 #Lab 5 - Working with Memory in C
 ##CS120 Spring 2020

 libraries >
	 #include <stdio.h>
	 #include <stdlib.h>

 files >
 	lab5.c -> source code file

 functions >
 	void display(int *array,int n);
 	special >
	 	malloc
	 	sizeof
	 	free

 values >
 	int size -> array size value


 Memory LEaks or Errors Report >

	==8342== 
	==8342== HEAP SUMMARY:
	==8342==     in use at exit: 55 bytes in 3 blocks
	==8342==   total heap usage: 9 allocs, 6 frees, 1,195 bytes allocated
	==8342== 
	==8342== LEAK SUMMARY:
	==8342==    definitely lost: 55 bytes in 3 blocks
	==8342==    indirectly lost: 0 bytes in 0 blocks
	==8342==      possibly lost: 0 bytes in 0 blocks
	==8342==    still reachable: 0 bytes in 0 blocks
	==8342==         suppressed: 0 bytes in 0 blocks
	==8342== Rerun with --leak-check=full to see details of leaked memory
	==8342== 
	==8342== Use --track-origins=yes to see where uninitialised values come from
	==8342== For lists of detected and suppressed errors, rerun with: -s
	==8342== ERROR SUMMARY: 35 errors from 9 contexts (suppressed: 0 from 0)
