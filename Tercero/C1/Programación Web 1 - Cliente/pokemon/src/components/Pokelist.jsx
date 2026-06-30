import { useState } from "react";

export default function PokeList ({pkms}) {

    const [pokemon,setPokemon] = useState(null)

    function cargarPokemon(url) {
        fetch(url)
        .then(response => response.json())
        .then(data => setPokemon({
            name:data.name,
            img:data.sprites.front_default,
            type:data.types[0].type.name
        }))
    }

    return (
        <>
        <ul>
            {pkms.map(item => <li key={item.id} onClick={() => cargarPokemon(item.url)}>{item.name}</li>)}
        </ul>
        {pokemon && 
            <div>
                <h1>{pokemon.name}</h1>
                <img src={pokemon.img}></img>
                <h2>{pokemon.type}</h2>
            </div>
        }
        </>

    );
}