var menuNav = document.getElementById("MenuNav");
var btnMenu = document.getElementById("btnMenu");

var imgJugadores = ["1.jpg","2.jpg", "3.jpg","4.jpg","5.jpg","6.jpg","7.jpg","8.jpg","9.jpg","10.jpg","11.jpg","12.jpg","13.jpg","14.jpg","15.jpg","16.jpg",
"17.jpg","18.jpg","19.jpg","20.jpg","21.jpg","22.jpg","23.jpg","24.jpg","25.jpg","26.jpg"];
var nombres = ["Carlos Abad", "Javier Cendón","Ángel Marín","Ryan Nolan","Alfonso Candelas","Sergi Molina","Josema","Samu Vázquez","Juanmi",
"Hugo Sanz","David López","Roger Colomina","Artiles","César Moreno","Carlos Mangada","Michel","Carlos de la Nava","Alvarito","Coscia",
"Nico Espinosa","Jean Paul", "Marcos Mendes", "Ketu","Salah","Galvañ", "Diego Lorenzo"];
var dorsal = [1,13,25,2,3,4,5,15,16,18,24,6,8,14,19,21,22,7,9,10,11,17,20,27,28,34];
var nacion = ["España", "España","España", "Irlanda","España","España","España","España","España","España","España","España","España","España","España",
"España","España","España","Argentina","España","Francia","Guinea-Bissau","Camerún","Marruecos","España","España"];
var posicion = ["Portero","Portero","Portero","Defensa Central","Lateral Izquierdo","Defensa Central","Defensa Central","Lateral Derecho","Defensa Central",
"Lateral Izquierdo","Lateral Derecho","Mediocentro", "Mediocentro","Mediocentro","Mediocentro","Mediocentro","Mediocentro","Extremo Izquierdo/Derecho",
"Delantero","Extremo Izquierdo/Derecho","Extremo Izquierdo/Derecho y Delantero","Delantero","Extremo Derecho y Delantero","Delantero","Delantero","Delantero"];
var goles = [10,3,0,0,1,0,1,2,2,0,0,3,0,0,1,0,1,4,1,0,0,5,3,0,0,0];
var valor = ["200k","25k","No disponible", "150k","200k","50k","200k","150k","200k","100k","No disponible","200k","200k","200k","100k","100k","200k","200k",
"200k","50k","50k","200k","200k","No disponible","No disponible","50k"];
var contador = 0;

var himno = new Audio("../media/audio/himno.mp3");
var ultimoVolumen;

var preguntas = ["¿Cuantas temporadas ha debutado en primera?","¿Cuantas victorias tiene en segunda division?","¿Quien es portero titular?",];
var respuestas1 = ["20","0","Angel Marin"];
var respuestas2 = ["5","4","Carlos Abad"];
var respuestas3 = ["14","3","Iker Casillas"];
var respuestas4 = ["19","1","Javier Cendon"];
var puntos = 0;
var i = 0;

//Programa Menu de navegacion
menuNav.style.left = "-30vw";

function abrirMenu(){
	
	if (menuNav.style.left === "-30vw"){
		menuNav.style.left = "0%";
		btnMenu.src="../media/img/Iconos/x.png";
	}
	else {
		menuNav.style.left = "-30vw";
		btnMenu.src="../media/img/Iconos/menu.png";
	}
}

//Funciones para cambiar jugador
function anterior(){
	if (contador > 0){
		contador--;
		document.getElementById("foto-jugador").src = "../media/img/Jugadores/"+imgJugadores[contador];
		document.getElementById("nombre").innerHTML = "Nombre: "+nombres[contador];
		document.getElementById("dorsal").innerHTML = "Dorsal: "+dorsal[contador];
		document.getElementById("nacionalidad").innerHTML = "Nacionalidad: "+nacion[contador];
		document.getElementById("posicion").innerHTML = "Posicion: "+posicion[contador];
		document.getElementById("valor").innerHTML = "Valor En Mercado: "+valor[contador];
		if (posicion[contador] === "Portero"){
			document.getElementById("goles").innerHTML = "Goles en Contra: "+goles[contador];
		}
		else{
			document.getElementById("goles").innerHTML = "Goles: "+goles[contador];
		}
	}
	else{
		contador = 0;
		document.getElementById("foto-jugador").src = "../media/img/Jugadores/"+imgJugadores[contador];
		document.getElementById("nombre").innerHTML = "Nombre: "+nombres[contador];
		document.getElementById("dorsal").innerHTML = "Dorsal: "+dorsal[contador];
		document.getElementById("nacionalidad").innerHTML = "Nacionalidad: "+nacion[contador];
		document.getElementById("posicion").innerHTML = "Posicion: "+posicion[contador];
		document.getElementById("valor").innerHTML = "Valor En Mercado: "+valor[contador];
		if (posicion[contador] === "Portero"){
			document.getElementById("goles").innerHTML = "Goles en Contra: "+goles[contador];
		}
		else{
			document.getElementById("goles").innerHTML = "Goles: "+goles[contador];
		}
	}
}

