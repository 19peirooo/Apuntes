import mongoose from "mongoose";

const movieSchema = mongoose.Schema(
    {
        name: {
            type: String,
            required: [true, 'Es necesario nombre pelicula']
        },
        rented: {
            type: Boolean,
            required: [true, 'Es necesario saber si esta alquilada'],
            default: false
        },
        num_rents: {
            type: Number,
            default: 0
        },
        genre: {
            type: String,
            enum: {
                values: ['comedy', 'fiction', 'scary']
            }
        }
    }
)

const Movie = mongoose.model('movie', movieSchema)

export default Movie;