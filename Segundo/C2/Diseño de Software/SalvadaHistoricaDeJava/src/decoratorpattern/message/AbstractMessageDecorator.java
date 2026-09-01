package decoratorpattern.message;

public abstract class AbstractMessageDecorator implements MessageComponent{
	
	private MessageComponent messageComponent;
	
	public AbstractMessageDecorator(MessageComponent messageComponent) {
		this.messageComponent = messageComponent;
	}

	public String getMessage() {
		if (this.messageComponent != null)
			return this.getDecoratedMessage(messageComponent.getMessage());
		else
			return this.getDecoratedMessage("");
	}
	
	public abstract String getDecoratedMessage(String message);
}
