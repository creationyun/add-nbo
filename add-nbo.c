#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t file_read_nbo(const char *filename)
{
    FILE *f;
    uint32_t num;

    /* file open */
    f = fopen(filename, "rb");

    /* check whether the file opened or not */
    if (f == NULL) {
        fprintf(stderr, "Error : cannot open '%s'\n", filename);
        exit(1);
    }

    /* read integer as network byte order */
    size_t elem_count = fread(&num, 1, sizeof(uint32_t), f);

    /* check whether the file is 4 or not */
    if (elem_count != 4) {
        fprintf(stderr, "Error : file '%s' is not 4 bytes size.\n", filename);
        fclose(f);
        exit(1);
    }

    /* file close and return */
    fclose(f);

    return num;
}


int main(int argc, char *argv[])
{
    uint32_t ha, hb, hc;

    /* it needs 3 arguments */
    if (argc != 3) {
        printf("Syntax : %s <file1> <file2>\n", argv[0]);
        return 0;
    }

    /* read integer and convert nbo to hbo */
    ha = ntohl(file_read_nbo(argv[1]));
    hb = ntohl(file_read_nbo(argv[2]));

    /* add as hbo and print */
    hc = ha + hb;

    /* print result */
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", ha, ha, hb, hb, hc, hc);
}
