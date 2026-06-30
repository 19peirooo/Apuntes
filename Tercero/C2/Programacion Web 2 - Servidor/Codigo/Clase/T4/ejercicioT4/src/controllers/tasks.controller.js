import { ApiError } from "../middleware/errorHandler"
import tasks from "../data/data.js"

export function getData(req, res) {
    try {
        res.json(tasks)
    } catch {
        throw ApiError
    }
}

export function getItem (req, res) {
    
}

export function createTask(req, res) {

}

export function updateTask(req, res) {

}

export function deleteTask(req, res) {
    
}

export function toggleCompleted(req, res) {

}