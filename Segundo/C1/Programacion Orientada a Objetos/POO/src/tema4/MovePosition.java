package tema4;

public class MovePosition {
	private Integer x;
	class RandomWalk {
		private Double  probability;
		private Boolean success;
		RandomWalk(){
			this(0.5);
		}
		RandomWalk(Double probability){
			this.probability = probability;
			this.walk();
		}
		
		public Double getProbability() {
			return probability;
		}
		
		public Boolean getSuccess() {
			return success;
		}
		public void walk() {
			Double randomExperiment = Math.random();
			this.success = randomExperiment <= this.probability;
			if (this.success) 
				++x; 
			else 
				--x;
		}
	}
	public Integer getX() {
		return x;
	}
	public void setX(Integer x) {
		this.x = x;
	}

	public MovePosition() {
		this(0);
	}
	
	public MovePosition(Integer x) {
		super();
		this.x = x;
	}
	
	public void move (Integer movimientos) {
		RandomWalk randomWalk = new RandomWalk();
		for (int i = 0; i < movimientos; i++) {
			randomWalk.walk();
		}
	}
		
	@Override
	public String toString() {
		return "Position [x=" + x + "]";
	}
	public static void main(String[] args) {
		MovePosition position = new MovePosition();
		System.out.println("Posición inicial "+ position);
		position.move(1000);
		System.out.println("Posición final real "+ position);
	
		
		
	}
}
