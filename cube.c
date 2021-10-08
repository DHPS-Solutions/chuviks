#include <stdio.h>

struct Cube {
    int pieces[6][9];
};

struct Cube cube;

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
    cube = setCubeState(cube);
    printCube(cube);
    moveR();
    printf("Made an R move");
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

// cube roatitions
// this entire function should be rewritten using a for loop
void moveR() {
    // necessairy because it will be overwritten
    int oldcahce[3] = { cube.pieces[3][2], cube.pieces[3][5], cube.pieces[3][8] };
    int newcahce[3];
    cube.pieces[3][2] = cube.pieces[0][2];
    cube.pieces[3][5] = cube.pieces[0][5];
    cube.pieces[3][8] = cube.pieces[0][8];

    // next permutation
    newcahce[0] = cube.pieces[5][2];
    newcahce[1] = cube.pieces[5][5];
    newcahce[2] = cube.pieces[5][8];
    cube.pieces[5][2] = oldcahce[0];
    cube.pieces[5][5] = oldcahce[1];
    cube.pieces[5][8] = oldcahce[2];

    // next permutation
    oldcahce[0] = newcahce[0];
    oldcahce[1] = newcahce[1];
    oldcahce[2] = newcahce[2];
    newcahce[0] = cube.pieces[4][2];
    newcahce[1] = cube.pieces[4][5];
    newcahce[2] = cube.pieces[4][8];
    cube.pieces[4][2] = oldcahce[0];
    cube.pieces[4][5] = oldcahce[1];
    cube.pieces[4][8] = oldcahce[2];

    // last permutation
    oldcahce[0] = newcahce[0];
    oldcahce[1] = newcahce[1];
    oldcahce[2] = newcahce[2];
    cube.pieces[0][2] = oldcahce[0];
    cube.pieces[0][5] = oldcahce[1];
    cube.pieces[0][8] = oldcahce[2];
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
