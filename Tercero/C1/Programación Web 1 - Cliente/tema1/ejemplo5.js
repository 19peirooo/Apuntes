let result = "Primer resultado";
function primeraPromesa (cadena) {
  
  const promesa = new Promise((resolve, reject) => {
    segundaPromesa(`primera ${cadena}`).then(result => resolve(result));

  })
  return promesa;
};
function segundaPromesa (cadena) {
  const promesa = new Promise((resolve, reject) => {
    resolve(`segunda ${cadena}`);
  })
  return promesa;
};

const llamada = primeraPromesa("empezamos");

llamada.then(result => console.log(result));
console.log("Ultima linea del programa: ${result}");