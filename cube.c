#include <stdio.h>

struct Cube {
    int pieces[6][9];
};

// changes the position of the cube's pieces
void moveR();
void moveL();
void moveU();
void moveD();
void moveF();
void moveB();

struct Cube setCubeState();
void printCube(struct Cube);

int main() {
    struct Cube cube = setCubeState();
    printCube(cube);
    return 0;
}

// eventually this function should read from std in.
// currently sets cube to solved state, subsequent to changes
struct Cube setCubeState() {
    struct Cube c;
    // set cube to solved state
    int faces = sizeof(c.pieces) / sizeof(c.pieces[0]);  // gets total faces
    int piecesPerFace = sizeof(c.pieces[0]) / sizeof(c.pieces[0][0]);  // gets total pieces per face

    for (int i = 0; i < faces; i++) {
        for (int j = 0; j < piecesPerFace; j++) {
            c.pieces[i][j] = i;
        }
    }
    return c;
}

void printCube(struct Cube c) {
    char colors[6][10] = { "green", "orange", "red", "white", "yellow", "blue" };
    char positions[6][10] = { "front", "left", "right", "up", "down", "back" };
    int faces = sizeof(c.pieces) / sizeof(c.pieces[0]);  // gets total faces
    int piecesPerFace = sizeof(c.pieces[0]) / sizeof(c.pieces[0][0]);  // gets total pieces per face

    printf("----------CURRENT STATE----------\n");
    for (int i = 0; i < faces; i++) {
        printf("%s: ", positions[i]);
        for (int j = 0; j < piecesPerFace; j++) {
            int pieceValue = c.pieces[i][j];
            printf("%s, ", colors[pieceValue]);
        }
        printf("\n");
    }
    printf("---------------------------------\n");
}
