
class DivParZero {
	public static void main (String argv[] ) {
		int zero=0;
		try { 
			zero = 1997/zero; 
		}
		catch (ArithmeticException e ){
			System.out.println("Une exception arithmétique a été levée");
			System.out.println("Message : " + e.getMessage());
			System.out.println("Pile :");
			e.printStackTrace(); 
		}
		finally
		{
			System.out.println("Fin du calcul");
		}
		System.out.println("Fin du programme");
	}
}
