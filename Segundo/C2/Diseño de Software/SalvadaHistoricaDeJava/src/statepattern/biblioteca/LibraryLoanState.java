package statepattern.biblioteca;

public interface LibraryLoanState {
	public void process();
	public LibraryLoanRequestContext getLibraryLoanRequestContext();
}
