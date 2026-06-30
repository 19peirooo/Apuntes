import { Router } from "express";
import { createAuthor, deleteAuthor, getAuthor, getAuthorBooks, getAuthors, updateAuthor } from "../controllers/author.controller";

const router = Router()

router.get('/', getAuthors)
router.get('/:id', getAuthor)
router.post('/',createAuthor)
router.delete('/:id',deleteAuthor)
router.put('/:id', updateAuthor)
router.get(':id/books', getAuthorBooks)