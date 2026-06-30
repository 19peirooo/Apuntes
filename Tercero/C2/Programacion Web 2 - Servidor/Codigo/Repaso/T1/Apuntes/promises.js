import { readFile, writeFile } from 'node:fs/promises';

try {
  const data1 = await readFile('archivo1.txt', 'utf-8');
  const data2 = await readFile('archivo2.txt', 'utf-8');
  await writeFile('resultado.txt', data1 + data2);
  console.log('Completado');
} catch (error) {
  console.error('Error:', error.message);
}

// Secuencial (lento): espera cada archivo
const data1 = await readFile('archivo1.txt', 'utf-8');
const data2 = await readFile('archivo2.txt', 'utf-8');

// Paralelo (rápido): lee todos a la vez
const [file1, file2, file3] = await Promise.all([
  readFile('archivo1.txt', 'utf-8'),
  readFile('archivo2.txt', 'utf-8'),
  readFile('archivo3.txt', 'utf-8')
]);