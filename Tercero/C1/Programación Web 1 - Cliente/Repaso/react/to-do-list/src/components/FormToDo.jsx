import { useState } from "react";
import "./styles/FormToDo.css"

export default function FormToDo ({onSubmit}) {

    const [input, setInput] = useState('')

    const handleSubmit = (e) => {
        e.preventDefault();
        onSubmit(input)
        setInput('');
    }

    const onChange = (e) => {
        setInput(e.target.value)
    }

    return (
        <form onSubmit={handleSubmit}>
            <input type="text" placeholder="Nueva Tarea" onChange={onChange} value={input}></input>
            <button>Añadir Tarea</button>
        </form>
    );

}