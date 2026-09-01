package strategypattern.areas;

public class ContextAreaStrategy implements AreaStrategy{
	
	private AreaStrategy areaStrategy;
	
	public ContextAreaStrategy() {
		this(new CircleAreaStrategy());
	}
	
	public ContextAreaStrategy(AreaStrategy areaStrategy) {
		this.areaStrategy = areaStrategy;
	}
	
	public void setAreaStrategy(AreaStrategy areaStrategy) {
		this.areaStrategy = areaStrategy;
	}
	
	@Override
	public Double calcularArea(Double parametro) {
		return this.areaStrategy.calcularArea(parametro); //Delegacion por agregacion
	}
	
	
}