function siguiente(){
	longitud = (imgJugadores.length)-1
	if (contador < longitud){
		contador++;
		document.getElementById("foto-jugador").src = "../media/img/Jugadores/"+imgJugadores[contador];
		document.getElementById("nombre").innerHTML = "Nombre: "+nombres[contador];
		document.getElementById("dorsal").innerHTML = "Dorsal: "+dorsal[contador];
		document.getElementById("nacionalidad").innerHTML = "Nacionalidad: "+nacion[contador];
		document.getElementById("posicion").innerHTML = "Posicion: "+posicion[contador];
		document.getElementById("valor").innerHTML = "Valor En Mercado: "+valor[contador];
		if (posicion[contador] === "Portero"){
			document.getElementById("goles").innerHTML = "Goles en Contra: "+goles[contador];
		}
		else{
			document.getElementById("goles").innerHTML = "Goles: "+goles[contador];
		}
	}
	else{
		contador = imgJugadores.length;
		document.getElementById("foto-jugador").src = "../media/img/Jugadores/"+imgJugadores[contador-1];
		document.getElementById("nombre").innerHTML = "Nombre: "+nombres[contador-1];
		document.getElementById("dorsal").innerHTML = "Dorsal: "+dorsal[contador-1];
		document.getElementById("nacionalidad").innerHTML = "Nacionalidad: "+nacion[contador-1];
		document.getElementById("posicion").innerHTML = "Posicion: "+posicion[contador-1];
		document.getElementById("valor").innerHTML = "Valor En Mercado: "+valor[contador-1];
		if (posicion[contador-1] === "Portero"){
			document.getElementById("goles").innerHTML = "Goles en Contra: "+goles[contador-1];
		}
		else{
			document.getElementById("goles").innerHTML = "Goles: "+goles[contador-1];
		}
	}
}

//Funciones para el himno

himno.addEventListener('ended', function(){reinciarAudio()})

function reinciarAudio(){
	himno.pause();
	himno.currentTime = 0;
	document.getElementById("play").src = "../media/img/Iconos/play.png";
	document.getElementById("play").onclick = dale;
}

function dale(){
	himno.play();
	document.getElementById("play").src = "../media/img/Iconos/pause.png";
	document.getElementById("play").onclick = pausa;
}

function pausa(){
	himno.pause();
	document.getElementById("play").src = "../media/img/Iconos/play.png";
	document.getElementById("play").onclick = dale;
}

function cambiarVolumen(){
	himno.volume = document.getElementById("volumen").value;
}

function silenciar(){
	ultimoVolumen = himno.volume;
	himno.volume = 0;
	document.getElementById("mute").src = "../media/img/Iconos/mute.png";
	document.getElementById("mute").onclick = activarSonido;
	document.getElementById("volumen").value = himno.volume;
}

function activarSonido(){
	himno.volume = ultimoVolumen;
	document.getElementById("mute").src = "../media/img/Iconos/volumen.png";
	document.getElementById("mute").onclick = silenciar;
	document.getElementById("volumen").value = himno.volume;
}

/*Funciones Quiz*/

function cambiarPregunta(){
	r1 = document.getElementById("r1");
	r2 = document.getElementById("r2");
	r3 = document.getElementById("r3");
	r4 = document.getElementById("r4");
	if (i === 2){
		document.getElementById("botonPreguntas").value = "Finalizar";
	}
	if (i < (preguntas.length)-1){
		if (i === 0 && r1.checked){
			puntos++;
		}
		else if(i === 1 && r3.checked){
			puntos++;
		}
		i++;
		document.getElementById("pregunta").innerHTML = preguntas[i];
		document.getElementById("tr1").innerHTML = respuestas1[i];
		document.getElementById("tr2").innerHTML = respuestas2[i];
		document.getElementById("tr3").innerHTML = respuestas3[i];
		document.getElementById("tr4").innerHTML = respuestas4[i];
	}
	else{
		if(i === 2 && r2.checked){
			puntos++;
		}
		document.getElementById("resultado").innerHTML += puntos + "/3"
		document.getElementById("botonPreguntas").value = "Retomar";
		document.getElementById("botonPreguntas").onclick = reiniciarQuiz;
	}
	r1.checked = false;
	r2.checked = false;
	r3.checked = false;
	r4.checked = false;
}

function reiniciarQuiz(){
	r1 = document.getElementById("r1");
	r2 = document.getElementById("r2");
	r3 = document.getElementById("r3");
	r4 = document.getElementById("r4");
	puntos = 0;
	i = 0;
	document.getElementById("pregunta").innerHTML = preguntas[i];
	document.getElementById("tr1").innerHTML = respuestas1[i];
	document.getElementById("tr2").innerHTML = respuestas2[i];
	document.getElementById("tr3").innerHTML = respuestas3[i];
	document.getElementById("tr4").innerHTML = respuestas4[i];
	r1.checked = false;
	r2.checked = false;
	r3.checked = false;
	r4.checked = false;
	document.getElementById("resultado").innerHTML = "Puntos: "
	document.getElementById("botonPreguntas").value = "Siguiente";
	document.getElementById("botonPreguntas").onclick = cambiarPregunta;
}