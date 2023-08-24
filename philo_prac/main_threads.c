#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void *routine_1()
{
	++x;
	sleep(2);
	printf("x value : %d\n", x);
	return (NULL);
}

void *routine_2()
{
	sleep(2);
	printf("x value : %d\n", x);
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t t1;
	pthread_t t2;
	if (pthread_create(&t1, NULL, &routine_1, NULL) != 0) {
		return (1);
	}
	if (pthread_create(&t2, NULL, &routine_2, NULL) != 0) {
		return (2);
	}
	if (pthread_join(t1, NULL)) {
		return (3);
	}
	if (pthread_join(t2, NULL)) {
		return (4);
	}
	return (0);
}
