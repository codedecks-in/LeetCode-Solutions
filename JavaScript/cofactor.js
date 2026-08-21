function minorAndSign(matrix, row, column) {
    const detNums = [];
    let detNumIdx = 0;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if ((i != row) && (j != column)) {
                detNums[detNumIdx] = matrix[i][j];
                detNumIdx += 1;
            }
        }
    }

    if ((row+column) % 2 != 0) {
        return (detNums[1]*detNums[2] - detNums[0]*detNums[3])
    }
    return (detNums[0]*detNums[3] - detNums[1]*detNums[2])
}


function printMatrix(matrix) {
    for (let row = 0; row < 3; row++) {
        console.log(matrix[row]);
    }
}


const matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]]


const coFacMatrix = [[], [], []]

for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
        let minor = minorAndSign(matrix, i, j);
        coFacMatrix[i][j] = minor;
    }
}
printMatrix(coFacMatrix);
