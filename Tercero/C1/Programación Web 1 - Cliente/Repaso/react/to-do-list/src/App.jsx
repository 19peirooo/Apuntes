import { useState } from 'react'
import './App.css'
import Logo from './components/Logo';
import FormToDo from './components/FormToDo';
import ToDoList from './components/ToDoList';
import { v4 } from 'uuid';

function App() {

  const [tasks,setTasks] = useState([]);

  const newTask = (task) => {
    const newTask = {
      id: v4(),
      name: task,
      complete: false
    }

    setTasks([...tasks,newTask])
  }

  const completeTask = (id) => {
    const modified_tasks = tasks.map(item => {
      if (item.id === id) {
        item.complete = !item.complete
      }
      return item;
    })
    setTasks(modified_tasks)
  }

  const deleteTask = (id) => {
    const filtered_tasks = tasks.filter(item => item.id !== id);
    setTasks(filtered_tasks)
  }

  return (
    <>
      <Logo></Logo>
      <div className="to-do-list-container">
        <FormToDo onSubmit={newTask}></FormToDo>
        <ToDoList tasks={tasks} onComplete={completeTask} onDelete={deleteTask}></ToDoList>
      </div>
    </>
  );

}

export default App
