import { Router } from "express";
import { getUsers, subirUser } from "../controllers/user.controllers.js";
import { validateToken } from "../middleware/token.middleware.js";

const router = Router()

router.get('/',validateToken,getUsers)
router.post('/', subirUser)

export default router;