package com.example.store.adapter

import android.annotation.SuppressLint
import android.content.Context
import android.view.LayoutInflater
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import com.example.store.R
import com.example.store.model.Serie
import com.bumptech.glide.Glide
import com.example.store.databinding.SerieItemBinding
import com.google.firebase.auth.FirebaseAuth

class SeriesAdapter(
    val context: Context,
    val auth: FirebaseAuth,
    val favs: MutableSet<Int>,
    val onDetailClick: (Int) -> Unit,
    val onFavouriteClick: (Int) -> Unit
)
    : RecyclerView.Adapter<SeriesAdapter.SeriesHolder>() {

    private val series = ArrayList<Serie>()

    inner class SeriesHolder(var binding: SerieItemBinding) :
        RecyclerView.ViewHolder(binding.root)

    override fun onCreateViewHolder(
        parent: ViewGroup,
        viewType: Int
    ): SeriesHolder {
        val binding : SerieItemBinding = SerieItemBinding.inflate(
            LayoutInflater.from(context),
            parent,
            false
        )

        return SeriesHolder(binding)
    }

    override fun onBindViewHolder(
        holder: SeriesHolder,
        position: Int
    ) {
        val serie: Serie = series[position]

        holder.binding.nombreSerie.text = serie.name

        Glide.with(context)
            .load(serie.image?.medium)
            .placeholder(R.drawable.store_logo)
            .into(holder.binding.imagenProducto)

        holder.binding.btnDetalles.setOnClickListener {
            onDetailClick(serie.id)
        }

        val isFav = favs.contains(serie.id)

        holder.binding.btnFavorito.setImageResource(
            if (isFav) R.drawable.heart_filled_icon
            else R.drawable.heart_icon
        )

        holder.binding.btnFavorito.setOnClickListener {
            if (favs.contains(serie.id)) {
                favs.remove(serie.id)
            } else {
                favs.add(serie.id)
            }

            notifyItemChanged(position)
            onFavouriteClick(serie.id)
        }

    }

    override fun getItemCount(): Int {
        return series.size
    }

    fun setSeries(newSeries: List<Serie>) {
        series.clear()
        series.addAll(newSeries)
        notifyItemRangeChanged(0, series.size)
    }



}