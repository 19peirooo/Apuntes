import { Router } from "express";
import { createBook, deleteBook, getBook, getBooks, updateBook } from "../controllers/book.controller";

const router = Router()

router.get('/', getBooks)
router.get('/:id', getBook)
router.post('/',createBook),
router.delete('/:id',deleteBook)
router.put('/:id', updateBook)