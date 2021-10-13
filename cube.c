#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Cube {
    int pieces[6][9];
};

// globals
int FACES = 6;
int PIECESPF = 9;

// functions that changes the position of the cube's pieces
void applyChanges(struct Cube *, struct Cube *);
void rotateFace(struct Cube *, int);
void moveF(struct Cube *);
void moveR(struct Cube *);
void moveL(struct Cube *);
void moveU(struct Cube *);
void moveB(struct Cube *);
void moveD(struct Cube *);
void randomScramble(struct Cube *, int);
struct Cube toSolvedState();

void printCube(struct Cube);

int main() {
    // for random()
    time_t t;
    srand((unsigned) time(&t));

    struct Cube cube = toSolvedState();
    printCube(cube);
    //randomScramble(15);
    moveF(&cube);
    moveR(&cube);
    moveL(&cube);
    moveU(&cube);
    moveB(&cube);
    moveD(&cube);
    printf("Moves: F R L U B D");
    printCube(cube);
    return 0;
}

// eventually this function should read from std in.
// currently sets cube to solved state, subsequent to changes
struct Cube toSolvedState() {
    struct Cube c;
    // set cube to solved state
    for (int i = 0; i < FACES; i++) {
        for (int j = 0; j < PIECESPF; j++) {
            c.pieces[i][j] = i;
        }
    }
    return c;
}

void randomScramble(struct Cube *ptr, int n) {
    for (int i = 0; i < n; i++) {
        int r = rand() % 10;
        switch(r) {
           case 0:
               moveF(ptr);
               break;
           case 1:
               moveR(ptr);
               break;
           case 2:
               moveL(ptr);
               break;
           case 3:
               moveU(ptr);
               break;
           case 4:
               moveB(ptr);
               break;
           case 5:
               moveD(ptr);
               break;
        }
    }

}

void applyChanges(struct Cube *ptr, struct Cube *tmp) {
    for (int i = 0; i < FACES; i++) {
        for (int j = 0; j < PIECESPF; j++) {
            ptr->pieces[i][j] = tmp->pieces[i][j];
        }
    }
}

void rotateFace(struct Cube *ptr, int face) {
    struct Cube temp = *ptr;

    temp.pieces[face][0] = ptr->pieces[face][6];
    temp.pieces[face][1] = ptr->pieces[face][3];
    temp.pieces[face][2] = ptr->pieces[face][0];
    temp.pieces[face][3] = ptr->pieces[face][7];
    temp.pieces[face][4] = ptr->pieces[face][4];
    temp.pieces[face][5] = ptr->pieces[face][1];
    temp.pieces[face][6] = ptr->pieces[face][8];
    temp.pieces[face][7] = ptr->pieces[face][5];
    temp.pieces[face][8] = ptr->pieces[face][2];

    applyChanges(ptr, &temp);
}

// cube roatitions
void moveF(struct Cube *ptr) {
    struct Cube temp = *ptr;

    // left face to up face
    temp.pieces[3][8] = ptr->pieces[1][2];
    temp.pieces[3][7] = ptr->pieces[1][5];
    temp.pieces[3][6] = ptr->pieces[1][8];

    // down face to left face
    temp.pieces[1][2] = ptr->pieces[4][0];
    temp.pieces[1][5] = ptr->pieces[4][1];
    temp.pieces[1][8] = ptr->pieces[4][2];

    // right face to down face
    temp.pieces[4][0] = ptr->pieces[2][6];
    temp.pieces[4][1] = ptr->pieces[2][3];
    temp.pieces[4][2] = ptr->pieces[2][0];

    // up face to right face
    temp.pieces[2][0] = ptr->pieces[3][6];
    temp.pieces[2][3] = ptr->pieces[3][7];
    temp.pieces[2][6] = ptr->pieces[3][8];

    applyChanges(ptr, &temp);
    // roate entire front face
    rotateFace(ptr, 0);
}

void moveR(struct Cube *ptr) {
    struct Cube temp = *ptr;
    // front face to up face
    temp.pieces[3][2] = ptr->pieces[0][2];
    temp.pieces[3][5] = ptr->pieces[0][5];
    temp.pieces[3][8] = ptr->pieces[0][8];

    // up face to back face
    temp.pieces[5][2] = ptr->pieces[3][2];
    temp.pieces[5][5] = ptr->pieces[3][5];
    temp.pieces[5][8] = ptr->pieces[3][8];

    // back face to down face
    temp.pieces[4][2] = ptr->pieces[5][2];
    temp.pieces[4][5] = ptr->pieces[5][5];
    temp.pieces[4][8] = ptr->pieces[5][8];

    // down face to front face
    temp.pieces[0][2] = ptr->pieces[4][2];
    temp.pieces[0][5] = ptr->pieces[4][5];
    temp.pieces[0][8] = ptr->pieces[4][8];

    applyChanges(ptr, &temp);
    // roate entire right face
    rotateFace(ptr, 2);
}

