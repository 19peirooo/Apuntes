package com.example.store.UI.fragment

import android.content.Context
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.navigation.fragment.findNavController
import com.example.store.R
import com.example.store.databinding.FragmentLoginBinding
import com.google.android.material.snackbar.Snackbar
import com.google.firebase.auth.FirebaseAuth

class LoginFragment : Fragment() {

    private lateinit var binding: FragmentLoginBinding

    private lateinit var auth: FirebaseAuth

    override fun onAttach(context: Context) {
        super.onAttach(context)
        auth = FirebaseAuth.getInstance()
    }

    override fun onResume() {
        super.onResume()
        if (auth.currentUser != null) {
            auth.signOut()
        }
    }

    override fun onStart() {
        super.onStart()
        binding.btnLogin.setOnClickListener {
            val email = binding.editMail.text.toString()
            val pass = binding.editPass.text.toString()

            if (email.isEmpty() || pass.isEmpty()) {
                Snackbar.make(
                    binding.root,
                    "Debes rellenar email y contraseña",
                    Snackbar.LENGTH_LONG
                ).show()
                return@setOnClickListener
            }

            auth.signInWithEmailAndPassword(email,pass)
                .addOnCompleteListener {
                    if (it.isSuccessful) {
                        findNavController().navigate(R.id.action_loginFragment_to_storeFragment)
                    } else {
                        Snackbar.make(
                            binding.root,
                            "ERROR en el proceso de login",
                            Snackbar.LENGTH_LONG
                        ).show()
                    }
                }
        }
        binding.btnRegister.setOnClickListener {
            val bundle = Bundle()
            bundle.putString("email", binding.editMail.text.toString())
            bundle.putString("pass", binding.editPass.text.toString())
            findNavController().navigate(R.id.action_loginFragment_to_registerFragment,bundle)
        }
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = FragmentLoginBinding.inflate(inflater,container,false)
        return binding.root
    }

    override fun onDetach() {
        super.onDetach()
    }

}