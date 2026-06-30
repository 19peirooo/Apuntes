import './App.css'
import { useEffect, useState } from 'react'

function App() {
  const [pkms,setPkms] = useState([]);

  useEffect(()=>{
    pkmn_data = fetch("https://pokeapi.co/api/v2/pokemon?offset=204&limit=20")
    .then(response => response.json())
    .then(data => load_data(data.results))
    setPkms(pkmn_data)
  },[pkms])

  return (
    <>
      <h1>Lista Pokemons</h1>
      <ul>
        {pkms.map(item => <li key={item.id}>{item.name}</li>)}
      </ul>
    </>
  )

}

export default App
