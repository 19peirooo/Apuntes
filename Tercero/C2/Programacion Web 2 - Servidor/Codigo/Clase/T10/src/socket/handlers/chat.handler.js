// src/socket/handlers/chat.handler.js
export function chatHandler(io, socket) {
  // Unirse a sala
  socket.on('chat:join', (room) => {
    socket.join(room);
    socket.to(room).emit('chat:user-joined', {
      userId: socket.id,
      user: socket.user
    });
  });

  // Enviar mensaje
  socket.on('chat:message', ({ room, message }) => {
    io.to(room).emit('chat:message', {
      userId: socket.id,
      user: socket.user,
      message,
      timestamp: new Date()
    });
  });

  // Salir de sala
  socket.on('chat:leave', (room) => {
    socket.leave(room);
    socket.to(room).emit('chat:user-left', {
      userId: socket.id
    });
  });

  // Escribiendo...
  socket.on('chat:typing', (room) => {
    socket.to(room).emit('chat:typing', {
      user: socket.user
    });
  });
}