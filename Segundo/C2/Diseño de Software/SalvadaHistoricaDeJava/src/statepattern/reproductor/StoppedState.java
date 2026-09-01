package statepattern.reproductor;

public class StoppedState implements ReproductorState{
	
	public void showState() {
		System.out.println("Musica Detenida");
	}
}
