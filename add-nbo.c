#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	FILE *f1, *f2;
	uint32_t a, b;
	uint32_t ha, hb, hc;

	/* it needs 3 arguments */
	if (argc != 3) {
		printf("syntax : %s <file1> <file2>\n", argv[0]);
		return 0;
	}

	/* first file open */
	f1 = fopen(argv[1], "rb");

	if (f1 == NULL) {
		fprintf(stderr, "error : cannot open %s\n", argv[1]);
		return 1;
	}

	/* second file open */
	f2 = fopen(argv[2], "rb");

	if (f2 == NULL) {
		fprintf(stderr, "error : cannot open %s\n", argv[2]);
		return 1;
	}


	/* read integer as network byte order */
	fread(&a, sizeof(uint32_t), 1, f1);
	fread(&b, sizeof(uint32_t), 1, f2);

	/* convert nbo to hbo */
	ha = ntohl(a);
	hb = ntohl(b);

	/* add as hbo and print */
	hc = ha + hb;

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", ha, ha, hb, hb, hc, hc);
}
