/*
    ICS 51, Lab #4

    --------------------------------------------------------------------

    IMPORTATNT NOTES:

    - This lab has four parts. The description of each part is given below.

    - Noramally, the compiler adds the prologue/epilogue code for the callee. However, when the 
    __declspec(naked) attribute is used, it is the programmer's responsibility to write the 
    prologue/epilogue code. In this lab you need to write prologue/epilogue code sections only 
    for the functions that have been declared with the naked attribute, namely:

       + findMinIndex
       + isPalindrome
       + performOperation

    - You cannot define any local variable in the C code. If you need additional variables in your
    assembly code, you have to allocate space for them in the prologue of the function. 

    - You are not allowed to change anything in this file except for adding your assembly code 
    between the lines marked with "YOUR CODE STARTS HERE" and "YOUR CODE ENDS HERE".

    - This lab has to be done individually.

    - Remember to fill in your name, student ID and UCInetID below.

    - Submit ONLY your completed lab4.c for grading.
*/

char *yourName = "Ran Duan";
char *yourStudentID = "23413224";
char *yourUCInetID = "duanr1";

#define RANDOMIZE_CALLEE_REGISTERS __asm mov ebx, 0xAFAFAFAF \
                                   __asm mov esi, 0xAFAFAFAF \
                                   __asm mov edi, 0xAFAFAFAF 
#define RANDOMIZE_CALLER_REGISTERS __asm mov eax, 0xAFAFAFAF \
                                   __asm mov ecx, 0xAFAFAFAF \
                                   __asm mov edx, 0xAFAFAFAF

/***********************************************************************************************

    PART 1: Change Letter Case

    You are given a string (null-terminated array of characters) that may contain numbers,
    upper and lower case letters, punctuations symbols, etc. Implement a function to convert all
    uppercase letters to lowercase and vice versa.
    For example "ThisIsTheFinalLabOf51" should be converted to "tHISiStHEfINALlABoF51".
    The string should be modifed in place. There is no explicit output for this function.

    Tips:

    - Note that each element of the arrays is a char (1 byte). You can NOT use a 32-bit register
    to read/write from/to a memory location. Instead you should use the 8-bit version of the x86
    general-purpose registers.

    - The link to the ASCII codes is here: http://www.asciitable.com/

************************************************************************************************/
void changeCase(char *string) {

    RANDOMIZE_CALLEE_REGISTERS
    RANDOMIZE_CALLER_REGISTERS

    __asm
    {
        // YOUR CODE STARTS HERE
		mov eax, string
		mov ecx, 0
		WHILE_LOOP:
			cmp byte ptr[eax + ecx], 0
			je END

			mov bl, byte ptr[eax + ecx]

			cmp bl, 65
			jl NEXT
			cmp bl, 91
			jl TO_LOWER
			cmp bl, 97
			jl NEXT
			cmp bl, 123
			jl TO_UPPER
			jmp NEXT

		TO_LOWER:
			or bl, 32
			jmp NEXT
		TO_UPPER:
			sub bl, 32
		NEXT:
			mov byte ptr[eax + ecx], bl
			inc ecx
			jmp WHILE_LOOP
		END:
			mov string, eax
        // YOUR CODE ENDS HERE
    }
}

