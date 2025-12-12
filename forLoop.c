#include <stdio.h>
#include <stdbool.h>

/* Advanced for-loop examples collected in this file.
   Compile: gcc "forLoop.c" -o forLoop.exe
   Run:     .\forLoop.exe
*/

void multiple_init_update(void) {
	puts("--- multiple init/update ---");
	for (int i = 0, j = 10; i < 5; ++i, j -= 2)
		printf("i=%d, j=%d\n", i, j);
}

void nested_loops_table(void) {
	puts("--- nested loops (5x5) ---");
	for (int r = 1; r <= 5; ++r) {
		for (int c = 1; c <= 5; ++c)
			printf("%3d", r * c);
		putchar('\n');
	}
}

void pointer_iteration(void) {
	puts("--- pointer iteration over array ---");
	int arr[] = {1, 2, 3, 4, 5};
	for (int *p = arr; p < arr + (int)(sizeof(arr)/sizeof(arr[0])); ++p)
		printf("%d ", *p);
	putchar('\n');
}

void break_and_continue_demo(void) {
	puts("--- break and continue demo ---");
	for (int i = 1; i <= 10; ++i) {
		if (i == 8) {
			puts("breaking at 8");
			break;
		}
		if (i % 3 == 0) {
			puts("skipping a multiple of 3");
			continue;
		}
		printf("i=%d\n", i);
	}
}

void empty_body_example(void) {
	puts("--- empty-body loop example ---");
	int data[] = {0, 0, 7, 0};
	int i = 0;
	for (; i < (int)(sizeof(data)/sizeof(data[0])) && data[i] == 0; ++i)
		; /* empty body */
	if (i < (int)(sizeof(data)/sizeof(data[0])))
		printf("first non-zero at index %d -> %d\n", i, data[i]);
	else
		puts("no non-zero found");
}

void simple_prime_finder(int limit) {
	puts("--- primes up to limit ---");
	if (limit < 2) { puts("no primes"); return; }
	for (int n = 2; n <= limit; ++n) {
		bool prime = true;
		for (int d = 2; d * d <= n; ++d) {
			if (n % d == 0) { prime = false; break; }
		}
		if (prime) printf("%d ", n);
	}
	putchar('\n');
}

int main(void) {
	int choice = -1;
	while (choice != 0) {
		puts("\nFor-loop Examples Menu:");
		puts(" 1) multiple init/update");
		puts(" 2) nested multiplication table");
		puts(" 3) pointer iteration over array");
		puts(" 4) break and continue demo");
		puts(" 5) empty-body loop example");
		puts(" 6) simple prime finder (enter limit)");
		puts(" 0) exit");
		printf("Enter choice: ");
		if (scanf("%d", &choice) != 1) {
			int ch;
			while ((ch = getchar()) != '\n' && ch != EOF) ;
			puts("Invalid input, try again.");
			continue;
		}

		switch (choice) {
			case 1:
				multiple_init_update();
				break;
			case 2: {
				int size = 5;
				printf("Enter table size (e.g. 5): ");
				if (scanf("%d", &size) != 1 || size <= 0) { size = 5; }
				for (int r = 1; r <= size; ++r) {
					for (int c = 1; c <= size; ++c)
						printf("%4d", r * c);
					putchar('\n');
				}
				break;
			}
			case 3:
				pointer_iteration();
				break;
			case 4:
				break_and_continue_demo();
				break;
			case 5:
				empty_body_example();
				break;
			case 6: {
				int limit = 30;
				printf("Enter limit for primes (e.g. 30): ");
				if (scanf("%d", &limit) != 1 || limit < 0) limit = 30;
				simple_prime_finder(limit);
				break;
			}
			case 0:
				puts("Goodbye.");
				break;
			default:
				puts("Unknown choice, try again.");
		}
		/* flush leftover input newline to prepare for next scanf */
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF) ;
	}
	return 0;
}

