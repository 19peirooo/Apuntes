package com.example.clase

import android.content.Intent
import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.example.clase.data.DataSet
import com.example.clase.databinding.ActivityLoginBinding
import com.example.clase.databinding.ActivityRegisterBinding
import com.example.clase.model.UserData
import com.example.clase.model.Usuario
import com.google.android.material.snackbar.Snackbar

class RegisterActivity : AppCompatActivity() {

    private lateinit var binding: ActivityRegisterBinding
    private lateinit var adapterEdad: ArrayAdapter<Int>
    private lateinit var listaEdades: ArrayList<Int>

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityRegisterBinding.inflate(layoutInflater)
        setContentView(binding.root)
        instancias()
        initGUI()
        acciones()
    }

    private fun acciones() {
        binding.botonRegister.setOnClickListener {

            val nombre = binding.registerName.text.toString()
            val apellido = binding.registerSurname.text.toString()
            val mail = binding.registerMail.text.toString()
            val pass = binding.registerPass.text.toString()
            val passVerificada = binding.verifyPass.text.toString()
            val edad = binding.registerEdad.selectedItem.toString().toInt()

            if (nombre.isEmpty() || apellido.isEmpty() || mail.isEmpty() ||
                pass.isEmpty() || passVerificada.isEmpty()) {

                getSnack("Faltan datos de registro").show()

                return@setOnClickListener
            }

            if (pass != passVerificada) {

                getSnack("Las contraseñas no coinciden").show()

                return@setOnClickListener
            }

            val user = UserData(nombre,apellido,mail,pass,edad)

            if (DataSet.addUser(user)) {
                getSnack("Usuario mostrado correctamente")
                    .setAction("Pulsar"){
                        val intent = Intent(applicationContext, LoginActivity::class.java)
                        intent.putExtra("mail",mail)
                        intent.putExtra("pass",pass)
                        startActivity(intent)
                    }
                    .show()

            } else {
                getSnack("Fallo en el registro de usuario").show()
            }


        }
    }

    private fun getSnack(mensaje: String) : Snackbar{
        return Snackbar.make(
            binding.root,
            mensaje,
            Snackbar.LENGTH_LONG
        )
    }

    private fun initGUI() {
        //Todas las inicializaciones graficas
        binding.registerEdad.adapter = adapterEdad
        adapterEdad.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
    }

    private fun instancias() {
        //Todas las inicializaciones de variables
        listaEdades = ArrayList()
        for (i in 18..90) {
            listaEdades.add(i)
        }
        adapterEdad = ArrayAdapter<Int>(applicationContext,
            android.R.layout.simple_spinner_item,listaEdades)
    }

    private fun vaciarDatos() {
        binding.registerName.text.clear()
        binding.registerSurname.text.clear()
        binding.registerMail.text.clear()
        binding.registerPass.text.clear()
        binding.verifyPass.text.clear()
        binding.registerEdad.setSelection(0)
    }

    override fun onRestart() {
        super.onRestart()
        vaciarDatos()
    }
}