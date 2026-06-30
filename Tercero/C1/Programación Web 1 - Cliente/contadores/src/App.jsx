import { useRef , useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  const [count, setCount] = useState(0)
  let tmpCount = useRef(0);

  return (
    <>
      <h1>Variables en React</h1>
      <button onClick={() => setCount(tmpCount.current)}> Numero de Clicks: {count} </button>
      <button onClick={() => {tmpCount.current++}}> Click Me! </button>
      <button onClick={() => {tmpCount.current = 0; setCount(tmpCount.current);}}>Reset Count</button>
    </>
  )
}

export default App
