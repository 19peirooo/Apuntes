import { Note } from "../models/notes.models.js";

export async function getNotes(req, res) {

    const notes = await Note.find({deleted: false})

    res.json(notes)

}

export async function getTrashedNotes(req, res) {
    const trashed_notes = await Note.findDeleted()

    res.json(trashed_notes)
}

export async function getNote(req, res) {

    const {id} = req.params

    const note = await Note.findById(id)

    res.json(note)
}

export async function createNote(req, res) {

    const created_note = await Note.create(req.body)

    res.json(created_note)
    
}

export async function updateNote(req, res) {

    const { id } = req.params
    
    const updated_note = await Note.findByIdAndUpdate(
        id,
        {$set: req.body},
        {runValidators: true, returnDocument: "after"}
    )

    res.json(updated_note)

}

export async function softDeleteNote(req, res) {
    
    const { id } = req.params

    const note = await Note.findById(id);

    if (note.author == req.user._id || req.user.role == 'admin') {
        await Note.softDeleteById(id, req.user._id)
    }

    res.json()

}

export async function restoreNote(req, res) {
    
    const { id } = req.params

    const note = await Note.findById(id);
    if (note.author == req.user._id || req.user.role == 'admin') {
        await Note.restoreById(id)
    }
    
    res.json()

}


export async function deleteNote(req, res) {
    
    const { id } = req.params

    const deleted_note = await Note.findByIdAndDelete(id)

    res.json(deleted_note)
}

export async function emptyTrash(req, res) {
    
    const deleted_notes = await Note.deleteMany({deleted: true})

    res.json(deleted_notes)

}