package com.example.clase.data

import com.example.clase.model.Product
import com.example.clase.model.UserData

class DataSet {

    companion object {
        private val listaUsuarios: ArrayList<UserData> = arrayListOf(
            UserData("admin", "admin apellido", "admin@admin.com","admin",20),
            UserData("guest", "guest apellido", "guest@guest.com","guest",20)
        )

        private val listaProductos: ArrayList<Product> = arrayListOf(
            Product("Zapatillas",
                "Zapatillas Casual",
                "zapatillas",
                200.00,
                "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSbJqdYTohZhroUJUWiVl23HbhD1FRw2CIV_g&s"),

            Product("Camiseta",
            "Vaqueros Casual",
            "vaqueros",
            10.50,
            "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRT8lfob4bbMV9zIq_w3QYdRE1irSA2oFmQ2w&s"),

            Product("Vaqueros",
                "Vaqueros Casual",
                "pantalones",
                50.50,
                "https://cdn.grupoelcorteingles.es/statics/manager/contents/images/uploads/2025/03/H1-jwm6c3Jg.jpeg?impolicy=Resize&width=800&height=800")

        )

        fun getAllProducts(): ArrayList<Product>{
            return listaProductos
        }

        fun addUser(user: UserData) : Boolean {

            if(!findUser(user.correo)) {
                listaUsuarios.add(user)
                return true
            }

            return false
        }

        private fun findUser(correo : String) : Boolean {
            return listaUsuarios.find { it.correo == correo } != null
        }

        fun login(correo: String, pass: String) : UserData? {
            return listaUsuarios.find { it.correo == correo && it.pass == pass}
        }

    }



}