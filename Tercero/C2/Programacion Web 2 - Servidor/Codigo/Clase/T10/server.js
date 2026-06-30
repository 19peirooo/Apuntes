// server.js
import { createServer } from 'node:http';
import { Server } from 'socket.io';

const httpServer = createServer();
const io = new Server(httpServer, {
  cors: {
    origin: '*',  // En producción, especificar dominios
    methods: ['GET', 'POST']
  }
});

io.on('connection', (socket) => {
  console.log('Usuario conectado:', socket.id);

  // Escuchar evento personalizado
  socket.on('chat:message', (data) => {
    console.log('Mensaje:', data);

    // Emitir a todos excepto al emisor
    socket.broadcast.emit('chat:message', data);
  });

  // Escuchar evento con acknowledgment
  socket.on('chat:private', (data, callback) => {
    console.log('Mensaje privado:', data);
    // Confirmar recepción
    callback({ status: 'ok', timestamp: Date.now() });
  });

  // Desconexión
  socket.on('disconnect', (reason) => {
    console.log('Usuario desconectado:', socket.id, reason);
  });
});

httpServer.listen(3000, () => {
  console.log('Servidor en http://localhost:3000');
});