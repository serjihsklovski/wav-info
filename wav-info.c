#include "wav-info.h"
#include <stdio.h>


int get_wav_info(char* file_name) {
    int EXIT_CODE = 0;

    FILE* file = fopen(file_name, "rb");

    if (file == NULL) {
        EXIT_CODE = 1;
    } else {
        Header wav_header;
        fread(&wav_header, sizeof(Header), 1, file);
        fclose(file);
        print_info(&wav_header);
    }

    return EXIT_CODE;
}


void print_info(const Header* header) {
    printf("chunkId:       %c%c%c%c\n", header->chunkId[0],
                                        header->chunkId[1],
                                        header->chunkId[2],
                                        header->chunkId[3]);

    printf("chunkSize:     %u\n",       header->chunkSize);

    printf("format:        %c%c%c%c\n", header->format[0],
                                        header->format[1],
                                        header->format[2],
                                        header->format[3]);

    printf("subchunk1Id:   %c%c%c%c\n", header->subchunk1Id[0],
                                        header->subchunk1Id[1],
                                        header->subchunk1Id[2],
                                        header->subchunk1Id[3]);

    printf("subchunk1Size: %u\n",       header->subchunk1Size);
    printf("audioFormat:   %u\n",       header->audioFormat);
    printf("numChannels:   %u\n",       header->numChannels);
    printf("sampleRate:    %u\n",       header->sampleRate);
    printf("byteRate:      %u\n",       header->byteRate);
    printf("blockAlign:    %u\n",       header->blockAlign);
    printf("bitsPerSample: %u\n",       header->bitsPerSample);

    printf("subchunk2Id:   %c%c%c%c\n", header->subchunk2Id[0],
                                        header->subchunk2Id[1],
                                        header->subchunk2Id[2],
                                        header->subchunk2Id[3]);

    printf("subchunk2Size: %u\n",       header->subchunk2Size);
}
