// src/socket/index.js
import { Server } from 'socket.io';
import { chatHandler } from './handlers/chat.handler.js';
import { notificationHandler } from './handlers/notification.handler.js';
import { authMiddleware } from './middleware/auth.middleware.js';

export function setupSocket(httpServer) {
  const io = new Server(httpServer, {
    cors: { origin: '*' }
  });

  // Middleware de autenticación
  io.use(authMiddleware);

  // Namespace principal
  io.on('connection', (socket) => {
    console.log('Conectado:', socket.id, socket.user?.name);

    // Registrar handlers
    chatHandler(io, socket);
    notificationHandler(io, socket);

    socket.on('disconnect', () => {
      console.log('Desconectado:', socket.id);
    });
  });

  return io;
}