package objectadapterpattern.socketStrategy;

//Adaptee --> Se adapta el voltaje que recibe
public class EnergySocket {
	
	private Volt volt;
	
	public EnergySocket() {
		this(new Volt(120));
	}
	
	public EnergySocket(Volt volt) {
		this.volt = volt;
	}
	
	public Integer getVolts() {
		return this.volt.getVolts(); //Delegacion por agregacion
	}

	public Volt getVolt() {
		return this.volt;
	}

	public void setVolt(Volt volt) {
		this.volt = volt;
	}
	
	
	
}
