const processArray = (arr) =>
    arr
        .reverse()
        .map((num) => (num % 2 === 0 ? num / 2 : num * 3 + 1))
        .filter((num) => num <= 100)
        .reduce((sum, num) => sum + num, 0);

const inputArray = [5, 12, 7, 9, 4, 6];
const res = processArray(inputArray);
console.log(res);
