#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 Advanced for-loop examples collected in one file.
 Each function demonstrates a different for-loop pattern.
 Compile with: gcc "advanced_for.c" -o advanced_for.exe
 Run with: .\advanced_for.exe
*/

void example_multiple_init_and_update(void) {
    puts("--- multiple init/update in for-loop ---");
    for (int i = 0, j = 10; i < 5; ++i, j -= 2)
        printf("i=%d, j=%d\n", i, j);
}

void example_nested_loops_table(void) {
    puts("--- nested loops: 5x5 multiplication table ---");
    for (int r = 1; r <= 5; ++r) {
        for (int c = 1; c <= 5; ++c)
            printf("%3d", r * c);
        putchar('\n');
    }
}

void example_array_with_pointer_iteration(void) {
    puts("--- iterate array with pointer ---");
    int a[] = {10, 20, 30, 40, 50};
    for (int *p = a; p < a + (sizeof(a) / sizeof(a[0])); ++p)
        printf("%d ", *p);
    putchar('\n');
}

void example_break_and_continue(void) {
    puts("--- break and continue demo ---");
    for (int i = 1; i <= 12; ++i) {
        if (i % 4 == 0) {
            puts("found a multiple of 4, breaking");
            break; /* stops the loop entirely */
        }
        if (i % 3 == 0) {
            puts("skipping a multiple of 3");
            continue; /* skip this iteration */
        }
        printf("i=%d\n", i);
    }
}

void example_empty_body_loop(void) {
    puts("--- empty-body loop (advance until condition) ---");
    int n = 123456;
    int digits = 0;
    for (; n > 0; n /= 10)
        ++digits; /* small body used here; to show empty-body style use ";" as body */
    printf("digit count = %d\n", digits);

    /* Example of truly empty body: advance index to first non-zero in array */
    int arr[] = {0, 0, 0, 5, 7};
    int idx = 0;
    for (; idx < (int)(sizeof(arr)/sizeof(arr[0])) && arr[idx] == 0; ++idx)
        ; /* empty body */
    if (idx < (int)(sizeof(arr)/sizeof(arr[0])))
        printf("first non-zero at index %d = %d\n", idx, arr[idx]);
    else
        puts("no non-zero element found");
}

void example_primes_sieve_style(int limit) {
    puts("--- simple prime finder using nested for-loops ---");
    if (limit < 2) {
        puts("no primes");
        return;
    }
    for (int n = 2; n <= limit; ++n) {
        bool is_prime = true;
        for (int d = 2; d * d <= n; ++d) {
            if (n % d == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            printf("%d ", n);
    }
    putchar('\n');
}

int main(void) {
    puts("Advanced for-loop examples running:\n");
    example_multiple_init_and_update();
    putchar('\n');

    example_nested_loops_table();
    putchar('\n');

    example_array_with_pointer_iteration();
    putchar('\n');

    example_break_and_continue();
    putchar('\n');

    example_empty_body_loop();
    putchar('\n');

    example_primes_sieve_style(50);

    return 0;
}