void moveL(struct Cube *ptr) {
    struct Cube temp = *ptr;
    // up face to front face
    temp.pieces[0][0] = ptr->pieces[3][0];
    temp.pieces[0][3] = ptr->pieces[3][3];
    temp.pieces[0][6] = ptr->pieces[3][6];

    // front face to down face
    temp.pieces[4][0] = ptr->pieces[0][0];
    temp.pieces[4][3] = ptr->pieces[0][3];
    temp.pieces[4][6] = ptr->pieces[0][6];

    // up down to back face
    temp.pieces[5][0] = ptr->pieces[4][0];
    temp.pieces[5][3] = ptr->pieces[4][3];
    temp.pieces[5][6] = ptr->pieces[4][6];

    // up back to uo face
    temp.pieces[3][0] = ptr->pieces[5][0];
    temp.pieces[3][3] = ptr->pieces[5][3];
    temp.pieces[3][6] = ptr->pieces[5][6];

    applyChanges(ptr, &temp);
    // roate entire left face
    rotateFace(ptr, 1);
}

void moveU(struct Cube *ptr) {
    struct Cube temp = *ptr;
    // right face to front face
    temp.pieces[0][0] = ptr->pieces[2][0];
    temp.pieces[0][1] = ptr->pieces[2][1];
    temp.pieces[0][2] = ptr->pieces[2][2];

    // front face to left face
    temp.pieces[1][0] = ptr->pieces[0][0];
    temp.pieces[1][1] = ptr->pieces[0][1];
    temp.pieces[1][2] = ptr->pieces[0][2];

    // left face to back face
    temp.pieces[5][8] = ptr->pieces[1][0];
    temp.pieces[5][7] = ptr->pieces[1][1];
    temp.pieces[5][6] = ptr->pieces[1][2];

    // back face to right face
    temp.pieces[2][0] = ptr->pieces[5][8];
    temp.pieces[2][1] = ptr->pieces[5][7];
    temp.pieces[2][2] = ptr->pieces[5][6];

    applyChanges(ptr, &temp);
    // roate entire up face
    rotateFace(ptr, 3);
}

void moveB(struct Cube *ptr) {
    struct Cube temp = *ptr;
    // right face to up face
    temp.pieces[3][0] = ptr->pieces[2][2];
    temp.pieces[3][1] = ptr->pieces[2][5];
    temp.pieces[3][2] = ptr->pieces[2][8];

    // up face to left face
    temp.pieces[1][6] = ptr->pieces[3][0];
    temp.pieces[1][3] = ptr->pieces[3][1];
    temp.pieces[1][0] = ptr->pieces[3][2];

    // left face to down face
    temp.pieces[4][8] = ptr->pieces[1][6];
    temp.pieces[4][7] = ptr->pieces[1][3];
    temp.pieces[4][6] = ptr->pieces[1][0];

    // down face to right face
    temp.pieces[2][2] = ptr->pieces[4][8];
    temp.pieces[2][5] = ptr->pieces[4][7];
    temp.pieces[2][8] = ptr->pieces[4][6];

    applyChanges(ptr, &temp);
    // roate entire back face
    rotateFace(ptr, 5);
}

void moveD(struct Cube *ptr) {
    struct Cube temp = *ptr;
    // left face to front face
    temp.pieces[0][6] = ptr->pieces[1][6];
    temp.pieces[0][7] = ptr->pieces[1][7];
    temp.pieces[0][8] = ptr->pieces[1][8];

    // front face to right face
    temp.pieces[2][6] = ptr->pieces[0][6];
    temp.pieces[2][7] = ptr->pieces[0][7];
    temp.pieces[2][8] = ptr->pieces[0][8];

    // right face to back face
    temp.pieces[5][2] = ptr->pieces[2][6];
    temp.pieces[5][1] = ptr->pieces[2][7];
    temp.pieces[5][0] = ptr->pieces[2][8];

    // back face to left face
    temp.pieces[1][6] = ptr->pieces[5][2];
    temp.pieces[1][7] = ptr->pieces[5][1];
    temp.pieces[1][8] = ptr->pieces[5][0];

    applyChanges(ptr, &temp);
    // roate entire down face
    rotateFace(ptr, 4);
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
