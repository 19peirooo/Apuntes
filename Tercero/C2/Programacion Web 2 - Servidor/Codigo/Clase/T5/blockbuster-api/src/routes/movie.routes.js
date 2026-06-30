import { Router } from "express";
import { createMovie, deleteMovie, getMovie, getMovies, rentMovie, returnMovie, showTop5Movies, updateMovie } from "../controllers/movie.controller.js";

const router = Router()

router.get('/', getMovies)
router.get('/:id', getMovie)
router.post('/', createMovie)
router.put('/:id', updateMovie)
router.delete('/id', deleteMovie)

router.patch('/:id/rent', rentMovie)
router.patch('/:id/return', returnMovie)
router.get('/stats/top', showTop5Movies)

export default router;