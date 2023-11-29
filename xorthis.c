#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hex_to_int(char* a, int len) {
	for (int i=0; i<len; i++) {
		// is number
		if (a[i] >= 48 && a[i] <= 57)
			a[i] -= 48;
		// is capital letter
		if (a[i] >= 65 && a[i] <= 90)
			a[i] -= 55;
		// is lowercase letter
		if (a[i] >= 97 && a[i] <= 122)
			a[i] -= 87;
	}
	// repeat incrementing 16 for length
	a[0] *= 16;
	return ((int)a[0] + a[1]);
}

int main(int argc, char* argv[]) {

	// Imagine here: a function that searches argv for options, and separates \
	//  them into independent variables, avoiding hard-coded argv[index]es
	int setX = 0;
	int setIn = 0;
	int key = 0;
	char* input;
	// I'm certain there's a more sophisticated way of doing this
	for (int i=1; i<argc; i++) {
		if (!strcmp(argv[i], "-x")) {
			setX = 1;
		} else if (strlen(argv[i]) == 1 && *argv[i] >= 48 && *argv[i] <= 57) {
			key = *argv[i] - 48;
		} else if (!strcmp(argv[i], "-")) {
			setIn = 1;
		} else {
			input = argv[i];
		}
	}

	// fuckin idiot, dont use single-letter vars, dumbass
	char c;

	// if - arg, read stdin to array, otherwise use arg
	if (setIn) {
		int i=0;
		while ( (c = getchar()) != EOF ) {
			input[i] = c;
			i++;
		}
	}

	char c2;
	char ic;
	char* h;
	h = malloc(sizeof(char)*2);

	for (int i=0; i<strlen(input); i++) {
		ic = input[i];
		if (setX) {
			h[0] = input[i];
			i++;
			h[1] = input[i];
			ic = hex_to_int(h, 2);
		}
		if (ic != '\n' && ic != 0x0)
			ic ^= key;
		if (ic == 0x0)
			ic = 0x20; // replace 0x0 with space
		printf("%c", ic);
	}

	return 0;
}

