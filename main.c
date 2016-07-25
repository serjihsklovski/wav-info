#include <stdio.h>
#include "wav-info.h"


int main(int argc, char* argv[]) {
    int EXIT_CODE;

    if (argc == 2) {
        EXIT_CODE = get_wav_info(argv[1]);
    } else {
        puts("invocation example: wav-info <file name>");
        EXIT_CODE = 1;
    }

    return EXIT_CODE;
}
