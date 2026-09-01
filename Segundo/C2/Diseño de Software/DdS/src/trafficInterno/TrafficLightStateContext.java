package trafficInterno;

import java.util.concurrent.TimeUnit;

public class TrafficLightStateContext {
	private TrafficLightState trafficLightState;
	private RedLightState redLightState;
	private AmberLightState amberLightState;
	private GreenLightState greenLightState;
	
	public TrafficLightStateContext() {
		this.redLightState = new RedLightState(this);
		this.amberLightState = new AmberLightState(this);
		this.greenLightState = new GreenLightState(this);
		this.setTrafficLightState(this.redLightState);
	}

	public TrafficLightState getTrafficLightState() {
		return this.trafficLightState;
	}

	public void setTrafficLightState(TrafficLightState trafficLightState) {
		this.trafficLightState = trafficLightState;
	}

	public RedLightState getRedLightState() {
		return this.redLightState;
	}

	public void setRedLightState(RedLightState redLightState) {
		this.redLightState = redLightState;
	}

	public AmberLightState getAmberLightState() {
		return this.amberLightState;
	}

	public void setAmberLightState(AmberLightState amberLightState) {
		this.amberLightState = amberLightState;
	}

	public GreenLightState getGreenLightState() {
		return this.greenLightState;
	}

	public void setGreenLightState(GreenLightState greenLightState) {
		this.greenLightState = greenLightState;
	}
	
	public void show() {
		this.trafficLightState.show();
	}
	
	public void switchOn() {
		for (int i = 0; i < 7; i++) {
			this.show();
			try {
				TimeUnit.SECONDS.sleep(2);
			} catch (Inte){}
		}
	}
}
