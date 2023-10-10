#include <unistd.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include "Itoa/itoa.h"
#include "print/print.h"

time_t start;
char hours[5];
char mins[3];
char secs[3];

void print_elapsed() {
	time_t elapsed = time(NULL) - start;
	if (elapsed / 3600 < 10) {
		strncpy(hours + 1, itoa(elapsed / 3600, 10), 4);
		hours[0] = '0';
	}
	else
		strncpy(hours, itoa(elapsed / 3600, 10), 5);
	if ((elapsed % 3600) / 60 < 10) {
		strncpy(mins + 1, itoa((elapsed % 3600) / 60, 10), 2);
		mins[0] = '0';
	}
	else
		strncpy(mins, itoa((elapsed % 3600) / 60, 10), 3);
	if (elapsed % 60 < 10) {
		strncpy(secs + 1, itoa(elapsed % 60, 10), 2);
		secs[0] = '0';
	} else
		strncpy(secs, itoa(elapsed % 60, 10), 3);
	printv(" ", hours, ":", mins, ":", secs, "\r");
}

void fine(int _) {
	print_elapsed();
	println("");
	_exit(0);
}

int main() {
	for (int i = 0; i < 5; i++)
		hours[i] = 0;
	for (int i = 0; i < 3; i++)
		mins[i] = 0;
	for (int i = 0; i < 3; i++)
		secs[i] = 0;
	start = time(NULL);
	signal(SIGINT, fine);
	signal(SIGTERM, fine);
	signal(SIGHUP, fine);
	signal(SIGQUIT, fine);
	for (;;) {
		print_elapsed();
		sleep(1);
	}
}
