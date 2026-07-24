package com.example.store.UI.fragment

import android.content.Context
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.navigation.fragment.findNavController
import androidx.recyclerview.widget.LinearLayoutManager
import com.example.store.R
import com.example.store.adapter.SeriesAdapter
import com.example.store.api.RetrofitClient
import com.example.store.databinding.FragmentStoreBinding
import com.example.store.model.Serie
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.FirebaseDatabase
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response

class StoreFragment : Fragment() {

    private lateinit var binding: FragmentStoreBinding
    private lateinit var adapterSeries: SeriesAdapter

    private lateinit var auth: FirebaseAuth
    private lateinit var database: FirebaseDatabase

    override fun onAttach(context: Context) { //Para asignaciones logicas
        super.onAttach(context)
        auth = FirebaseAuth.getInstance()
        database = FirebaseDatabase.getInstance("https://dam-victorpeiro-default-rtdb.europe-west1.firebasedatabase.app/")

        database.reference.child("nombreApp").setValue("Series FB")
    }

    override fun onStart() {
        super.onStart()
        binding.btnGoFavorites.setOnClickListener {
            findNavController().navigate(R.id.action_storeFragment_to_favouritesFragment)
        }
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {

        binding = FragmentStoreBinding.inflate(inflater, container, false)

        binding.recyclerSeries.layoutManager =
            LinearLayoutManager(requireContext())

        loadSeries()

        return binding.root
    }

    private fun toggleFavourite(serieId: Int) {

        val user = auth.currentUser ?: return
        val userId = user.uid

        val favRef = database
            .reference
            .child("favourites")
            .child(userId)
            .child(serieId.toString())

        favRef.get().addOnSuccessListener { snapshot ->

            if (snapshot.exists()) {
                favRef.removeValue()
            } else {
                favRef.setValue(true)
            }
        }
    }

    private fun loadFavourites(onLoaded: (Set<Int>) -> Unit) {

        val user = auth.currentUser ?: return
        val userId = user.uid

        database.reference
            .child("favourites")
            .child(userId)
            .get()
            .addOnSuccessListener { snapshot ->

                val favs = mutableSetOf<Int>()

                for (child in snapshot.children) {
                    child.key?.toIntOrNull()?.let {
                        favs.add(it)
                    }
                }

                onLoaded(favs)
            }
    }

    private fun loadSeries() {

        loadFavourites { favSet ->

            val call = RetrofitClient.api.getShows()

            call.enqueue(object : Callback<List<Serie>> {

                override fun onResponse(
                    call: Call<List<Serie>>,
                    response: Response<List<Serie>>
                ) {

                    if (response.isSuccessful && response.body() != null) {

                        val seriesList = response.body()!!

                        adapterSeries = SeriesAdapter(
                            requireContext(),
                            auth,
                            favSet.toMutableSet(),
                            onDetailClick = { serieId ->

                                val bundle = Bundle().apply {
                                    putInt("id", serieId)
                                }

                                findNavController().navigate(
                                    R.id.action_storeFragment_to_serieFragment,
                                    bundle
                                )
                            },
                            onFavouriteClick = { serieId ->
                                toggleFavourite(serieId)
                            }
                        )

                        binding.recyclerSeries.adapter = adapterSeries
                        adapterSeries.setSeries(seriesList)
                    }
                }

                override fun onFailure(call: Call<List<Serie>>, t: Throwable) {
                    t.printStackTrace()
                }
            })
        }
    }

}