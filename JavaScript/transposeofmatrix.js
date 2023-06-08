function transposeOfMatrix(arr) {
    console.log("before arr", arr);
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < i; j++) {
            let tmp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = tmp;
        }
    }

    console.log("after arr", arr);
}

transposeOfMatrix([[1, 2, 3], [4, 5, 6], [7, 8, 9]]);
