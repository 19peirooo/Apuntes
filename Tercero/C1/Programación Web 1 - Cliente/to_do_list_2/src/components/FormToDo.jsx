import {useState} from "react";
import './styles/FormToDo.css'

function FormToDo ({onSubmit}) {

  const [input, setInput] = useState('');

  function handleSubmit(e) {
    e.preventDefault();
    onSubmit(input);
  }

  function handleChange (e) {
    setInput(e.target.value);
    
  }

  return (<form onSubmit={handleSubmit}>
    <input type="text" placeholder="Nueva tarea" onChange={handleChange} value={input} ></input>
    <button>Añadir tarea</button>
  </form>)
}

export default FormToDo;