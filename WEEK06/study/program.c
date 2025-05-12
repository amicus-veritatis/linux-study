#include <stdio.h>
#define MAX_FIBO_MEMO 5000

unsigned long long memo[MAX_FIBO_MEMO];

unsigned long long fibonacci_recursive (int n) {
	if (n <= 2) {
		return 1;
	}
	return (fibonacci_recursive(n-1) + fibonacci_recursive(n-2)) % 1000000007;
}

unsigned long long fibonacci_memoization (int n) {
	if (n <= 2) {
		return 1;
	}
	if (memo[n] != 0) return memo[n];
	memo[n] = (fibonacci_memoization(n-2) + fibonacci_memoization(n-1)) % 1000000007;
	return memo[n];	
}

int main() {
	printf("Hello, World!\n");
	printf("F_40 (mod 1000000007) = \n");
        printf("\t%llu\n", fibonacci_recursive(40));
	printf("F_2000 (mod 1000000007) = \n");
	printf("\t%llu\n", fibonacci_memoization(2000));
	printf("F_4000 (mod 1000000007) = \n");
	printf("\t%llu\n", fibonacci_memoization(4000));
	return 0;
}
