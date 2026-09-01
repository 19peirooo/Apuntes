package abstractfactorymethod.enemy;

public class W1Witch implements Witch{
		
		private String name;
		private Integer power;
		private Integer lives;
		private String magicPower;
		
		public W1Witch() {
			this.name = "Witch";
			this.power = 20 * World.World1.getComplexFactor();
			this.lives = 2 * World.World1.getComplexFactor();
			this.magicPower = "Varita Magica";
		}

		@Override
		public String getName() {
			return this.name;
		}

		@Override
		public Integer getPower() {
			return this.power;
		}

		@Override
		public Integer getLives() {
			return this.lives;
		}

		@Override
		public String getMagicPower() {
			return this.magicPower;
		}

		@Override
		public String toString() {
			return "W1Witch [name=" + name + ", power=" + power + ", lives=" + lives + ", magicPower=" + magicPower
					+ "]";
		}
		
		
}
