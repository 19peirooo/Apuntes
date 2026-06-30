const nuevoIntento = () => {
  return new Promise ((resolve, reject)=> {
    const number = Math.random(); 
    if (number < 0.8) {
      resolve (number)
    } else {
      resolve ("No ha habido suerte");
    }
  });
}

const miPromesa = nuevoIntento();

miPromesa.then(result => console.log(result));
miPromesa.then(result => console.log(result));
miPromesa.then(result => console.log(result));
miPromesa.then(result => console.log(result));
miPromesa.then(result => console.log(result));

const miPromesa2 = nuevoIntento();
miPromesa2.then(result => console.log(result));
miPromesa2.then(result => console.log(result));
miPromesa2.then(result => console.log(result));
miPromesa2.then(result => console.log(result));
miPromesa2.then(result => console.log(result));
