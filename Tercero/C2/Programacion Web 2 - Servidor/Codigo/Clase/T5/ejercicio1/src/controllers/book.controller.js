import Book from "../models/book.models"

export async function getBooks(req,res) {
    try {
        const { genre, available } = req.params
        const filter = {}

        if (genre) filter.genre = genre
        if (available !== undefined) filter.available = available

        const books = await Book.find(filter).populate("author")

        if (!books) {
            res.status(404).json({ message: "ERROR: No se encontraron libros "})
        }

        res.status(200).json(books)

    } catch {
        res.status(500).json({message: "ERROR: No se pudieron obtener datos", error})
    }
    
}

export async function getBook(req,res) {

    try {

        const {id} = req.params;

        const book = await Book.findById(id).lean()

        if (!book) res.status(404).json({message: "ERROR: No se encontro libro"})

        res.status(200).json(book)

    } catch (error) {
        res.status(500).json({message: "ERROR: No se pudo obtener acceso a datos", error})
    }

}

export async function createBook(req,res) {
    try {
        const book = await Book.create(req.body)

        res.status(201).json({message: "Libro creado con exito", book})
    } catch (error) {
        res.status(400).json({ message: "ERROR: No se pudo crear el libro", error })
    }
}

export async function updateBook(req,res) {
    try {
        const { id } = req.params;

        const updatedBook = await Book.findByIdAndUpdate(
            id,
            req.body,
            { new: true, runValidators: true }
        );

        if (!updatedBook)
            return res.status(404).json({ message: "ERROR: No se pudo encontrar libro" });

        res.status(200).json({message: "Libro actualizado con exito", updatedBook});
    } catch (error) {
        res.status(400).json({ message: "ERROR: No se pudo actualizar el libro", error });
    }
}

export async function deleteBook(req,res) {
    try {
        const { id } = req.params;

        const deletedBook = await Book.findByIdAndDelete(id);

        if (!deletedBook)
            return res.status(404).json({ message: "ERROR: No se pudo encontrar el libro" });

        res.status(200).json({ message: "Se elimino libro con exito" });
    } catch (error) {
        res.status(500).json({ message: "ERROR: No se pudo eliminar recurso", error });
    }
}