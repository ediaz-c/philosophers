#include <stdio.h>
#include <sys/time.h>

int main(void)
{
    struct timeval tv;
	while (1)
	{
    	gettimeofday(&tv, NULL);
    	printf("Segundos: %ld\n", tv.tv_sec);
    	printf("Microsegundos: %d\n", tv.tv_usec);
		system("clear");
	}
    return 0;

}
