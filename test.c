#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ByteSize 8

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


int main(void) {

    char * ptr;
    char Byte[ByteSize] = "";
    int display[8];
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) { // draw tetris pieces already placed on the board
            // if (board->grid[x][y] != 0) {
            if (((x + y) + 5) % 3 == 0) {
                // wmove(board->gameWin, y + 1, x + 1);
                // waddch(board->gameWin, 79);
                strncat(Byte, "1", 1);
            }
            else {
                strncat(Byte, "0", 1);
            }
        }
        int parsed = strtol(Byte, & ptr, 2);
        // printf("%x\n", parsed);
        display[y] = parsed;
        Byte[0] = '\0';
    }

    // for (int i = 0; i < 8; i++){
    //     printf("%x, ", display[i]);
    // }
    // printf("\n");

    for (int i = 0; i < 8; i++){
        printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(display[i]));
        printf("\n");
    }
    printf("\n");

    char Byte2[ByteSize] = "";
    int display2[8];
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) { // draw tetris pieces already placed on the board
            // if (board->grid[x][y] != 0) {
            if (((x + y) + 3) % 5 == 0) {
                // wmove(board->gameWin, y + 1, x + 1);
                // waddch(board->gameWin, 79);
                strncat(Byte2, "1", 1);
            }
            else {
                strncat(Byte2, "0", 1);
            }
        }
        int parsed = strtol(Byte2, & ptr, 2);
        // printf("%x\n", parsed);
        display2[y] = parsed;
        Byte2[0] = '\0';
    }

    // for (int i = 0; i < 8; i++){
    //     printf("%x, ", display2[i]);
    // }
    // printf("\n");

    for (int i = 0; i < 8; i++){
        printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(display2[i]));
        printf("\n");
    }
    printf("\n");

    int display_fin[8];
    for (int i = 0; i < 8; i++){
        display_fin[i] = display[i] | display2[i];
        printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(display_fin[i]));
        printf("\n");
    }

    return 0;
}
