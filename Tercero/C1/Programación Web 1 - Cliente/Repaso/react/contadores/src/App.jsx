import { useState, useRef } from 'react'
import './App.css'
import Button from './components/Button';

function App() {
  
  const [count,setCount] = useState(0);
  const temp_count = useRef(0)

  
  const handleClick = () => {
    temp_count.current++;
  }

  const handleShow = () => {
    setCount(temp_count.current);
  }

  return (
    <>
      <Button name="Click Me" handleClick={handleClick}></Button>
      <Button name={count} handleClick={handleShow}></Button>
    </>
  );

}

export default App
