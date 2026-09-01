package decoratorpattern.message;

public class Message implements MessageComponent {
	
	private String message;
	
	public Message() {
		this("");
	}
	
	public Message(String message) {
		this.message = message;
	}
	
	@Override
	public String getMessage() {
		return this.message;
	}

}
