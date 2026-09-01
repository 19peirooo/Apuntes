package facadepattern.server;

public class ScheduleServerTest {
	public static void main(String[] args) {
		ScheduleServer server = new ScheduleServer();
		ScheduleServerFacade facade = new ScheduleServerFacade(server);
		facade.startServer();
		System.out.println("***Server Started***");
		facade.stopServer();
	}
}
