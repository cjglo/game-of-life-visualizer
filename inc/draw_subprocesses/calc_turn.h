#ifndef __CALC_TURN_H__
#define __CALC_TURN_H__

#include "../const.h"
// this is the algorithm for the Game of Life, its rules are documented online
/* 
 * NOTE: Using modulos here because it is constant space, so matrix is written to during calculations
 * meaning I must preserve old state as I write, so 2 is cell being born and 3 is one dying.
 * This allows me to see old data (ex/ 2 must have been a 0 the turn before) but still record new state 
*/
int check_if_neighbors_alive(int i, int j, struct matrix* m, int rows, int columns);

void calculate_life_turn(struct matrix* m, int rows, int columns) {

	for(int i = 0; i<rows; i++) {

		for(int j = 0; j<columns; j++) {

			int alive_cells = check_if_neighbors_alive(i, j, m, rows, columns);
			
			// if cell was alive last turn
			if(m->data[i][j] == 1) {	
				
				if(alive_cells < 2 || alive_cells > 3) {
					m->data[i][j] = 3; // mod 2 is 1 so algo will know was alive 
				} else {
					m->data[i][j] = 1;
				}
			}
			// cell was dead last turn
			else {
				
				if(alive_cells == 3) {
					m->data[i][j] = 2; // mod is 0 so algo will knw was dead
				} else {
					m->data[i][j] = 0;
				}
			}	

		}
	}


	

	// now that process done, convert all 2 and 3 to correct value (0 or 1)	
	for(int i = 0; i<rows; i++) {
	
		for(int j = 0; j<columns; j++) {
			
			// now we care what it will become, 2 was a birth & 3 was a death
			if(m->data[i][j] == 2) {
				m->data[i][j] = 1;
			} else if(m->data[i][j] == 3) {
				m->data[i][j] = 0;
			}

		}
	}


}


int check_if_neighbors_alive(int i, int j, struct matrix* m, int rows, int columns) {

	int counter = 0;
	// booleans used to make code cleaner
	int is_not_top_row = i > 0;
	int is_not_bottom_row = i < rows - 1;
	int is_not_first_col = j > 0;
	int is_not_last_col = j < columns - 1;

	// there is a less verbose way, but I thought this is the cleanest to read
	if(is_not_top_row) {
		// cell right above
		counter += (m->data[i-1][j] % 2);	
	} 
	if(is_not_top_row && is_not_last_col ) {
		// cell top right
		counter += (m->data[i-1][j+1] % 2);
	}
	if(is_not_last_col) {
		// cell to the right
		counter += (m->data[i][j+1] % 2);
	}
	if(is_not_bottom_row && is_not_last_col) {
		// cell bottom right
		counter += (m->data[i+1][j+1] % 2);
	}	
	if(is_not_bottom_row) {
		// cell directly below
		counter += (m->data[i+1][j] % 2);
	}
	if(is_not_bottom_row && is_not_first_col) {
		// cell bottom left
		counter += (m->data[i+1][j-1] % 2);
	}
	if(is_not_first_col) {
		// cell directly left
		counter += (m->data[i][j-1] % 2);
	}
	if(is_not_top_row && is_not_first_col) {
		// cell top left
		counter += (m->data[i -1][j-1] % 2);
	}
	

	return counter;
}



#endif