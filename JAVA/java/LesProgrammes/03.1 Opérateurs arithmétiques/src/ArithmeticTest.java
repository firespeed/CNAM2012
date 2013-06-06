class ArithmeticTest
{
	public static void main (String[] args)
	{
		short x = 6;
		int y = 4;
		float a = 12.5f;
		float b = 7f;
		
		byte w = 120;

			// Affichage d'un short et d'un int
			System.out.println("x egal " + x + ", y egal " + y);			
			// Addition d'un short et d'un int
			System.out.println("x + y = " + (x + y));			
			// Soustraction d'un short et d'un int
			System.out.println("x - y = " + (x - y));
			// Division d'un short par un int
 			System.out.println("x / y = " + (x / y));
			// Modulo d'un short par un int
 			System.out.println("x % y = " + (x % y));
			// Affichage de float
 			System.out.println("a egal " + a + ", b egal " + b);
			// Division de float
 			System.out.println("a / b = " + (a / b));
			// Boucle sortant de la valeur permise d'un byte
			for(int i=0;i<10;i++)
			{
				w++;
				System.out.println("w = " + w);
			}
	}
}