package com.example.clase2.UI.fragment

import android.content.Context
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.navigation.fragment.findNavController
import com.example.clase2.R
import com.example.clase2.databinding.RegisterFragmentBinding
import com.example.clase2.model.User
import com.google.android.material.snackbar.Snackbar
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.FirebaseDatabase

class RegisterFragment : Fragment() {
    private lateinit var binding: RegisterFragmentBinding
    private lateinit var auth: FirebaseAuth
    private lateinit var database: FirebaseDatabase

    override fun onAttach(context: Context) { //Para asignaciones logicas
        super.onAttach(context)
        auth = FirebaseAuth.getInstance()
        database = FirebaseDatabase.getInstance("https://dam-victorpeiro-default-rtdb.europe-west1.firebasedatabase.app/")

        database.reference.child("nombreApp").setValue("TIENDA FB")
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = RegisterFragmentBinding.inflate(inflater,container,false)
        return binding.root
    }

    override fun onStart() {
        super.onStart()

        binding.btnRegister.setOnClickListener{
            val nombre = binding.editName.text.toString()
            val apellido = binding.editSurname.text.toString()
            val correo = binding.editMail.text.toString()
            val pass = binding.editPass.text.toString()

            //validar datos
            auth.createUserWithEmailAndPassword(correo,pass)
                .addOnCompleteListener {
                    if (it.isSuccessful) {

                        var referenciaUser = database.reference.child("users")

                        referenciaUser.child(auth.currentUser!!.uid)
                            .setValue(
                            User(
                                nombre,
                                apellido,
                                correo,
                                pass
                            )
                        )

                        Snackbar.make(
                            binding.root,
                            "Registro Completado, ¿Quieres Iniciar Sesion?",
                            Snackbar.LENGTH_LONG
                        ).setAction("OK"){
                            findNavController().navigate(R.id.action_registerFragment_to_mainFragment)
                        }.show()

                    } else {
                        Snackbar.make(
                            binding.root,
                            "ERROR en el proceso de Registro",
                            Snackbar.LENGTH_LONG
                        ).show()
                    }
            }

        }
    }

    override fun onDetach() {
        super.onDetach()
    }
}