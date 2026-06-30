import './styles/ToDo.css'
import { FaTrashAlt } from "react-icons/fa";

export default function ToDo ({task, onComplete, onDelete}) {
  return (<li 
    onClick={()=>onComplete(task.id)} 
    className={task.complete ? 'complete' : ''}>
    {task.text}   
    <FaTrashAlt onClick={(e) => {
      e.stopPropagation();
      onDelete(task.id)}}/>
    </li>
  )
}