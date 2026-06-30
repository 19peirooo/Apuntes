window.addEventListener('load', () => {
    fetch("https://pokeapi.co/api/v2/pokemon?offset=204&limit=20")
    .then(response => response.json())
    .then(data => load_data(data.results))
});

function load_data(data) {
    const lista = document.getElementById("ListaPokemon");
    data.forEach(item => {
        const li = document.createElement("li");
        li.innerText= item.name;
        li.addEventListener('click', () => {
            fetch(item.url)
            .then(response => response.json())
            .then(pkmn_data => {
                const img = document.getElementById("pkmn_img")
                img.src = pkmn_data.sprites.front_default;
                img.alt = item.name;
            })
        });
        lista.appendChild(li)
    });
}