package objectadapterpattern.socketStrategy;

public class EnergySocket12VStrategy implements EnergySocketStrategy{

	@Override
	public Volt convertVolt(Volt volt) {
		return new Volt(volt.getVolts()/10);
	}

}
