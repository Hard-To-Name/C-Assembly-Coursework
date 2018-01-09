#include <stdio.h>

__declspec(naked) int callee (int a, int b, int* c)
{

	_asm {

			// Subroutine Prologue
			push ebp           // Save the old base pointer value.
			mov ebp, esp       // Set the new base pointer value.
  
			sub esp, 4         // Make room for one 4-byte local variable.
  
			push edi           // Save the values of registers that the function
			push esi           // will modify. This function uses EDI and ESI and
			push ebx           // EBX

			// Subroutine Body
			mov eax, [ebp+8]   // Move value of parameter 1 into EAX
			mov esi, [ebp+12]  // Move value of parameter 2 into ESI
			mov edi, [ebp+16]  // Move the address of parameter 3 into EDI
			mov ebx, [edi]     // Get the value of parameter 3. Remember, 3rd parameter uses call-by-reference

			mov [ebp-4], ebx   // Move value of parameter 3 into the local variable
			add [ebp-4], esi   // Add ESI into the local variable
  
			add eax, [ebp-4]   // Add the contents of the local variable
							   // into EAX (final result)

			// Subroutine Epilogue 
			pop ebx            // Recover register values
			pop esi            
			pop edi
  
			mov esp, ebp       // Deallocate local variables
  
			pop ebp            // Restore the caller's base pointer value
  
			ret

	     }
}

void caller ()
{
	int var;
	int return_val;

	__asm {
               
			push eax
			push ecx
			push edx

			mov var, 10           
			mov eax, 30

			lea  ecx, var  
			push ecx              // Push (the address of) last parameter first (c)
			push 20               // Push the second parameter (b)
			push eax              // Push first parameter last (a)

			call callee           // Call the function "int callee (int a, int b, int* c)"

			add esp, 12           // Clear the stack (3 integer argumenets => 3 * 4 bytes => 12 bytes)

			mov return_val, eax   // Read the returned value (the callee puts the return value into eax, so the caller can read it from there)

			pop edx
			pop ecx
			pop eax
			
          }

	printf ("Return value (a + b + c) = %d \n", return_val);
}

int
main(int argc, char* argv[])
{
 
  caller();
  
  return 0;
}