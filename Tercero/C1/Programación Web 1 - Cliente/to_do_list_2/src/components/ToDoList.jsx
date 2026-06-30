import ToDo from "./ToDo.jsx"
import "./styles/ToDoList.css"
export default function ToDoList({ tasks, onComplete , onDelete}) {
  return (<div id="todolist">
    <h1>Mis tareas</h1>
    <ul id="list">{tasks.map(item => <ToDo key={item.id} task={item} onComplete={onComplete} onDelete={onDelete}/>)}</ul>
  </div>
  )
}
