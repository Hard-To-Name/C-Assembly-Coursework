/*
    ICS 51, Lab #3

    --------------------------------------------------------------------
 
    IMPORTATNT NOTES:
    
    - To test your code use the tests in lab3-tester.cpp
    
    - Write your assembly code only in the marked areas.
    
    - You are not allowed to change anything in this file except for adding your assembly code 
    between the lines marked with "YOUR CODE STARTS HERE" and "YOUR CODE ENDS HERE".

    - This lab has to be done individually.

    - Remember to fill in your name, student ID number and UCInetID below.

    - Two test images are provided to you (lena.png and authoritah.png)
    
    - ONLY submit your completed lab3.cpp for grading.
*/

char *yourName = "Ran Duan";
char *yourStudentID = "23413224";
char *yourUCInetID = "duanr1";

/***********************************************************************************************

    PART 1: Image Thresholding

    - This function takes in a square sized grayscale image and applies thresholding on each pixel.
      i.e. it should change pixel values according to this formula:
                        0xFF       if x >= threshold
                        0x00       if x <  threshold
    - The width and height of the image are equal to dim. 
    - You are not allowed to define additional variables.

************************************************************************************************/
void imageThresholding(unsigned char* image, int dim, unsigned char threshold) {
    __asm 
    {
        // YOUR CODE STARTS HERE

		mov eax, image
		movzx edx, threshold
		mov ecx, dim
		imul ecx, dim
		dec ecx
		WHILE_LOOP:
			cmp ecx, -1
			jle END

			movzx ebx, byte ptr[eax + ecx]
			cmp ebx, edx
			jge WHITE

			mov byte ptr[eax + ecx], 0x00
			jmp NEXT

			WHITE:
			mov byte ptr[eax + ecx], 0xFF

			NEXT:
			dec ecx
			jmp WHILE_LOOP

		END:

        // YOUR CODE ENDS HERE
    }
}


/***********************************************************************************************

    PART 2: Image Rotation

    - This function rotates a square sized color image 90 degress clockwise.
    - The width and height of the image are both equal to dim.
    - Four variables (a0, a90, a180, a270) are defined that you may use in your implementation for
    temporary data storage. You are not allowed to define additional variables.

************************************************************************************************/
void imageRotation(unsigned int* image, int dim) {
    unsigned int a0, a90, a180, a270;
    __asm 
    {
        // YOUR CODE STARTS HERE
		mov eax, image
		mov ecx, dim
		shr ecx, 1
		mov edx, 0
        // Iterate over the red triangle (row by row starting from top left)
		WHILE_LOOP_1:
		    cmp edx, ecx
			jge END_1
			
			mov ebx, edx
			WHILE_LOOP_2:
				mov edi, dim
				dec edi
				sub edi, edx
				cmp ebx, edi
				jge END_2
            // compute index of pixel p0, find the corresponding memory address and store it in a0
		        mov edi, ebx
				imul edi, dim
				add edi, edx
				mov esi, dword ptr[eax + edi*4]
				mov a0, esi
            // compute index of pixel p90, find the corresponding memory address and store it in a90
				mov edi, edx
				imul edi, dim
				add edi, dim
				dec edi
				sub edi, ebx
				mov esi, dword ptr[eax + edi*4]
				mov a90, esi
            // compute index of pixel p180, find the corresponding memory address and store it in a180
				mov edi, dim
				dec edi
				sub edi, ebx
				imul edi, dim
				add edi, dim
				dec edi
				sub edi, edx
				mov esi, dword ptr[eax + edi*4]
				mov a180, esi
            // compute index of pixel p270, find the corresponding memory address and store it in a270
				mov edi, dim
				dec edi
				sub edi, edx
				imul edi, dim
				add edi, ebx
				mov esi, dword ptr[eax + edi*4]
				mov a270, esi
            // rotationaly swap pixel values: p0 -> p90 -> p180 -> p270 -> p0
				mov edi, ebx
				imul edi, dim
				add edi, edx
				mov esi, a270
				mov dword ptr[eax + edi*4], esi

				mov edi, edx
				imul edi, dim
				add edi, dim
				dec edi
				sub edi, ebx
				mov esi, a0
				mov dword ptr[eax + edi*4], esi

				mov edi, dim
				dec edi
				sub edi, ebx
				imul edi, dim
				add edi, dim
				dec edi
				sub edi, edx
				mov esi, a90
				mov dword ptr[eax + edi*4], esi

				mov edi, dim
				dec edi
				sub edi, edx
				imul edi, dim
				add edi, ebx
				mov esi, a180
				mov dword ptr[eax + edi*4], esi

				inc ebx
				jmp WHILE_LOOP_2
			END_2:
				inc edx
			jmp WHILE_LOOP_1
		END_1:
        // YOUR CODE ENDS HERE
    }
}