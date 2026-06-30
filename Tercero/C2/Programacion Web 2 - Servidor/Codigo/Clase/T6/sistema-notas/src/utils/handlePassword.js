// src/utils/handlePassword.js
import bcryptjs from 'bcryptjs';

/**
 * Encripta una contraseña
 * @param {string} clearPassword - Contraseña en texto plano
 * @returns {Promise<string>} - Hash de la contraseña
 */
export const encrypt = async (clearPassword) => {
  // El número "salt" (10) añade aleatoriedad al hash
  // Más alto = más seguro pero más lento
  const hash = await bcryptjs.hash(clearPassword, 10);
  return hash;
};

/**
 * Compara contraseña con su hash
 * @param {string} clearPassword - Contraseña en texto plano
 * @param {string} hashedPassword - Hash almacenado en BD
 * @returns {Promise<boolean>} - true si coinciden
 */
export const compare = async (clearPassword, hashedPassword) => {
  const result = await bcryptjs.compare(clearPassword, hashedPassword);
  return result;
};