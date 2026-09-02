var t = 10;
var intervalo;

function restar(){
	if (t==0){
		document.getElementById("contador").innerHTML ="BOOM!";
		clearInterval(intervalo);
	}
	else{
		t--;
		document.getElementById("contador").innerHTML ="00:00:0"+t;
	}
}

function activar(){
	intervalo = setInterval(restar,1000)
	}
}

function desactivar(){
	clearInterval(intervalo);
}
