

class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<String> set = new HashSet<>();
        for (int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[row].length; col++) {
                if (board[row][col] != '.') {
                    if (!set.add("row"+row+board[row][col]) || !set.add("col"+col+board[row][col])) {
                        return false;
                    }
                    if (!set.add("square:row"+row/3+"col"+col/3+board[row][col])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
