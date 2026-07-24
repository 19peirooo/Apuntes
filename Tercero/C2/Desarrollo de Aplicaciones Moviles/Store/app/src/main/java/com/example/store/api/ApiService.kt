package com.example.store.api

import com.example.store.model.Serie
import com.example.store.model.SerieDetails
import retrofit2.Call
import retrofit2.http.GET
import retrofit2.http.Path

interface ApiService {

    @GET("shows")
    fun getShows(): Call<List<Serie>>

    @GET("shows/{id}")
    fun getShowById(@Path("id") id: Int): Call<SerieDetails>
}