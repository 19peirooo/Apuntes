// src/models/user.model.js
import mongoose from 'mongoose';

const userSchema = new mongoose.Schema(
  {
    name: {
      type: String,
      required: [true, 'El nombre es requerido'],
      trim: true,
      minlength: [3, 'Mínimo 3 caracteres'],
      maxlength: [99, 'Máximo 99 caracteres']
    },
    email: {
      type: String,
      required: [true, 'El email es requerido'],
      unique: true,
      lowercase: true,
      trim: true
    },
    password: {
      type: String,
      required: [true, 'La contraseña es requerida'],
      minlength: [8, 'Mínimo 8 caracteres'],
      select: false  // No incluir en consultas por defecto
    },
    age: {
      type: Number,
      min: [0, 'Edad no puede ser negativa']
    },
    role: {
      type: String,
      enum: ['user', 'admin'],
      default: 'user'
    }
  },
  {
    timestamps: true,
    versionKey: false
  }
);

const User = mongoose.model('User', userSchema);
export default User;