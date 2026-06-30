import { verifyToken } from "../utils/handleJwt.js"
import User from "../models/user.models.js"


export async function validateToken (req,res,next) {
    const authHeader = req.headers.authorization.split(" ")

    if (authHeader[0] !== "Bearer") {
        return res.status(400).json({
            message: "ERROR: Cabecera Invalida"
        })
    }

    const user_in_payload = verifyToken(authHeader[1])
    console.log(user_in_payload)
    if (user_in_payload) {
        const user = await User.findById(user_in_payload._id)
        req.user = user
        next()
    } else {
        return res.status(400).json("ERROR: Token Invalido")
    }

}