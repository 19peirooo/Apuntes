
function devolverPromesa() {
    return new Promise(resolve => setTimeout(() => resolve([1,2,3]),3000))
}

// const res = await devolverPromesa();
// console.log("Resultado de devolverPromesa",res)

async function usaPromesa() {
    const res2 = await devolverPromesa();
    return res2;
}

const result2 = await usaPromesa()
console.log("Resultado de devolverPromesa",result2)