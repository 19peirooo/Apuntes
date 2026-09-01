package decoratorpattern.message;

public class Screen {
	
	private MessageComponent msg;
	
	public Screen() {
		this.msg = new Message("Hola Soy Gonzalo y me va a quedar Java");
	}
	
	public MessageComponent getMsg() {
		return this.msg;
	}

	public void setMsg(MessageComponent msg) {
		this.msg = msg;
	}

	public String getMessage() {
		return this.msg.getMessage();
	}
	
	public void showMsg() {
		System.out.println(this.getMessage());
	}
	
}
