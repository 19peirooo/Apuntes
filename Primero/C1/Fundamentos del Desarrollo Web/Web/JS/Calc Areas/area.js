function calculaAreaT(){
    var base;
    var altura;
    var area;
    base = document.getElementById("base").value;
    altura = document.getElementById("altura").value;
    area = parseFloat(base)*parseFloat(altura)/2;
    document.getElementById("resultado_T").value = area;
}
function calculaAreaC(){
    var radio;
    var area;

    radio = document.getElementById("radio").value
    area = Math.PI*(parseFloat(Math.pow(radio,2)));
    document.getElementById("resultado_C").value = area;
}