/***********************************************************************************************

    PART 2: Selection Sort

    Selection sort is an in-place comparison sort algorithm that works by dividing the input list 
    into two parts: the sublist of items already sorted, which is built up from left to right of 
    the list, and the sublist of items remaining to be sorted that occupy the rest of the list. 
    Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. 
    The algorithm proceeds by finding the smallest element in the unsorted sublist, exchanging it 
    with the leftmost unsorted element (putting it in sorted order), and moving the sublist 
    boundaries one element to the right. To learn more, read: 
    https://en.wikipedia.org/wiki/Selection_sort#Example

    Our implementation here uses a function called "findMinIndex" to find the index of smallest
    element between ith index and jth index of the array. The function "selectionSort" uses
    this function to find the smallest number and exchanges it with the leftmost unsorted element
    in each iteration. You need to implement the behavior of both functions in x86 assembly.

************************************************************************************************/
__declspec(naked) 
int findMinIndex (int integer_array[], int i, int j)
{

// C code to be converted to x86 assembly
/*
    int iMin = i;
    // test against elements after i and before j to find the smallest 
    for ( i ; i < j; i++) {
        // if this element is less, then it is the new minimum   
        if (integer_array[i] < integer_array[iMin]) {
            // found new minimum; remember its index 
            iMin = i;
        }
    }

    return iMin;
*/

    RANDOMIZE_CALLER_REGISTERS

    __asm
    {
        // YOUR CODE STARTS HERE
		push ebp
		mov ebp, esp

		sub esp, 4

		push edi
		push esi
		push ebx

		mov eax, [ebp+8] // array
		mov esi, [ebp+12] // i
		mov edi, [ebp+16] // j
		mov [ebp-4], esi // iMin

		WHILE_LOOP:
			cmp esi, edi
			jge END

			mov ebx, [ebp-4]
			mov ebx, dword ptr[eax+ebx*4]
			mov ecx, dword ptr[eax+esi*4]
			cmp ecx, ebx
			jge NEXT
			mov [ebp-4], esi
		NEXT:
			inc esi
			jmp WHILE_LOOP
		END:
			mov eax, [ebp-4]

		pop ebx
		pop esi
		pop edi

		mov esp, ebp
		pop ebp
        // YOUR CODE ENDS HERE
        ret
    }

}

void selectionSort (int integer_array[], int array_size)
{

// C code to be converted to x86 assembly
/*  
    int j;
    int iMin;
    int temp;

    // advance the position through the entire array //
    // (could do j < n-1 because single element is also min element) //
    for (j = 0; j < array_size-1; j++) {

        // find the index of min element in the unsorted a[j .. n-1] //
        iMin = findMinIndex (integer_array, j, array_size);
 
        if(iMin != j) { // swap values
            temp = integer_array[iMin];
            integer_array[iMin] = integer_array [j];
            integer_array[j] = temp;    
        }
    }
*/

    RANDOMIZE_CALLEE_REGISTERS
    RANDOMIZE_CALLER_REGISTERS

    __asm
    {
        // YOUR CODE STARTS HERE
		mov eax, integer_array
		mov ebx, integer_array
		mov ecx, array_size
		mov edx, 0 // j
		WHILE_LOOP:
			cmp edx, ecx
			jge END
			
			push eax
			push ecx
			push edx

			// array_size, j, integer_array
			push ecx
			push edx
			push eax

			call findMinIndex

			add esp, 12

			pop edx
			pop ecx

			mov esi, dword ptr[ebx + eax*4]
			mov edi, dword ptr[ebx + edx*4]
			mov dword ptr[ebx + eax*4], edi
			mov dword ptr[ebx + edx*4], esi

			pop eax

			inc edx
			jmp WHILE_LOOP
		END:
			mov integer_array, ebx
        // YOUR CODE ENDS HERE
    }

}

/***********************************************************************************************

    PART 3: Palindrome

    Given a string, complete the implementation of the recursive function isPalindrome() to check 
    if the string is palindrome or not. A string is said to be palindrome if reverse of the 
    string is same as string. For example, “abba?is palindrome, but “abbc?is not palindrome.

************************************************************************************************/
__declspec(naked)
int isPalindrome(char *input_string, int left_index, int right_index)
{

// C code to be converted to x86 assembly
/*
    // Input Validation
    if (NULL == input_string || left_index < 0 || right_index < 0){
        return -1;
    }
    // Recursion termination condition
    if (left_index >= right_index)
        return 1;
    if (input_string[left_index] == input_string[right_index]){
        return isPalindrome(input_string, left_index + 1, right_index - 1);
    }
    return -1;
*/

    RANDOMIZE_CALLER_REGISTERS

    __asm
    {
        // YOUR CODE STARTS HERE
		push ebp // callee
		mov ebp, esp

		push edi
		push esi
		push ebx

		mov eax, [ebp+8] // input_string
		mov esi, [ebp+12] // left_index
		mov edi, [ebp+16] // right_index

		cmp eax, 0
		je END1
		cmp esi, 0
		jl END1
		cmp edi, 0
		jl END1
		cmp esi, edi
		jge END2

		//if (input_string[left_index] == input_string[right_index])
		mov cl, byte ptr[eax+esi]
		mov ch, byte ptr[eax+edi]
		cmp cl, ch
		jne END1

		// caller
		push eax
		push ecx
		push edx

		dec edi
		inc esi
		push edi
		push esi
		push eax

		call isPalindrome
		jmp END

		add esp, 12

		pop edx
		pop ecx
		pop eax

		END1:
			mov eax, -1
			jmp END
		END2:
			mov eax, 1
		END:

		pop ebx
		pop esi
		pop edi

		mov esp, ebp
		pop ebp
        // YOUR CODE ENDS HERE
        ret
    }
}

