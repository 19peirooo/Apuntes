package com.example.store.UI.fragment

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import com.bumptech.glide.Glide
import com.example.store.R
import com.example.store.api.RetrofitClient
import com.example.store.databinding.FragmentSerieBinding
import com.example.store.model.Serie
import com.example.store.model.SerieDetails

class SerieFragment : Fragment() {

    private lateinit var binding: FragmentSerieBinding

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = FragmentSerieBinding.inflate(inflater,container,false)

        val id = arguments?.getInt("id") ?: return binding.root

        loadSerie(id)

        return binding.root
    }

    private fun loadSerie(id: Int) {

        val call = RetrofitClient.api.getShowById(id)

        call.enqueue(object : retrofit2.Callback<SerieDetails> {

            override fun onResponse(
                call: retrofit2.Call<SerieDetails>,
                response: retrofit2.Response<SerieDetails>
            ) {

                if (response.isSuccessful && response.body() != null) {

                    val serie = response.body()!!

                    binding.textName.text = serie.name
                    binding.textRating.text = "⭐ ${serie.rating.average.toString()}"
                    binding.textSummary.text = android.text.Html.fromHtml(
                        serie.summary ?: "",
                        android.text.Html.FROM_HTML_MODE_LEGACY
                    )
                    binding.textGenres.text = serie.genres.toString()

                    Glide.with(requireContext())
                        .load(serie.image?.original)
                        .into(binding.imageDetail)
                }
            }

            override fun onFailure(call: retrofit2.Call<SerieDetails>, t: Throwable) {
                t.printStackTrace()
            }
        })
    }

}