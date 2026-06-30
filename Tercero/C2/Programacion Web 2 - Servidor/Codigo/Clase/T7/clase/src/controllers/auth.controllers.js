// src/controllers/auth.controller.js
import User from '../models/user.model.js';
import RefreshToken from '../models/refreshToken.model.js';
import { encrypt, compare } from '../utils/handlePassword.js';
import {
  generateAccessToken,
  generateRefreshToken,
  getRefreshTokenExpiry
} from '../utils/handleJwt.js';

/**
 * Login - genera ambos tokens
 */
export const loginCtrl = async (req, res) => {
  const { email, password } = req.body;

  const user = await User.findOne({ email }).select('+password');

  if (!user || !(await compare(password, user.password))) {
    return res.status(401).json({ error: true, message: 'Credenciales inválidas' });
  }

  // Generar tokens
  const accessToken = generateAccessToken(user);
  const refreshToken = generateRefreshToken();

  // Guardar refresh token en BD
  await RefreshToken.create({
    token: refreshToken,
    user: user._id,
    expiresAt: getRefreshTokenExpiry(),
    createdByIp: req.ip
  });

  // Ocultar password
  user.password = undefined;

  res.json({
    accessToken,
    refreshToken,
    user
  });
};

/**
 * Refresh - obtener nuevo access token
 */
export const refreshCtrl = async (req, res) => {
  const { refreshToken } = req.body;

  if (!refreshToken) {
    return res.status(400).json({ error: true, message: 'Refresh token requerido' });
  }

  // Buscar token en BD
  const storedToken = await RefreshToken.findOne({ token: refreshToken }).populate('user');

  if (!storedToken || !storedToken.isActive()) {
    return res.status(401).json({ error: true, message: 'Refresh token inválido o expirado' });
  }

  // Generar nuevo access token
  const accessToken = generateAccessToken(storedToken.user);

  res.json({ accessToken });
};

/**
 * Logout - revocar refresh token
 */
export const logoutCtrl = async (req, res) => {
  const { refreshToken } = req.body;

  if (refreshToken) {
    await RefreshToken.findOneAndUpdate(
      { token: refreshToken },
      { revokedAt: new Date(), revokedByIp: req.ip }
    );
  }

  res.json({ message: 'Sesión cerrada' });
};

/**
 * Revocar todos los tokens de un usuario (logout global)
 */
export const revokeAllTokensCtrl = async (req, res) => {
  await RefreshToken.updateMany(
    { user: req.user._id, revokedAt: null },
    { revokedAt: new Date(), revokedByIp: req.ip }
  );

  res.json({ message: 'Todas las sesiones cerradas' });
};