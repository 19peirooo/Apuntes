package observerpattern.tienda;

import java.util.ArrayList;
import java.util.List;

public class Product implements PullPushObservable {
	
	private String name;
	private Integer stock;
	private List<PullPushObserver> observers;
	
	public Product(Integer stock, String name) {
		this.name = name;
		this.stock = stock;
		this.observers = new ArrayList<PullPushObserver>();
	}
	
	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Integer getStock() {
		return this.stock;
	}

	public void setStock(Integer stock) {
		this.stock = stock;
		this.notifyObservers();
	}

	@Override
	public void attach(PullPushObserver observer) {
		this.observers.add(observer);
	}

	@Override
	public void detach(PullPushObserver observer) {
		this.observers.remove(observer);
	}

	@Override
	public void notifyObservers() {
		for (PullPushObserver observer: this.observers) {
			observer.update(this, this.stock);
		}
	}

	@Override
	public boolean equals(Object obj) {
		if (obj instanceof Product) {
			Product prod = (Product)obj;
			return this.name.equals(prod.getName());
		} else {
			return false;
		}
		
	}

	@Override
	public String toString() {
		return "Product [name=" + this.name + ", stock=" + this.stock + "]";
	}
	
	
	
}
