package EntregaDecoratorPattern;

public class KinderGartenBaby {
	
	//Atributos
	private String nombre;
	private Integer edad;
	private RewardComponent reward;
	
	//Constructor
	public KinderGartenBaby(String nombre, Integer edad) {
		this.nombre = nombre;
		this.edad = edad;
		this.reward = new StickerComponent(this.nombre);
	}
	
	//Getters y Setters
	public String getNombre() {
		return this.nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Integer getEdad() {
		return this.edad;
	}

	public void setEdad(Integer edad) {
		this.edad = edad;
	}

	public RewardComponent getReward() {
		return this.reward;
	}

	public void setReward(RewardComponent reward) {
		this.reward = reward;
	}
	
	public String getDescription() {
		return this.reward.getDescription(); //Delegacion por composicion
	}
	
	//Muestra las recompensas de cada bebe
	public void showRewards() {
		System.out.println(this.getDescription());
	}
	
	
	
}
