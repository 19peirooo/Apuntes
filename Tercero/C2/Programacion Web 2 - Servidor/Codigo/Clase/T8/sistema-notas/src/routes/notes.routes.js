import Router from "express"
import { createNote,
    deleteNote,
    emptyTrash,
    getNote,
    getNotes,
    getTrashedNotes,
    restoreNote,
    softDeleteNote,
    updateNote } from "../controllers/notes.controllers.js"
import { authMiddleware } from "../middleware/session.middleware.js"
import { checkRoles } from "../middleware/rol.middleware.js"

const router = Router()
router.use(authMiddleware)

router.get("/", getNotes)
router.get("/trash",checkRoles(['admin','user']), getTrashedNotes)
router.post("/",checkRoles(['admin','user']), createNote)
router.delete("/trash/empty",checkRoles(['admin','user']),checkRoles(['admin']), emptyTrash)

router.get("/:id", getNote)
router.patch("/:id",checkRoles(['admin','user']), updateNote)
router.delete("/:id",checkRoles(['admin','user']), softDeleteNote)
router.post("/:id/restore",checkRoles(['admin','user']), restoreNote)
router.delete("/:id/permanent",checkRoles(['admin']), deleteNote)

export default router;