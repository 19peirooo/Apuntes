function promesaAnidada (num){
  const anidada = new Promise ((resolve,reject) => {
    if (Math.random() < 0.2) {
      resolve(num);
    } else {
      reject("Rechazada al final");
    }
  })

  return anidada;
}

function randomPromise() {
  const miPromesa = new Promise((resolve, reject) => {
    setTimeout(() => {
      const exito = true;
      if (exito) {
        promesaAnidada(78).then (result => resolve(result), error => reject (error));
      }
      else {
        reject("No ha habido suerte");
      }
    }, 3000);
  });


  return miPromesa;
}



const miFunctionok = (result) => console.log(`Todo ha ido bien: ${result}`)
const promesaDevuelta = randomPromise();
console.log(promesaDevuelta);

const mensaje = promesaDevuelta.then(result => console.log(`Todo ha ido bien: ${result}`)).catch(err => console.log(`Error: ${err}`));
console.log("Ultimo mensaje por consola");
