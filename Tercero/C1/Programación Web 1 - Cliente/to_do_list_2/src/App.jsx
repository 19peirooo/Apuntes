
import './App.css'
import Logo from './components/Logo';
import FormToDo from './components/FormToDo'
import { v4 } from 'uuid';
import { useState } from 'react';
import ToDoList from './components/ToDoList';

function App() {

  const [tasks, setTasks] = useState([]);

  function handleNewtask(task) {
    console.log(task);
    const newTask = {
      text: task,
      id: v4(),
      complete: false
    }

    setTasks([...tasks, newTask]);
  }

  function handleComplete(id) {
    const modified = tasks.map(item => {
      if (item.id === id) {
        item.complete = !item.complete;
      }
      return item;
    })
    setTasks(modified);
  }

  function handleDelete(id) {
    const filtered = tasks.filter(item => item.id != id);
    setTasks(filtered);
  }

  return (<>
    <Logo></Logo>
    <FormToDo onSubmit={handleNewtask} />
    <ToDoList tasks={tasks} onComplete={handleComplete} onDelete={handleDelete}/>
  </>)

}

export default App
