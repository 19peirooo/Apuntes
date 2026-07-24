package com.example.clase2.UI.fragment

import android.content.Context
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.navigation.fragment.findNavController
import com.example.clase2.R
import com.example.clase2.databinding.LoginFragmentBinding
import com.google.android.material.snackbar.Snackbar
import com.google.firebase.auth.FirebaseAuth

class LoginFragment : Fragment() {

    private lateinit var binding: LoginFragmentBinding
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
            auth.signInWithEmailAndPassword(email,pass)
                .addOnCompleteListener {
                    if (it.isSuccessful) {
                        findNavController().navigate(R.id.action_loginFragment_to_mainFragment)

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
            findNavController().navigate(R.id.action_loginFragment_to_registerFragment)
        }
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = LoginFragmentBinding.inflate(inflater,container,false)
        return binding.root
    }

    override fun onDetach() {
        super.onDetach()
    }



}

