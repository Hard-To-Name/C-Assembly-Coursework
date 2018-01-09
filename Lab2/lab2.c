/*
    ICS 51, Lab #2
    
    --------------------------------------------------------------------

    IMPORTATNT NOTES:
    
    - To test your code see function testcode() in lab2-tester.c
        
    - For part 2, you are NOT allowed to use any version of the 
      MULTIPLY instruction.

    - You are not allowed to change anything in this file except for adding your assembly code 
    between the lines marked with "YOUR CODE STARTS HERE" and "YOUR CODE ENDS HERE".

    - This lab has to be done individually.
    
    - Remember to fill in your name, student ID number and UCInetID below.
    
    - ONLY submit your completed lab2.c for grading.
*/

char *yourName = "Ran Duan";
char *yourStudentID = "23413224";
char *yourUCInetID = "duanr1";

/***********************************************************************************************

    PART 1: 

    A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte.
    Given a byte (x), swap the two nibbles in it. For example 100 in decimal is represented as 
    01100100 in a byte (or 8 bits). The two nibbles are (0110) and (0100). If we swap the two 
    nibbles, we get 01000110 which is 70 in decimal.
    
    Implementation details:
    The input integer is stored in registers cl. You need to store the answer into register al.

************************************************************************************************/
unsigned char swapNibbles(unsigned char x)
{
    unsigned char result;

    __asm 
    {
        mov al, -1
        mov cl, x

        // YOUR CODE STARTS HERE
        
		mov al, x
		shl al, 4
		shr cl, 4
		or al, cl
        
        // YOUR CODE ENDS HERE
 
        mov result, al
    }
    return result;

}

/***********************************************************************************************

    PART 2: 
    
    You are given three 32-bit signed integers. You need to add the 
    smallest number to the largest number and multiply that sum by 2017. 
    You cannot use mul/imul instructions. Instead decompose the multiplier
    into powers of two and use the shift and add instructions to do the
    multiplication. Read about "ancient Egyptian multiplication" here:
    https://en.wikipedia.org/wiki/Ancient_Egyptian_multiplication

    Implementation details:
    The three integers are stored in registers ebx, ecx, and edx. You need to store the answer 
    into register eax. Note that you cannot use register esi in your code.

************************************************************************************************/
void minMax(int a, int b, int c, int *result)
{
    __asm 
    {
        mov eax, -1
        mov esi, result

        mov ebx, a
        mov ecx, b
        mov edx, c

        // YOUR CODE STARTS HERE
        
        cmp ebx, ecx
		jl c_b

		cmp ebx, edx
		jl d_b_c

		cmp ecx, edx
		jl b_d_c

		mov eax, ebx
		add eax, edx
		jmp End_of_compare

		b_d_c:
		mov eax, ebx
		add eax, ecx
		jmp End_of_compare

		d_b_c:
		mov eax, edx
		add eax, ecx
		jmp End_of_compare

		c_b:
		cmp ecx, edx
		jl d_c_b

		cmp ebx, edx
		jl c_d_b

		mov eax, ecx
		add eax, edx
		jmp End_of_compare

		d_c_b:
		mov eax, edx
		add eax, ebx
		jmp End_of_compare

		c_d_b:
		mov eax, ecx
		add eax, ebx
		jmp End_of_compare
	
		End_of_compare:
		mov ebx, eax
		shl ebx, 5
		add eax, ebx
		shl ebx, 1
		add eax, ebx
		shl ebx, 1
		add eax, ebx
		shl ebx, 1
		add eax, ebx
		shl ebx, 1
		add eax, ebx
		shl ebx, 1
		add eax, ebx

        
        // YOUR CODE ENDS HERE

        mov [esi][0], eax
    }
}

/***********************************************************************************************

    PART 3:

    Implement a function that determines if a number is a power of two or not. It 
    takes a positive integer n as an argument, and returns 1 if n is a power of two, 
    and otherwise 0.

    Implementation details:
    The input integer is stored in registers ecx. You need to store the result into register eax.

    Hint:
    The integer n is a power of two if (n & (n-1)) == 0 (Why?)

************************************************************************************************/
int isPowerOfTwo(unsigned int n)
{
    __asm
    {
		mov ecx, n

		// YOUR CODE STARTS HERE

		mov ebx, ecx
		dec ebx
		and ebx, ecx
		cmp ebx, 0
		jne not_a_pow_of_two
		mov eax, 1
		jmp end
		
		not_a_pow_of_two:
		mov eax, 0

		end:
        
        // YOUR CODE ENDS HERE
    }
}