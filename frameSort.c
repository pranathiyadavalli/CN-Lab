#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define FSIZE 3
#define FMAX 127

char strg[FSIZE * FMAX];

struct frame {
	char text[FSIZE];
	int sno;
} fr[FMAX], sh[FMAX];

int assignSno();
void generate(int*, const int);
void shuffle (const int);
void sort(const int);

int main() {

	int frames, i;
	printf("Enter the message: ");
	gets(strg);
	frames = assignSno();
	shuffle(frames);
	sort(frames);
	printf("\n\nAFTER SORTING\n");
	for(i = 0; i < frames; i++)
	printf("%s",sh[i].text);
	printf("\n\n");
	return 0;
}

int assignSno() {
	int k = 0, i, j;
	for (i = 0; i < strlen(strg); k++) {
		fr[k].sno = k;
		for (j = 0; j < FSIZE && strg[i] != '\0'; j++) {
			fr[k].text[j] = strg[i++];
		}		
	}
	printf("\nAfter assigning sequence numbers:\n");
	for(i = 0; i < k; i++) {
		printf("%d:%s ", i, fr[i].text);
	}
	return k;
}

void generate(int *random, const int lt) {
	int r, i = 0, j;
	while (i < lt) {
		r = rand() % lt;
		for (j = 0; j < i; j++) {
			if (random[j] == r) {
				break;
			}
		}
			if (i == j) {
				random[i++] = r;
			}
	}
}

void shuffle (const int frames) {
	int i, k = 0, random[frames];
	generate(random, frames);
	for (i = 0; i < frames; i++) {
		sh[i] = fr[random[i]];
	}
	printf("\n\nAFTER SHUFFLING:\n");
	for (i = 0; i < frames; i++) {
		printf("%d:%s ", sh[i].sno, sh[i].text);
	}
}

void sort(const int frames) {
	int i, j, flag = 1;
	struct frame hold;
	for (i = 0; i < frames - 1 && flag == 1; i++) {
		flag = 0;
		for (j = 0; j < frames - 1 - i; j++) {
			if (sh[j].sno > sh[j+1].sno) {
				hold = sh[j];
				sh[j] = sh[j+1];
				sh[j+1] = hold;
				flag = 1;
			}
		}
	}
}



