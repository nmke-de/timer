#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "Itoa/itoa.h"
#include "print/print.h"

void fine(int _) {
	_exit(0);
}

int main() {
	char hours[5];
	for (int i = 0; i < 5; i++)
		hours[i] = 0;
	char mins[3];
	for (int i = 0; i < 3; i++)
		hours[i] = 0;
	const time_t start = time(NULL);
	signal(SIGINT, fine);
	signal(SIGTERM, fine);
	signal(SIGHUP, fine);
	signal(SIGQUIT, fine);
	for (;;) {
		time_t elapsed = time(NULL) - start;
		strncpy(hours, itoa(elapsed / 3600, 10), 5);
		strncpy(hours, itoa((elapsed % 3600) / 60, 10), 3);
		println("\r ", hours, ":", mins, ":", itoa(elapsed % 60, 10), "elapsed.");
		sleep(1);
	}
	// const time_t end = time(NULL);
}
