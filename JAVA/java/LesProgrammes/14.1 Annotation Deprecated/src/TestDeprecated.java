public class TestDeprecated {
	public static void main(String[] args) {
		MaSousClasse td = new MaSousClasse();
		td.maMethode();
	}
}


@Deprecated
class MaSousClasse {
	/**
	 * Afficher un message de test
	 * 
	 * @deprecated methode non compatible
	 */
	@Deprecated
	public void maMethode() {
		System.out.println("test");
	}
}
