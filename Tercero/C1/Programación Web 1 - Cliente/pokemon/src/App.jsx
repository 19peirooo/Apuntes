import { useState, useEffect } from 'react'
import './App.css'
import PokeList from './components/Pokelist';

function App() {
  const [pkms,setPkms] = useState([]);

  useEffect(()=>{
      fetch("https://pokeapi.co/api/v2/pokemon?offset=204&limit=20")
      .then(response => response.json())
      .then(data => setPkms(data.results))
      
  },[])

  return (
    <>
      <h1>Lista Pokemons</h1>
      <PokeList pkms={pkms}/>
    </>
  )
}

export default App
