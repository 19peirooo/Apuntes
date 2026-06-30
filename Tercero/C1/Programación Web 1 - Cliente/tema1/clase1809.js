const students = [
    {name: 'Marc', group: 'INSOA'},
    {name: 'Rachel', group: 'INSG'},
    {name: 'John', group: 'INSG'},
    {name: 'Mary', group: 'INSOB'}
]

const studentsINSO = students.filter(x => x.group == 'INSG')

console.log(studentsINSO)

students.forEach(x => console.log(x.name))

const arrObj = [
    {name: 'Carlos', age: 34},
    {name: 'Javi', age: 22}
]

const arrCpy = [...arrObj]
arrObj[0] = {name: 'Juan', age: 33}

console.log(arrObj)
console.log(arrCpy)