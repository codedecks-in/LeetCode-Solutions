/* 

Problem Link : https://leetcode.com/problems/flipping-an-image/

Difficulty Level: Hard
Run time: 1ms
Memory: 41.7 MB

Time Complexity - O(n^n)
Space Complexity - O(1)


Example : 

Input: image = [[1,1,0],[1,0,1],[0,0,0]]

Output: [[1,0,0],[0,1,0],[1,1,1]]

Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

*/

public class 832_Flipping_an_image 
{
    public static void main(String[] args) {

        int [][] image = {{1,1,0},
                {1,0,1},{0,0,0}};

        int[][] ans =flipAndInvertImage(image);

        for (int i = 0; i < ans.length; i++) {
            for (int a = 0; a < ans[i].length; a++) {
                System.out.print(ans[i][a] + " ");
            }
            System.out.println();
        }
    }

    public static int[][] flipAndInvertImage(int[][] image) {

        for(int[] row : image) {
            // reverse this array
            for (int i = 0; i < (image[0].length + 1) / 2; i++) {
                // swap the elements
                int temp = row[i] ^ 1;
                row[i] = row[image[0].length - i - 1] ^ 1;
                row[image[0].length - i - 1] = temp;
            }

            /* we know 0^ 1 = 1 and 1 ^ 1 = 0, since we needed to change 0 to 1 and vice
             * versa, here we used the bitwise operator to do that  */

        }
        return image;

    }
    
}
