package AbstractFactoryMotorola;
/**
 * Enumerado con los valores posibles de lenguaje y su codificación
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public enum Language {
	ENGLISH("en"),SPANISH("es");
	private String	isoCode;

	private Language(String isoCode) {
		this.isoCode = isoCode;
	}

	public String getIsoCode() {
		return isoCode;
	}
}
