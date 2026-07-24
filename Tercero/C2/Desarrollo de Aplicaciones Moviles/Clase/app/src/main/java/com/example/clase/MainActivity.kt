package com.example.clase

import android.os.Bundle
import android.util.Log
import android.view.View
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.example.clase.databinding.ActivityLoginBinding
import com.example.clase.databinding.ActivityMainBinding
import com.example.clase.model.Usuario
import com.google.android.material.snackbar.Snackbar

class MainActivity : AppCompatActivity(), View.OnClickListener {

    private lateinit var binding: ActivityMainBinding
    private lateinit var usuario: Usuario

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        getDatos()
        actions()
        initGUI()
        Log.v("ciclo_vida", "ejecutando metodo onCreate")

    }

    private fun initGUI() {
        binding.editNombre.setText(usuario.mail)
    }

    private fun getDatos() {
        usuario = intent.getSerializableExtra("usuario_dato") as Usuario
    }

    private fun actions() {
        binding.botonSaludar.setOnClickListener(this)
        binding.botonVaciar.setOnClickListener(this)
    }

    override fun onClick(v: View?) {
        when(v!!.id){
            binding.botonVaciar.id->{
                if(binding.editNombre.text.toString().isEmpty()){
                    Snackbar.make(binding.root,
                        R.string.text_empty_edit,
                        Snackbar.LENGTH_LONG).show()
                }
                else{
                    Snackbar.make(binding.root,
                        "Enhorabuena ${binding.editNombre.text.toString().trim()}",
                        Snackbar.LENGTH_LONG).show()
                }
            }
            binding.botonSaludar.id->{
                Snackbar.make(binding.root, "Enhorabuena ${binding.editNombre.text.toString()}", Snackbar.LENGTH_LONG).show()
            }

        }
    }

}