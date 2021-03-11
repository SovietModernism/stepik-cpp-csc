#include <iostream>
using namespace std;

void swap_min(int *m[], unsigned rows, unsigned cols)
{
	if( rows == 0 && cols == 0) return;
    int min = m[0][0];
	int minrow = 0;
	for(unsigned i = 0; i < rows; i++) {
		for(unsigned j = 0; j < cols; j++) {
			if(min > m[i][j]) {
				min = m[i][j];
				minrow = i;
			}
		}
	}
	for(unsigned j = 0; j < cols; j++) {
		int t = m[0][j];
		m[0][j] = m[minrow][j];
		m[minrow][j] = t;
	}
}