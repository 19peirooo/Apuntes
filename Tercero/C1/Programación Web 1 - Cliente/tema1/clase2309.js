function sinParams() {
    console.log("Funciona");
}

function conParams(key) {
    console.log(`Hello ${key}`);
}

function numero1(callback, key) {
    setTimeout(callback(key), 3000);
}

numero1(conParams,"Victor");