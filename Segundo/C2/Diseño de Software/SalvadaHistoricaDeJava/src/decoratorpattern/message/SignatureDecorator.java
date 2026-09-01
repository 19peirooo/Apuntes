package decoratorpattern.message;

public class SignatureDecorator extends AbstractMessageDecorator{
	
	private String signature;
	
	public SignatureDecorator(MessageComponent messageComponent, String signature) {
		super(messageComponent);
		this.signature = signature;
	}

	@Override
	public String getDecoratedMessage(String message) {
		return message + " Signature: " + this.signature;
	}

}
