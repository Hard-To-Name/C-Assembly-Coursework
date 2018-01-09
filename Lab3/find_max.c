#include <stdio.h>

/*
find_max() finds and returns the maximum number in a given array of integers.
The function has the following inputs: an array of integers (passed
as a pointer to the begining of that array) and the size of the
array. The result (i.e. the largest integer) in stored in edx.
*/

int find_max(int *integer_array, int array_size)
{
	int max;

	/* C code

	int i = 0;
	max = integer_array[0];

	i++;
	while(i < array_size) {
		if (max < integer_array[i]) {
			max = integer_array[i];
		}
		i++;
	}
	
	*/

	__asm{

		// BEGIN YOUR CODE HERE

		mov ecx, 0; // loop counter ( = current index)
		mov eax, integer_array  // eax = base_addr
		mov edx, dword ptr[eax] // edx = current maximum int. (initially, the first element in the array)
		inc ecx // skip comparing the first element, since it's currently the maximum int.
		FOR_LOOP :
			cmp ecx, array_size // while ecx < array_size
			jge END
			mov ebx, dword ptr[eax + 4 * ecx] // read the next element in the array
			cmp edx, ebx  // compare current max against the next number 
			jge NEXT
			mov edx, ebx  // update current max if necessary
			NEXT :
			add ecx, 1  // update counter to query next element
		jmp FOR_LOOP
		END :

		// END YOUR CODE HERE

		mov max, edx // read edx

	}

	return max;
}

int main(void)
{
	int i;

#define SIZE 15
	int arrayOfNumbers1[SIZE] = { 4, 5, 1, 222, 5, 5, 33, 11, -4, 12, -333, 10, -28349, 74, 323232 };
	int arrayOfNumbers2[SIZE] = { +32131, +432, +232, +4, -1, -4, -5, -7, -8, -8, -9, -100000, -200000, -300000, -9999999 };
	int arrayOfNumbers3[SIZE] = { -4, -5, -1, -222, -5, -5, -33, -11, -4, -12, -333, -10, -28349, -74, -323232 };

	printf("\nThe original array of numbers is:\n");
	for (i = 0; i<SIZE; i++){
		printf("%d ", arrayOfNumbers1[i]);
	}
	printf("\n");
	printf("The largest number is: %d\n\n", find_max(arrayOfNumbers1, SIZE));

	printf("\nThe original array of numbers is:\n");
	for (i = 0; i<SIZE; i++){
		printf("%d ", arrayOfNumbers2[i]);
	}
	printf("\n");
	printf("The largest number is: %d\n\n", find_max(arrayOfNumbers2, SIZE));

	printf("\nThe original array of numbers is:\n");
	for (i = 0; i<SIZE; i++){
		printf("%d ", arrayOfNumbers3[i]);
	}
	printf("\n");
	printf("The largest number is: %d\n\n", find_max(arrayOfNumbers3, SIZE));

	getchar();
	return 0;
}
