// src/docs/swagger.js
import swaggerJsdoc from 'swagger-jsdoc';

const options = {
  definition: {
    openapi: '3.0.3',
    info: {
      title: 'API de Tracks - Express con Swagger',
      version: '1.0.0',
      description: 'API REST documentada con Swagger',
      license: {
        name: 'MIT',
        url: 'https://spdx.org/licenses/MIT.html'
      },
      contact: {
        name: 'Tu Nombre',
        email: 'tu@email.com'
      }
    },
    servers: [
      {
        url: 'http://localhost:3000',
        description: 'Servidor de desarrollo'
      }
    ],
    // components: {
    //   securitySchemes: {
    //     bearerAuth: {
    //       type: 'http',
    //       scheme: 'bearer',
    //       bearerFormat: 'JWT'
    //     }
    //   },
    //   schemas: {
    //     User: {
    //       type: 'object',
    //       required: ['name', 'email', 'password'],
    //       properties: {
    //         name: { type: 'string', example: 'Juan Pérez' },
    //         email: { type: 'string', format: 'email', example: 'juan@ejemplo.com' },
    //         password: { type: 'string', format: 'password', example: 'MiPassword123' },
    //         age: { type: 'integer', example: 25 },
    //         role: { type: 'string', enum: ['user', 'admin'], default: 'user' }
    //       }
    //     },
    //     Track: {
    //       type: 'object',
    //       required: ['title', 'artist', 'duration'],
    //       properties: {
    //         title: { type: 'string', example: 'Mi Canción' },
    //         artist: { type: 'string', example: '65f8b3a2c9d1e20012345678' },
    //         duration: { type: 'integer', example: 180 },
    //         genres: { 
    //           type: 'array', 
    //           items: { type: 'string' },
    //           example: ['rock', 'pop']
    //         }
    //       }
    //     },
    //     Login: {
    //       type: 'object',
    //       required: ['email', 'password'],
    //       properties: {
    //         email: { type: 'string', format: 'email' },
    //         password: { type: 'string', format: 'password' }
    //       }
    //     },
    //     Error: {
    //       type: 'object',
    //       properties: {
    //         error: { type: 'boolean', example: true },
    //         message: { type: 'string', example: 'Error message' }
    //       }
    //     }
    //   }
    // }
  },
  apis: ['./src/routes/*.js']
};

export default swaggerJsdoc(options);