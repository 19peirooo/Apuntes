package com.example.store.model

class SerieDetails (
    val id : Int,
    val name: String,
    val image: Image,
    val summary: String,
    val rating: Rating,
    val genres: List<String>
)