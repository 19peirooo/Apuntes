package statepattern.traffic.estadosinternos;

import java.util.concurrent.TimeUnit;

public class TrafficLight {
	
	private TrafficLightState trafficLightState;
	private RedLightState redLight;
	private AmberLightState amberLight;
	private GreenLightState greenLight;
	
	public TrafficLight() {
		this.redLight = new RedLightState(this);
		this.amberLight = new AmberLightState(this);
		this.greenLight = new GreenLightState(this);
		this.setTrafficLightState(this.redLight);
	}

	public TrafficLightState getTrafficLightState() {
		return this.trafficLightState;
	}

	public void setTrafficLightState(TrafficLightState trafficLightState) {
		this.trafficLightState = trafficLightState;
	}
	
	public RedLightState getRedLight() {
		return this.redLight;
	}

	public AmberLightState getAmberLight() {
		return this.amberLight;
	}

	public GreenLightState getGreenLight() {
		return this.greenLight;
	}

	public void showState() {
		this.trafficLightState.showState(); //Delegacion por composicion
	}
	
	public void switchOn() {
		for (int i = 0; i < 7; i++) {
			this.showState();
			try {
				TimeUnit.SECONDS.sleep(2);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
