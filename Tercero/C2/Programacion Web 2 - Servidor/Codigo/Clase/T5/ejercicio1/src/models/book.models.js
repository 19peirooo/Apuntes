import mongoose from "mongoose";
import Author from "./author.models";


const bookSchema = mongoose.Schema(
    {
        title:{
            type: String,
            required: [true, 'Un libro necesito titulo']
        },
        isbn:{
            type: String,
            required: [true,'Un libro necesita ISBN'],
            unique: true
        },
        author:{
            type: mongoose.Schema.Types.ObjectId,
            ref: 'Author',
            required: [true,'Un libro necesita autor']
        },
        genre:{
            type: String,
            enum: {
                values: ['fiction', 'terror', 'fantasy']
            }
        },
        publishedYear:{
            type: Number

        },
        pages:{
            type: Number
        },
        available:{
            type: Boolean
        }

    }
)

bookSchema.index({isbn: "text"})

const Book = mongoose.model('Book',bookSchema)

export default Book