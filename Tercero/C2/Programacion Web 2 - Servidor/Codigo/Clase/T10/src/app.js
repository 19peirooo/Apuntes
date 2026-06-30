// src/app.js
import express from 'express';
import { createServer } from 'node:http';
import { Server } from 'socket.io';
import path from 'node:path';

const app = express();
const httpServer = createServer(app);
const io = new Server(httpServer, {
  cors: {
    origin: process.env.CORS_ORIGIN || '*'
  }
});

// Middleware
app.use(express.json());
app.use(express.static('public'));

// Rutas REST
app.get('/api/status', (req, res) => {
  res.json({
    status: 'ok',
    connections: io.engine.clientsCount
  });
});

// Socket.IO
io.on('connection', (socket) => {
  console.log(`[WS] Conectado: ${socket.id}`);

  socket.on('message', (data) => {
    // Broadcast a todos
    io.emit('message', {
      id: socket.id,
      ...data,
      timestamp: new Date()
    });
  });

  socket.on('disconnect', () => {
    console.log(`[WS] Desconectado: ${socket.id}`);
  });
});

// Hacer io accesible en las rutas
app.set('io', io);

// Ejemplo: emitir desde una ruta REST
app.post('/api/notify', (req, res) => {
  const { message } = req.body;
  const io = req.app.get('io');

  io.emit('notification', { message, timestamp: new Date() });

  res.json({ success: true, message: 'Notificación enviada' });
});

const PORT = process.env.PORT || 3000;
httpServer.listen(PORT, () => {
  console.log(`Servidor en http://localhost:${PORT}`);
});

export { app, io };