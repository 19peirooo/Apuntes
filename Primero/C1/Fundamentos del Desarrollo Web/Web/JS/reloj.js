


function reloj(){
	var fecha = new Date();
	var hora = fecha.getHours();
	var minuto = fecha.getMinutes();
	var segundo = fecha.getSeconds();
	var dia = fecha.getDate();
	var mes = fecha.getMonth();
	var anyo = fecha.getFullYear();
	
	if(hora < 10){
		hora = "0"+hora;
	}
	if(minuto < 10){
		minuto = "0"+minuto;
	}
	if(segundo < 10){
		segundo = "0"+segundo;
	}
	document.getElementById("hora").innerHTML = (hora + ":" + minuto + ":" + segundo + " " + dia + "/" + mes + "/" + anyo);
}

function cargar(){
	setInterval(reloj,1000);
}