import mongoose from "mongoose";
import { softDeletePlugin } from "../plugins/softDelete.plugin.js";

const noteSchema = mongoose.Schema (
    {
        title: {
            type: String,
            required: [true, "Un nota necesita titulo"],
            trim: true,
            minLength: [3, 'Mínimo 3 caracteres']
        },
        content: {
            type: String,
            required: [true, "Un nota necesita contenido"],
            trim: true
        },
        color: {
            type: String,
            enum: ["red","blue","green"],
            default: "red"
        },
        pinned: {
            type: Boolean,
            default: false
        },
        author: {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'User',
            required: true
        }
    }
)

noteSchema.plugin(softDeletePlugin);

export const Note = mongoose.model('Note', noteSchema);