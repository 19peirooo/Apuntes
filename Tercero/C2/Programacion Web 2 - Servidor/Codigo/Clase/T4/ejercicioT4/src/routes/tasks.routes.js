import { Router } from "express"
import { createTask, deleteTask, getData, getItem, toggleCompleted, updateTask } from "../controllers/tasks.controller";

const router = Router()

router.get('/',getData)

router.get('/:id', getItem)

router.post('/', createTask)

router.put('/:id', updateTask)

router.delete('/:id', deleteTask)

router.patch('/:id/toggle', toggleCompleted)

export default router;
