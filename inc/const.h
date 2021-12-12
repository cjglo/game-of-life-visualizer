#ifndef __CONST_H__
#define __CONST_H__

// window of application
#define WINDOW_HEIGHT 1700
#define WINDOW_LENGTH 1000

// matrix is the array or arrays that holds the life game-state:
#define MATRIX_HEIGHT 100
#define MATRIX_LENGTH 180

// matrix struct consiting of matrix and game flag
struct matrix  {
    int** data;
    int game_has_started;
};


#endif