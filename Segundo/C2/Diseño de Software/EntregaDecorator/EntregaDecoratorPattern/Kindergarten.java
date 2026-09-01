package EntregaDecoratorPattern;

import java.util.List;
import java.util.ArrayList;

//Clase Guarderia
public class Kindergarten {
	
	//Atributo --> Lista de bebes
	private List<KinderGartenBaby> babies;
	
	//Constructor
	public Kindergarten() {
		this.babies = new ArrayList<KinderGartenBaby>();
	}
	
	//Getters y Setters
	public List<KinderGartenBaby> getBabies() {
		return this.babies;
	}

	public void setBabies(List<KinderGartenBaby> babies) {
		this.babies = babies;
	}
	
	//Añade un bebe a la lista
	public void addBaby(KinderGartenBaby baby) {
		this.babies.add(baby);
	}
	
	//Elimina un bebe de la lista
	public void removeBaby(KinderGartenBaby baby) {
		this.babies.remove(baby);
	}
	
	//Muestra los premios de todos los bebes
	public void checkBabies() {
		for (KinderGartenBaby baby : this.babies) {
			baby.showRewards();
		}
	}
}
