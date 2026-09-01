package statepattern.reproductor;

public class PlayingState implements ReproductorState{

	@Override
	public void showState() {
		System.out.println("Musica Sonando");
	}

}
