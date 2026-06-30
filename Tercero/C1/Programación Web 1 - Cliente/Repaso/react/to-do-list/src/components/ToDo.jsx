import { FaTrashAlt } from "react-icons/fa";
import "./styles/ToDo.css"

export default function ToDo({task,onComplete,onDelete}) {

   return (<li 
       onClick={()=>onComplete(task.id)} 
       className={task.complete ? 'complete' : ''}>
       {task.name}   
       <FaTrashAlt onClick={(e) => {
         e.stopPropagation();
         onDelete(task.id)}}/>
       </li>
     )

}