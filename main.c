#include <unistd.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include "Itoa/itoa.h"
#include "print/print.h"

time_t start;
char hours[5];
char mins[3];

void fine(int _) {
	time_t elapsed = time(NULL) - start;
	strncpy(hours, itoa(elapsed / 3600, 10), 5);
	strncpy(mins, itoa((elapsed % 3600) / 60, 10), 3);
	println("\r ", hours, ":", mins, ":", itoa(elapsed % 60, 10), " elapsed.");
	_exit(0);
}

int main() {
	for (int i = 0; i < 5; i++)
		hours[i] = 0;
	for (int i = 0; i < 3; i++)
		hours[i] = 0;
	start = time(NULL);
	signal(SIGINT, fine);
	signal(SIGTERM, fine);
	signal(SIGHUP, fine);
	signal(SIGQUIT, fine);
	for (;;) {
		time_t elapsed = time(NULL) - start;
		strncpy(hours, itoa(elapsed / 3600, 10), 5);
		strncpy(mins, itoa((elapsed % 3600) / 60, 10), 3);
		printv("\r ", hours, ":", mins, ":", itoa(elapsed % 60, 10), " elapsed.");
		sleep(1);
	}
	// const time_t end = time(NULL);
}
