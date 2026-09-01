package EntregaStatePattern;

//Cada estado ha de ser procesado --> Cada estado ha de poder acceder al contexto para poder acceder a los estados internos
public interface LibraryLoanState {
	public void process();
	public LibraryLoanRequestContext getLibraryLoanRequestContext();
}
