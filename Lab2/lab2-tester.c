#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

#ifndef GRADING_MODE
/* Once you are done implementing the functions, activate one or more of
 the following test sequences.
 Procedure to activate a single test sequence:
     replace 
          #define TEST_PART1_1 0
     with
          #define TEST_PART1_1 1
*/

#define TEST_PART1_1 1
#define TEST_PART1_2 1
#define TEST_PART1_3 1
#define TEST_PART1_4 1

#define TEST_PART2_1 1
#define TEST_PART2_2 1
#define TEST_PART2_3 1
#define TEST_PART2_4 1
#define TEST_PART2_5 1
#define TEST_PART2_6 1

#define TEST_PART3_1 1
#define TEST_PART3_2 1
#define TEST_PART3_3 1
#define TEST_PART3_4 1
#define TEST_PART3_5 1
#endif

extern void minMax(int a, int b, int c, int *result);
extern int swapNibbles(unsigned char x);
extern int isPowerOfTwo(unsigned int n);

extern char *yourName;
extern char *yourStudentID;
extern char *yourUCInetID;
static void testcode();

int main(void)
{
	testcode();
	#ifndef GRADING_MODE
	getchar();
	#endif
	return 0;
}

static void testcode (void)
{
	unsigned char result1;
	unsigned char correct_answer1;
	int *result2;
	int correct_answer2;
	int result3;
	int correct_answer3;

	int c = 56;

	printf ("ICS 51, Lab 2, %s, %s, %s\n\n", yourName, yourStudentID, yourUCInetID);

	#ifndef GRADING_MODE
	printf( "\nTesting part 1 \n" );
	#endif
	#if TEST_PART1_1
		result1 = swapNibbles(0xFA);
		correct_answer1 = 0xAF;
		#ifndef GRADING_MODE
		printf( "Input = 0x%02X, Output = 0x%02X - %s\n", 0xFA, result1, result1==correct_answer1 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", result1==correct_answer1 ? 1 : 0);
		#endif
	#endif

	#if TEST_PART1_2
		result1 = swapNibbles(0x89);
		correct_answer1 = 0x98;
		#ifndef GRADING_MODE
		printf( "Input = 0x%02X, Output = 0x%02X - %s\n", 0x89, result1, result1==correct_answer1 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", result1==correct_answer1 ? 1 : 0);
		#endif
	#endif

	#if TEST_PART1_3
		result1 = swapNibbles(0x00);
		correct_answer1 = 0x00;
		#ifndef GRADING_MODE
		printf( "Input = 0x%02X, Output = 0x%02X - %s\n", 0x00, result1, result1==correct_answer1 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", result1==correct_answer1 ? 1 : 0);
		#endif
    #endif

	#if TEST_PART1_4
		result1 = swapNibbles(0x01);
		correct_answer1 = 0x10;
		#ifndef GRADING_MODE
		printf( "Input = 0x%02X, Output = 0x%02X - %s\n", 0x01, result1, result1==correct_answer1 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", result1==correct_answer1 ? 1 : 0);
		#endif
    #endif

	#ifndef GRADING_MODE
	printf( "\nTesting part 2 \n" );
	#endif
	#define MULTIPLIER 2017
	#if TEST_PART2_1
		result2 = (int*) malloc(sizeof(int));
		minMax(1,2,3,result2);
		correct_answer2 = (1 + 3) * MULTIPLIER;
		#ifndef GRADING_MODE
		printf( "Input = %d, %d, %d, Output = %d - %s\n", 1, 2, 3, *result2, *result2==correct_answer2 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", *result2==correct_answer2 ? 1 : 0);
		#endif
		free(result2);
	#endif

	#if TEST_PART2_2
		result2 = (int*) malloc(sizeof(int));
		minMax(4,2,7,result2);
		correct_answer2 = (2 + 7) * MULTIPLIER;
		#ifndef GRADING_MODE
		printf( "Input = %d, %d, %d, Output = %d - %s\n", 4, 2, 7, *result2, *result2==correct_answer2 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", *result2==correct_answer2 ? 1 : 0);
		#endif
		free(result2);
	#endif

	#if TEST_PART2_3
		result2 = (int*) malloc(sizeof(int));
		minMax(3,2,1,result2);
		correct_answer2 = (1 + 3) * MULTIPLIER;
		#ifndef GRADING_MODE
		printf( "Input = %d, %d, %d, Output = %d - %s\n", 3, 2, 1, *result2, *result2==correct_answer2 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", *result2==correct_answer2 ? 1 : 0);
		#endif
		free(result2);
	#endif

	#if TEST_PART2_4
		result2 = (int*) malloc(sizeof(int));
		minMax(-50,2,-100,result2);
		correct_answer2 = (-100 + 2) * MULTIPLIER;
		#ifndef GRADING_MODE
		printf( "Input = %d, %d, %d, Output = %d - %s\n", -50, 2, -100, *result2, *result2==correct_answer2 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", *result2==correct_answer2 ? 1 : 0);
		#endif
		free(result2);
	#endif
	
	#if TEST_PART2_5
		result2 = (int*) malloc(sizeof(int));
		minMax(0,0,0,result2);
		correct_answer2 = (0 + 0) * MULTIPLIER;
		#ifndef GRADING_MODE
		printf( "Input = %d, %d, %d, Output = %d - %s\n", 0, 0, 0, *result2, *result2==correct_answer2 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", *result2==correct_answer2 ? 1 : 0);
		#endif
		free(result2);
	#endif

	#if TEST_PART2_6
		result2 = (int*) malloc(sizeof(int));
		minMax(-100,-200,300,result2);
		correct_answer2 = (-200 + 300) * MULTIPLIER;
		#ifndef GRADING_MODE
		printf("Input = %d, %d, %d, Output = %d - %s\n", -100, -200, 300, *result2, *result2 == correct_answer2 ? "CORRECT" : "INCORRECT");
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", *result2==correct_answer2 ? 1 : 0);
		#endif
		free(result2);
	#endif

	#ifndef GRADING_MODE
	printf( "\nTesting part 3 \n" );
	#endif
	#if TEST_PART3_1
		result3 = isPowerOfTwo(1);
		correct_answer3 = 1;
		#ifndef GRADING_MODE
		printf( "Input = %d, Output = %d - %s\n", 1, result3, result3==correct_answer3 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", result3==correct_answer3 ? 1 : 0);
		#endif
	#endif

	#if TEST_PART3_2
		result3 = isPowerOfTwo(2048);
		correct_answer3 = 1;
		#ifndef GRADING_MODE
		printf( "Input = %d, Output = %d - %s\n", 2048, result3, result3==correct_answer3 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", result3==correct_answer3 ? 1 : 0);
		#endif
	#endif

	#if TEST_PART3_3
		result3 = isPowerOfTwo(91919);
		correct_answer3 = 0;
		#ifndef GRADING_MODE
		printf( "Input = %d, Output = %d - %s\n", 91919, result3, result3==correct_answer3 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", result3==correct_answer3 ? 1 : 0);
		#endif
	#endif

	#if TEST_PART3_4
		result3 = isPowerOfTwo(1024*1024);
		correct_answer3 = 1;
		#ifndef GRADING_MODE
		printf( "Input = %d, Output = %d - %s\n", 1024*1024, result3, result3==correct_answer3 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", result3==correct_answer3 ? 1 : 0);
		#endif
	#endif

	#if TEST_PART3_5
		result3 = isPowerOfTwo(1023*1023);
		correct_answer3 = 0;
		#ifndef GRADING_MODE
		printf( "Input = %d, Output = %d - %s\n", 1023*1023, result3, result3==correct_answer3 ? "CORRECT": "INCORRECT" );
		#endif
		#ifdef GRADING_MODE
		printf( "%d\n", result3==correct_answer3 ? 1 : 0);
		#endif
	#endif

	#ifndef GRADING_MODE
	printf( "\n" );
	#endif
}