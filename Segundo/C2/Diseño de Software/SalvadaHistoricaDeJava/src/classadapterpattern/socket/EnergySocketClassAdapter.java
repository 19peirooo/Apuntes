package classadapterpattern.socket;

//Adaptador Concreto --> Lo que va a adaptar el objeto adaptado
public class EnergySocketClassAdapter extends EnergySocket implements EnergySocketAdapter{

	@Override
	public Volt getVolt() {
		return super.getVolt();
	}

	@Override
	public Volt get3Volt() {
		return this.convertVolts(this.getVolt(), 40);
	}

	@Override
	public Volt get12Volt() {
		return this.convertVolts(this.getVolt(), 10);
	}

	@Override
	public Volt get120Volt() {
		return this.convertVolts(this.getVolt(), 1);
	}
	
	public Volt convertVolts(Volt v, Integer i) {
		return new Volt(v.getVolts()/i);
	}

}
