//Name: Ran Duan
//Student ID: 23413224
#include <stdio.h>
#include <stdlib.h>

void p1_parity();
void p2_accumulator();
void p3_fibonacci();
void p4_while();
void p5_replace_loop();
void p6_swap(int *, int *);

int main() {
	int i = 1;
	int a = 5, b = 4;
	while (i != 0) {
		printf("\nType 0 to exit or type the question number to proceed: ");
		scanf_s("%d", &i);
		switch (i) {
		case 1:
			p1_parity();
			break;
		case 2:
			p2_accumulator();
			break;
		case 3:
			p3_fibonacci();
			break;
		case 4:
			p4_while();
			break;
		case 5:
			p5_replace_loop();
			break;
		case 6:
			printf("Before: a=%d, b=%d", a, b);
			p6_swap(&a, &b);
			printf("\nAfter: a=%d, b=%d", a, b);
		default:
			break;
		}
	}
}


void p1_parity() {
	// Your code goes here!
	int num;
	scanf_s("%d", &num);
	if (num % 2 == 0)
		printf("Even");
	else
		printf("Odd");
	//
}

void p2_accumulator() {
	// Your code goes here!
	int n, sum = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		sum += 2 * i + 1;
	printf("%d", sum);
	//
}

void p3_fibonacci() {
	// Your code goes here!
	int n, a = 1, b = 1;
	scanf_s("%d", &n);
	if (n == 0) return;
	printf("%d ", a);
	if (n == 1) return;
	printf("%d ", b);
	int c;
	while (n > 0)
	{
		c = a + b;
		printf("%d ", c);
		a = b;
		b = c;
		n -= 1;
	}
	//
}

void p4_while() {
	// Your code goes here!
	char grade;
	int count = 0, a = 0, b = 0, c = 0, d = 0, f = 0;
	while (scanf_s(" %c", &grade))
	{
		if (grade == 'Z' || grade == 'z') break;
		if (grade == 'A' || grade == 'a') a += 1;
		else if (grade == 'B' || grade == 'b') b += 1;
		else if (grade == 'C' || grade == 'c') c += 1;
		else if (grade == 'D' || grade == 'd') d += 1;
		else if (grade == 'F' || grade == 'f') f += 1;
		count += 1;
	}
	printf("Total Number of Scores Entered: %d\n", count);
	printf("A: %d\n", a);
	printf("B: %d\n", b);
	printf("C: %d\n", c);
	printf("D: %d\n", d);
	printf("F: %d", f);
	//
}

void p5_replace_loop() {
	int thresh;
	int max = 500;

	printf(" Enter threshold value (between 0 and 500) :");
	scanf_s("%d", &thresh);

	int i, j;
	int sum = 0;

	// Your code goes here!
	i = 0;
	j = max;
	while (i < thresh && j > thresh)
	{
		sum += (i + j);
		i += 1;
		j -= 2;
	}
	//

	printf(" Sum equals to: %d \n", sum);
}

void p6_swap(int *p1, int *p2) {
	// Your code goes here!
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	//
}
