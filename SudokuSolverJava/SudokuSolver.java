import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.concurrent.ExecutionException;

public class SudokuSolver extends JFrame {
    private JTextField[][] cells = new JTextField[9][9];
    private JButton solveButton;
    private JButton clearButton;
    private JLabel messageLabel;

    private int[][] startingBoard = {
            { 6, 9, 1, 0, 0, 0, 0, 0, 5 },
            { 0, 0, 0, 3, 0, 0, 0, 8, 1 },
            { 2, 3, 8, 1, 0, 0, 4, 6, 0 },
            { 7, 0, 2, 0, 0, 0, 0, 9, 4 },
            { 4, 8, 9, 0, 2, 7, 0, 1, 0 },
            { 3, 0, 0, 5, 0, 4, 8, 7, 2 },
            { 8, 7, 3, 4, 5, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 1, 6, 0, 0, 0, 0, 3, 4, 0 }
    };

    public SudokuSolver() {
        setTitle("Sudoku Solver");
        setSize(700, 700);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel gridPanel = new JPanel();
        gridPanel.setLayout(new GridLayout(9, 9));
        Font font = new Font("Arial", Font.BOLD, 30);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cells[i][j] = new JTextField();
                cells[i][j].setFont(font);
                cells[i][j].setHorizontalAlignment(JTextField.CENTER);
                if (startingBoard[i][j] != 0) {
                    cells[i][j].setText(Integer.toString(startingBoard[i][j]));
                    cells[i][j].setEditable(true);
                    cells[i][j].setForeground(Color.BLACK);
                }
                gridPanel.add(cells[i][j]);
            }
        }

        solveButton = new JButton("Solve");
        clearButton = new JButton("Clear");
        messageLabel = new JLabel(" ");

        solveButton.addActionListener(new SolveButtonListener());
        clearButton.addActionListener(new ClearButtonListener());

        JPanel controlPanel = new JPanel();
        controlPanel.setLayout(new FlowLayout());
        controlPanel.add(solveButton);
        controlPanel.add(clearButton);
        controlPanel.add(messageLabel);

        add(gridPanel, BorderLayout.CENTER);
        add(controlPanel, BorderLayout.SOUTH);
    }

    private class SolveButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            messageLabel.setText("Checking input...");
            solveButton.setEnabled(false);
            clearButton.setEnabled(false);

            SwingWorker<Boolean, Void> worker = new SwingWorker<>() {
                @Override
                protected Boolean doInBackground() {
                    int[][] board = new int[9][9];
                    try {
                        for (int i = 0; i < 9; i++) {
                            for (int j = 0; j < 9; j++) {
                                String text = cells[i][j].getText();
                                if (!text.isEmpty()) {
                                    int value = Integer.parseInt(text);
                                    if (value < 1 || value > 9) {
                                        throw new NumberFormatException();
                                    }
                                    board[i][j] = value;
                                } else {
                                    board[i][j] = 0;
                                }
                            }
                        }

                        if (!isValidSudoku(board)) {
                            return false;
                        }

                        return solveSudoku(board);
                    } catch (NumberFormatException ex) {
                        return false;
                    }
                }

                @Override
                protected void done() {
                    try {
                        Boolean result = get();
                        if (result) {
                            messageLabel.setText("Solved!");
                        } else {
                            messageLabel.setText("Invalid input or no solution exists.");
                        }
                    } catch (InterruptedException | ExecutionException ex) {
                        ex.printStackTrace();
                        messageLabel.setText("An error occurred.");
                    } finally {
                        solveButton.setEnabled(true);
                        clearButton.setEnabled(true);
                    }
                }
            };

            worker.execute();
        }
    }

    private class ClearButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cells[i][j].setText("");
                    cells[i][j].setForeground(Color.BLACK);
                }
            }
            messageLabel.setText(" ");
        }
    }

    private boolean solveSudoku(int[][] board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == 0) {
                    for (int num = 1; num <= 9; num++) {
                        if (isSafe(board, row, col, num)) {
                            board[row][col] = num;
                            updateBoard(board);
                            try {
                                Thread.sleep(50);
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                            if (solveSudoku(board)) {
                                return true;
                            }
                            board[row][col] = 0;
                            updateBoard(board);
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    private void updateBoard(int[][] board) {        
        Color textColor = new Color(70, 230, 20);
        SwingUtilities.invokeLater(() -> {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cells[i][j].setText(board[i][j] == 0 ? "" : Integer.toString(board[i][j]));
                    if (!cells[i][j].getForeground().equals(Color.BLACK)) {
                        cells[i][j].setForeground(textColor);
                    }
                }
            }
        });
    }

    private boolean isSafe(int[][] board, int row, int col, int num) {
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == num || board[x][col] == num ||
                    board[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
                return false;
            }
        }
        return true;
    }

    private boolean isValidSudoku(int[][] board) {
        for (int i = 0; i < 9; i++) {
            boolean[] rowCheck = new boolean[10];
            boolean[] colCheck = new boolean[10];
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != 0) {
                    if (rowCheck[board[i][j]]) {
                        return false;
                    }
                    rowCheck[board[i][j]] = true;
                }
                if (board[j][i] != 0) {
                    if (colCheck[board[j][i]]) {
                        return false;
                    }
                    colCheck[board[j][i]] = true;
                }
            }
        }
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                boolean[] subGridCheck = new boolean[10];
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        if (board[i][j] != 0) {
                            if (subGridCheck[board[i][j]]) {
                                return false;
                            }
                            subGridCheck[board[i][j]] = true;
                        }
                    }
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            SudokuSolver solver = new SudokuSolver();
            solver.setVisible(true);
        });
    }
}
