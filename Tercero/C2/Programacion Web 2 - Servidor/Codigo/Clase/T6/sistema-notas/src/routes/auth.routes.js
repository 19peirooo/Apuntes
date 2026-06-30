// src/routes/auth.routes.js
import { Router } from 'express';
import authMiddleware from '../middleware/session.middleware.js';
import {
  loginCtrl,
  registerCtrl,
  refreshCtrl,
  logoutCtrl,
  revokeAllTokensCtrl
} from '../controllers/auth.controllers.js';

const router = Router();

router.post('/register', registerCtrl);
router.post('/login', loginCtrl);
router.post('/refresh', refreshCtrl);           // Obtener nuevo access token
router.post('/logout', logoutCtrl);             // Revocar refresh token
router.post('/logout-all', authMiddleware, revokeAllTokensCtrl); // Cerrar todas las sesiones

export default router;