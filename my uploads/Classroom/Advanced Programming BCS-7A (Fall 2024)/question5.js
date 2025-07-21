const processArray = (array, ...additionalArgs) => {
    const [firstHalf, secondHalf] = array.reduce(
        (acc, num, i) => {
            (i < Math.ceil(array.length / 2) ? acc[0] : acc[1]).push(num);
            return acc;
        },
        [[], []]
    );

    const combinedSum = firstHalf
        .concat(additionalArgs)
        .reduce((sum, num) => sum + num, 0);
    const secondHalfSum = secondHalf.reduce((sum, num) => sum + num, 0);

    return combinedSum * secondHalfSum;
};

const arr = [1, 2, 3, 4, 5, 6];
const output = processArray(arr, 10, 20, 30);
console.log(output);
