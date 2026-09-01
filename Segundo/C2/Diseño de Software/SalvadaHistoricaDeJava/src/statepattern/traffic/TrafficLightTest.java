package statepattern.traffic;

import java.util.concurrent.TimeUnit;

public class TrafficLightTest {
	public static void main(String[] args) {
		TrafficLight trafficLight = new TrafficLight();
		for (int i = 0; i < 7; i++) {
			trafficLight.showState();
			try {
				TimeUnit.SECONDS.sleep(2);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
