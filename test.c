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

    int display[8] = {0};
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) { // draw tetris pieces already placed on the board
            // if (board->grid[x][y] != 0) {
            if (((x + y) + 5) % 3 == 0) {
                display[y] |= (1u << x);
            }
        }
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

    int display2[8] = {0};
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) { // draw tetris pieces already placed on the board
            // if (board->grid[x][y] != 0) {
            if (((x + y) + 3) % 5 == 0) {
                // wmove(board->gameWin, y + 1, x + 1);
                // waddch(board->gameWin, 79);
                display2[y] |= (1u << x);
            }
        }
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