/***********************************************************************************************

    PART 4: Vector Operation

    The vectorOperations function gets as parameters 4 arrays of the same length and
    the number of elements in those arrays. 

    For each pair of elements in first_array and second_array, it calls performOperation
    and stores the returned result in the same index of output_array.

    output_array[index] = performOperation(operation_array[index], first_array[index], second_array[index]).

    You also need to implement the body of performOperation function according to the provided
    C code.
  
************************************************************************************************/
__declspec(naked) 
int performOperation (int operation, int first, int second)
{

// C code to be converted to x86 assembly
/*
    if (operation==0) 
        return first - second;
    else if (operation==1)
        return first + second;
    else if (operation==2)
        return (first < second)? first : second;
    else if (operation==3)
        return (first > second)? first : second;
    else
        return first;
*/

    RANDOMIZE_CALLER_REGISTERS

    __asm
    {
        // YOUR CODE STARTS HERE
		push ebp
		mov ebp, esp

		push edi
		push esi
		push ebx

		mov esi, [ebp+8] // operation
		mov edi, [ebp+12] // first
		mov ebx, [ebp+16] // second

		cmp esi, 0
		jne ELSE_IF1
		sub edi, ebx
		jmp END

		ELSE_IF1:
			cmp esi, 1
			jne ELSE_IF2
			add edi, ebx
			jmp END

		ELSE_IF2:
			cmp esi, 2
			jne ELSE_IF3
			cmp edi, ebx
			jl END
			mov edi, ebx
			jmp END

		ELSE_IF3:
			cmp esi, 3
			jne END
			cmp edi, ebx
			jg END
			mov edi, ebx
			jmp END

		END:
			mov eax, edi
		
		pop ebx
		pop esi
		pop edi

		mov esp, ebp
		pop ebp
        // YOUR CODE ENDS HERE
        ret
    }
}

void vectorOperations (int number_of_elements, int *first_array, int *second_array, 
                       int *operation_array, int *output_array)
{
// C code to be converted to x86 assembly
/*
    int i;
    for (i=0; i<number_of_elements; i++)
    {
        output_array[i] = performOperation(operation_array[i], first_array[i], second_array[i]);
    }
*/

    RANDOMIZE_CALLEE_REGISTERS
    RANDOMIZE_CALLER_REGISTERS

    __asm 
    {
        // YOUR CODE STARTS HERE
		mov edi, output_array
		mov edx, 0 // index

		WHILE_LOOP:
			cmp edx, number_of_elements
			jge END

			mov eax, first_array
			mov eax, dword ptr[eax+edx*4]
			mov ebx, second_array
			mov ebx, dword ptr[ebx+edx*4]
			mov ecx, operation_array
			mov ecx, dword ptr[ecx+edx*4]

			push eax
			push ecx
			push edx

			// int second, int first, int operation
			push ebx
			push eax
			push ecx

			call performOperation

			add esp, 12

			pop edx

			mov dword ptr[edi+edx*4], eax

			pop ecx
			pop eax

		NEXT:
			inc edx
			jmp WHILE_LOOP
		END:
        // YOUR CODE ENDS HERE
    }
}