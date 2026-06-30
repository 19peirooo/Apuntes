import express from "express"
import helmet from "helmet";
import router from "./routes/tasks.routes";
import { errorHandler, notFoundHandler } from "./middleware/errorHandler";


const app = express()
app.use(express.static('public'))
app.use(express.json())
app.use(helmet())
app.use('/api/tasks', router)
app.use(notFoundHandler)
app.use(errorHandler)

export default app;