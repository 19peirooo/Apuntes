package statepattern.biblioteca;

public interface LibraryLoanStateTransition {
	public void aceptar();
	public void rechazar();
	public void devolver();
	public void recoger();
}
