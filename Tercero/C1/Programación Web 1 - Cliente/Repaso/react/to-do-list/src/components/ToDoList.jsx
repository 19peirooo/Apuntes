import ToDo from "./ToDo.jsx";
import "./styles/ToDoList.css"

export default function ToDoList ({tasks,onComplete,onDelete}) {

    return (
        <ul id="todolist">
            {tasks.map(item => <ToDo key={item.id} task={item} onComplete={onComplete} onDelete={onDelete}></ToDo>)}
        </ul>
    );

}