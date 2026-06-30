import Author from "../models/author.models"

export async function getAuthors(req,res) {
    try {
        const authors = await Author.find().lean()
        res.status(200).json(authors)
    } catch (error) {
        res.status(500).json({message: "ERROR: No se pudo obtener datos", error})
    }
    
}

export async function getAuthor(req,res) {

    try {
        const { id } = req.params

        const author = await Author.findById(id).lean()

        if (!author) {
            res.status(404).json({message: "ERROR: Autor no encontrado"})
        }

        res.status(200).json(author)

    } catch (error) {
        res.status(500).json({message: "ERROR: No se pudo obtener datos", error})
    }

}

export async function createAuthor(req,res) {
    
    try {
        const author = await Author.create(req.body)
        res.status(201).json({message: "Author creado con exito", author: author})
    } catch (error) {
        res.status(400).json({ message: "ERROR: No se pudo crear autor", error })
    }

}

export async function updateAuthor(req,res) {

    try {
        const {id} = req.params;
        const updatedAuthor = await Author.findByIdAndUpdate(id, req.body,{ new: true, runValidators: true })

        if (!updatedAuthor) {
            res.status(404).json({message: "ERROR: No se encontro autor"})
        }

        res.status(200).json({message: "Author actualizado con exito", author: updatedAuthor})
    } catch (error) {
        res.status(400).json({ message: "ERROR: No se pudo actualizar", error });
    }

}

export async function deleteAuthor(req,res) {
    try {
        const { id } = req.params;

        const deletedAuthor = await Author.findByIdAndDelete(id);

        if (!deletedAuthor) {
            return res.status(404).json({ message: "ERROR: No se pudo borrar autor" });
        }

        res.status(200).json({ message: "Autor eliminado con exito", author: deletedAuthor });
    } catch (error) {
        res.status(500).json({ message: "ERROR: No se pudo eliminar autor", error });
    }
}

export async function getAuthorBooks(req, res) {
    try {
        const { id } = req.params;

        const books = await Book.find({ author: id }).lean();

        if (!books) {
            res.status(404).json({message: "ERROR: No se encontraron libros del autor"})
        }

        res.status(200).json(books);
    } catch (error) {
        res.status(500).json({ message: "ERROR: No se pudo obtener libros del autor", error });
    }
}