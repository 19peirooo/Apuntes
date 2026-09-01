package tema4;

public class EdificioOficinas implements Edificio{
	
	private Double superficie;
	
	public EdificioOficinas(Double superficie) {
		this.superficie = superficie;
	}
	
	@Override
	public Double superficieEdificio() {
		// TODO Auto-generated method stub
		return this.superficie;
	}
	
}
