var ImagenNames = ["pickachu","caterpie","bulbasur","squirtel","charmander","pickachuborracho","metapod","snorlax","gyarados"];
var Frases = ["Llegaré a ser el mejor.","El mejor que habrá jamás.","Mi causa es ser su entrenador.","Tras poderlos captura.",
"Viajaré a cualquier lugar.","Llegare a cualquier rincon.","Y al fin podré desentrañar.","El poder de su interior.","Pokémon! (Hazte con todos)."]
var Names = ["pickachu", "caterpie", "bulbasur", "squirtel", "charmander","pickachuborracho","metapod","snorlax", "gyarados"];

var TextElement = document.getElementById("Texto");
var NameElement = document.getElementById("Nombre");
var ImgElement = document.getElementById("ImgContainer");

var i = 0;

function inicio()
{
	setInterval(CambiarImagenes, 3200);
}

function CambiarImagenes()
{
	
	i++;
	if(i >= ImagenNames.length)
	{
		i = 0;
	}
	
	TextElement.innerHTML = Frases[i];
	NameElement.innerHTML = '- ' + Names[i] + ' -';
	ImgElement.innerHTML = "<img src='fotos/Imagen/" + ImagenNames[i] + ".jpg' alt='Image not found' height='100%' width='100%'>"

}