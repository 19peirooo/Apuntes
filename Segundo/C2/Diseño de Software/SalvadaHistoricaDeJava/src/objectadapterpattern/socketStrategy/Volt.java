package objectadapterpattern.socketStrategy;

public class Volt {
	private Integer volts;
	
	public Volt(Integer volts) {
		this.volts = volts;
	}
	
	public Integer getVolts() {
		return this.volts;
	}

	@Override
	public String toString() {
		return "Volt [volts=" + this.volts + "]";
	}
	
	
}
