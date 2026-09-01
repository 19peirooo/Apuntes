package decoratorpattern.message;

public class GreetingDecorator extends AbstractMessageDecorator{
	
	private String greeting;
	
	public GreetingDecorator(MessageComponent messageComponent, String greeting) {
		super(messageComponent);
		this.greeting = greeting;
	}

	@Override
	public String getDecoratedMessage(String message) {
		return this.greeting + " " + message;
	}

}
