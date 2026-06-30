import mongoose from "mongoose";

const authorSchema = mongoose.Schema(
    {
        name: {
            type: String,
            required: [true, 'Es necesario el nombre'],
            trim: true
        },
        nationality: {
            type: String
        },
        birthDate: {
            type: Date
        },
        bio: {
            type: String
        }
    }
)

authorSchema.index({name: "text"})

const Author = mongoose.model('Author',authorSchema)

export default Author