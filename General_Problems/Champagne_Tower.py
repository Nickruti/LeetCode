'''
We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row. 
Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top. 
When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it. 
When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on. 
(A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now. 
After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full.
'''

'''
Approach #1: Simulation
Intuition

Instead of keeping track of how much champagne should end up in a glass, keep track of the total amount of champagne that flows through a glass. 
For example, if poured = 10 cups are poured at the top, then the total flow-through of the top glass is 10; 
the total flow-through of each glass in the second row is 4.5, and so on.

Algorithm

In general, if a glass has flow-through X, 
then Q = (X - 1.0) / 2.0 quantity of champagne will equally flow left and right. 
We can simulate the entire pour for 100 rows of glasses.
A glass at (r, c) will have excess champagne flow towards (r+1, c) and (r+1, c+1).
'''


class Solution(object):
    def champagneTower(self, poured, query_row, query_glass):
        A = [[0] * k for k in range(1, 102)]
        A[0][0] = poured
        for r in range(query_row + 1):
            for c in range(r+1):
                q = (A[r][c] - 1.0) / 2.0
                if q > 0:
                    A[r+1][c] += q
                    A[r+1][c+1] += q

        return min(1, A[query_row][query_glass])
        
'''
Input - 
1
1
1

Output - 
0.00000
'''
