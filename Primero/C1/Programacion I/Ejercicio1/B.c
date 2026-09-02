/*Ejercicio B
Una tienda ha pedido un sistema gestor para generar sus tickets.
La tienda ofrece descuentos en función del tipo de cliente y del monto de la compra. Existendos tipos de clientes:
- VIP: Obtienen un 20% de descuento si la compra es mayor o igual a 100€ y un 10% si es inferior.
- Normal: Obtienen un 5% de descuento si la compra es mayor o igual a 50€.
Sobre el importe se debe aplicar el IVA correspondiente del 21%. Del precio final se destinan siempre los céntimos para causas benéficas.
Se necesita generar un ticket de compra en el que, dado un importe inicial y el tipo de cliente introducido por el personal del establecimiento, se muestre:
- Importe total.
- Tipo de cliente.
- Cada descuento e impuesto aplicado sobre el precio.
- Importe definitivo.
- Dinero destinado a causas benéficas.
El programa debe pedir al usuario, que habitualmente será el comerciante: El tipo de cliente, el monton de la compra y generar el ticket*/

#include <stdio.h>

int main(){
	char TipoCliente;
	double ImporteInicial,NuevoImporte,Donacion;
	int descuento;
	
	printf("Introduce si eres cliente VIP o Normal: v/n \n");
	scanf("%c",&TipoCliente);
	
	if (TipoCliente == 'V' || TipoCliente == 'v'){
		printf("Introduce el Importe Inicial: \n");
		scanf("%lf", &ImporteInicial);
		if (ImporteInicial >= 100){
			descuento = 20;
		}
		else{
			descuento = 10;
		}
	}
	else if (TipoCliente == 'N' || TipoCliente == 'n'){
		printf("Introduce el Importe Inicial: \n");
		scanf("%lf", &ImporteInicial);
		if (ImporteInicial >= 50){
			descuento = 5;
		}
		else{
			descuento = 0;
		}
	}
	else{
		printf("Tipo de Cliente no valido");
		return 0;
	}
	printf("Ticket: \n");
	printf("Importe Total: %.2lf \n", ImporteInicial);
	if (TipoCliente == 'V' || TipoCliente == 'v'){
		printf("Tipo de Cliente: VIP \n");
	}
	else{
		printf("Tipo de Cliente: Normal \n");
	}
	printf("Descuento: %d% \nImpuesto: 21% \n", descuento);
	NuevoImporte = ImporteInicial - (ImporteInicial*((double)descuento/100));
	NuevoImporte *= 1.21;
	printf("Importe Definitivo: %.2lf \n", NuevoImporte);
	Donacion = NuevoImporte -(int)NuevoImporte;
	printf("Dinero a causas beneficas: %.2lf",Donacion);
	return 0;
}