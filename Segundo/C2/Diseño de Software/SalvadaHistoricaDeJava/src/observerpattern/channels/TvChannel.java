package observerpattern.channels;

public class TvChannel implements PullPushObserver{

	@Override
	public void update(PullPushObservable observable, Object object) {
		if (observable instanceof WeatherObservable) {
			System.out.println("[Pull Protocol TV Channel] Hexadecimal Integer as String: " + ((WeatherObservable)observable).getWeather());
		} else if (object instanceof String) {
			System.out.println("[Push Protocol TV Channel] Hexadecimal Integer as String: " + (String)object);
		}
	}

}
