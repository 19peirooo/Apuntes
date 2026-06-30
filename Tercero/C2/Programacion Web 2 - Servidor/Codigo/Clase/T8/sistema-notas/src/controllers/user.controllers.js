import User from "../models/user.models.js";
import { tokenSign } from "../utils/handleJwt.js";
import { encrypt } from "../utils/handlePassword.js";

export async function getUsers(req,res) {

    const users = await User.find()
    res.json(users)
    

}

export async function subirUser(req, res) {
    
    const { email, password } = req.body;

    try {

        const user = await User.find({email: email}).lean()

        if (user.length > 0) {
            res.status(400).json({message: "ERROR: Ya existe un usuario con este email"}) 
            return
        }
        
        const hashedPassword = await encrypt(password)
        req.body.password = hashedPassword;
        
        const created_user = await User.create(req.body)
        res.status(200).json(tokenSign(created_user))
    } catch (error) {
        res.status(500).json({message: "ERROR: No se pudo crear usuario"})
    }

}