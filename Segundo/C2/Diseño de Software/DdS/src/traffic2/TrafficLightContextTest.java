package traffic2;

import java.util.concurrent.TimeUnit;

public class TrafficLightContextTest { 
	public static void main(String[] args) { 
		TrafficLightContext trafficLight = new TrafficLightContext(); 
		for (int i=0; i<7; i++){ 
			trafficLight.show(); 
			try { 
				TimeUnit.SECONDS.sleep(2); 
			} catch (InterruptedException e) { 
				e.printStackTrace(); 
			} 
		} 
	} 
}