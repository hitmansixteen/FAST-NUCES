const reverse = (arr, start, end) => {
    while (start < end) [arr[start++], arr[end--]] = [arr[end], arr[start]];
};

const rotateArray = (arr, num) => (
    reverse(arr, 0, arr.length - 1),
    reverse(arr, 0, (num % arr.length) - 1),
    reverse(arr, num % arr.length, arr.length - 1),
    arr
);

// Example usage
const arr = [1, 2, 3, 4, 5, 6, 7];
rotateArray(arr, 3);
console.log(arr);
