package com.example.clase

import android.os.Bundle
import android.widget.LinearLayout
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.recyclerview.widget.GridLayoutManager
import androidx.recyclerview.widget.LinearLayoutManager
import com.example.clase.adapter.ProductAdapter
import com.example.clase.data.DataSet
import com.example.clase.databinding.ActivityListaBinding

class ListaActivity : AppCompatActivity() {

    private lateinit var binding: ActivityListaBinding

    private lateinit var adapterProducts: ProductAdapter

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityListaBinding.inflate(layoutInflater)
        setContentView(binding.root)
        instancias()
        initGUI()
    }

    private fun initGUI() {
        binding.recyclerProductos.adapter = adapterProducts
        if (resources.configuration.orientation == 1) {
            binding.recyclerProductos.layoutManager =
                LinearLayoutManager(this, LinearLayoutManager.VERTICAL,false)
        } else {
            binding.recyclerProductos.layoutManager =
                GridLayoutManager(this,2, LinearLayoutManager.VERTICAL,false)
        }

    }
    private fun instancias() {
        adapterProducts = ProductAdapter(DataSet.getAllProducts(), this)
    }
}