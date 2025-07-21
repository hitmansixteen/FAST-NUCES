const zigzagTraversal = (matrix) =>
    matrix.reduce(
        (res, row, i) => res.concat(i % 2 == 0 ? row : row.reverse()),
        []
    );

const matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
];
const output = zigzagTraversal(matrix);
console.log(output);
