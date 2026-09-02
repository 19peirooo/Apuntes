var t=0;
var imagenes = ["img1.jpg","img2.jpg","img3.jpg","img4.jpg","img5.jpg","img6.jpg"]
function anterior(){
	if (t !== 0){
		t--;
		document.getElementById("imagen").src = 'imagenes/'+imagenes[t];
	}
	else{
		document.getElementById("imagen").src = 'imagenes/img1.jpg';
	}
}
function siguiente(){
	if (t !== 5){
		t++;
		document.getElementById("imagen").src = 'imagenes/'+imagenes[t];
	}
	else{
		document.getElementById("imagen").src = 'imagenes/img6.jpg';
	}
}