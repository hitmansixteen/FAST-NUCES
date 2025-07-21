const flattenArray = (arr) =>
    arr.reduce(
        (res, val) => res.concat(Array.isArray(val) ? flattenArray(val) : val),
        []
    );

const nestedArray = [[1, [2, [3]]], 4, [5, [6, [7]]]];
const flatArray = flattenArray(nestedArray);
console.log(flatArray);
