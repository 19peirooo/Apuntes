import Movie from "../models/movie.models.js";

export async function getMovies(req, res) {
    
    const { genre } = req.query;
    const filter = {}
    if (genre) filter.genre = genre

    try {
        const movies = await Movie.find(filter)
        res.status(200).json(movies)
    } catch (error) {
        res.status(500).json({message: "ERROR: No se pudo acceder a DB", error})
    }
}

export async function getMovie(req,res) {
    const {id} = req.params

    try {
        const movie = await Movie.findById(id)

        if (!movie) {
            res.status(404).json({message: "ERROR: No se encontro pelicula"})
        }
        res.status(200).json(movie)
    } catch (error) {
        res.status(500).json({message: "ERROR: No se pudo acceder a DB", error})
    }
}

export async function createMovie(req, res) {

    try {
        const new_movie = await Movie.create(req.body)
        res.status(201).json({message: "Pelicula creada con exito", new_movie})
    } catch (error) {
        res.status(500).json({message: "ERROR: No se pudo acceder a DB", error})
    }

}

export async function updateMovie(req, res) {
    try {
        const { id } = req.params;

        const updated_movie = await Movie.findByIdAndUpdate(
            id,
            req.body,
            { new: true, runValidators: true }
        );

        if (!updated_movie)
            return res.status(404).json({ message: "ERROR: No se pudo encontrar pelicula" });

        res.status(200).json({message: "Pelicula actualizada con exito", updated_movie});
    } catch (error) {
        res.status(400).json({ message: "ERROR: No se pudo actualizar el pelicula", error });
    }
}

export async function deleteMovie(req, res) {
    try {
        const { id } = req.params;

        const deleted_movie = await Movie.findByIdAndDelete(id);

        if (!deleted_movie)
            return res.status(404).json({ message: "ERROR: No se pudo encontrar pelicula" });

        res.status(200).json({message: "Pelicula eliminada con exito", deleted_movie});
    } catch (error) {
        res.status(400).json({ message: "ERROR: No se pudo eliminar el pelicula", error });
    }
}

export async function rentMovie(req, res) {
    
    try {
        const { id } = req.params;

        const updated_movie = await Movie.findByIdAndUpdate(
            id,
            {rented: true},
            { new: true, runValidators: true }
        );

        if (!updated_movie)
            return res.status(404).json({ message: "ERROR: No se pudo encontrar pelicula" });

        res.status(200).json({message: "Pelicula actualizada con exito", updated_movie});
    } catch (error) {
        res.status(400).json({ message: "ERROR: No se pudo actualizar el pelicula", error });
    }

}

export async function returnMovie(req, res) {
    try {
        const { id } = req.params;

        const updated_movie = await Movie.findByIdAndUpdate(
            id,
            {rented: false},
            { new: true, runValidators: true }
        );

        if (!updated_movie)
            return res.status(404).json({ message: "ERROR: No se pudo encontrar pelicula" });

        res.status(200).json({message: "Pelicula actualizada con exito", updated_movie});
    } catch (error) {
        res.status(400).json({ message: "ERROR: No se pudo actualizar el pelicula", error });
    }
}

export async function showTop5Movies(req, res) {
    try {

        const topMovies = await Movie.find({rented: true}).sort({num_rents: -1}).limit(5)

        res.status(200).json(topMovies)

    } catch (error) {
        res.status(400).json({ message: "ERROR: No se pudo actualizar el pelicula", error });
    }
}