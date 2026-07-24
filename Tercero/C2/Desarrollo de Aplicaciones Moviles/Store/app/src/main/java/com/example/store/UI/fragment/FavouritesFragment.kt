package com.example.store.UI.fragment

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

class FavouritesFragment : Fragment() {

    private lateinit var binding: FragmentStoreBinding
    private lateinit var adapterSeries: SeriesAdapter

    private lateinit var auth: FirebaseAuth
    private lateinit var database: FirebaseDatabase

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {

        binding = FragmentStoreBinding.inflate(inflater, container, false)

        auth = FirebaseAuth.getInstance()
        database = FirebaseDatabase.getInstance(
            "https://dam-victorpeiro-default-rtdb.europe-west1.firebasedatabase.app/"
        )

        binding.recyclerSeries.layoutManager =
            LinearLayoutManager(requireContext())

        loadFavorites()

        return binding.root
    }

    private fun loadFavorites() {

        val user = auth.currentUser ?: return
        val userId = user.uid

        // 1. obtener IDs favoritos
        database.reference
            .child("favourites")
            .child(userId)
            .get()
            .addOnSuccessListener { snapshot ->

                val favIds = snapshot.children.mapNotNull {
                    it.key?.toIntOrNull()
                }

                if (favIds.isEmpty()) return@addOnSuccessListener

                // 2. traer todas las series
                RetrofitClient.api.getShows()
                    .enqueue(object : retrofit2.Callback<List<Serie>> {

                        override fun onResponse(
                            call: retrofit2.Call<List<Serie>>,
                            response: retrofit2.Response<List<Serie>>
                        ) {

                            if (response.isSuccessful) {

                                val allSeries = response.body() ?: emptyList()

                                // 3. filtrar solo favoritos
                                val favSeries = allSeries.filter {
                                    favIds.contains(it.id)
                                }

                                adapterSeries = SeriesAdapter(
                                    requireContext(),
                                    auth,
                                    favIds.toMutableSet(),
                                    onDetailClick = { serieId ->

                                        val bundle = Bundle().apply {
                                            putInt("id", serieId)
                                        }

                                        findNavController().navigate(R.id.action_favouritesFragment_to_serieFragment)
                                    },
                                    onFavouriteClick = { serieId ->
                                        toggleFavourite(serieId)
                                    }
                                )

                                binding.recyclerSeries.adapter = adapterSeries
                                adapterSeries.setSeries(favSeries)
                            }
                        }

                        override fun onFailure(
                            call: retrofit2.Call<List<Serie>>,
                            t: Throwable
                        ) {
                            t.printStackTrace()
                        }
                    })
            }
    }

    private fun toggleFavourite(serieId: Int) {

        val user = auth.currentUser ?: return
        val userId = user.uid

        val favRef = database.reference
            .child("favourites")
            .child(userId)
            .child(serieId.toString())

        favRef.removeValue()
    }
}