
function randomPromise () {
  const miPromesa = new Promise ((resolve,reject) => {
    setTimeout(() => resolve("Hola")
    ,3000);
  });
  
  return miPromesa;
}


const promesaDevuelta = randomPromise();
promesaDevuelta.then(result => console.log("La Promesa ha terminado")).catch(err => console.log("Error: ", err))
console.log(promesaDevuelta);
console.log("Ha terminado el programa");