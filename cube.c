#include <stdio.h>

struct Cube {
    int pieces[6][9];
};

// globals
struct Cube cube;
int FACES = 6;
int PIECESPF = 9;

// changes the position of the cube's pieces
void moveR();
void moveL();
void moveU();
void moveD();
void moveF();
void moveB();
void rotateFace(int);

struct Cube setCubeState();
void printCube(struct Cube);

int main() {
    cube = setCubeState(cube);
    printCube(cube);
    moveR();
    moveL();
    printf("Made R and L moves\n");
    printCube(cube);
    moveR();
    moveR();
    moveR();
    moveL();
    moveL();
    moveL();
    printf("Made R3 and L3 moves to solve cube\n");
    printCube(cube);
    return 0;
}

// eventually this function should read from std in.
// currently sets cube to solved state, subsequent to changes
struct Cube setCubeState() {
    struct Cube c;
    // set cube to solved state
    for (int i = 0; i < FACES; i++) {
        for (int j = 0; j < PIECESPF; j++) {
            c.pieces[i][j] = i;
        }
    }
    return c;
}

void rotateFace(int face) {
    struct Cube temp = cube;

    temp.pieces[face][0] = cube.pieces[face][6];
    temp.pieces[face][1] = cube.pieces[face][3];
    temp.pieces[face][2] = cube.pieces[face][0];
    temp.pieces[face][3] = cube.pieces[face][7];
    temp.pieces[face][4] = cube.pieces[face][4];
    temp.pieces[face][5] = cube.pieces[face][1];
    temp.pieces[face][6] = cube.pieces[face][8];
    temp.pieces[face][7] = cube.pieces[face][5];
    temp.pieces[face][8] = cube.pieces[face][2];
}

// cube roatitions
void moveR() {
    struct Cube temp = cube;
    // front face to up face
    temp.pieces[3][2] = cube.pieces[0][2];
    temp.pieces[3][5] = cube.pieces[0][5];
    temp.pieces[3][8] = cube.pieces[0][8];

    // up face to back face
    temp.pieces[5][2] = cube.pieces[3][2];
    temp.pieces[5][5] = cube.pieces[3][5];
    temp.pieces[5][8] = cube.pieces[3][8];

    // back face to down face
    temp.pieces[4][2] = cube.pieces[5][2];
    temp.pieces[4][5] = cube.pieces[5][5];
    temp.pieces[4][8] = cube.pieces[5][8];

    // down face to front face
    temp.pieces[0][2] = cube.pieces[4][2];
    temp.pieces[0][5] = cube.pieces[4][5];
    temp.pieces[0][8] = cube.pieces[4][8];

    cube = temp;
    // roate entire right face
    rotateFace(2);
}

void moveL() {
    struct Cube temp = cube;
    // up face to front face
    temp.pieces[0][0] = cube.pieces[3][0];
    temp.pieces[0][3] = cube.pieces[3][3];
    temp.pieces[0][6] = cube.pieces[3][6];

    // front face to down face
    temp.pieces[4][0] = cube.pieces[0][0];
    temp.pieces[4][3] = cube.pieces[0][3];
    temp.pieces[4][6] = cube.pieces[0][6];

    // up down to back face
    temp.pieces[5][0] = cube.pieces[4][0];
    temp.pieces[5][3] = cube.pieces[4][3];
    temp.pieces[5][6] = cube.pieces[4][6];

    // up back to uo face
    temp.pieces[3][0] = cube.pieces[5][0];
    temp.pieces[3][3] = cube.pieces[5][3];
    temp.pieces[3][6] = cube.pieces[5][6];

    cube = temp;
    // roate entire left face
    rotateFace(1);
}


void printCube(struct Cube c) {
    char colors[6][10] = { "green", "orange", "red", "white", "yellow", "blue" };
    char positions[6][10] = { "front", "left", "right", "up", "down", "back" };
    printf("----------CURRENT STATE----------\n");
    for (int i = 0; i < FACES; i++) {
        printf("%s: ", positions[i]);
        for (int j = 0; j < PIECESPF; j++) {
            int pieceValue = c.pieces[i][j];
            printf("%s, ", colors[pieceValue]);
        }
        printf("\n");
    }
    printf("---------------------------------\n");
}
