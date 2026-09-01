package singleton.contador;

import observerpattern.tienda.Client;
import observerpattern.tienda.Product;

public class ContadorInstancias {
	
	private static ContadorInstancias contador = new ContadorInstancias();
	private Integer numPeople;
	private Integer numProducts;
	
	private ContadorInstancias() {
		this.numPeople = 0;
		this.numProducts = 0;
	}
	
	public static ContadorInstancias getInstance() {
		return contador;
	}
	
	public void crea(Object obj) {
		if (obj instanceof Client) {
			this.numPeople++;
		} else if (obj instanceof Product) {
			this.numProducts++;
		}
	}
	
	public Integer getNumPeople() {
		return numPeople;
	}

	public void setNumPeople(Integer numPeople) {
		this.numPeople = numPeople;
	}

	public Integer getNumProducts() {
		return numProducts;
	}

	public void setNumProducts(Integer numProducts) {
		this.numProducts = numProducts;
	}

	public static void main(String[] args) {
		ContadorInstancias contador = ContadorInstancias.getInstance();
		contador.crea(new Client("x"));
		System.out.println("Clientes: " + contador.getNumPeople() + ". Productos: " + contador.getNumProducts());
	}
	
}
