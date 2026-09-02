var t = 0;
var imagenes = ["camavinga.jpg","chuameni.png","vini.png"];
var frases = ["Camavinga Camao Camao ~ Camavinga","Me encanta pensamiento creativo ~ Chuameni","UH UH AH AH ~ Vinicius Jr"];

function cargar(){
	setInterval(cambiarImagen, 3000);
}

function cambiarImagen(){
	document.getElementById("imagen").src='imagenes/'+imagenes[t];
	document.getElementById("texto").innerHTML = frases[t];
	
	if (t === 2){
		t = 0;
	} else {
		t++;
	}
}

