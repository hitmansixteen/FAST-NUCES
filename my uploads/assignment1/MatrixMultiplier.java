import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class MatrixMultiplier {
    public static void main(String[] args) {
        try {
            if (args.length != 2) {
                System.out.println("Usage: java MatrixMultiplier <input file> <output file>");
                return;
            }
            String inputFile = args[0];
            String outputFile = args[1];

            long startTime;
            double readTime, computeTime, writeTime;

            startTime = System.nanoTime();

            File file = new File(inputFile);
            Scanner scanner = new Scanner(file);

            int opcode = scanner.nextInt();
            System.out.println("Opcode: " + opcode);
            int dataType = scanner.nextInt();
            System.out.println("Data type: " + dataType);
            scanner.nextLine();
            String[] dimensionsA = scanner.nextLine().split(" ");
            int rowsA = Integer.parseInt(dimensionsA[0]);
            int colsA = Integer.parseInt(dimensionsA[1]);
            System.out.println("Matrix A: " + rowsA + "x" + colsA);

            Number[][] matrixA = new Number[rowsA][colsA];

            for (int i = 0; i < rowsA; i++) {
                String[] rowValues = scanner.nextLine().split(" ");
                for (int j = 0; j < colsA; j++) {
                    switch (dataType) {
                        case 1: // 32 bit integers
                            matrixA[i][j] = Integer.parseInt(rowValues[j]);
                            break;
                        case 2: // 32 bit floats
                            matrixA[i][j] = Float.parseFloat(rowValues[j]);
                            break;
                        case 3: // 64 bit integers
                            matrixA[i][j] = Long.parseLong(rowValues[j]);
                            break;
                        case 4: // 64 bit doubles
                            matrixA[i][j] = Double.parseDouble(rowValues[j]);
                            break;
                        default:
                            // Handle invalid data type
                            break;
                    }
                }
            }

            String[] dimensionsB = scanner.nextLine().split(" ");
            int rowsB = Integer.parseInt(dimensionsB[0]);
            int colsB = Integer.parseInt(dimensionsB[1]);
            System.out.println("Matrix B: " + rowsB + "x" + colsB);

            Number[][] matrixB = new Number[rowsB][colsB];
            for (int i = 0; i < rowsB; i++) {
                String[] rowValues = scanner.nextLine().split(" ");
                for (int j = 0; j < colsB; j++) {
                    switch (dataType) {
                        case 1: // 32 bit integers
                            matrixB[i][j] = Integer.parseInt(rowValues[j]);
                            break;
                        case 2: // 32 bit floats
                            matrixB[i][j] = Float.parseFloat(rowValues[j]);
                            break;
                        case 3: // 64 bit integers
                            matrixB[i][j] = Long.parseLong(rowValues[j]);
                            break;
                        case 4: // 64 bit doubles
                            matrixB[i][j] = Double.parseDouble(rowValues[j]);
                            break;
                        default:
                            // Handle invalid data type
                            break;
                    }
                }
            }

            readTime = (double) (System.nanoTime() - startTime) / 1_000_000_000.0;

            System.err.println("Read time: " + readTime + "s");

            scanner.close();

            startTime = System.nanoTime();

            Number[][] result = new Number[rowsA][colsB];

            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsB; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < colsA; k++) {
                        result[i][j] = result[i][j].doubleValue()
                                + matrixA[i][k].doubleValue() * matrixB[k][j].doubleValue();
                    }
                }
                System.out.println(i);
            }

            computeTime = (double) (System.nanoTime() - startTime) / 1_000_000_000.0;
            System.out.println("Compute time: " + computeTime + "s");

            startTime = System.nanoTime();

            try (PrintWriter writer = new PrintWriter(new FileWriter(outputFile))) {

                writer.println(dataType);

                writer.println(result.length + " " + result[0].length);

                for (Number[] row : result) {
                    for (Number value : row) {
                        writer.print(value + " ");
                    }
                    writer.println();
                }

            } catch (IOException e) {
                e.printStackTrace();
            }

            writeTime = (double) (System.nanoTime() - startTime) / 1_000_000_000.0;
            System.out.println("Write time: " + writeTime + "s");

            try (PrintWriter writer = new PrintWriter(new FileWriter("graph.txt", true))) {
                writer.printf("%d %d %.6f %.6f %.6f%n", opcode, dataType, readTime, computeTime, writeTime);
            } catch (IOException e) {
                e.printStackTrace();
            }

        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        }

    }
}