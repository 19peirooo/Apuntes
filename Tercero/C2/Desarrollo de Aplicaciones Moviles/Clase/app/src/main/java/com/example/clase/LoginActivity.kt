package com.example.clase

import android.content.Intent
import android.os.Bundle
import android.widget.Adapter
import android.widget.ArrayAdapter
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.example.clase.data.DataSet
import com.example.clase.databinding.ActivityLoginBinding
import com.example.clase.model.UserData
import com.example.clase.model.Usuario
import com.google.android.material.snackbar.Snackbar

class LoginActivity : AppCompatActivity() {

    private lateinit var binding: ActivityLoginBinding
    private lateinit var adapterPerfil: ArrayAdapter<CharSequence>
    private lateinit var listaPerfiles: List<CharSequence>
    private var mail: String? = null
    private var pass: String? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityLoginBinding.inflate(layoutInflater)
        setContentView(binding.root)
        recuperarDatos();
        instancias()
        initGUI()
        acciones()
    }

    private fun recuperarDatos() {
        mail = intent.getStringExtra("mail")
        pass = intent.getStringExtra("pass")
    }

    private fun acciones() {
        binding.botonLogin.setOnClickListener {

            val mail =  binding.editMail.text.toString()
            val pass = binding.editPass.text.toString()
            val perfil = binding.spinnerPerfil.selectedItem.toString()
            val recordar = binding.checkbox.isChecked

            if (mail.isEmpty() || pass.isEmpty()) {
                getSnack("Faltan Datos Por Rellenar").show()
                return@setOnClickListener
            }

            val loggedInUser = DataSet.login(mail, pass)

            if (loggedInUser != null) {
                val intent = Intent(applicationContext, ListaActivity::class.java)
                intent.putExtra("Usuario_dato", loggedInUser)
                startActivity(intent)
            } else {
                getSnack("Login Incorrecto").show()
            }
        }

        binding.botonRegister.setOnClickListener {
            val intent = Intent(applicationContext, RegisterActivity::class.java)
            startActivity(intent)
        }
    }

    private fun initGUI() {
        //Todas las inicializaciones graficas
        binding.spinnerPerfil.adapter = adapterPerfil
        adapterPerfil.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)

        if (mail != null && pass != null) {
            binding.editMail.setText(mail)
            binding.editPass.setText(pass)
        }

    }

    private fun instancias() {
        //Todas las inicializaciones de variables
        listaPerfiles = listOf("Administrador", "Usuario", "Invitado")
        adapterPerfil = ArrayAdapter<CharSequence>(applicationContext,
            android.R.layout.simple_spinner_item,listaPerfiles)
    }

    private fun vaciarDatos() {
        binding.editPass.text.clear()
        binding.editMail.text.clear()
        binding.checkbox.isChecked = false
        binding.spinnerPerfil.setSelection(0)
    }

    override fun onRestart() {
        super.onRestart()
        vaciarDatos()
    }

    private fun getSnack(mensaje: String) : Snackbar{
        return Snackbar.make(
            binding.root,
            mensaje,
            Snackbar.LENGTH_LONG
        )
    }

}